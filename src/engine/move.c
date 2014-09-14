#include <shogi.h>

/* Moves a piece from one location on the board to another, and moves the "killed" piece to the killer's drop pile 
 * Input coordinates are in absolute terms, and move must be proven legal first.
 */
void mkmove(struct gm_status *game, int * src, int * dst){
  //a 'd-' prefix means destination; a 's-' prefix means source
  int drank = dst[0];
  int dfile = dst[1];
  int srank = src[0];
  int sfile = src[1];
  int player = game->player;
  int spiece = game->board[srank][sfile];
  int dpiece = game->board[drank][dfile]; /*dpiece is the board cell being attacked*/ 
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
  
  int drank = dst[0];
  int dfile = dst[1];
  game->board[drank][dfile] = piece;
}

/*Takes coordinates from characters to absolute coordinates in /
  integer form. This will make an string {<file><rank>} or "e4"
  into {rank,file} or {3,4}.
 */

void cToCoords(struct gm_status *game, int *converted, char *to_convert){
  int crank = to_convert[1];
  int cfile = to_convert[0];
  int irank; 
  int ifile;
  if (game->player == P1){
    irank = (8 - 'a') + crank;
    ifile = cfile;
  }
  else if(game->player == P2){
    irank = crank;
    ifile = (8 - 'a') + crank;
  }
  converted[0] = irank;
  converted[1] = ifile;
}
