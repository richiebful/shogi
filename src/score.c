/** \file */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "shogi.h"
#include "ai.h"

#define SCORE_TEST 1
#define SCORE_BOARD_PIECE_COEFF 1.0
#define DROPPABILITY_COEFF 1.0
#define IN_CHECK_COEFF 1.0

int32_t scoreGraveyardPiece(char piece, int player, int owner);
int32_t scoreDroppability(char piece, char board[9][9], int player);
int32_t scoreBoardPiece(char piece, int player);
int32_t scorePieceDevelopment(int loc[2], char board[9][9], int player);
int32_t scoreSign(int player, int owner);
int32_t scorePiece(char piece, int player);
int32_t scoreBishopDevelopment(int loc[2], char board[9][9], int player);
int32_t scoreUpBishopDevelopment(int loc[2], char board[9][9], int player);
int32_t scoreLanceDevelopment(int loc[2], char board[9][9], int player);
int32_t scoreRookDevelopment(int loc[2], char board[9][9], int player);
int32_t scoreUpRookDevelopment(int loc[2], char board[9][9], int player);
int32_t scoreKnightDevelopment(int loc[2], char board[9][9], int player);
int32_t obstructionTest(char attackedPiece, bool atAttackingPiece, bool pastAttackingPiece, int player, int count);
int ownerOf(char piece);


/**
 * Scores a game state in the decision tree
 * @todo determine factors to multiply helper functions by
 */
int32_t scoreState(char board[9][9], char graveyard[2][GRAVEYARD_MAX], int player){
  int i, j;
  char piece;
  int32_t score = isCheck(board, player) * IN_CHECK_COEFF;
  for (i = 0; i < 9; i++){
    for (j = 0; j < 9; j++){
      piece = board[i][j];
      if (piece != ' '){
	int loc[2] = {i, j};
	score += scorePieceDevelopment(loc, board, player);
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
int32_t scoreGraveyardPiece(char piece, int player, int owner){
  for (int i = 0; i < sizeof(PIECE_VALUES.name); i++){
    if (toupper(piece) == PIECE_VALUES.name[i]){
      printf("toupper(piece) -> %c \n", toupper(piece));
      return scoreSign(player, owner) * PIECE_VALUES.score[i];
    }
  }
}

/**
 * (Returns number of locations a piece can be dropped) * k
 * @pre piece is in the graveyard of the player
 */
int32_t scoreDroppability(char piece, char board[9][9], int player){
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
 * Scores an individual piece on the board
 * @pre piece is in the graveyard of the player
 */
int32_t scoreBoardPiece(char piece, int player){
  return SCORE_BOARD_PIECE_COEFF * scorePiece(piece, player);
}

/**
 * Scores a piece generally, based on its assumed value in game play
 */
int32_t scorePiece(char piece, int player){
  for (int i = 0; i < sizeof(PIECE_VALUES.name); i++){
    if (piece == PIECE_VALUES.name[i]){
      return scoreSign(player, 1) * PIECE_VALUES.score[i];
    }
    else if (toupper(piece) == PIECE_VALUES.name[i]){
      return scoreSign(player, 2) * PIECE_VALUES.score[i];
    }
  }
}

/**
 * (Returns a measurement of piece development) * k
 * @pre board[rank][file] is a piece
 * @note only pieces with range, like rook, bishop, lance can be developed
 */
int32_t scorePieceDevelopment(int loc[2], char board[9][9], int player){
  char piece = board[loc[0]][loc[1]];
  switch (piece){
    case 'B':
    case 'b':
      return scoreBishopDevelopment(loc, board, player);
    case 'C':
    case 'c':
      return scoreUpBishopDevelopment(loc, board, player);
    case 'L':
    case 'l':
      return scoreLanceDevelopment(loc, board, player);
    case 'N':
    case 'n':
      return scoreKnightDevelopment(loc, board, player);
    case 'R':
    case 'r':
      return scoreRookDevelopment(loc, board, player);
    case 'S':
    case 's':
      return scoreUpRookDevelopment(loc, board, player);
    default:
      return 0;
  }
}

/**
 * Determines sign of factor k in above calculations
 */
int32_t scoreSign(int player, int owner){
  return (player == owner) ? 1 : -1;
}

/**
 * @todo develop functionality, ensure dpiece is in range
 */
int32_t scoreBishopDevelopment(int loc[2], char board[9][9], int player){
  int i;
  //all arrays of 2 elements are of format {-slope diagonal, +slope diagonal}
  int32_t count[2] = {0, 0};
  for (i = 0; i < sizeof(board)/sizeof(board[0]); i++){
    char pcInSame[2] = {board[loc[0]][loc[1] - 1] , board[loc][loc[1]]};
    bool atRookIn[2] = {loc[1] == i, loc[0] == i};
    bool pastRookIn[2] = {loc[1] > i, loc[0] > i};
    int32_t nCount[2];
    int j;
    for (j = 0; j < 2; j++){
      if (nCount[j] < 0){
	continue;
      }
      nCount[j] = obstructionTest(pcInSame[j], atRookIn[j], pastRookIn[j], player, count[j]);
      if (nCount[j] >= 0){
	count[j] = nCount[j];
      }
    }
  }
  return count[0] + count[1];
}

/**
 * @todo develop functionality
 */
int32_t scoreUpBishopDevelopment(int loc[2], char board[9][9], int player){
  
}

/**
 * @todo test the shit out of this
 */
int32_t scoreLanceDevelopment(int loc[2], char board[9][9], int player){
  int32_t count = 0;
  int rel_dir = relativeDirectionOf(player);
  int outOfBounds = 4 + 5 * rel_dir;
  int i;
  for (i = loc[0]; i != outOfBounds; i += rel_dir){
    int32_t nCount;
    char attackedPiece = board[loc[0][loc[1]];
    nCount = obstructionTest(attackedPiece, false, true, player, count);
    if (nCount >= 0)
      count = nCount;
    else
      break;
  }
  return count;
}

/**
 * Works on pieces that cannot jump, but make "ranged" attacks, e.g. bishop, rook
 * @todo test
 */
int32_t obstructionTest(char attackedPiece, bool atAttackingPiece, bool pastAttackingPiece, int player, int count){
  if (attackedPiece == ' '){
      return count + 1;
  }
  else if (scoreSign(isupper(attackedPiece) + 1, player) == 1){
    if (pastAttackingPiece){
      return -1;
    } else if (!atAttackingPiece){
      return 0;
    } else {
      return count;
    }
  }
  else{
    if (pastAttackingPiece){
      return count + 1;
      break;
    } else if (!atAttackingPiece){
      return 1;
    } else {
      return count;
    }
  }
}

/**
 * @todo test
 */
int32_t scoreRookDevelopment(int loc[2], char board[9][9], int player){
  int i;
  //all arrays of 2 elements are of format {rank, file}, ie. pcInSame[rank]
  int32_t count[2] = {0, 0};
  for (i = 0; i < sizeof(board)/sizeof(board[0]); i++){
    char pcInSame[2] = {board[loc[0]][i] , board[i][loc[1]]};
    bool atRookIn[2] = {loc[1] == i, loc[0] == i};
    bool pastRookIn[2] = {loc[1] > i, loc[0] > i};
    int32_t nCount[2];
    int j;
    for (j = 0; j < 2; j++){
      if (nCount[j] < 0){
	continue;
      }
      nCount[j] = obstructionTest(pcInSame[j], atRookIn[j], pastRookIn[j], player, count[j]);
      if (nCount[j] >= 0){
	count[j] = nCount[j];
      }
    }
  }
  return count[0] + count[1];
}

/**
 * @todo develop functionality
 */
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

/**
 * @todo develop functionality
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

