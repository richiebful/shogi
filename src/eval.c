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
      thisPiece = board[i][j];
      FOREACH(pcValue->name, k){
        if (pcValue->name[k] == thisPiece){
          scorePiece(game.board, loc, thisPiece);
        }
      }
    }
  }

  if (this_player == player){
    score = this_score - last_score;
  }
  else{
    score = last_score - this_score;
  }
  return score;
}

int scorePiece(int *board[], int *loc, char piece){
	int i, j;
	FOREACH(board, i){
		FOREACH(board[0], j){
			if(legalmove())
		}
	}
}
