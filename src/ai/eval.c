#include <shogi.h>
#include <ai.h>

int scoreNode(struct tree_node *node,
	      int player){
  int score = 0;
  int this_player = node->game.player;
  
  int i, j;
  int last_score, this_score;
  FORRANGE(i, 0, 10, 1){
    FORRANGE(j, 0, 10, 1){
      
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
