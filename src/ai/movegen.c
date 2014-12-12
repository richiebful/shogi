#include <shogi.h>
#include <ai.h>

/*This function generates children of an existing game state
 *Returns true if no failure
 *Returns false if it fails to generate legal moves
 */
int generateChildren(struct gm_status *curr_game, 
		     struct tree_node * node_set,
		     struct tree_node * parent){

  struct tree_node *node = malloc(sizeof(tree_node)*16);

  /*This loop goes through all possible moves
   *and determines the legal ones. The legal ones are scored.
   */
  int i, j, k, l;
  int node_i = 0;
  int src[2], dst[2];
  FORRANGE(i, 0, 10, 1){
    FORRANGE(j, 0, 10, 1){
      FORRANGE(k, 0, 10, 1){
	FORRANGE(l, 0, 10, 1){
	  src[0] = i, src[1] = j;
	  dst[0] = k, dst[1] = l;
	  if (legalmove(*curr_game, player, src, dst, 0)){
	    node[node_i].potential = 0;
	    node[node_i].raw_score = scoreNode(node[this_node]);
	    node[node_i].score = 0;
	    node[node_i].parent = &parent;
	    node[node_i].child_row = NULL;
	    memcpy(node[node_i].src, src, sizeof(src));
	    memcpy(node[node_i].dst, dst, sizeof(dst));
	    this_node ++;

	    int node_ct = sizeof(node);
	    if (this_node == node_ct){
	      free(&node);
	      *node = malloc(node_ct*2);
	    }
	  }
	}
      }
    }
  }
  node_set = &tree_node;
}

int scoreNode(struct gm_status *curr_game,
	      struct tree_node *node){
  int score = 0;
  return score;
}
