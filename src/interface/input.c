/** \file */
#include <shogi.h>

/*if return 1, continue to next player
 *if return 0, execute the commmand, if any,
 *then query the player for input again 
 *if return -1, input kills the program.
 */
int processcmd(char *command, struct gm_status *game){
  //printf("%s", command);
  if (strncmp(command, "show", 4) == 0){
    dispBoard(game);
    return 0;
  }
  else if (strncmp(command, "help", 4) == 0){
    dispHelp();
    return 0;
  }
  else if (strncmp(command, "go", 2) == 0){
    //have AI make the current move
    printf("AI is not complete yet");
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
  else if (islower(command[0]) &&
	   isdigit(command[1]) &&
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
  else if ((isupper(command[0]) != 0) &&
	   (isdigit(command[1]) != 0) &&
	   (islower(command[2]) != 0) &&
	   (strlen(command) <= 5)){
    //interpret move of form P4e
    int src[2], dst[2];
    char dst_c[2], piece;
    snprintf(dst_c, 3, "%s", command+1);
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
  else if (isupper(command[0]) &&
	   command[1] == '*' &&
	   islower(command[2]) &&
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
  int drank =  dst[0],  dfile = 8 - dst[1];
  printf("d-pos: (%i,%i)", drank, dfile);
  /*n is count of possible pieces executing the move*/
  int i, j, n = 0;
  int srank, sfile;//outputted in dst
  char thisPiece;
  FORRANGE(i, 0, 9, 1){
    FORRANGE(j, 0, 9, 1){
      thisPiece = game.board[i][j];
      src[0] = i;
      src[1] = 8 - j;
      //tests whether a the selected pice on the board can make the move or not
      if (thisPiece ==  piece && legalmove(&game, src, dst)){
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
  char *cmd = malloc(sizeof(char)*10);
  scanf("%s", cmd);
  processcmd(cmd, &game);
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

  int i;
  FORRANGE(i,0,38,1){
    game->graveyard.challenging[i] = '\0';
    game->graveyard.reigning[i] = '\0';
  }
  //set each player's clocks to 60:00
  game->clock.player_t[0][0] = game->clock.player_t[1][0] = 60;
  game->clock.player_t[0][1] = game->clock.player_t[1][1] = 0;
  game->clock.advance_t = 15; //15s added per move
}
