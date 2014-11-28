/** \file */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>

#define CHALLENGING 1
#define REIGNING 2
#define P1 1
#define P2 2
#define FORRANGE(var, beginning, end, increment) \
  for(var = beginning; var < end; var += increment)
#define FOREACH(iterable, var) \
  for(var = 0; var < sizeof(iterable)/sizeof(iterable[0]); var++)

struct droppable{
  char challenging[38];
  char reigning[38];
};

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
void mkmove(struct gm_status *game, int *src, int *dst);
void mkdrop(struct gm_status *game, char piece, int *dst);
void ctocoords(int *converted, char *to_convert);
int processcmd(char *command, struct gm_status *game);
int processmv(struct gm_status game, char piece, int *src, int *dst);
void dispBoard(struct gm_status *game);
void dispClock(struct gm_status *game);
void dispHelp();
void clockUpdate(struct gm_status *game);



