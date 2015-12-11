/** \file */
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "shogi.h"

/**
 * \fn rel_dir_gen
 * Determines the direction of the player, up or down, for lances/pawns
 * \param player the player making the move
 * \return -1 for down, 1 for up
 */
int rel_dir_gen(int player){
  return (player == 1) ? -1 : 1;
}

/**
 * \fn movesLikeGold
 * Tells whether a piece moves like it is a gold general.
 */
bool movesLikeGold(char piece){
  piece = tolower(piece); 
  return (piece == 'u' || piece == 'h' ||
	  piece == 'q' || piece == 'm' ||
	  piece == 'o');
}

/**
 *
 */
int goldLegalMove(int player, int *src, int *dst){
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

int silverLegalMove(int player, int *src, int *dst){
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

int kingLegalMove(int player, int *src, int *dst){
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

int lanceLegalMove(char board[9][9],
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
      if (board[sfile][i] != ' '){
	return false;
      }
    }
    return true;
  }
}

int bishopLegalMove(char board[9][9],
		    int player, int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  eprintf("%i, %i to %i, %i", srank, sfile, drank, dfile);
  float slope;
  int direction;
  slope = (float) (drank - srank) / (dfile - sfile);
  if (slope != 1 && slope != -1)
    return false;
  else if (dfile < sfile)
    direction = -1;
  else
    direction = 1;
  
  int i,  rankInt = srank - slope * sfile;
  eprintf("%f*x+%i=y, %i", slope, rankInt, direction);
  for (i = sfile + direction; i != dfile; i += direction){
    if (board[(int)slope * i + rankInt][i] != ' '){
       return false;
    }
  }
  eprintf("Bishop returns true\n");
  return true;
}

int upBishopLegalMove(int player, int *src, int *dst){
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

int rookLegalMove(char board[9][9],
		  int player, int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  int i;
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

int upRookLegalMove(int player, int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  int  possible[4][2] = { {srank + 1, sfile},
			  {srank - 1, sfile},
			  {srank, sfile + 1},
			  {srank, sfile - 1} };
  int  i;
  for (i = 0; i < sizeof(possible)/sizeof(possible[0]); i++){
    if (possible[i][0] == drank && possible[i][1] == dfile){
      return true;
    }
  }
  return false;
}

int pawnLegalMove(int player, int *src, int *dst){
  int srank = src[0], sfile = src[1],
    drank = dst[0], dfile = dst[1];
  int rel_dir = rel_dir_gen(player);
  eprintf("%i from %i, %i to %i, %i\n", player, srank, sfile, drank, dfile);
  return srank + rel_dir == drank && sfile == dfile;
}

int gmLegalMove(struct gm_status *game, int *src, int *dst){
  return legalMove(game->board, game->player, src, dst, false);
}

int legalMove(char board[9][9], int player,
	      int *src, int *dst, int from_check_f){
  int srank = src[0], sfile = src[1],
      drank = dst[0], dfile = dst[1];

  char piece = board[srank][sfile];
  eprintf("P%i with %c from %i, %i to %i, %i \n",
          player, piece, srank, sfile, drank, dfile);
 
  char test_board[9][9];
  char blank[2][38];
  memcpy(&test_board, board, sizeof(test_board));
  makeMove(test_board, blank, player, src, dst, 0);

  if (legaldest(board, player, dst[0], dst[1]) == false){
    return false;
  }
  else if (legalsrc(piece, player, src[0], src[1]) == false){
    return false;
  }
  else if (drank == srank && dfile == sfile){
    return false;
  }
  else if (from_check_f == false && ischeck(test_board, player)){
    return false;
  }
  else if (piece == 'P' || piece == 'p'){
    eprintf("trigger pawn %i \n", pawnLegalMove(player, src, dst));
    return pawnLegalMove(player, src, dst);
  }
  else if (piece == 'R' || piece == 'r'){
    return rookLegalMove(board, player, src, dst);
  }
  else if (piece == 'S' || piece == 's'){
    return (rookLegalMove(board, player, src, dst)||
	    upRookLegalMove(player, src, dst));
  }
  else if (piece == 'B' || piece == 'b'){
    return bishopLegalMove(board, player ,src, dst);
  }
  else if (piece == 'C' || piece == 'c'){
    return (bishopLegalMove(board, player, src, dst) ||
	    upBishopLegalMove(player, src, dst));
  }
  else if (piece == 'L' || piece == 'l'){
    return lanceLegalMove(board, player, src, dst);
  }
  else if (piece == 'K' || piece == 'k'){
    return kingLegalMove(player, src, dst);
  }
  else if (piece == 'G' || piece == 'g'){
    return silverLegalMove(player, src, dst);
  }
  else if (movesLikeGold(piece)){
    return goldLegalMove(player, src, dst);
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

int legaldest(char board[9][9], int player, int rank, int file){
  char dpiece = board[rank][file];
  if (inrange(rank, file) == false){
    return false; 
  }
  else if ((player == 1 && isupper(dpiece)) || dpiece == ' '){
    return true;
  }
  else if ((player == 2 && islower(dpiece)) || dpiece == ' '){
    return true;
  }
  else{
    return false;
  }
}

int legalsrc(char piece, int player, int rank, int file){
  if (inrange(rank, file) == false){
    printf("rangeFail");
    return false;
  }
  else if (player == 1 && islower(piece)){
    return true;
  }
  else if (player == 2 && isupper(piece)){
    return true;
  }
  else{
    return false;
  }
}

int inGraveyard(char graveyard[2][38], int player, char piece){
  int i;
  for(i = 0; i < sizeof(graveyard[0])/sizeof(char); i++) {
    if (graveyard[player][i] == piece) {
      return true;
    }
  }
  return false;
}

int legaldrop(char board[9][9], char graveyard[2][38],
	      int player, char piece, int *dst){
  int drank = dst[0];
  int dfile = dst[1];
  char dpiece = board[drank][dfile];
  printf("%c*(%i, %i)", piece, drank, dfile);
  if (dpiece != ' ') {
    return false;
  }
  else{
    return inGraveyard(graveyard, player, piece);
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

bool legalUpgrade(char board[9][9], char piece, int player, int rank){
  eprintf("R:%i, Piece:%c, Player:%i", rank, piece, player);
  if (player == 1 && rank < 3 && isUpgradablePiece(piece)){
    return true;
  }
  else if (player == 2 && rank > 5 && isUpgradablePiece(piece)){
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
