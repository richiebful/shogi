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

/**
 *\brief Shows the board and graveyard
 */
void dispBoard(struct gm_status *game){
  char board[9][9];
  memcpy(board, game->board, sizeof(board));
  int i, j;

  printf("\n");

  for (i = 0; i < 9; i++){
    printf(" ");
    for (j = 0; j < 9; j++){
      char piece = board[i][j];
      char upgraded_f = ' ';
      if (isUpgradedPiece(piece)){
        upgraded_f = '+';
        piece--;
      }
      if (isupper(board[i][j])){
	//print the piece out in white
	printf("\x1b[37m%c%c", piece, upgraded_f);
      }
      else if(piece == ' '){
	printf("  ");
      }
      else{
	//print the piece out in red
	printf("\x1b[31m%c%c", piece-32, upgraded_f);
      }
      if (j == 8){ //prints the rank no.
	printf("\x1b[37m%c ", i+97);
      }
    }
    printf("\n");
  }
  printf("\x1b[37m ");
  for(i = 9; i > 0; i--){
    printf("%i ", i);
  }
  printf("\n\n");
  char p1Yard[38];
  char p2Yard[38];
  memcpy(p1Yard, game->graveyard[0], sizeof(p1Yard));
  memcpy(p2Yard, game->graveyard[1], sizeof(p2Yard));
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
  //reset colours to default
  printf("\x1b[0m");
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
  updateClock(game);

  struct time_s clock;
  memcpy(&clock, &game->clock, sizeof(clock));

  int seconds = clock.player_t[0] % 60;
  int minutes = clock.player_t[0] / 60;

  printf("Player 1: %i:%.2i\n",  minutes, seconds);

  seconds = clock.player_t[1] % 60;
  minutes = clock.player_t[1] / 60;
  
  printf("Player 2: %i:%.2i\n\n", minutes, seconds);
	 
}

bool dispHistory(struct gm_status *game){
  struct hist_s *this_move = game->history;
  if (game->history->num != 0){
    while (this_move->prev_move->num != 0){
      this_move = this_move->prev_move;
    }
    int i;
    for (i = 1; i <= game->history->num; i++){ 
      printf("%i. %s\n", i, this_move->move);
      this_move = this_move->next_move;
    }
  }
  return true;
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
  game->clock.last_t = time(NULL);
  game->clock.advance_t = 15; //15s added per move
}

#endif
