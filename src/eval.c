/*\file*/
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "shogi.h"
#include "ai.h"

int scoreNode(struct tree_node *node,
	      int player){
  int score = 0;
  int this_player = node->game.player;

  int board[8][8];
  memcpy(board, node->game->board, sizeof(board));

  int loc[2];
  int last_score, this_score;
  char this_piece;
  FORRANGE(loc[0], 0, 10, 1){
    FORRANGE(loc[1], 0, 10, 1){
      thisPiece = board[loc[0]][loc[1]];
      score += scorePiece(board, loc, thisPiece);
    }
  } 
  return score;
}

int scorePiece(int *board[], int *loc, char piece){
  int i;
  for (int i = 0; i < sizeof(pcValuation); i++){
    if (name[i] = piece){
      return score[i];
    }
  }
}
