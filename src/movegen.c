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

int findBestMove(struct gm_status *game, int depth){
  
}

int generateNodes(struct tree_node *parent){
  int src[2], dst[2];
  int player = parent->player;
  for (src[0] = 0; src[0] < 9; src[0]++){
    for (src[1] = 0; src[1] < 9; src[1]++){
      for (dst[0] = 0; dst[0] < 9; dst[0]++){
	for (dst[1] = 0; dst[1] < 9; dst[1]++){
	  //redefine function wrapper to copy to new node
	  //consider both options, however
	  makemove(parent->board, parent->graveyard, src, dst);
	}
      }
    }
  }
}
