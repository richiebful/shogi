#include "shogi.h"

int main(void){
  struct gm_status game;
  init_game(&game);
  int input_f = 0;
  while (true){
    char command[20] = "NULL";
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
      game.check_f = ischeck(&game, game.player);
      game.mate_f = ismate(&game, game.player);
      if (game.mate_f == true){
	printf("Checkmate.\n");
	break;
      }
    }
    else if (input_f == -1){
      break;
    }
  }
  return 0;  
}
