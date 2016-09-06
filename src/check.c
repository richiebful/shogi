/**\file*/
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "shogi.h"


#ifdef CHECK_TEST

int eprintf(char *format, ...){
  va_list argp;
  va_start(argp, format);
  vprintf(format, argp);
  va_end(argp);
  return true;
}

int main(){
  struct gm_status game;
  init_game(&game);
  printf("%i",ischeck(&game, 2));
}

void init_game(struct gm_status *game){
  const char init_board[9][9] = {"LNGUKUGNL",
				 " R     B ",
				 "PPPPPPbPP",
				 "         ",
				 "         ",
				 "         ",
				 "ppppppppp",
				 " b     r ",
				 "lngukugnl"};
  memcpy(game->board,init_board,sizeof(init_board));

  game->player = 1;

  game->history = malloc(sizeof(struct hist_s));
  game->history->num = 0;

  int i;
  for(i = 0; i < 38; i++){
    game->graveyard[0][i] = '\0';
    game->graveyard[1][i] = '\0';
  }
  //set each player's clocks to 60:00
  game->clock.player_t[0] = game->clock.player_t[1] = 3600;
  game->clock.advance_t = 15; //15s added per move
  game->clock.last_t = time(NULL);

  game->check_f = false;
  game->mate_f = false;
}

#endif

#ifdef CMATE_TEST

int main(){
  struct gm_status game;
  int player = 1;
  init_game(&game);
  printf("%i",ischeck(game, player));
}
#endif
