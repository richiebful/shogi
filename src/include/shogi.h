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
  bool bitboard[9][9][9][9];
  int player;
  struct droppable graveyard;
  bool check_f;
  bool cmate_f;
};

bool legaldest(struct gm_status *game, int rank, int file);
void mkbitboard(struct gm_status *game);
bool legalmove(struct gm_status *game, int *src, int *dst);
bool inrange(int rank, int file);
bool legalsrc(struct gm_status *game, int rank, int file);
bool legaldrop(struct gm_status *game, char piece, int *dst);
void init_game(struct gm_status *game);
void mkmove(struct gm_status *game, int * src, int * dst);
void mkdrop(struct gm_status *game, char piece, int *dst);
void ctocoords(struct gm_status *game, int *converted, char *to_convert);
int processCMD(char *command, struct gm_status *game);





