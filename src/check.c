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

int wherePiece(char board[9][9], int loc[2], char piece){
  for (loc[0] = 0; loc[0] < 9; loc[0]++){
    for (loc[1] = 0; loc[1] < 9; loc[1]++){
      eprintf("%i, %i\n", loc[0], loc[1]);
      if (board[loc[0]][loc[1]] == piece){
	return true;
      }
    }
  }
  return false;
}

int ischeck(char board[9][9], int player){
  int otherPlayer = player % 2 + 1;

  int dst[2];

  char king = (player == 1) ? 'k' : 'K';
  
  wherePiece(board, dst, king);

  eprintf("%i, %i is king\n", dst[0], dst[1]);
  int src[2];
  for (src[0] = 0; src[0] < 9; src[0]++){
    for (src[1] = 0; src[1] < 9; src[1]++){
      if (legalMove(board, otherPlayer, src, dst, true)){
	return true;
      }
    }
  }
  return false;
}

int ismate(char board[9][9], char graveyard[2][38], int player){
  char test_board[9][9];
  memcpy(&test_board, &board, sizeof(test_board));
  
  player = player % 2 + 1;

  /*Player must be in check to be in mate*/
  if (ischeck(board, player)==false){
    return false;
  }
  /*test all possible following moves, then determine 
   *whether check still
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
	  if (legalMove(test_board, player, src, dst, true) == true){
	    makeMove(test_board, graveyard, player, src, dst, false);
	    if (ischeck(test_board, player) == false){
	      return false;
	    }
	    memcpy(test_board, &board, sizeof(test_board));
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
