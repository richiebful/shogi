/*Game tree node*/
struct game_tn{
  int potential;
  int raw_score;
  int score;
  struct * game_tn;
}

/*Game tree row*/
struct game_tr{
  struct * game_tn nodes;
  struct * game_tn best_tn;
  double best_tn_score;
}
