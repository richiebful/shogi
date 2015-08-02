/** \file */
#include "shogi.h"

int rel_dir_gen(int player){
  return (player == REIGNING) ? 1 : -1;
}

int movesLikeGold(char piece){
  return (piece == 'U' || piece == 'u' ||
	  piece == 'H' || piece == 'h' ||
	  piece == 'Q' || piece == 'q' ||
	  piece == 'M' || piece == 'm' ||
	  piece == 'O' || piece == 'o');
}

int goldLegalMove(struct gm_status *game,
		  int player, int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  int rel_dir = rel_dir_gen(player);
  int possible[6][2] = { {srank + rel_dir, sfile - 1},
			 {srank + rel_dir, sfile},
			 {srank + rel_dir, sfile + 1},
			 {srank,           sfile - 1},
			 {srank,           sfile + 1},
			 {srank - rel_dir, sfile} };
  int i;
  for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++) {
    if (possible[i][0] == drank && possible[i][1] == dfile) {
      return true;
    }
  }
  return false;
}

int silverLegalMove(struct gm_status *game,
		    int player, int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  int rel_dir = rel_dir_gen(player);
  int  possible[5][2] = { {srank + rel_dir, sfile - 1},
			  {srank + rel_dir, sfile},
			  {srank + rel_dir, sfile + 1},
			  {srank - rel_dir, sfile - 1},
			  {srank - rel_dir, sfile + 1}	};
  int  i;
  for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++) {
    if (possible[i][0] == drank && possible[i][1] == dfile) {
      return true;
    }
  }
  return false;
}

int kingLegalMove(struct gm_status *game,
		  int player, int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  int possible[8][2] = { {srank + 1, sfile + 1},
			 {srank + 1, sfile},
			 {srank + 1, sfile - 1},
			 {srank, sfile + 1},
			 {srank, sfile - 1},
			 {srank - 1, sfile + 1},
			 {srank - 1, sfile},
			 {srank - 1, sfile - 1} };
  int i;
  for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++)
    if (possible[i][0] == drank && possible[i][1] == dfile)
      return true;
  return false;
}

int lanceLegalMove(struct gm_status *game,
		   int player, int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  int direction = rel_dir_gen(player);
  if (sfile != dfile){
    return false; 
  }
  else if ((drank - srank) * direction < 0){
    return false;
  }
  else{
    int i;
    for (i = srank + direction; i != drank; i += direction) {
      if (game->board[sfile][i] != ' '){
	return false;
      }
    }
    return true;
  }
}

/**This has major errors in the upgrade handling mechanism*/
int bishopLegalMove(struct gm_status *game,
		    int player, int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  double slope, direction;
  slope = (drank - srank) / (dfile - sfile);
  if (slope != 1 && slope != -1)
    return false;
  else if (dfile < sfile)
    direction = -1;
  else
    direction = 1;
  
  int i,  yInt = srank - slope * sfile;
  for (i = sfile + direction; i != dfile; i += direction) {
     if (game->board[(int) slope * i + yInt][i] != ' ') {
      return false;
    }
  }
  return true;
}

int upBishopLegalMove(struct gm_status *game,
		      int player, int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  int  possible[4][2] = { {srank + 1, sfile},
			  {srank - 1, sfile},
			  {srank, sfile + 1},
			  {srank, sfile - 1} };
  int i;
  for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++)
    if (possible[i][0] == drank && possible[i][1] == dfile)
      return true;
  return false;
}

int rookLegalDirection(int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  return ((drank != srank && dfile == sfile) ||
	  (drank == srank && dfile != sfile));
}

int rookLegalMove(struct gm_status *game,
		  int player, int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  int i;
  char board[9][9];
  memcpy(board, game->board, sizeof(board));
  if (rookLegalDirection(src, dst)){
    return false;
  }
  else if (drank > srank){
    for (i = srank + 1; i != drank; ++i){
      if (board[i][sfile] != ' ') {
	return false;
      }
    }
  }
  else if (drank < srank){
    for (i = srank - 1; i != drank; --i){
      if (board[i][sfile] != ' '){ 
	return false;
      }
    }
  }
  else if (dfile > sfile){
    for (i = sfile + 1; i != dfile; ++i){
      if (board[srank][i] != ' '){
	return false;
      }
    }
  }
  else{
    for (i = sfile - 1; i != dfile; --i){
      if (board[srank][i] != ' '){
	return false;
      }
    }
  }
  return true;
}

int upRookLegalMove(struct gm_status *game,
		    int player, int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  int  possible[4][2] = { {srank + 1, sfile},
			  {srank - 1, sfile},
			  {srank, sfile + 1},
			  {srank, sfile - 1} };
  int  i;
  FOREACH(possible, i){
    if (possible[i][0] == drank && possible[i][1] == dfile){
      return true;
    }
  }
  return false;
}

int pawnLegalMove(struct gm_status *game,
		  int player, int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  int rel_dir = rel_dir_gen(player);
  if (srank + rel_dir == drank && sfile == dfile){
    return true;
  }
  else{
    return false;
  }
}

int legalmove(struct gm_status *game, int player,
	      int *src, int *dst, int from_check_f){
  int srank = src[0], sfile = src[1],
      drank = dst[0], dfile = dst[1];

  char board[9][9];
  memcpy(board, game->board, sizeof(board));
  char piece = board[srank][sfile];
  eprintf("%c from %i, %i to %i, %i",
          piece, srank, sfile, drank, dfile);
  
  struct gm_status test_game;
  memcpy(&test_game, game, sizeof(test_game));

  if (legaldest(game, player, dst[0], dst[1]) == false){
    eprintf("Dst fail\n");
    return false;
  }
  else if (legalsrc(game, player, src[0], src[1]) == false){
    eprintf("Src fail\n");
    return false;
  }
  else if (drank == srank && dfile == sfile){
    eprintf("equality fail\n");
    return false;
  }
  else if (from_check_f == false && ischeck(&test_game, player)){
    eprintf("Check fail\n");
    return false;
  }
  else if (piece == 'P' || piece == 'p'){
    eprintf("gets to pawn\n");
    return pawnLegalMove(game, player, src, dst);
  }
  else if (piece == 'R' || piece == 'r'){
    return rookLegalMove(game, player, src, dst);
  }
  else if (piece == 'S' || piece == 's'){
    return (rookLegalMove(game, player, src, dst)||
	    upRookLegalMove(game, player, src, dst));
  }
  else if (piece == 'B' || piece == 'b'){
    return bishopLegalMove(game, player, src, dst);
  }
  else if (piece == 'C' || piece == 'c'){
    return (bishopLegalMove(game, player, src, dst) ||
	    upBishopLegalMove(game, player, src, dst));
  }
  else if (piece == 'L' || piece == 'l'){
    return lanceLegalMove(game, player, src, dst);
  }
  else if (piece == 'K' || piece == 'k'){
    return kingLegalMove(game, player, src, dst);
  }
  else if (piece == 'G' || piece == 'g'){
    return silverLegalMove(game, player, src, dst);
  }
  else if (movesLikeGold(piece)){
    return goldLegalMove(game, player, src, dst);
  }
  else{
    return false;
  }
}

int inrange(int rank, int file){
    if (rank > 8 || rank < 0 || file > 8 || file < 0){
      return false;
    }
    else{
      return true;
    }
}

int legaldest(struct gm_status *game, int player, int rank, int file){
  char dpiece = game->board[rank][file];
  if (inrange(rank, file) == false){
    return false; 
  }
  else if ((player == P1 && isupper(dpiece)) || dpiece == ' '){
    return true;
  }
  else if ((player == P2 && islower(dpiece)) || dpiece == ' '){
    return true;
  }
  else{
    return false;
  }
}

int legalsrc(struct gm_status *game, int player, int rank, int file){
  char spiece = game->board[rank][file];
  if (inrange(rank, file) == false){
    return false;
  }
  else if (player == P1 && islower(spiece)){
    return true;
  }
  else if (player == P2 && isupper(spiece)){
    return true;
  }
  else{
    return false;
  }
}

int legalDropPiece(player, piece){
  if (isupper(piece) && player == 2){
    return true;
  }
  else if (islower(piece) && player == 1){
    return true;
  }
  else{
    return false;
  }
}

int inGraveyard(struct gm_status *game, int player, char piece){
  int i,  graveyard[38];
  memcpy(graveyard, game->graveyard[player], sizeof(graveyard));
  FOREACH(graveyard, i) {
    if (graveyard[i] == piece) {
      return true;
    }
  }
  return false;
}

int legaldrop(struct gm_status *game, int player, char piece, int *dst){
  int drank = dst[0];
  int dfile = dst[1];
  char board[9][9];
  memcpy(board, game->board, sizeof(game->board));
  char dpiece = board[drank][dfile];
  if (dpiece != ' ') {
    return false;
  } 
  else if (legaldest(game, player, drank, dfile) == false) {
    return false;
  }
  else if (legalDropPiece(player, piece) == false){
    return false;
  }
  else{
    return inGraveyard(game, player, piece);
  }
}

bool isUpgradablePiece(char piece){
  piece = tolower(piece);
  return (piece == 'g' || piece == 'r'||
          piece == 'b' || piece == 'p'||
          piece == 'n' || piece == 'l');
}

bool isUpgradedPiece(char piece){
  piece = tolower(piece);
  return (piece == 'h' || piece == 's' ||
          piece == 'c' || piece == 'q' ||
          piece == 'o' || piece == 'm');
}

bool legalUpgrade(struct gm_status *game, int player, int *coords){
  int rank = coords[0];
  char piece = game->board[rank][coords[1]];
  if (player == 1 && rank < 5 && isUpgradablePiece(piece)){
    return true;
  }
  else if (player == 2 && rank > 3 && isUpgradablePiece(piece)){
    return true;
  }
  else{
    return false;
  }
}

#ifdef LEGAL_TEST
int main(void){
  struct gm_status game;
  init_game(&game);
  int legal_f = 0, i;
  // of form {{{srank,sfile},{drank,dfile}},...}
  int trueCases[10][2][2];
  int falseCases[1][2][2] = { {{7, 1}, {8, 4}} };
  int srank, sfile, drank, dfile;
  FOREACH(trueCases, i) {
    srank = trueCases[i][0][0];
    sfile = trueCases[i][0][1];
    drank = trueCases[i][1][0];
    dfile = trueCases[i][1][1];
    legal_f = legalmove(&game, 1, trueCases[i][0], trueCases[i][1]);
    printf("%i,%i to %i,%i -> %i", srank, sfile, drank, dfile,
	   legal_f);
  }
  FOREACH(falseCases, i) {
    srank = falseCases[i][0][0];
    sfile = falseCases[i][0][1];
    drank = falseCases[i][1][0];
    dfile = falseCases[i][1][1];
    legal_f = legalmove(&game, 1,
                        falseCases[i][0], falseCases[i][1]);
    printf("%i,%i to %i,%i returns %i\n", srank, sfile,
           drank, dfile, legal_f);
  }
  return 0;
}

#endif
