#include <shogi.h>
#include <ai.h>

int scoreNode(struct tree_node *node){
  int score = 0;
  
  scoreNode(*node->parent);
  while (*node){
    
    node++;
  }
  return score;
}
