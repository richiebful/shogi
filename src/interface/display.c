/** \file */
#include <shogi.h>

/**
 *\brief Shows the board and graveyard
 */
void dispBoard(struct gm_status *game){
  char board[9][9];
  memcpy(board, game->board, sizeof(board));
  int i, j;
  for (i = 0; i < 9; i++){
    for (j = 0; j < 9; j++){
      char piece = board[i][j];
      if (isupper(board[i][j])){
	//print the piece out in white
	printf(" \x1b[37m%c", piece);
      }
      else if(piece == ' '){
	printf("  ");
      }
      else{
	//print the piece out in red
	printf(" \x1b[31m%c", piece-32);
      }
      if (j == 8){ //prints the rank no.
	printf(" \x1b[37m%i", i+1);
      }
    }
    printf("\n");
  }
  printf("\x1b[37m");
  for(i = 8+97; i > 96; i--){
    printf(" %c", i);
  }
  printf("\n\n");
  char p1Yard[38];
  char p2Yard[38];
  memcpy(p1Yard, game->graveyard.challenging, sizeof(p1Yard));
  memcpy(p2Yard, game->graveyard.reigning, sizeof(p2Yard));
  for (i = 0; i < 38; i++){
    if (p1Yard[i] != '\0'){
      printf("\x1b[31m%c ", p1Yard[i]);
    }
  }
  printf("\n");
  for (i = 0; i < 38; i++){
    if (p2Yard[i] != '\0'){
      printf("\x1b[37m%c ", p2Yard[i]);
    }
  }
  printf("\n");
}


void dispHelp(void){
  printf("7g7f\t move from 7g to 7f\t");
  printf("quit\texit Shogi\n");
  printf("S6h\tmove Silver to 6h\t");
  printf("resign\tresign the game to your opponent\n");
  printf("2d2c+\tmove to 2c and promote\t");
  printf("show\tshows board and graveyard from your pov\n");
  printf("P*5e\tdrop pawn at 5e\t");
  printf("revert\tgo back a move, or several\n");
}

void dispClock(struct gm_status *game){
  clockUpdate(game);

  struct time_s clock;
  memcpy(&clock, &game->clock, sizeof(clock));

  //display clock
  printf("Black: %i:%.2i\n",
	 clock.player_t[1][0],
	 clock.player_t[1][1]);
  printf("White: %i:%.2i\n",
	 clock.player_t[0][0],
	 clock.player_t[0][1]);
}


#ifdef DISPLAY_TEST
int main(void){
  struct gm_status game;
  init_game(&game);
  dispBoard(&game);
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
  game->clock.last_t = time(NULL);
  game->clock.advance_t = 15; //15s added per move
}

#endif
