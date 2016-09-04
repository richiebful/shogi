/*Game tree node*/
struct tree_node{
  int score;
  char *delta; //probably should specify this better
  SLIST_ENTRY(tree_node) *link;
};

struct board_entry{
  char board[9][9];
  SLIST_ENTRY(board_entry) entries;
};

struct grave_entry{
  char graveyard[2][GRAVEYARD_MAX];
  SLIST_ENTRY(grave_entry) entries;
};

SLIST_HEAD(bhead, board_entry) boardHead;
SLIST_HEAD(ghead, grave_entry) graveHead;
