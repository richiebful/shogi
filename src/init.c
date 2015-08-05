/** \file */
#include "shogi.h"

void init_game(struct gm_status *game){
  const char init_board[9][9] = {"LNGUKUGNL",
				 " R     B ",
				 "PPPPPPPPP",
				 "         ",
				 "         ",
				 "         ",
				 "ppppppppp",
				 " b     r ",
				 "lngukugnl"};
  memcpy(game->board,init_board,sizeof(init_board));

  game->player = 1;

  game->history = NULL;

  int i;
  FORRANGE(i,0,38,1){
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


#ifdef ERROR_F
int eprintf(char *format, ...){
  va_list argp;
  va_start(argp, format);
  vprintf(format, argp);
  va_end(argp);
  return true;
}

#else
int eprintf(char *format, ...){
  return true;
}
#endif
