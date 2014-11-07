#include <shogi.h>
/*
int main(void){
  struct gm_status game;
  init_game(&game);
  bool fatal_f = 0;
  int legal_f = 0, i;
  //of form {{{srank,sfile},{drank,dfile}},...} 
  int trueCases[10][2][2]; 
  int falseCases[10][2][2];
  int srank, sfile, drank, dfile;
  FOREACH(trueCases, i){
    srank = trueCases[i][0][0];
    sfile = trueCases[i][0][1];
    drank = trueCases[i][1][0];
    dfile = trueCases[i][1][1];
    if (legal_f = legalmove(&game, trueCases[i][0], trueCases[i][1])){
      printf("%i,%i to %i,%i returns %i", srank, sfile, drank, dfile, legal_f);
    }
  }
  FOREACH(falseCases, i){
    srank = falseCases[i][0][0];
    sfile = falseCases[i][0][1];
    drank = falseCases[i][1][0];
    dfile = falseCases[i][1][1];
    if(legal_f = legalmove(&game, falseCases[i][0], falseCases[i][1])){
      printf("%i,%i to %i,%i returns %i", srank, sfile, drank, dfile, input_f);
    }
  }
  printf("%i", legal_f);
  return 0;  
}
*/


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
	  int src[2] = {srank, sfile};
	  int dst[2] = {drank, dfile};
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
  int sfile = 8 - src[1];
  int drank = dst[0];
  int dfile = 8 - dst[1];
  
  int rel_srank, rel_sfile, rel_drank, rel_dfile;
  int player = game->player;
  if (player == P1){
    rel_srank = srank;
    rel_drank = drank;
    rel_sfile = sfile;
    rel_dfile = dfile;
  }
  else{
    rel_srank = 8 - srank;
    rel_drank = 8 - drank;
    rel_sfile = 8 - sfile;
    rel_dfile = 8 - dfile;
  }
  
  char board[9][9];
  memcpy(board,game->board,sizeof(board));
  
  char piece = board[srank][sfile];
  char dpiece = board[drank][dfile];
  
  if (legaldest(game,drank,dfile) == false){
    printf("legaldest\n");
    return false;
  }
  else if (legalsrc(game,drank,dfile) == false){
    printf("legalsrc");
    return false;
  }
  else if (drank == srank && dfile == sfile){
    printf("same piece");
    return false;
  }
  else if (piece == 'P' || piece == 'p'){ //pawn check
    //pawns can only move forward one relative rank
    if (rel_srank + 1 == rel_drank && rel_sfile == rel_dfile){
      return true;
    }
    else{
      printf("bad pawn");
      return false;
    }
  }
  else if (piece == 'R' || piece == 'r'||
	   piece == 'S' || piece == 's'){ //checks legality of rook move
    int i, rook_fatal_flag = false;
    if ((drank != srank && dfile != sfile)||
	(drank == srank && dfile == sfile)){
      rook_fatal_flag = true;
    }
    else if (drank > srank){ //it is implied that dfile == sfile
      for (i = srank; i != drank; ++i){
	if (board[i][sfile] != ' '){
	  rook_fatal_flag = true;
	}
      }
      printf("bad rook");
      rook_fatal_flag = false;
    }
    else if (drank < srank){
      for (i = srank; i != drank; --i){
	if (board[i][sfile] != ' '){
	  rook_fatal_flag = true;
	}
      }
      printf("bad rook");
      rook_fatal_flag = false;
    }
    else if (dfile > sfile){
      for (i = sfile; i != dfile; ++i){
	if (board[srank][i] != ' '){
	  rook_fatal_flag = true;
	}
      }
      printf("bad rook");
      rook_fatal_flag = false;
    }
    else{ //dfile < sfile
      for (i = sfile; i != dfile; --i){
	if (board[srank][i] != ' '){
	  rook_fatal_flag = true;
	}
      }
      printf("bad rook");
      rook_fatal_flag = false;
    }
    
    if (piece == 'R' || piece == 'r'){
      return rook_fatal_flag;
    }
    else{ //if it is upgraded rook
      int i;
      int possible[4][2] = {{srank + 1, sfile},
			    {srank - 1, sfile},
			    {srank, sfile + 1},
			    {srank, sfile - 1}};
      for (i = 0; i < sizeof(possible)/sizeof(possible[0]); i++){
	if (possible[i][0] == drank && possible[i][1] == dfile){
	  return true;
	}
      } 
      return false;
    }
  }
  else if (piece == 'B' || piece == 'b'||
	   piece == 'C' || piece == 'c'){ //checks bishop's legality
    int slope, direction;
    bool bishop_fatal_f = false;
    slope = (drank-srank)/(dfile-sfile);
    if (slope != 1 && slope != -1){
      printf("bad bishop1");
      return false;
    }
    else if (drank < srank){
      direction = -1;
    }
    else{
      direction = 1;
    }
    int i, yInt = sfile/(slope*srank);
    for (i = srank+direction; i != drank+direction; i += direction){
      //checks whether the move is blocked by a piece
      if (board[i][slope*i+yInt] != ' '){
	bishop_fatal_f = true;
      }
    }
    if (bishop_fatal_f == true){
      printf("bad bishop2\n");
    }
    if (piece == 'B' || piece == 'b'){
      //returns opposite of fatal_f
      return ~bishop_fatal_f;
    }
    else{
      int possible[4][2] = {{srank + 1, sfile},
			    {srank - 1, sfile},
			    {srank, sfile + 1},
			    {srank, sfile - 1}};
      for (i = 0; i < sizeof(possible)/sizeof(possible[0]); i++){
	if (possible[i][0] == drank && possible[i][1] == dfile){
	  return true;
	}
      }
      return false;
    }
  }
  else if (piece == 'L'|| piece == 'l'){ //checks lance's legality
    int direction;
    //if the lance isn't moving forward, it is illegal
    if (rel_drank <= rel_srank || sfile != dfile){
      return false;
    }
    else if (drank > srank){
      direction = 1;
    }
    else{
      direction = -1;
    }
    int i;
    for (i = srank + direction; i != drank; i += direction){
      if (board[sfile][i] != ' '){
	return false;
      }
    }
    return true;
  }
  else if (piece == 'K' || piece == 'k'){
    int possible[8][2] = {{srank + 1, sfile + 1},
			  {srank + 1, sfile},
			  {srank + 1, sfile - 1},
			  {srank, sfile + 1},
			  {srank, sfile - 1},
			  {srank - 1, sfile + 1},
			  {srank - 1, sfile},
			  {srank - 1, sfile - 1}};
    int i;
    for (i = 0; i < sizeof(possible)/sizeof(possible[0]); i++){
      if (possible[i][0] == drank && possible[i][1] == dfile){
	return true;
      }
    }
    return false;
  }
  else if (piece == 'G' || piece == 'g'){
    int i;
    int possible[5][2] = {{rel_srank + 1, rel_sfile - 1},
			  {rel_srank + 1, rel_sfile},
			  {rel_srank + 1, rel_sfile + 1},
			  {rel_srank - 1, rel_sfile - 1},
			  {rel_srank - 1, rel_sfile + 1}};
    for (i = 0; i < sizeof(possible)/sizeof(possible[0]); i++){
      if (possible[i][0] == rel_drank && possible[i][1] == rel_dfile){
	return true;
      }
    }
    return false;
  }
  else if (piece == 'U' || piece == 'u'||
	   piece == 'H' || piece == 'h'||
	   piece == 'Q' || piece == 'q'||
	   piece == 'M' || piece == 'm'||
	   piece == 'O' || piece == 'o'){
    int i;
    int possible[6][2] = {{rel_srank + 1, rel_sfile - 1},
			  {rel_srank + 1, rel_sfile},
			  {rel_srank + 1, rel_sfile + 1},
			  {rel_srank, rel_sfile - 1},
			  {rel_srank, rel_sfile + 1},
			  {rel_srank-1, rel_sfile}};
    for (i = 0; i < sizeof(possible)/sizeof(possible[0]); i++){
      if (possible[i][0] == rel_drank && possible[i][1] == rel_dfile){
	return true;
      }
    }
    return false;
  }
  return false;
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
    if (isupper(dpiece)==true){
      return false;
    }
    else{
      return true;
    }
  }
  else{
    if (islower(dpiece)==true){
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
bool legaldrop(struct gm_status *game, char piece, int *dst){
  int drank = dst[0];
  int dfile = dst[1];
  int player = game->player;
  char board[9][9];
  memcpy(board, game->board, sizeof(game->board));
  
  char dpiece = board[drank][dfile];
  if (dpiece != ' '){
    return false;
  }
  else if(legaldest(game, drank, dfile)== false){
    return false;
  }
  else if(player == P1 && isupper(piece)){
      return false;
  }
  else if (islower(piece)){
      return false;
  }
  else{
    int i;
    if (player == 1){
      for (i = 0; i < 38; i++){
	if (game->graveyard.challenging[i] == piece){
	  return true;
	}
      }
      return false;
    }
    else{ //player == 2
      for (i = 0; i < 38; i++){
	if (game->graveyard.reigning[i] == piece){
	  return true;
	}
      }
      return false;
    }
    return true;
  }
}
