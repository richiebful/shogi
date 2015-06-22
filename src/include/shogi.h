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
  //sec format
  int player_t[2];
  time_t last_t;
  int advance_t; //time added per move, if at all
};

struct hist_s{
  char move[5];
  time_t tm_executed;
  struct hist_s *prev_move;
  struct hist_s *next_move;
  int num;
};

struct gm_status{
  char board[9][9];
  struct hist_s *history;
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
int eprintf(char *format, ...);
/*move.c*/
void mkmove(struct gm_status *game, int player,
	    int *src, int *dst, bool update_f);
void mkdrop(struct gm_status *game, int player, 
	    char piece, int *dst, bool update_f);
void ctocoords(int *converted, char *to_convert);
void coordsToC(char *converted, int *to_convert);
void updateHistory(struct gm_status *game, char *move, int s_lost);
/*check.c*/
int ischeck(struct gm_status *game, int player);
int ismate(struct gm_status *game, int player);
/*clock.c*/
long updateClock(struct gm_status *game);

/*display.c*/
void dispBoard(struct gm_status *game);
void dispClock(struct gm_status *game);
void dispHelp();
void dispHistory(struct gm_status *game);
/*input.c*/
int processcmd(struct gm_status *game, char *command);
int processmv(struct gm_status *game, char piece, int *src, int *dst);
