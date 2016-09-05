/** @file */
#pragma once

/**
 * Comprises nodes in the game decision tree
 */
struct tree_node{
  int score;
  char *delta; //probably should specify this better
  int childCount, childCapacity;
  struct tree_node *children;
  struct tree_node *parent;
};


/**
 * Comprises the stack of board modifications
 */
struct board_entry{
  char board[9][9];
  SLIST_ENTRY(board_entry) entries;
};


/**
 * Comprises the stack of graveyard modifications
 */
struct grave_entry{
  char graveyard[2][GRAVEYARD_MAX];
  SLIST_ENTRY(grave_entry) entries;
};

SLIST_HEAD(bhead, board_entry) boardHead;
SLIST_HEAD(ghead, grave_entry) graveHead;
