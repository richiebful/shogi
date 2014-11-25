/**Makes the bitboard for the current game board
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
