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

/**\fn ischeck
 * \param game the current game state
 * \param player, the player being evaluated for being in check
 */

int ischeck(struct gm_status *game, int player){
  int i, j;
  char board[9][9];
  int otherPlayer = player % 2 + 1;
  memcpy(board, game->board, sizeof(board));

  int dst[2];

  int king = 'k' - 32*(player-1);
  
  for (i = 0; i < 9; i++){
    for (j = 0; j < 9; j++){
      if (board[i][j] == king){
	dst[0] = i;
	dst[1] = j;
	break;
      }
    }
  }

  int src[2];
  bool exit_f = false;
  for (i = 0; i < 9; i++){
    for (j = 0; j < 9; j++){
      src[0] = i;
      src[1] = j;
      if (legalmove(game, otherPlayer, src, dst, true)){
	return true;
      }
    }
  }

  return exit_f;
}

int ismate(struct gm_status *game, int player){
  struct gm_status test_game;
  //int otherPlayer = player % 2 + 1;
  memcpy(&test_game, &game, sizeof(test_game));

  /*Player must be in check to be in mate*/
  if (ischeck(game, player)==false){
    return false;
  }
  /*test all possible following moves, then determine whether check still
   *exists under the new game state*/
  int i, j, k, l;
  int src[2], dst[2];
  
  /*Assume checkmate until it is disproven*/
  for(i= 0; i < 9; i++){
    for (j = 0; j < 9; j++){
      for (k = 0; k < 9; k++){
	for (l = 0; l < 9; l++){
	  src[0] = i; src[1] = j;
	  dst[0] = k; dst[1] = l;
	  if (legalmove(&test_game, player, src, dst, 1) == true){
              mkmove(&test_game, player, src, dst, false, false);
	    if (ischeck(&test_game, player) == false){
	      return false;
	    }
	    memcpy(&test_game, &game, sizeof(test_game));
	  }
	}
      }
    }
  }
  return true;
}

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
