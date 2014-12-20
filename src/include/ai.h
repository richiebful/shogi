/*Game tree node*/
struct tree_node{
  int potential;
  int raw_score;
  int score;
  int src[2], dst[2];
  struct * tree_node parent;
  struct * tree_row child_row;
};

/*Stores values for piece valuation*/
struct ai_score_book{
  char piece[14];
  int score[14];
  int check_v;
}

/*Determines the difficulty of the game AI*/
struct gm_ai_profile{
  int depth;
  int threshold; //highest allowable score for node
  int level; //official level 1-9
  struct ai_score_book score_book;
}ai_profile;
