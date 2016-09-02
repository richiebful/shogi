/** \file */
#include <assert.h>
#include <string.h>
#include "shogi.h"
#include "ai.h"

struct board_entry{
  char board[8][8];
  SLIST_ENTRY(board_entry) entries;
};

struct grave_entry{
  char graveyard[2][GRAVEYARD_MAX];
  SLIST_ENTRY(grave_entry) entries;
};

SLIST_HEAD(bhead, board_entry) boardHead;
SLIST_HEAD(ghead, grave_entry) graveHead;

/*int findBestMove(struct gm_status *game, int depth){
  
  }*/

void pushGraveyardEntry(char graveyard[2][GRAVEYARD_MAX]){
  struct grave_entry *nEntry;
  nEntry = malloc(sizeof(struct grave_entry));
  if (nEntry){
    memcpy_s(nEntry->graveyard, GRAVEYARD_MAX*2, graveyard, GRAVEYARD_MAX*2);
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

/**
 * @pre delta is a six-byte null-terminated string
 * @param delta, first char is an addition, second char is a subtraction from the graveyard
 */
void applyDelta(char board[9][9], char graveyard[2][GRAVEYARD_MAX], int player, char *delta){
  if (delta[0]){
    int src[2], dst[2];
    cToCoords(src, delta);
    cToCoords(src, delta + 2);
    bool upgrade_f = delta[5];
    makeMove(board, graveyard, player, src, dst, upgrade_f);
  }
  else{
    char piece = delta[1];
    int dst[2];
    cToCoords(dst, delta + 2);
    makeDrop(board, graveyard, player, piece, dst);
  }
}

///makes root of search from a game status
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
  int player = 2; //getNodePlayer();
  char board[9][9] = SLIST_FIRST(&boardHead)->board;
  char graveyard[2][GRAVEYARD_MAX] = SLIST_FIRST(&graveHead)->graveyard;
  char piece;
  for (dst[0] = 0; dst[0] < 9; dst[0]++){
    for (dst[1] = 0; dst[1] < 9; dst[1]++){
      /*checking for legal moves*/
      for (src[0] = 0; src[0] < 9; src[0]++){
	for (src[1] = 0; src[1] < 9; src[1]++){
	  if (legalMove(board, player, src, dst, false)){
	    //be sure to not modify currBoard, currGraveyard
	    makeMoveNode(parent, player,
			 src, dst, false);
	    if (legalUpgrade(currBoard, /*fn*/, player, dst)){
	      makeMoveNode(parent, player,
			   src, dst, false);
	    }
	  }
	}
      }

      /*now check for legal drops*/
      int i;
      for (i = 0; i < GRAVEYARD_MAX; i++){
	if (piece = graveyard[player - 1][i] && //pravda
	    legalDrop(board, graveyard, player, piece, dst)){
	  makeDropNode(parent, player, piece, dst);
	}
      }
    }
  } 
}

int main(void){
  struct gm_status *game = malloc(sizeof(struct gm_status));
  init_game(game);
  dispBoard(game->board);
  dispGraveyard(game->graveyard);
  struct tree_node *root = malloc(sizeof(struct tree_node));
  buildRoot(game, root);
}
