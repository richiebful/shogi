/** \file */
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "shogi.h"
#include "ai.h"
#include "movegen.h"

#define MOVEGEN_TEST

/**
 * Adds a new updated graveyard to the top of the stack
 */
void pushGraveyardEntry(char graveyard[2][GRAVEYARD_MAX]){
    struct grave_entry *nEntry;
    nEntry = malloc(sizeof(struct grave_entry));
    if (nEntry){
        memcpy(nEntry->graveyard, graveyard, GRAVEYARD_MAX*2);
    }
    SLIST_INSERT_HEAD(&graveHead, nEntry, entries);
}

/**
 * Adds a new updated board to the top of the stack
 */
void pushBoardEntry(char board[9][9]){
    struct board_entry *nEntry;
    nEntry = malloc(sizeof(struct board_entry));
    if (nEntry){
        memcpy(nEntry->board, board, 9*9);
    }
    SLIST_INSERT_HEAD(&boardHead, nEntry, entries);
}

/**
 * Modifies board/graveyard based on the delta contained in tree_node
 * @see tree_node
 * @pre delta is a six-byte null-terminated string
 * @param delta first char is an addition, second char is a subtraction from the graveyard
 */
void applyDelta(char board[9][9], char graveyard[2][GRAVEYARD_MAX], int player, char *delta){
    if (delta[0]){
        printf("is move\n");
        int src[2], dst[2];
        src[0] = delta[0] - '0';
        src[1] = delta[1] - '0';
        dst[0] = delta[2] - '0';
        dst[1] = delta[3] - '0';
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

/**
 * Connects the parent and the child in the decision tree
 */
void attachNode(struct tree_node *parent, struct tree_node *child){
    //add parent pointer to child
    child->parent = parent;

    //allocate more memory to store more child pointers if necessary
    if (parent->childCapacity < parent->childCount){
        printf("ensures capacity");
        struct tree_node **temp = calloc(2 * parent->childCapacity, __SIZEOF_POINTER__);
        printf("tempsize %d\n",__SIZEOF_POINTER__ * parent->childCapacity);
        memcpy(temp, parent->children, parent->childCapacity * __SIZEOF_POINTER__);
        free(parent->children);
        
        parent->children = temp;
        parent->childCapacity = 2 * parent->childCapacity;
    }

    //add pointer to child
    *(parent->children + parent->childCount) = child;
    parent->childCount++;
}

///makes root of search from a game status
void buildRoot(struct gm_status *game, struct tree_node *root){
    root->score = 0;
    SLIST_INIT(&boardHead);
    SLIST_INIT(&graveHead);
    pushGraveyardEntry(game->graveyard);
    pushBoardEntry(game->board);

    size_t childCapacity = 16;
    root->children = calloc(childCapacity, __SIZEOF_POINTER__);
    printf("size: %lu\n",sizeof(root->children));
    root->childCapacity = childCapacity;
    root->childCount = 0;
}


/**
 * Creates a new decision tree node for moving a piece on the board
 * @todo make board and graveyard parameters
 */
struct tree_node *generateMoveNode(int player, int *src, int *dst, bool isUpgrade){
    struct tree_node *child;
    child = malloc(sizeof(struct tree_node));
    child->childCount = 0;

    child->delta = calloc(sizeof(char), 6);
    sprintf(child->delta, "%1d%1d%1d%1d%1d", src[0], src[1], dst[0], dst[1], isUpgrade);
    printf("%s,", child->delta);

    char graveyard[2][38], board[9][9];
    memcpy(board, SLIST_FIRST(&boardHead)->board, sizeof(board)); //hopefully copies top of stack
    memcpy(graveyard, SLIST_FIRST(&graveHead)->graveyard, sizeof(graveyard));

    applyDelta(board, graveyard, player, child->delta);
    //scoreNode(board, graveyard, player, child->delta);
    return child;
}

/**
 * Creates a new decision tree node for dropping a piece on the board
 * @todo make board and graveyard parameters
 */
struct tree_node *generateDropNode(int player, char piece, int *dst){
    struct tree_node *child;
    child = malloc(sizeof(struct tree_node));

    child->delta = calloc(sizeof(char), 6);
    child->childCount = 0;
    sprintf(child->delta, "\0%c%1d%1d", piece, dst[0], dst[1]);

    char graveyard[2][38], board[9][9];
    memcpy(board, SLIST_FIRST(&boardHead)->board, sizeof(board)); //hopefully copies top of stack
    memcpy(graveyard, SLIST_FIRST(&graveHead)->graveyard, sizeof(graveyard));

    applyDelta(board, graveyard, player, child->delta);
    //scoreNode(board, graveyard, player, child->delta);
    return child;
}

/**
 * Returns the player who is making the game tree node's move 1 or 2
 * @param player is the current gm_status's player opposed to forcasted moves in the game tree
 */
int getNodePlayer(int currPlayer){
  struct board_entry *entry;
  int i = 0;
  //counts number of entries in stack - 1
  if (entry = SLIST_FIRST(&boardHead)){
    while (entry = SLIST_NEXT(&entry, d)){
      i++;
    }
  }
  return (currPlayer + i) % 2 + 1;
}

/**
 * @param parent the decision tree node of the previous move
 * @param player the player making this move
 */
int generateChildNodes(struct tree_node *parent, int player){
    int src[2], dst[2];
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
                        child = generateMoveNode(player, src, dst, false);
                        attachNode(parent, child);
                        piece = board[src[0]][src[1]];
                        if (legalUpgrade(board, piece, player, dst)){
                            child = generateMoveNode(player, src, dst, true);
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
                    child = generateDropNode(player, piece, dst);
                    attachNode(parent, child);
                }
            }
        }
    }
    return 0;
}

void recursiveFree(struct tree_node *parent){
    printf("recursiveChildCount = %d\n", parent->childCount);
    if (parent->childCount > 0){
        for (int i = 0; i < parent->childCount; i++){
            printf("\ni = %d\nenters recursion\n", i);
            recursiveFree(*(parent->children + i));
            printf("\nexits recursion\n");
        }
    }
    printf("frees");
    free(parent);
}

void breakBranch(

int32_t alphabeta(struct tree_node *node, int32_t alpha, int32_t beta, bool maximizeF){
    if (node->parent == NULL || node->children == NULL){
        return node->score;
    }else if (maximizeF){
        int32_t v = INT32_MIN;
        int i = 0;
        for (i = 0; i < node->childCount; i++){
            int32_t result = alphabeta(*(node->children + i), alpha, beta, false)
            v = (v > result) ? v : result;
            alpha = (alpha > v) ? alpha : v;
            if (beta <= alpha){
                detatchNode(node, *(node->children + i));
            }
        }
        return v;
    }else{
        int32_t v = INT32_MAX;
        int i = 0;
        for (i = 0; i < node->childCount; i++){
            int32_t result = alphabeta(*(node->children + i), alpha, beta, true);
            v = (v < result) ? v : result;
            beta = (beta < v) ? beta : v;
            if (beta <= alpha){
                detatchNode(node, *(node->children + i));
            }
        }
        return v;
    }
}

void buildTree(struct tree_node *parent, int player){
    generateChildNodes(parent, player);
    alphabeta(parent);
    int i;
    for (i = 0; i < parent->childCount; i++){
        player = (player + 1) % 2 + 1; //change player
        //buildTree(parent, player);
    }
};


#ifdef MOVEGEN_TEST

int main(void){
  struct gm_status *game = malloc(sizeof(struct gm_status));
  init_game(game);
  dispBoard(game->board);
  dispGraveyard(game->graveyard);
  struct tree_node *root = malloc(sizeof(struct tree_node));
  buildRoot(game, root);
  generateChildNodes(root, game->player);
  printf("childCount = %d\n", root->childCount);
  printf("childCapacity = %d\n", root->childCapacity);
  //recursiveFree(root);
  free(game);
}

#endif
