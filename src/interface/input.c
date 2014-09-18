#include <shogi.h>

/*if return 1, continue to next player
 *if return 0, execute the commmand, if any,
 *then query the player for input again 
 *if return -1, input kills the program.
 */
int processCMD(char *command, struct gm_status *game){
  if (strncmp(command, "show", 4) == true){
    dispboard(game);
    return 0;
  }
  else if (strncmp(command, "help", 4) == true){
    disphelp();
    return 0;
  }
  else if (strncmp(command, "go", 2) == true){
    //have AI make the current move
    return 1;
  }
  else if (strncmp(command, "exit", 4) == true){
    return -1;
  }
  else if (strncmp(command, "resign", 6) == true){
    printf("Player %i has resigned. You win, Player %i",
	   game->player, ((game->player)%2)+1);
    return -1;
  }
  else{
    return 0;
  }
}
