/* \file */
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

int main(void){
  struct gm_status game;
  init_game(&game);
  int input_f = 0;
  char command[10];
  while (true){
    input_f = 0;
    if (game.check_f == true){
      printf("Check.\n");
    }
    while (input_f == 0){
      printf("Player %i:\n", game.player);
      scanf("%s", command);
      input_f = processcmd(&game, command);
    }
    if (input_f == 1){
      game.player = game.player % 2 + 1;
      game.check_f = ischeck(game.board, game.player);
      game.mate_f = ismate(&game.board, &game.graveyard, game.player);
      if (game.mate_f == true){
	printf("Checkmate.\n");
	dispBoard(game.board);
	dispGraveyard(game.graveyard);
	break;
      }
    }
    else if (input_f == -1){
      break;
    }
  }
  return 0;  
}
