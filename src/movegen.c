/* \file */
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
  int player;
  struct gm_status last_game;

  if (parent != NULL){
    player = parent->game.player;
    memcpy(last_game, parent->game, sizeof(last_game));
  }
  else{
    player = curr_game.player;
    memcpy(last_game, curr_game, sizeof(last_game));
  }

  FORRANGE(i, 0, 10, 1){
    FORRANGE(j, 0, 10, 1){
      FORRANGE(k, 0, 10, 1){
        FORRANGE(l, 0, 10, 1){
          src[0] = i, src[1] = j;
          dst[0] = k, dst[1] = l;
          if (legalmove(*last_game, player, src, dst, 0)){
            node[node_i].potential = 0;

            mkmove(*last_game, player, src, dst);
            memcpy(node[node_i]->game, last_game,
                   sizeof(last_game));

            node[node_i].raw_score = scoreNode(node[this_node]);
            node[node_i].score = 0;
            node[node_i].parent = &parent;
            node[node_i].children = NULL;
            memcpy(node[node_i].src, src, sizeof(src));
            memcpy(node[node_i].dst, dst, sizeof(dst));
            this_node ++;

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
  return true;
}

int pruneTree(struct tree_node *parent){
  return true;
}
