/** \file */

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CHALLENGING 1
#define REIGNING 2
#define P1 1
#define P2 2
#define FORRANGE(var, beginning, end, increment) \
  for(var = beginning; var < end; var += increment)
#define FOREACH(iterable, var) \
  for(var = 0; var < sizeof(iterable)/sizeof(iterable[0]); var++)

struct time_s{
  //mm:ss format
  int player_t[2][2];
  time_t last_t;
  int advance_t; //time added per move, if at all
};

struct gm_status{
  char board[9][9];
  char *history;
  struct time_s clock;
  int player;
  char graveyard[2][38];
  bool check_f;
  bool mate_f;
};

/*legal.c*/
int legaldest(struct gm_status *game, int player, int rank, int file);
int legalmove(struct gm_status *game, int player, int *src, int *dst, 
	      int from_check_f);
int inrange(int rank, int file);
int legalsrc(struct gm_status *game, int player, int rank, int file);
int legaldrop(struct gm_status *game, int player, char piece, int *dst);
/*init.c*/
void init_game(struct gm_status *game);
/*move.c*/
void mkmove(struct gm_status *game, int player, int *src, int *dst);
void mkdrop(struct gm_status *game, int player, char piece, int *dst);
void ctocoords(int *converted, char *to_convert);
void updateHist(struct gm_status *game, int *src, int *dst);
/*check.c*/
int ischeck(struct gm_status *game, int player);
int ismate(struct gm_status *game, int player);
/*clock.c*/
void updateClock(struct gm_status *game);

/*display.c*/
void dispBoard(struct gm_status *game);
void dispClock(struct gm_status *game);
void dispHelp();
/*input.c*/
int processcmd(struct gm_status *game, char *command);
int processmv(struct gm_status *game, char piece, int *src, int *dst);
