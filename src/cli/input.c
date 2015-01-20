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
  else if (strncmp(command, "undo", 4) == 0){
    printf("Undo has not been constructed yet");
    return 1;
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
    if (legalmove(game,game->player, src, dst, 0)==true){
      mkmove(game, game->player, src, dst);
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
    char dst_c[2], piece = command[0];
    snprintf(dst_c, 3, "%s", command+1);
    ctocoords(dst, dst_c);
    int processed_f = processmv(*game, piece, src, dst);
    if(legalmove(game, game->player, src, dst, 0)==true &&
       processed_f == true){
      mkmove(game, game->player, src, dst);
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
    if (legaldrop(game, game->player, piece, dst) == true){
      mkdrop(game, game->player, piece ,dst);
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
  printf("Piece: %c\n", piece);
  if (game.player == CHALLENGING){
    piece = tolower(piece);
  }
  else if(game.player == REIGNING){
    piece = toupper(piece);
  }
  int drank =  dst[0],  dfile = dst[1];
  printf("d-pos: (%i,%i)", drank, dfile);
  /*n is count of possible pieces executing the move*/
  int n = 0;
  int srank, sfile;//outputted in dst
  char thisPiece;
  for (src[0] = 0; src[0] < 9; src[0]++){
    for (src[1] = 0; src[1] < 9; src[1]++){
      thisPiece = game.board[src[0]][src[1]];
      printf("SRC={%i, %i} DST={%i, %i}\n",
	     src[0], src[1], dst[0], dst[1]);
      /*tests whether a the selected piece on 
	the board can make the move or not*/
      if (thisPiece ==  piece && 
	  legalmove(&game, game.player, src, dst, 0)){
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
  char pieces[5] = "PBUNG";
  int *src = malloc(2*sizeof(int));
  int dsts[5][2] = {{3,0},{2,2},{1,4},{2,2},{2,1}};
  int i, mv_f;
  FOREACH(pieces, i){
    mv_f = processmv(game, pieces[i], src, dsts[i]);
    if (mv_f == true){
      printf("%i,%i\n", src[0], src[1]);
      mv_f = false;
    }
    else{
      printf("Failure\n");
    }
  }
  return 0;
}

void init_game(struct gm_status *game){
  const char init_board[9][9] = {"LNGAKAGNL",
				 " R     B ",
				 "PPPPPPPPP",
				 "         ",
				 "         ",
				 "         ",
				 "ppppppppp",
				 " b     r ",
				 "lngakagnl"};

  memcpy(game->board,init_board,sizeof(init_board));

  game->player = 2;

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

#endif
