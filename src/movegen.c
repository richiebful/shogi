/* \file */
#include <assert.h>
#include <string.h>
#include "shogi.h"
#include "ai.h"

struct board_entry{
  char board[8][8];
  SLIST_ENTRY(board_entry) entries;
};

struct grave_entry{
  char graveyard[2][38];
  SLIST_ENTRY(grave_entry) entries;
};

SLIST_HEAD(bhead, board_entry) boardHead;
SLIST_HEAD(ghead, grave_entry) graveHead;

int findBestMove(struct gm_status *game, int depth){
  
}

void pushGraveyardEntry(char graveyard[2][38]){
  struct grave_entry *nEntry;
  nEntry = malloc(sizeof(struct grave_entry));
  if (nEntry){
    memcpy_s(nEntry->graveyard, 38*2, graveyard, 38*2);
  }
  SLIST_INSERT_HEAD(&graveHead, nEntry, entries);
}

void pushBoardEntry(char board[9][9]){
  struct board_entry *nEntry;
  nEntry = malloc(sizeof(struct board_entry));
  if (nEntry){
    memcpy_s(nEntry->board, 9*9, board, 9*9);
  }
  SLIST_INSERT_HEAD(&boardHead, nEntry, entries);
}

void pushGraveyardDelta(char delta){
  pushGraveyardEntry();
}

void pushBoardDelta(char delta){
  pushBoardEntry(something);
}

//makes root of search from a game status
void buildRoot(struct gm_status *game, struct tree_node *root){
  root->score = 0;
  root->parent = NULL;
  root->children = malloc(64 * sizeof(int));
  SLIST_INIT(&boardHead);
  SLIST_INIT(&graveHead);
  pushGraveyardEntry(game->graveyard);
  pushBoardEntry(game->board);
}

int generateNodes(struct tree_node *parent){
  int src[2], dst[2];
  bool upgrade_f;
  int player = parent->player;
  for (src[0] = 0; src[0] < 9; src[0]++){
    for (src[1] = 0; src[1] < 9; src[1]++){
      for (dst[0] = 0; dst[0] < 9; dst[0]++){
	for (dst[1] = 0; dst[1] < 9; dst[1]++){
	  
	}
      }
    }
  }
}

int main(void){
  struct tree_node *root = malloc(sizeof(struct tree_node));
  struct gm_status *game = malloc(sizeof(struct gm_status));
  init_game(game);
  
}
