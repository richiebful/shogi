/** \file */
#include <shogi.h>

/* Moves a piece from one location on the board to another, and moves the "killed" piece to the killer's drop pile 
 * Input coordinates are in absolute terms, and move must be proven legal first.
 */

void mkmove(struct gm_status *game, int player, int *src, int *dst){
  //a 'd-' prefix means destination; a 's-' prefix means source
  int drank = dst[0];
  int dfile = dst[1];
  int srank = src[0];
  int sfile = src[1];
  char spiece = game->board[srank][sfile];
  char dpiece = game->board[drank][dfile];
  game->board[srank][sfile] = ' ';
  game->board[drank][dfile] = spiece;
  
  int i;
  if (dpiece != ' '){
    if (player == P1){
      for (i = 0; i < 38; i++){
	if (game->graveyard[player][i] != '\0'){
	  game->graveyard[player][i] = dpiece + 32;
	}
      }
    }
    else{
      for (i = 0; i < 38; i++){
	if (game->graveyard[player][i] != '\0'){
	  game->graveyard[player][i] = spiece - 32;
	}
      }
    }
  }
  //updateHist(game, src, dst);
  //updateClock(game);
}

void updateHist(struct gm_status *game, int *src, int *dst){
  /*This section adds move to the history*/
  char *history = game->history;
  const int step = 4;
  char *lastMove;
  int i = 0;
  while (*history != '\0' && i < sizeof(history)){
    lastMove = history;
    history += step;
    i += step;
  }

  if (i + 1 == sizeof(game->history)){
    /*Expand history to double its present size*/
    char *nHistory = calloc(2*sizeof(game->history), sizeof(char)*4);
    memcpy(nHistory, game->history, sizeof(*game->history));
    free(game->history);
    /*Re-establishes current place in history*/
    history = game->history + i;
  }
  
  /*Copy move being made to current place in history*/
  snprintf(history, 4, "%i%i%i%i", src[0], src[1], dst[0], dst[1]);
}

/*Takes a piece from the player's graveyard, and drops it.
  Destination coordinates are in absolute terms
  Assumes the move is legal
*/

void mkdrop(struct gm_status *game, int player, char piece, int *dst){
  int i = 0;
  if (player == P1){
    while (game->graveyard[player][i] != piece){
      i++;
    }
    game->graveyard[player][i] = '\0'; //remove the piece from the graveyard
  }
  else{
    while (game->graveyard[player][i] != piece){
      i++;
    }
    game->graveyard[player][i] = '\0';//remove piece from graveyard
  }
  
  int drank = 8 - dst[0];
  int dfile = dst[1];
  game->board[drank][dfile] = piece;
  //clockUpdate(game);
}

/**Takes coordinates from characters to absolute coordinates in /
  integer form. This will make an string {<file><rank>} or "e4"
  into {rank,file} or {3,4}.
 */

void ctocoords(int *converted, char *to_convert){
  //input is of form 7e, (file, rank)
  //output is of form (4,), (rank, file)
  char crank = to_convert[1];
  char cfile = to_convert[0];
  int irank; 
  int ifile;
  irank = crank - 'a';
  ifile = 8 - (cfile - '1');
  converted[0] = irank;
  converted[1] = ifile;
}
#ifdef UNDO_NEEDED
/*Undoes the last move 
 *Returns 1 if successful, 0 if failure
 */
int undo(struct gm_status *game){
  /*Makes a copy of game history*/
  char *history = game->history;
  int step = 4;
  char *lastMove;
  int i;
  while (*history != '\0' && i < sizeof(history)){
    lastMove = history;
    history += step;
    i += step;
  }
  
  /*Flip-flops sources and destinations in history to reverse them*/
  char src[2] = {*(lastMove+2), *(lastMove+3)};
  char dst[2] = {*(lastMove), *(lastMove+1)};

  mkmove(game, (game.player) % 2 + 1, src, dst);
  snprintf(history, 4, "    ");
}
#endif

#ifdef MOVE_TEST
int main(){
  struct gm_status game;
  init_game(&game);
  int moves[1][2][2] = {{{1,7},{2,6}}};
  int drops[3][2][2];
  int src[2], dst[2];
  int i;
  FOREACH(moves, i){
    memcpy(src, moves[i][0], sizeof(src));
    memcpy(dst, moves[i][1], sizeof(dst));
    printf("%i,%i to %i, %i\n", src[0], src[1], dst[0], dst[1]);
    if (legalmove(&game, 2, src, dst, false) == true){
      mkmove(&game, 1, src, dst);
    }
    else{
      printf("False\n");
    }
    dispBoard(&game);
  }
  return 0;  
}
#endif
