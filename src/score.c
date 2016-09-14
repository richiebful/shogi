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

uint32_t scoreGraveyardPiece(char piece, int player, int owner);
uint32_t scoreDroppability(char piece, char board[9][9], int player);
uint32_t scoreBoardPiece(char piece, int player);
uint32_t scorePieceDevelopment(int loc[2], char board[9][9], int player);
uint32_t scoreSign(int player, int owner);
uint32_t scorePiece(char piece, int player);
uint32_t scoreBishopDevelopment(int loc[2], char board[9][9], int player);
uint32_t scoreUpBishopDevelopment(int loc[2], char board[9][9], int player);
uint32_t scoreLanceDevelopment(int loc[2], char board[9][9], int player);
uint32_t scoreRookDevelopment(int loc[2], char board[9][9], int player);
uint32_t scoreUpRookDevelopment(int loc[2], char board[9][9], int player);
uint32_t scoreKnightDevelopment(int loc[2], char board[9][9], int player);


/**
 * Scores a game state in the decision tree
 * @todo determine factors to multiply helper functions by
 */
uint32_t scoreState(char board[9][9], char graveyard[2][GRAVEYARD_MAX], int player){
  int i, j;
  char piece;
  uint32_t score = isCheck(board, player) * IN_CHECK_COEFF;
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
uint32_t scoreGraveyardPiece(char piece, int player, int owner){
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
uint32_t scoreDroppability(char piece, char board[9][9], int player){
  int dst[2];
  uint32_t count;
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
uint32_t scoreBoardPiece(char piece, int player){
  return SCORE_BOARD_PIECE_COEFF * scorePiece(piece, player);
}

/**
 * Scores a piece generally, based on its assumed value in game play
 */
uint32_t scorePiece(char piece, int player){
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
uint32_t scorePieceDevelopment(int loc[2], char board[9][9], int player){
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
uint32_t scoreSign(int player, int owner){
  return (player == owner) ? 1 : -1;
}

/**
 * @todo develop functionality
 */
uint32_t scoreBishopDevelopment(int loc[2], char board[9][9], int player){
  
}

/**
 * @todo develop functionality
 */
uint32_t scoreUpBishopDevelopment(int loc[2], char board[9][9], int player){
  
}

/**
 * @todo develop functionality
 */
uint32_t scoreLanceDevelopment(int loc[2], char board[9][9], int player){
  
}

/**
 * @todo develop functionality
 */
uint32_t scoreRookDevelopment(int loc[2], char board[9][9], int player){
  
}

/**
 * @todo develop functionality
 */
uint32_t scoreUpRookDevelopment(int loc[2], char board[9][9], int player){
  
}

/**
 * @todo develop functionality
 */
uint32_t scoreKnightDevelopment(int loc[2], char board[9][9], int player){
  
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

