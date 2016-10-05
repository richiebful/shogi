/** @file */
#pragma once
#include <sys/queue.h>
#define NO_PIECES 14
#define MAIN_STAGES 4

/**Game tree node*/
struct tree_node{
  int score;
  char *delta; //probably should specify this better
  int childCount, childCapacity;
  struct tree_node **children;
  struct tree_node *parent;
};

struct pcValuation{
  char name[14];
  short score[14];
} PIECE_VALUES = {
  "PLNGUBRQMOHCSK",
  {7, 20, 20, 35, 40, 90, 95, 15, 25, 25, 35, 99, 97, 100}
};

struct aiScoreBook{
  struct pcValuation pcValues;
  double inCheckCoefficient;
  double droppabilityCoefficient;
  //etc.
}; //pass this to scoreState function

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
