#include <shogi.h>
#include <ai.h>

int scoreNode(struct tree_node *node,
	      int player){
  int score = 0;
  int this_player = node->game.player;
  
  int board[8][8];
  memcpy(board, node->game->board, sizeof(board));
  
  int i, j, k;
  int last_score, this_score;
  FORRANGE(i, 0, 10, 1){
    FORRANGE(j, 0, 10, 1){
      char thisPiece = board[i][j];
      FOREACH(pcValue->name, k){
        if (pcValue->name[k] == thisPiece){
          //score piece
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

int historyLength(){
  
}
