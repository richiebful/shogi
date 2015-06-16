/** \file */
#include <shogi.h>

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

  /*the equivalent of char game->history[150][5]*/
  game->history = calloc(sizeof(char)*4*32, 5);

  int i;
  FORRANGE(i,0,38,1){
    game->graveyard.challenging[i] = '\0';
    game->graveyard.reigning[i] = '\0';
  }
  //set each player's clocks to 60:00
  game->clock.player_t[0][0] = game->clock.player_t[1][0] = 60;
  game->clock.player_t[0][1] = game->clock.player_t[1][1] = 0;
  game->clock.advance_t = 15; //15s added per move

  game->check_f = false;
  game->mate_f = false;
}

/*http://c-faq.com/varargs/handoff.html for more details on variadic error messages*/
#ifdef ERROR_F
int eprintf(char *format, ...){
  return true;
}

#else
int eprintf(char *format, ...){
  va_list argp;
  va_start(argp, fmt);
  vfprintf(format, argp);
  va_end(argp);
}
#endif
