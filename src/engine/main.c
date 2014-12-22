/** \file */
#include <shogi.h>


int main(void){
  struct gm_status game;
  init_game(&game);
  int input_f;
  while (fatal_f != true){
    char command[20] = "NULL";
    input_f = 0;
    printf("Player %i:", game.player);
    while (input_f == 0){
      scanf("%s", command);
      input_f = processcmd(command, &game);
    }
    if (input_f == 1){
      game.player = game.player % 2 + 1;
    }
    if (input_f == -1){
      //if move is fatal
      break;
    }
  }
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
  game->history = calloc(sizeof(char)*4*32);

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
