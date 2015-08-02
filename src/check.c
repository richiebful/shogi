/**\file*/
#include "shogi.h"


int ischeck(struct gm_status *game, int player){
  int i, j;
  char board[9][9];
  memcpy(board, game->board, sizeof(board));

  int otherPlayer = (player) % 2 + 1;
  int dst[2];

  int king = 'k' - 32*(player-1);
  
  FORRANGE(i, 0, 9, 1){
    FORRANGE(j, 0, 9, 1){
      if (board[i][j] == king){
	dst[0] = i;
	dst[1] = 8 - j;
	break;
      }
    }
  }

  int src[2];
  bool exit_f = false;
  FORRANGE(i, 0, 9, 1){
    FORRANGE(j, 0, 9, 1){
      src[0] = i;
      src[1] = 8 - j;
      if (legalmove(game, player, src, dst, true)){
	return true;
      }
    }
  }

  return exit_f;
}

int ismate(struct gm_status *game, int player){
  struct gm_status test_game;
  memcpy(&test_game, &game, sizeof(test_game));

  /*Player must be in check to be in mate*/
  if (ischeck(game, player)==false){
    return false;
  }
  /*test all possible following moves, then determine whether check still
   *exists under the new game state*/
  int i, j, k, l;
  int src[2], dst[2];
  
  /*Assume checkmate until it is disproven*/
  FORRANGE(i, 0, 9, 1){
    FORRANGE(j, 0, 9, 1){
      FORRANGE(k, 0, 9, 1){
	FORRANGE(l, 0, 9, 1){
	  src[0] = i; src[1] = j;
	  dst[0] = k; dst[1] = l;
	  if (legalmove(&test_game, player, src, dst, 1) == true){
              mkmove(&test_game, player, src, dst, false, false);
	    if (ischeck(&test_game, player) == false){
	      return false;
	    }
	    memcpy(&test_game, &game, sizeof(test_game));
	  }
	}
      }
    }
  }
  return true;
}

#ifdef CHECK_TEST 

int main(){
  struct gm_status game;
  int player = 1;
  init_game(&game);
  printf("%i",ischeck(game, player));
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

#endif

#ifdef CMATE_TEST

int main(){
  struct gm_status game;
  int player = 1;
  init_game(&game);
  printf("%i",ischeck(game, player));
}
#endif