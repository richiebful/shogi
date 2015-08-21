/** \file */
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

/*if return 1, continue to next player
 *if return 0, execute the commmand, if any,
 *then query the player for input again 
 *if return -1, input kills the program.
 */
 
int processcmd(struct gm_status *game, char *command){
  //printf("%s", command);
  if (strncmp(command, "show", 4) == 0){
    dispBoard(game->board, game->graveyard);
    return 0;
  }
  else if (strncmp(command, "help", 4) == 0){
    dispHelp();
    return 0;
  }
  else if (strncmp(command, "go", 2) == 0){
    //have AI make the current move
    printf("Sorry, AI is not complete yet\n");
    return 0;
  }
  else if (strncmp(command, "undo", 4) == 0){
    if (undo(game) == true)
      return 1;
    else
      return 0;
  }
  else if (strncmp(command, "exit", 4) == 0){
    return -1;
  }
  else if (strncmp(command, "resign", 6) == 0){
    printf("Player %i has resigned. You win, Player %i.\n",
	   game->player, ((game->player)%2)+1);
    return -1;
  }
  else if (strncmp(command, "clock", 5) == 0){
    dispClock(game);
    return 0;
  }
  else if (strncmp(command, "history", 7) == 0){
    dispHistory(game);
    return 0;
  }
  else if (isdigit(command[0]) &&
	   islower(command[1]) &&
	   (strlen(command) == 4 ||
            strlen(command) <= 5)){
    /*input is of format 5e4e(+)*/
    char src_c[3], dst_c[3];
    int src[2], dst[2];
    bool upgrade_f;
    snprintf(src_c, 3, "%s", command);
    snprintf(dst_c, 3, "%s", command+2);
    cToCoords(dst, dst_c);
    cToCoords(src, src_c);
    upgrade_f =  (command[4] == '+');
    if (legalmove(game,game->player, src, dst, 0)==true){
      mkmove(game, game->player, src, dst, true, false);
      return 1;
    }
    else{
      return 0;
    }
  }
  else if ((isupper(command[0]) != 0) &&
	   (isdigit(command[1]) != 0) &&
	   (islower(command[2]) != 0) &&
	   (strlen(command) <= 5)){
    //interpret move of form P4e(+)
    int src[2], dst[2];
    char dst_c[2], piece = command[0];
    snprintf(dst_c, 3, "%s", command+1);
    cToCoords(dst, dst_c);
    int processed_f = processmv(game, piece, src, dst);
    bool upgrade_f = (legalUpgrade(game, game->player, dst) &&
                      command[3] == '+');
    if(processed_f == true &&
       legalmove(game, game->player, src, dst, 0)==true){
      mkmove(game, game->player, src, dst, true, upgrade_f);
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (isupper(command[0]) &&
	   command[1] == '*' &&
	   islower(command[2]) &&
	   sizeof(command) == 4){
    //inteprets drop of form P*4e
    char piece = command[0], dst_c[2];
    int dst[2];
    snprintf(dst_c, 2, "%s", command+2);
    cToCoords(dst, dst_c);
    if (legaldrop(game, game->player, piece, dst) == true){
      mkdrop(game, game->player, piece ,dst, true);
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    printf("Sorry, that move is invalid, please try again.\n");
    return 0;
  }
}

/*Converts move from form "<piece><file><rank>"
 *or "Pe4" to the form "e4e5" or "<sfile><srank><dfile><drank>"
 *then executes the move function.
 */

int processmv(struct gm_status *game, char piece, int *src, int *dst){
  if (game->player == CHALLENGING){
    piece = tolower(piece);
  }
  else if(game->player == REIGNING){
    piece = toupper(piece);
  }

  /*Possible optimisation by early exit if 
   *legaldest() returns false*/

  /*n is count of possible pieces executing the move*/
  int n = 0;
  int srank, sfile;//outputted in dst
  char thisPiece;
  for (src[0] = 0; src[0] < 9; src[0]++){
    for (src[1] = 0; src[1] < 9; src[1]++){
      thisPiece = game->board[src[0]][src[1]];
      /*tests whether a the selected piece on 
	the board can make the move or not*/
      if (thisPiece ==  piece && 
	  legalmove(game, game->player, src, dst, 0)){
	srank = src[0];
	sfile = src[1];
	n++;
      }
    }
  }
  if (n == 1){
    src[0] = srank;
    src[1] = sfile;
    return true;
  }
  else if (n == 0){
    printf("Invalid move/formatting.\n");
    return false;
  }
  else{
    printf("Ambiguous move.\n");
    return false;
  }
}

#ifdef INPUT_TEST
int main(){
  struct gm_status game;
  init_game(&game);
  char command[5][4] = {"B7g","P7f","B7g","G",""};
  int i, mv_f;
  FOREACH(command, i){
    mv_f = processcmd(&game, command[i]);
    if (mv_f == 1){
      printf("Success\n");
      mv_f = 0;
    }
    else{
      printf("Failure\n");
    }
    dispBoard(&game);
  }
  return 0;
}

#endif
