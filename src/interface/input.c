/** \file */
#include <shogi.h>

/*if return 1, continue to next player
 *if return 0, execute the commmand, if any,
 *then query the player for input again 
 *if return -1, input kills the program.
 */
int processcmd(char *command, struct gm_status *game){
  if (strncmp(command, "show", 4) == true){
    dispBoard(game);
    return 0;
  }
  else if (strncmp(command, "help", 4) == true){
    dispHelp();
    return 0;
  }
  else if (strncmp(command, "go", 2) == true){
    //have AI make the current move
    printf("AI is not complete yet");
    return 0;
  }
  else if (strncmp(command, "exit", 4) == true){
    return -1;
  }
  else if (strncmp(command, "resign", 6) == true){
    printf("Player %i has resigned. You win, Player %i.\n",
	   game->player, ((game->player)%2)+1);
    return -1;
  }
  else if (islower(command[0]) == true &&
	   isdigit(command[1]) == true &&
	   sizeof(command) == 4){
    /*copies command[0:2] to src
     *and copies command[2:4] to dst
     *input is of format 5e4e*/
    char src_c[2], dst_c[2];
    int src[2], dst[2];
    snprintf(src_c, 2, "%s", command);
    snprintf(dst_c, 2, "%s", command+2);
    ctocoords(dst, dst_c);
    ctocoords(src, src_c);
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
    //interpret move of form P4e
    int src[2], dst[2];
    char piece = command[0], dst_c[2];
    snprintf(dst_c, 2, "%s", command+1);
    ctocoords(dst, dst_c);
    int processed_f = processmv(*game, piece, src, dst);
    if(legalmove(game, src, dst)==true &&
       processed_f == true){
      mkmove(game, src, dst);
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (isupper(command[0]) == true &&
	   command[1] == '*' &&
	   islower(command[2]) == true &&
	   sizeof(command) == 4){
    //inteprets drop of form P*4e
    char piece = command[0], dst_c[2];
    int dst[2];
    snprintf(dst_c, 2, "%s", command+2);
    ctocoords(dst, dst_c);
    if (legaldrop(game, piece, dst) == true){
      mkdrop(game, piece ,dst);
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

int processmv(struct gm_status game, char piece, int *src, int *dst){
  if (game.player == 1){
    piece = tolower(piece);
  }
  else if(game.player == 0){
    piece = toupper(piece);
  }
  int dfile =  dst[1],  drank = dst[0];
  /*n is count of possible pieces executing the move*/
  int i, j, n = 0;
  int srank, sfile;//outputted in dst
  dst[0] = drank;
  dst[1] = dfile;
  FORRANGE(i, 0, 9, 1){
    FORRANGE(j, 0, 9, 1){
      char thisPiece = game.board[i][j];
      //tests whether a the selected pice on the board can make the move or not
      if(thisPiece ==  piece && legalmove(&game, src, dst)){
	srank = i;
	sfile = 8 - j;
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

int main(){
  struct gm_status game;
  init_game(&game);
  return 0;  
}

void init_game(struct gm_status *game){
  const char init_board[9][9] = {{'L','N','G','U','K','U','G','N','L'},
				 {' ','R',' ',' ',' ',' ',' ','B',' '},
				 {'P','P','P','P','P','P','P','P','P'},
				 {' ',' ',' ',' ',' ',' ',' ',' ',' '},
				 {' ',' ',' ',' ',' ',' ',' ',' ',' '},
				 {' ',' ',' ',' ',' ',' ',' ',' ',' '},
				 {'p','p','p','p','p','p','p','p','p'},
				 {' ','b',' ',' ',' ',' ',' ','r',' '},
				 {'l','n','g','u','k','u','g','n','l'}};
  memcpy(game->board,init_board,sizeof(init_board));

  game->player = 1;

  /*the equivalent of char game->history[150][5]*/
  game->history = malloc(sizeof(char)*5*150);
  game->check_f = 0;
  game->cmate_f = 0;

  int i;
  FORRANGE(i,0,38,1){
    game->graveyard.challenging[i] = '\0';
    game->graveyard.reigning[i] = '\0';
  }
}
