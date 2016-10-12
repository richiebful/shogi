/** \file */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "shogi.h"
#include "ai.h"

#define DEBUG_FLAG 1
#define BISHOP_DEVELOPMENT_TEST 1

#ifdef DEBUG_FLAG
struct aiParameters defaultParams{
  {
    "PLNGUBRQMOHCSK",
    {7, 20, 20, 35, 40, 90, 95, 15, 25, 25, 35, 99, 97, 10}
  },
  {
    "PLNGUBRQMOHCSK",
    {7, 20, 20, 35, 40, 90, 95, 15, 25, 25, 35, 99, 97, 10}
  },
  {
    "PLNGUBRQMOHCSK",
    {3, 10, 10, 17, 20, 45, 47, 7, 12, 12, 17, 49, 48, 5}
  },
  75,
  3
};
#endif

int32_t scoreGraveyardPiece(char piece, int player, int owner);
int32_t scoreDroppability(char piece, char board[9][9], int player);
int32_t scorePieceDevelopment(int loc[2], char board[9][9], int player, bool oppInCheckF);
int32_t scoreSign(int player, int owner);
int32_t scoreBishopDevelopment(int loc[2], char board[9][9], int player);
int32_t scoreUpBishopDevelopment(int loc[2], char board[9][9], int player);
int32_t scoreLanceDevelopment(int loc[2], char board[9][9], int player);
int32_t scoreRookDevelopment(int loc[2], char board[9][9], int player);
int32_t scoreUpRookDevelopment(int loc[2], char board[9][9], int player);
int32_t scoreKnightDevelopment(int loc[2], char board[9][9], int player);
bool obstructionTest(char attackedPiece, bool atAttackingPiece, bool pastAttackingPiece, int player, int *count);
int32_t scorePinning(int loc[2], char board[9][9], int player);
int ownerOf(char piece);

/**
 * Scores a game state in the decision tree
 * @todo determine factors to multiply helper functions by
 */
int32_t scoreState(char board[9][9], char graveyard[2][GRAVEYARD_MAX], int player, struct aiParameters *params){
  int opponent = (player % 2) + 1;

  // if opponent in check, return max score, else if player in check, return min score
  if (isMate(board, graveyard, opponent)){
    return INT32_MAX;
  }
  else if (isMate(board, graveyard, player)){
    return INT32_MIN;
  }
  
  int i, j;
  char piece;
  int32_t score = (isCheck(board, opponent) - isCheck(board, opponent)) * params.isCheck;
  for (i = 0; i < 9; i++){
    for (j = 0; j < 9; j++){
      piece = board[i][j];
      if (piece != ' '){
	int loc[2] = {i, j};
	//don't let pieceDevelopment run when piece's player is in check
	score += scorePieceDevelopment(loc, board, player);
	score += scorePinning(loc, board, player);
      }
    }
  }
  
  for (i = 0; i < 2; i++){
    for (j = 0; j < GRAVEYARD_MAX; j++){
      piece = graveyard[i][j];
      if (piece){
	score += scoreGraveyardPiece(piece, player, i + 1);
	score += scoreDroppability(piece, board, player);
      }
    }
  }
  return score;
}

/**
 * Returns score for piece in graveyard, 
 *  factoring in who has ownership
 */
int32_t scoreGraveyardPiece(char piece, int player, int owner, struct pcValuation *values){
  for (int i = 0; i < sizeof(values->name)/sizeof(values->name[0]); i++){
    if (toupper(piece) == values->name[i]){
      //printf("toupper(piece) -> %c \n", toupper(piece));
      return scoreSign(player, owner) * values->score[i];
    }
  }
}

/**
 * (Returns number of locations a piece can be dropped) * k
 * @pre piece is in the graveyard of the player
 */
int32_t scoreDroppability(char piece, char board[9][9], int player, const double DROPPABILITY_COEFF){
  int dst[2];
  int32_t count;
  for (dst[0] = 0; dst[0] < 9; dst[0]++){
    for (dst[1] = 0; dst[1] < 9; dst[1]++){
      if (legalDrop(board, player, piece, dst)){
	count++;
      }
    }
  }
  return DROPPABILITY_COEFF * count;
}

/**
 * Scores a piece generally, based on its assumed value in game play
 */
int32_t scorePiece(char piece, int player, struct pcValuation *value){
  for (int i = 0; i < sizeof(value->name)/sizeof(value->name[0]); i++){
    if (piece == value->name[i]){
      return scoreSign(player, 1) * value->score[i];
    }
    else if (toupper(piece) == PIECE_VALUES.name[i]){
      return scoreSign(player, 2) * value->score[i];
    }
  }
}

/**
 * (Returns a measurement of piece development) * k
 * @pre board[rank][file] is a piece
 * @note only pieces with range, like rook, bishop, lance can be developed
 */
int32_t scorePieceDevelopment(int loc[2], char board[9][9], int player, struct pcValuation *devValue){
  char piece = board[loc[0]][loc[1]];
  int32_t score = 0;
  switch (piece){
  case 'B':
  case 'b':
  case 'C':
  case 'c':
    score = scoreBishopDevelopment(loc, board, player);
    break;
  case 'L':
  case 'l':
    score = scoreLanceDevelopment(loc, board, player);
    break;
  case 'N':
  case 'n':
    score = scoreKnightDevelopment(loc, board, player);
    break;
  case 'R':
  case 'r':
  case 'S':
  case 's':
    score = scoreRookDevelopment(loc, board, player);
    break;
  }
  
  return scorePiece(piece, player, devValue) * score;
}

/**
 * Determines whether a piece at loc is pinned by the opponent to protect the king
 */
int32_t scorePinning(int loc[2], char board[9][9], int player, struct pcValuation *pinValue){
  char tempBoard[9][9];
  memcpy(tempBoard, board, sizeof(char)*9*9);
  int32_t score = 0;
  char pinCandidate = tempBoard[loc[0]][loc[1]];
  tempBoard[loc[0]][loc[1]] = ' ';
  score -= scoreSign(player, ownerOf(pinCandidate)) * isCheck(board, (player % 2) + 1);
  tempBoard[loc[0]][loc[1]] = pinCandidate;
  return score * scorePiece(pinCandidate, player, pinValue);
}

/**
 * Determines sign of factor k in above calculations
 */
int32_t scoreSign(int player, int owner){
  return (player == owner) ? 1 : -1;
}

/**
 * @todo test functionality
 */
int32_t scoreBishopDevelopment(int loc[2], char board[9][9], int player){
  int dfile, drank;
  //all arrays of 2 elements are of format {-slope diagonal, +slope diagonal}
  int32_t count[2] = {0, 0};
  bool atBishopIn, pastBishopIn;
  char pcInSame;
  int i;
  for (i = -1; i < 2; i += 2){
    int32_t nCount = 0;
    for (drank = 0; drank < 9; drank++){
      atBishopIn = drank == loc[0];
      pastBishopIn = drank > loc[0];
      dfile = -i * drank + (loc[1] + i * loc[0]);
      //dfile = (i == -1) ? drank + (loc[1] - loc[0]) : -drank + (loc[1] + loc[0]);
      pcInSame = board[drank][dfile];
      printf("currentDest: (%i, %i)\n", drank, dfile);
      if (nCount < 0 || !inRange(drank, dfile)){
	continue;
      }
      if (!obstructionTest(pcInSame, atBishopIn, pastBishopIn, player, &count[(i + 1)/2])){
	break;
      }
    }
  }
  return count[0] + count[1];
}

/**
   int32_t scoreUpBishopDevelopment(int loc[2], char board[9][9], int player){
   int32_t count = scoreBishopDevelopment(loc, board, player);
   int potentialDst[4][2] = {{loc[0] + 1, loc[1]},
   {loc[0] - 1, loc[1]},
   {loc[0], loc[1] + 1},
   {loc[0], loc[1] - 1}};
   for (int i = 0; i < sizeof(potentialDst)/sizeof(potentialDst[0]); i++){
   char dstPiece = board[potentialDst[i][0]][potentialDst[i][1]];
   if (ownerOf(dstPiece) != player){
   score++;
   } else {
   continue;
   }
   }
   }
*/

/**
 * @todo test the shit out of this
 */
int32_t scoreLanceDevelopment(int loc[2], char board[9][9], int player){
  int32_t count = 0, nCount;
  int rel_dir = relativeDirectionOf(player);
  int outOfBounds = 4 + 5 * rel_dir;
  int i;
  for (i = loc[0] + rel_dir; i != outOfBounds; i += rel_dir){
    char attackedPiece = board[i][loc[1]];
    if (!obstructionTest(attackedPiece, false, true, player, &count)){
      break;
    }
  }
  return count;
}

bool playerAttackingOwn(char piece, int player){
  return ('a' < piece && piece < 'z' && player == 1) || 
    ('A' < piece && piece < 'Z' && player == 2);
}

/**
 * Works on pieces that cannot jump, but make "ranged" attacks, e.g. bishop, rook, lance
 * @todo test
 */
bool obstructionTest(char attackedPiece, bool atAttackingPiece, bool pastAttackingPiece, int player, int *count){
  if (attackedPiece == ' '){
    *count += 1;
    return true;
  }
  else if (playerAttackingOwn(attackedPiece, player)){
    if (pastAttackingPiece){
      return false;
    } else if (atAttackingPiece){
      return true;
    } else {
      *count = 0;
      return true;
    }
  }	
  else{
    if (pastAttackingPiece){
      *count += 1;
      return false;
    } else if (atAttackingPiece){
      return true;
    } else {
      *count = 1;
      return true;
    }
  }
}

/**
 * @todo TEST
 */
int32_t scoreRookDevelopment(int loc[2], char board[9][9], int player){
  //all arrays of 2 elements are of format {rank, file}, ie. pcInSame[rank]
  bool atRookIn, pastRookIn;
  int32_t count[2] = {0, 0};
  int32_t nCount;
  int i, j;
  for (i = 0; i < 2; i++){
    for (j = 0; j < 9; j++){
      char pcInSame[2] = {board[loc[0]][j] , board[j][loc[1]]};
      atRookIn = (j == loc[i]);
      pastRookIn = (j > loc[i]);
      printf("obstructionTest(%c, %d, %d, %d, %d)\n", pcInSame[i], atRookIn, pastRookIn, player, count[i]);
      if(!obstructionTest(pcInSame[i], atRookIn, pastRookIn, player, &count[i])){
	break;
      }
    }
  }
  
  return count[0] + count[1];
}

/**
   int32_t scoreUpRookDevelopment(int loc[2], char board[9][9], int player){
   int32_t score = scoreRookDevelopment(loc, board, player);
   int potentialDst[4][2] = {{loc[0] + 1, loc[1] + 1},
   {loc[0] - 1, loc[1] + 1},
   {loc[0] + 1, loc[1] - 1},
   {loc[0] - 1, loc[1] - 1}};
   for (int i = 0; i < sizeof(potentialDst)/sizeof(potentialDst[0]); i++){
   char dstPiece = board[potentialDst[i][0]][potentialDst[i][1]];
   if (ownerOf(dstPiece) != player){
   score++;
   } else {
   continue;
   }
   }
   }
*/

/**
 * Determines how many places a knight can jump
 * @see scorePieceDevelopment
 */
int32_t scoreKnightDevelopment(int loc[2], char board[9][9], int player){
  int dst[2][2] = {{loc[0] + relativeDirectionOf(player), loc[1] + 1}, 
                   {loc[0] + relativeDirectionOf(player), loc[1] - 1}};
  int32_t score = 0;
  int i;
  for (i = 0; i < sizeof(dst)/sizeof(dst[0]); i++){
    if (legalMove(board, player, loc, dst[i], false)){
      score++;
    }
  }
  return score;
}

int ownerOf(char piece){
  if (isupper(piece))
    return 2; 
  else if (islower(piece))
    return 1;
  else
    return 0;
}


#ifdef SCORE_TEST

int main(){
  struct gm_status game;
  struct move_test{
    int src[2];
    int dst[2];
    bool legalF;
    uint32_t score;
    char board[9][9];
    int player;
  };
  struct move_test test[] = {{ .src = {6, 2}, 
			       .dst = {5, 2},
			       .legalF = true, 
			       .score = 0, 
			       .board = {"LNGUKUGNL", 
				         " R     B ", 
					 "PPPPPPPPP", 
					 "         ", 
					 "         ", 
					 "  p      ",
				         "pp pppppp",
				         " b     r ",
				         "lngukugnl"},
			       .player = 1
    },
			     { .src = {7, 1},
			       .dst = {1, 7},
			       .legalF = false,
			       .score = 0,
			       .board = {"LNGUKUGNL", 
					 " R     B ", 
					 "PPPPPPPPP", 
					 "         ", 
					 "         ", 
					 "  p      ",
					 "pp pppppp",
					 " b     r ",
					 "lngukugnl"},
			       .player = 1
			     },
			     { .src = {7, 1},
			       .dst = {2, 6},
			       .legalF = true,
			       .score = 80,
			       .board = {"LNGUKUGNL", 
					 " R     B ", 
					 "PPPPPPbPP", 
					 "         ", 
					 "         ", 
					 "  p      ",
					 "pp pppppp",
					 "       r ",
					 "lngukugnl"},
			       .player = 1
			     },
			     { .src = {0, 7}, 
			       .dst = {2, 6},
			       .legalF = true,
			       .score = 225,
			       .board = {"LNGUKUG L", 
					 " R     B ", 
					 "PPPPPPNPP", 
					 "         ", 
					 "         ", 
					 "  p      ",
					 "pp pppppp",
					 "       r ",
					 "lngukugnl"},
			       .player = 2}
  };
  init_game(&game);
  dispGraveyard(game.graveyard);
  for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++){
    game.player = test[i].player;
    dispBoard(game.board);
    bool legalF = gmLegalMove(&game, test[i].src, test[i].dst);
    printf("%i %i to %i %i \n", test[i].src[0], test[i].src[1], test[i].dst[0], test[i].dst[1]);
    assert(legalF == test[i].legalF);
    if (legalF){
      gmMakeMove(&game, test[i].player, test[i].src, test[i].dst, false, false);
      assert(memcmp(game.board, test[i].board, 9*9) == 0);
      uint32_t score = scoreState(game.board, game.graveyard, test[i].player);
      printf("score: %i\n", score);
      assert(score == test[i].score);
    }
  }
}
#endif

struct board_score_test{
  uint32_t score;
  char board[9][9];
  int pcLocation[2];
  int player;
};
  
#ifdef BISHOP_DEVELOPMENT_TEST
int main(void){
  struct board_score_test test[] = {
    {.board = {"LNGUKUGNL", 
               " R     B ", 
	       "PPPPPPbPP", 
	       "         ", 
	       "         ", 
	       "  p      ",
	       "pp pppppp",
	       "       r ",
	       "lngukugnl"},
     .score = 10,
     .pcLocation = {2, 6},
     .player = 1},
    {.board = {"LNGUKUG L", 
	       " R     B ", 
	       "PPPPPPNPP", 
	       "         ",
	       "         ",
	       "  p      ",
	       "pp pppppp",
	       "       r ",
	       "lngukugnl"},
     .pcLocation = {1, 7},
     .score = 0,
     .player = 2}
  };
  for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++){
    printf("scoreBishopDevelopment given arguments: \n");
    printf("loc = (%i, %i) \n", test[i].pcLocation[0], test[i].pcLocation[1]);
    dispBoard(test[i].board);
    printf("player = %i\n", test[i].player);
    int32_t develScore = scoreBishopDevelopment(test[i].pcLocation, test[i].board, test[i].player);
    printf("--->> \t %i\n", develScore);
    
    assert(test[i].score == develScore);
  }
  return 0;
}
#endif
#ifdef ROOK_DEVELOPMENT_TEST
int main(void){
  struct board_score_test test[] = {
    {.board = {"LNGUKUGNL", 
               " R     B ", 
	       "P PPPPbPP", 
	       " P       ", 
	       "         ", 
	       "  p      ",
	       "pp pppppp",
	       "       r ",
	       "lngukugnl"},
     .score = 7,
     .pcLocation = {1, 1},
     .player = 2},
    {.board = {"LNGUKUG L", 
	       " R     B ", 
	       "PPPPPPNPP", 
	       "         ", 
	       "         ",
	       "  p      ",
	       "pp pppp p",
	       "       r ",
	       "lngukugnl"},
     .pcLocation = {7, 7},
     .score = 13,
     .player = 1}
  };
  for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++){
    printf("--> %i: expected: %i", scoreRookDevelopment(test[i].pcLocation, test[i].board, test[i].player), test[i].score);
    assert(test[i].score == scoreRookDevelopment(test[i].pcLocation, test[i].board, test[i].player));
  }
  return 0;
}
#endif
#ifdef LANCE_DEVELOPMENT_TEST
int main(void){
  struct board_score_test test[] = {
    {.board = {"LNGUKUGNL", 
               " R     B ", 
	       "PPPPPPbPP", 
	       "         ", 
	       "         ", 
	       "  p      ",
	       "pp pppppp",
	       "       r ",
	       "lngukugnl"},
     .score = 1,
     .pcLocation = {8, 8},
     .player = 1},
    {.board = {"LNGUKUGNL", 
               " R     B ", 
	       "PPPPPPbPP", 
	       "         ", 
	       "         ", 
	       "  p      ",
	       "pp ppppp ",
	       "       r ",
	       "lngukugnl"},
     .score = 6,
     .pcLocation = {8, 8},
     .player = 1},
    {.board = {"LNGUKUG L", 
	       " R     B ", 
	       "PPPPPPNPP", 
	       "         ", 
	       "         ",
	       "  p      ",
	       "pp pppppp",
	       "       r ",
	       "lngukugnl"},
     .pcLocation = {0, 0},
     .score = 1,
     .player = 2}
  };
  for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++){
    printf("lanceDevelopment -->> %i, expects: %i\n", scoreLanceDevelopment(test[i].pcLocation, test[i].board, test[i].player), test[i].score);
    assert(test[i].score == scoreLanceDevelopment(test[i].pcLocation, test[i].board, test[i].player));
  }
  return 0;
}
#endif

#ifdef PIN_SCORE_TEST
int main(void){
  struct board_score_test test[] = {
    {.board = {"LNGUK GNL", 
               " R   U B ", 
	       "PPPPPPbPP", 
	       "         ", 
	       "         ", 
	       "  p      ",
	       "pp pppppp",
	       "       r ",
	       "lngukugnl"},
     .score = 1,
     .pcLocation = {8, 8},
     .player = 1},
    {.board = {"LNGUKUGNL", 
               " R     B ", 
	       "PPPPPPbPP", 
	       "         ",
	       "         ", 
	       "  p      ",
	       "pp ppppp ",
	       "       r ",
	       "lngukugnl"},
     .score = 6,
     .pcLocation = {8, 8},
     .player = 1},
    {.board = {"LNGUKUG L", 
	       " R     B ", 
	       "PPPPPPNPP", 
	       "         ", 
	       "         ",
	       "  p      ",
	       "pp pppppp",
	       "       r ",
	       "lngukugnl"},
     .pcLocation = {0, 0},
     .score = 1,
     .player = 2}
  };
  for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++){
    printf("pinningTest -->> %i, expects: %i\n", scoreLanceDevelopment(test[i].pcLocation, test[i].board, test[i].player), test[i].score);
    assert(test[i].score == scoreLanceDevelopment(test[i].pcLocation, test[i].board, test[i].player));
  }
  return 0;
}

#endif
