void dispBoard(struct gm_status *game){
  char board[9][9];
  const char convert_tbl[8][2][6]={{"王將","K "},
				   {"玉將","k "},
				   {"飛車","Rr"},
				   {"龍王","Ss"},
				   {"角行","Bb"},
				   {"龍馬","Cc"},
				   {"金将","Uu"},
				   {"銀将","Ss"},
				   {"成銀","Tt"},
				   {"桂馬","Nn"}
				   {"成桂","Oo"},
				   {"香車","Ll"},
				   {"成香","Nn"},
				   {"成香","Pp"},
				   {"と金","Qq"}}
  memcpy(board, game->board);
  int i, j, k;
  for (i = 0; i < sizeof(board)/sizeof(board[0]); i++){
    for (j = 0; j < sizeof(board[0])/sizeof(board[0][0]); j++){
      char piece[6];
      for (k = 0; k < sizeof(convert_tbl)/sizeof(convert_tbl[0]); k++){
	if (convert_tbl[k][1][0] == board[i][j]||
	    convert_tbl[k][1][1] == board[i][j]){
	  memcpy(piece, board[k][0], sizeof(board[k][0]));
	  break;
	}
      }
      if (isupper(board[i][j])==true){
	//print the piece out in white
	printf("\x1b[37m%s\t", piece);
      }
      else{
	//print the piece out in red
	printf("\x1b[31m%s\t", piece);
      }
    }
    printf("\n");
  }
  //return color to default
}
