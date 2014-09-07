#include <shogi.h>

/*Makes the bitboard for the current game board
 */
void mkbitboard(struct gm_status *game){
  bool bitboard[9][9][9][9];
  memcpy(game->bitboard, bitboard, sizeof(bitboard));

  int srank, sfile, drank, dfile;
  char piece;
  for (srank = 0; srank < 9; srank++){
    for (sfile = 0; sfile < 9; sfile++){
      for (drank = 0; drank < 9; drank++){
	for (dfile = 0; dfile < 9; dfile++){
	  int src[2] = {srank, sfile}
	  int dst[2] = {drank, dfile}
	  if(legalmove(game,src,dst)==true){
	    bitboard[srank][sfile][drank][dfile] = 1;
	  }
	  else{
	    bitboard[srank][sfile][drank][dfile] = 0;
	  }
	}
      }
    }
  }
}

/*Checks whether a move works
 *Coords are in absolute terms 
 */

bool legalmove(struct gm_status *game, int *src, int *dst){
  int srank = src[0];
  int sfile = src[1];
  int drank = dst[0];
  int dfile = dst[1];
  
  int rel_srank, rel_sfile, rel_drank, rel_dfile;
  int player = game->player;
  if (player == P1){
    rel_srank = 8 - srank;
    rel_drank = 8 - drank;
    rel_sfile = sfile;
    rel_dfile = dfile;
  }
  else{
    rel_srank = srank;
    rel_drank = drank;
    rel_sfile = 8 - sfile;
    rel_dfile = 8 - dfile;
  }
  
  char board[9][9];
  memcpy(board,game->board,sizeof(board));
  char piece = board[srank][sfile];
  char dpiece = board[drank][dfile];
  
  if (legaldest(game,drank,dfile) == false){
    return false;
  }
  if (legalsrc(game,drank,dfile) == false){
    return false;
  }
  else if (piece == 'P' || piece == 'p'){
    if (rel_srank + 1 == rel_drank && rel_sfile == rel_dfile){
      return true;
    }
    else{
      return false;
    }
  }
  else if (piece == 'R' || piece == 'r'){
    int i, var_s, var_d, sign;
    if ((drank != srank && dfile != sfile)||
	(drank == srank && dfile == sfile)){
      return false;
    }
    else if (drank > srank){ //it is implied that dfile == sfile
      for (i = srank; i != drank; ++i){
	if (dpiece != ' '){
	  return false;
	}
      }
      return true;
    }
    else if (drank < srank){
      for (i = srank; i != drank; --i){
	if (dpiece != ' '){
	  return false;
	}
      }
      return true;
    }
    else if (dfile > sfile){
      for (i = sfile; i != dfile; ++i){
	if (dpiece != ' '){
	  return false;
	}
      }
      return true;
    }
    else{ //dfile < sfile
      for (i = sfile; i != dfile; --i){
	if (dpiece != ' '){
	  return false;
	}
      }
      return true;
    }
  }
}
/*Determines whether the rank and file are out of range
 *of the board or not.
 */
bool inrange(int rank, int file){
  if (rank > 8 || rank < 0 || file > 8 || file < 0){
    return false;
  }
  return true;
}

/*determines whether a destination is legal regardless of
 *a specific move's legality
 */ 
bool legaldest(struct gm_status *game, int rank, int file){
  char dpiece = game->board[rank][file];
  int player = game->player;

  if (inrange(rank, file) == false){
    return false;
  }
  else if (player == P1){ //player can't attack own piece
    if (islower(dpiece)){
      return false;
    }
    else{
      return true;
    }
  }
  else{
    if (isupper(dpiece)){
      return false;
    }
    else{
      return true;
    }
  }
  return true;
}

/*Tests whether the coordinates point to something can be moved
 *by a certain player
 */

bool legalsrc(struct gm_status *game, int rank, int file){
  char spiece =  game->board[rank][file];
  int player = game->player;

  if (inrange(rank, file) == false){
    return false;
  }
  else if(player == P1){
    if (isupper(spiece)){
      return false;
    }
    else{
      return true;
    }
  }
  else{
    if (islower(spiece)){
      return false;
    }
    else{
      return true;
    }
  }
}

/*Returns true if drop is legal, false if not
 *Coordinates must be in absolute terms
 */
bool isLegalDrop(struct gm_status *game, int *dst){
  int drank = dst[0];
  int dfile = dst[1];
  return true;
}
