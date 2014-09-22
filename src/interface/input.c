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
  else if (islower(command[0]) == true &&
	   isdigit(command[1]) == true &&
	   sizeof(command) >= 4){
    /*copies command[0:2] to src
     *and copies command[2:4] to dst*/
    char src[2], char dst[2];
    snprintf(src, 2, "%s", command);
    snprintf(dst, 2, "%s", command+2);
    if (legalmove(game, src, dst)==true){
      mkmove(game, src, dst);
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (isupper(command[0]) == true &&
	   islower(command[1]) == true &&
	   isdigit(command[2]) == true &&
	   sizeof(command) <= 5){
    //interpret move of form Pe4
    
    return 1;
  }
  else if (isupper(command[0]) == true &&
	   command[1] == '*' &&
	   islower(command[2]) == true &&
	   sizeof(command) == 4){
    //inteprets drop of form P*e4
    char piece = command[0], dst[2];
    snprintf(dst, 2, "%s", command+2);
    if (legaldrop(game, src, dst)){
      return 1;
    }
    return 0;
  }
  else{
    printf("Sorry, that move is invalid, please try again.")
    return 0;
  }
}

void processMove(struct gm_status game, char *move, int *dst, int *src){
  char piece = move[0];
  int dfile =  move[1] - 'a';
  int drank = move[2] - '0';
  dst[0] = drank;
  dst[1] = dfile;
}
