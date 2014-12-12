/*Game tree node*/
struct tree_node{
  int potential;
  int raw_score;
  int score;
  int src[2], dst[2];
  struct * tree_node parent;
  struct * tree_row child_row;
};
