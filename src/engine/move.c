/** \file */
#include <shogi.h>

/* Moves a piece from one location on the board to another, and moves the "killed" piece to the killer's drop pile 
 * Input coordinates are in absolute terms, and move must be proven legal first.
 */

void mkmove(struct gm_status *game, int player,
	    int *src, int *dst, bool update_f){
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
	if (game->graveyard[player-1][i] != '\0'){
	  game->graveyard[player-1][i] = tolower(dpiece);
	}
      }
    }
    else{
      for (i = 0; i < 38; i++){
	if (game->graveyard[player-1][i] != '\0'){
	  game->graveyard[player-1][i] = toupper(spiece);
	}
      }
    }
  }
  if (update_f == true){
    time_t tm_executed = updateClock(game);
    char move[4];
    int i_src[2] = {srank, sfile};
    int i_dst[2] = {drank, dfile};
    char c_src[2];
    char c_dst[3];
    coordsToC(c_src, i_src);
    coordsToC(c_dst, i_dst);;
    snprintf(move, 6, "%s%s", c_src, c_dst);
    updateHistory(game, move, tm_executed);
  }
}

void updateHistory(struct gm_status *game, char *move, time_t tm_executed){
  /*This section adds move to the history*/
  struct hist_s *prev_move = game->history;
  struct hist_s *this_move = malloc(sizeof(struct hist_s));
  printf("%s\n", move);
  strncpy(prev_move->move, move, 5);
  printf("%s\n", prev_move->move);
  prev_move->next_move = this_move;

  this_move->prev_move = prev_move;
  this_move->next_move = NULL;

  game->history = this_move;
  
  this_move->tm_executed = tm_executed;

  this_move->num = prev_move->num + 1;
}

/*Takes a piece from the player's graveyard, and drops it.
  Destination coordinates are in absolute terms
  Assumes the move is legal
*/

void mkdrop(struct gm_status *game, int player,
	    char piece, int *dst, bool update_f){
  int i = 0;
  if (player == P1){
    while (game->graveyard[player-1][i] != piece){
      i++;
    }
    game->graveyard[player-1][i] = '\0'; //remove the piece from the graveyard
  }
  else{
    while (game->graveyard[player-1][i] != piece){
      i++;
    }
    game->graveyard[player-1][i] = '\0';//remove piece from graveyard
  }
  
  int drank = dst[0];
  int dfile = dst[1];
  game->board[drank][dfile] = piece;

  if (update_f){
    long s_lost = updateClock(game);
    char move[4];
    //inaccurate
    snprintf(move, 4, "%c*%i%i", piece, drank, dfile);
    updateHistory(game, move, s_lost);
  }
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
  int irank, ifile;
  irank = crank - 'a';
  ifile = 8 - (cfile - '1');
  converted[0] = irank;
  converted[1] = ifile;
}

void coordsToC(char *converted, int *to_convert){
  int irank = to_convert[0];
  int ifile = to_convert[1];
  int crank, cfile;
  crank = irank + 'a';
  cfile = (8 - ifile) + '1';
  converted[0] = cfile;
  converted[1] = crank;
}

#ifdef UNDO
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
