#include <stdio.h>
#include <stdlib.h>
#include "shogi.h"
#include "ai.h"

uint32_t scoreGraveyardPiece(char piece, int player);
uint32_t scoreDroppability(int rank, int file, char board[9][9], int player);
uint32_t scoreBoardPiece(char piece, int player);
uint32_t scorePieceDevelopment(int rank, int file, char board[9][9], int player);
uint32_t scoreSign(int player, int owner);


/**
 * Scores a game state in the decision tree
 * @todo determine factors to multiply helper functions by
 */
uint32_t scoreState(char board[9][9], char graveyard[2][GRAVEYARD_MAX], int player){
  int i, j;
  char piece;
  uint32_t score = 0;
  
  for (i = 0; i < 9; i++){
    for (j = 0; j < 9; j++){
      if (board[i][j] != ' '){
	piece = board[i][j];
	score += scoreBoardPiece(piece, player);
	score += scorePieceDevelopment(i, j, board, player);
      }
    }
  }
  
  for (i = 0; i < 2; i++){
    for (j = 0; j < GRAVEYARD_MAX; j++){
      if (board[i][j] != ' '){
	piece = board[i][j];
	score += scoreGraveyardPiece(piece, player);
	score += scoreDroppability(i, j, board, player);
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
    if (toupper(piece) == name[i]){
      return scoreSign(player, owner) * score[i];
    }
  }
}

/**
 * (Returns number of locations a piece can be dropped) * k
 * @pre piece is in the graveyard of the player
 */
uint32_t scoreDroppability(char piece, char board[9][9], int player){
  
}

/**
 * Scores an individual piece on the board
 * @pre piece is in the graveyard of the player
 */
uint32_t scoreBoardPiece(char piece, int player){
  return SCORE_BOARD_PIECE_COEFF * scorePiece(piece, player);
}

uint32_t scorePiece(char piece, int player){
  for (int i = 0; i < sizeof(PIECE_VALUES.name); i++){
    if (toupper(piece) == name[i]){
      return scoreSign(player, islower(piece) + 1) * score[i];
    }
  }
}

/**
 * (Returns a measurement of piece development) * k
 * @pre board[rank][file] is a piece
 */
uint32_t scorePieceDevelopment(int rank, int file, char board[9][9], int player){

}

/**
 * Determines sign of factor k in above calculations
 */
uint32_t scoreSign(int player, int owner){
  return (player == owner) ? 1 : -1;
}
=======
/** \file */
#include "shogi.h"
#include "ai.h"
#include <stdio.h>

#ifdef SCORE_TEST

int main(){

}

#endif
