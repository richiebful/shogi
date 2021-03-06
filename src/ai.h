#define treetop (struct tree_node);

/*Game tree node*/
struct tree_node{
  int score;
  int number;
  int player;
  char board[9][9];
  char graveyard[2][38];
  struct tree_node *children;
  struct tree_node *parent;
};

/*Stores values for piece valuation*/
struct ai_score_book{
  char piece[14];
  int score[14];
  int check_v;
};

/*Determines the difficulty of the game AI*/
struct gm_ai_profile{
  int depth;
  int level; //official level 1-9
  struct ai_score_book score_book;
}ai_profile;

#define NO_PIECES 14
#define MAIN_STAGES 4

struct pcValuation{
  char name[14] = "PLNGUBRQMOHCSK";
  short score[14] = {7, 20, 20, 35, 40, 90, 95, 15, 25, 25, 35, 99, 97, 100};
}pcValue;

#ifdef ADVANCED_VALUE
struct pcValuation{
  char name[NO_PIECES] = "PLNGUBRQMOHCSK";
  short score[NO_PIECES][MAIN_STAGES] = {{   0,  35,  70,  99}, /* main stage borders */
					 {   7,   7,   8,  10 }, /* Pawn               */
					 {  20,  35,  45,  60 }, /* Lance              */
					 {  20,  35,  45,  60 }, /* Knight             */
					 {  35,  40,  60,  80 }, /* Silver             */
					 {  40,  55,  65,  80 }, /* Gold               */
					 {  90,  90,  90,  90 }, /* Bishop             */
					 {  95,  95,  95,  95 }, /* Rook               */
					 {  15,  25,  40,  65 }, /* promoted Pawn      */
					 {  25,  45,  55,  65 }, /* promoted Lance     */
					 {  25,  45,  55,  65 }, /* promoted Knight    */
					 {  35,  55,  75,  75 }, /* promoted Silver    */
					 {  99,  99,  99,  99 }, /* promoted Bishop    */
					 {  97,  97,  99,  99 }, /* promoted Rook      */
					 { 100, 100, 100, 100 }  /* King               */};
}pcValue;
#endif

/*
 * pcValuation scores are better converted to continuous functions in order to circumvent boundary inaccuracies.
 * For example, pawn_score = 10 - (3)*nthroot(round, 
 */
