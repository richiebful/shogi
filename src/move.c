
/** \file */
#include "shogi.h"


/** 
 *\fn mkmove
 * Moves a piece from one position to another, and upgrades
 *   if necessary
 *
 *\param game the current game status
 *\param player the player making the move
 *\param src array of source coordinates
 *\param dst array of destination coordinates
 *\param update_f add move to history
 *\param upgrade_f upgrade piece
 *
 *\pre move is legal, include upgrade
 *\pre game includes a well-formed gm_status
 */

void mkmove(struct gm_status *game, int player,
	    int *src, int *dst,
	    bool update_f, bool upgrade_f){
  int drank = dst[0];
  int dfile = dst[1];
  int srank = src[0];
  int sfile = src[1];
  char spiece = game->board[srank][sfile];
  char dpiece = game->board[drank][dfile];
  game->board[srank][sfile] = ' ';
  game->board[drank][dfile] = spiece + upgrade_f;
  
  digGrave(game, player, dpiece);

  if (update_f == true){
    time_t tm_executed = updateClock(game);
    char move[6];
    int i_src[2] = {srank, sfile};
    int i_dst[2] = {drank, dfile};
    char c_src[2];
    char c_dst[2];
    char upgrade_c =  (upgrade_f) ? '+' : '\0';
    coordsToC(c_src, i_src);
    coordsToC(c_dst, i_dst);
    snprintf(move, 6, "%.2s%.2s%c", c_src, c_dst, upgrade_c);
    updateHistory(game, move, tm_executed);
  }
}

/**
 * \fn digGrave
 * Adds a piece to the given player's graveyard
 *
 * \param player who's graveyard the piece should be added to
 * \param game the current game state
 * \param piece the piece to be added
 */

int digGrave(struct gm_status *game, int player, char piece){
  int i;
  if (piece != ' '){
    if (player == P1){
      for (i = 0; i < 38; i++){
	if (game->graveyard[player-1][i] != '\0'){
	  game->graveyard[player-1][i] = tolower(piece);
	}
      }
    }
    else{
      for (i = 0; i < 38; i++){
	if (game->graveyard[player-1][i] != '\0'){
	  game->graveyard[player-1][i] = toupper(piece);
	}
      }
    }
  }
  return true;
}

/**
 * \fn updateHistory
 * Adds a given move to the history linked list
 *
 * \param game the current game state
 * \param move a string showing the move in algebraic notation
 * \param tm_executed the amount of time the move took to make 
 */

void updateHistory(struct gm_status *game, char *move,
                   time_t tm_executed){
  /*This section adds move to the history*/
  struct hist_s *prev_move = game->history;
  struct hist_s *this_move = malloc(sizeof(struct hist_s));
  strncpy(prev_move->move, move, 6);
  prev_move->next_move = this_move;

  this_move->prev_move = prev_move;
  this_move->next_move = NULL;

  game->history = this_move;
  
  this_move->tm_executed = tm_executed;

  this_move->num = prev_move->num + 1;
}

/** 
 * \fn mkdrop
 * Drops a piece from the player's graveyard onto the board
 *
 * \param game the current game state
 * \param player the player making the move
 * \param piece the piece being dropped
 * \param dst the coordinates of where the piece is being dropped
 * \param update_f add the move to history?
 *
 * \pre Move is legal
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

/**
 * \fn cToCoords
 * Converts algebraic notation to coordinates
 * \param converted integer array output of coordinates
 * \param to_convert character array input of algebraic notation
 */

void cToCoords(int *converted, char *to_convert){
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

bool undo(struct gm_status *game){
  if (game->history->move != NULL){
    int dst[2];
    int src[2];
    cToCoords(dst, game->history->move);
    cToCoords(src, game->history->move+2);
  }
  return true;
}

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
