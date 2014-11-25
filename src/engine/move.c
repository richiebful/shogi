/** \file */
#include <shogi.h>

/* Moves a piece from one location on the board to another, and moves the "killed" piece to the killer's drop pile 
 * Input coordinates are in absolute terms, and move must be proven legal first.
 */
void mkmove(struct gm_status *game, int * src, int * dst){
  //a 'd-' prefix means destination; a 's-' prefix means source
  int drank = dst[0];
  int dfile = 8 - dst[1];
  int srank = src[0];
  int sfile = 8 - src[1];
  int player = game->player;
  int spiece = game->board[srank][sfile];
  /*dpiece is the board cell being attacked*/ 
  int dpiece = game->board[drank][dfile];
  game->board[srank][sfile] = ' ';
  game->board[drank][dfile] = spiece;
  
  int i;
  /*captures a piece and places it into the 
    capturing player's graveyard*/
  if (dpiece != ' '){
    if (player == P1){
      for (i = 0; i < 38; i++){
	if (game->graveyard.challenging[i] != '\0'){
	  game->graveyard.challenging[i] = dpiece + 32;
	}
      }
    }
    else{
      for (i = 0; i < 38; i++){
	if (game->graveyard.reigning[i] != '\0'){
	  game->graveyard.reigning[i] = spiece - 32;
	}
      }
    }
  }
  clockUpdate(game);
}

/*Takes a piece from the player's graveyard, and drops it.
  Destination coordinates are in absolute terms
  Assumes the move is legal
*/

void mkdrop(struct gm_status *game, char piece, int *dst){
  int i = 0;
  if (game->player == P1){
    while (game->graveyard.challenging[i] != piece){
      i++;
    }
    game->graveyard.challenging[i] = '\0'; //remove the piece from the graveyard
  }
  else{
    while (game->graveyard.reigning[i] != piece){
      i++;
    }
    game->graveyard.reigning[i] = '\0';//remove piece from graveyard
  }
  
  int drank = 8 - dst[0];
  int dfile = dst[1];
  game->board[drank][dfile] = piece;

  clockUpdate(game);
}

/**Takes coordinates from characters to absolute coordinates in /
  integer form. This will make an string {<file><rank>} or "e4"
  into {rank,file} or {3,4}.
 */

void ctocoords(int *converted, char *to_convert){
  int crank = to_convert[1];
  int cfile = to_convert[0];
  int irank; 
  int ifile;
  irank = 8 -(crank - 'a');
  ifile = cfile;
  converted[0] = irank;
  converted[1] = ifile;
}

int main(){
  struct gm_status game;
  init_game(&game);
  int moves[3][2][2] = {{{2,2},{3,2}},
			{{1,1},{4,4}},
			{{5,5},{6,6}}};
  int drops[3][2][2];
  int src[2], dst[2];
  int i;
  FOREACH(moves, i){
    memcpy(src, moves[i][0], sizeof(src));
    memcpy(dst, moves[i][1], sizeof(dst));
    printf("%i,%i to %i, %i\n", src[0], src[1], dst[0], dst[1]);
    if (legalmove(&game, src, dst) == true){
      mkmove(&game, src, dst);
    }
    dispBoard(&game);
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
  game->history = malloc(sizeof(char)*5*150);
  game->check_f = 0;
  game->cmate_f = 0;

  int i;
  FORRANGE(i,0,38,1){
    game->graveyard.challenging[i] = '\0';
    game->graveyard.reigning[i] = '\0';
  }
}

