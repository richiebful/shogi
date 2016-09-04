/** \file */
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "shogi.h"
#include "ai.h"
#include "movegen.h"

void pushGraveyardEntry(char graveyard[2][GRAVEYARD_MAX]){
    struct grave_entry *nEntry;
    nEntry = malloc(sizeof(struct grave_entry));
    if (nEntry){
        memcpy(nEntry->graveyard, graveyard, GRAVEYARD_MAX*2);
    }
    SLIST_INSERT_HEAD(&graveHead, nEntry, entries);
}

void pushBoardEntry(char board[9][9]){
    struct board_entry *nEntry;
    nEntry = malloc(sizeof(struct board_entry));
    if (nEntry){
        memcpy(nEntry->board, board, 9*9);
    }
    SLIST_INSERT_HEAD(&boardHead, nEntry, entries);
}

/**
 * @pre delta is a six-byte null-terminated string
 * @param delta first char is an addition, second char is a subtraction from the graveyard
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

///@todo implement this
void attachNode(struct tree_node *parent, struct tree_node *child){
    
}

///makes root of search from a game status
void buildRoot(struct gm_status *game, struct tree_node *root){
    root->score = 0;
    SLIST_INIT(&boardHead);
    SLIST_INIT(&graveHead);
    pushGraveyardEntry(game->graveyard);
    pushBoardEntry(game->board);
}

struct tree_node *generateMoveNode(struct tree_node *parent, int player, int *src, int *dst, bool isUpgrade){
    struct tree_node *child;
    child = malloc(sizeof(struct tree_node));

    child->delta = calloc(sizeof(char), 6);
    sprintf(child->delta, "%1d%1d%1d%1d%1d", src[0], src[1], dst[0], dst[1], isUpgrade);

    char graveyard[2][38], board[9][9];
    memcpy(board, SLIST_FIRST(&boardHead)->board, sizeof(board)); //hopefully copies top of stack
    memcpy(graveyard, SLIST_FIRST(&graveHead)->graveyard, sizeof(graveyard));

    applyDelta(board, graveyard, player, child->delta);
    scoreNode(board, graveyard, player, child->delta);
    return child;
}

struct tree_node *generateDropNode(int player, char piece, int *dst){
    struct tree_node *child;
    child = malloc(sizeof(struct tree_node));

    child->delta = calloc(sizeof(char), 6);
    sprintf(child->delta, "\0%c%1d%1d", piece, dst[0], dst[1]);

    char graveyard[2][38], board[9][9];
    memcpy(board, SLIST_FIRST(&boardHead)->board, sizeof(board)); //hopefully copies top of stack
    memcpy(graveyard, SLIST_FIRST(&graveHead)->graveyard, sizeof(graveyard));

    applyDelta(board, graveyard, player, child->delta);
    scoreNode(board, graveyard, player, child->delta);
    return child;
}

/**
 * Returns the player who is making the game tree node's move 1 or 2
 * @param currPlayer is the current gm_status's player opposed to forcasted moves in the game tree
 */
int getNodePlayer(int currPlayer){
    struct board_entry *entry;
    int i = 0;
    //counts number of entries in stack - 1
    if ((entry = SLIST_FIRST(&boardHead))){
        while ((entry = &(SLIST_NEXT(&entry, entries)))){
            i++;
        }
    }
    return (currPlayer + i) % 2 + 1;
}

int generateChildNodes(struct gm_status *game, struct tree_node *parent){
    int src[2], dst[2];
    int player = getNodePlayer(game->player);

    char board[9][9], graveyard[2][GRAVEYARD_MAX];
    memcpy(board, SLIST_FIRST(&boardHead)->board, 9*9);
    memcpy(graveyard, SLIST_FIRST(&graveHead)->graveyard, 2*GRAVEYARD_MAX);

    char piece;
    struct tree_node *child;
    for (dst[0] = 0; dst[0] < 9; dst[0]++){
        for (dst[1] = 0; dst[1] < 9; dst[1]++){
            for (src[0] = 0; src[0] < 9; src[0]++){
                for (src[1] = 0; src[1] < 9; src[1]++){
                    if (legalMove(board, player, src, dst, false)){
                        //be sure to not modify currBoard, currGraveyard
                        child = generateMoveNode(parent, player,
                            src, dst, false);
                        attachNode(parent, child);
                        piece = board[src[0]][src[1]];
                        if (legalUpgrade(board, piece, player, dst)){
                            child = generateMoveNode(parent, player,
                                src, dst, true);
                            attachNode(parent, child);
                        }
                    }
                }
            }

            /*now check for legal drops*/
            int i;
            for (i = 0; i < GRAVEYARD_MAX; i++){
                if ((piece = graveyard[player - 1][i]) &&
                    legalDrop(board, graveyard, player, piece, dst)){
                    child = generateDropNode(parent, player, piece, dst);
                    attachNode(parent, child);
                }
            }
        }
    } 
}


#ifdef MOVEGEN_TEST

int main(void){
  struct gm_status *game = malloc(sizeof(struct gm_status));
  init_game(game);
  dispBoard(game->board);
  dispGraveyard(game->graveyard);
  struct tree_node *root = malloc(sizeof(struct tree_node));
  buildRoot(game, root);
  generateChildNodes(game, root);
}

#endif
