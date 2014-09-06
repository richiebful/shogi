#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define CHALLENGING 1
#define REIGNING 2
#define P1 1
#define P2 2

struct droppable{
  char challenging[38];
  char reigning[38];
};
  
struct gm_status{
  char board[9][9];
  int player;
  struct droppable graveyard;
  bool check;
};

