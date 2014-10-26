#include <shogi.h>

void dispBoard(struct gm_status *game){
  char board[9][9];
  const char convert_tbl[16][2][6]={{"王將","K"},
				    {"玉將","k"},
				    {"飛車","Rr"},
				    {"龍王","Ss"},
				    {"角行","Bb"},
				    {"龍馬","Cc"},
				    {"金将","Uu"},
				    {"銀将","Gg"},
				    {"成銀","Tt"},
				    {"桂馬","Nn"},
				    {"成桂","Oo"},
				    {"香車","Ll"},
				    {"成香","Nn"},
				    {"歩兵","Pp"},
				    {"と金","Qq"}};
  memcpy(board, game->board, sizeof(board));
  int i, j, k;
  
  for (i = 8; i >= 0; i--){
    for (j = 8; j >= 0; j--){
      char piece[6];
      if (board[i][j] == ' '){
	printf("     ");
	continue;
      }
      for (k = 0; k < sizeof(convert_tbl)/sizeof(convert_tbl[0]); k++){
	if (convert_tbl[k][1][0] == board[i][j]||
	    convert_tbl[k][1][1] == board[i][j]){
	  memcpy(piece, convert_tbl[k][0], sizeof(convert_tbl[k][0]));
	  break;
	}
      }
      if (isupper(board[i][j])){
	//print the piece out in white
	printf("\x1b[37m%s ", piece);
      }
      else{
	//print the piece out in red
	printf("\x1b[31m%s ", piece);
      }
    }
    printf("\n");
  }
  printf("Hello");
}


void dispHelp(void){
  printf("7g7f\t move from 7g to 7f\t");
  printf("quit\texit Shogi\n");
  printf("S6h\tmove Silver to 6h\t");
  printf("resign\tresign the game to your opponent\n");
  printf("2d2c+\tmove to 2c and promote\t");
  printf("show\tshows board and graveyard from your pov\n");
  printf("P*5e\tdrop pawn at 5e\t");
  printf("revert\tgo back a move, or several\n");
}

void init_game(struct gm_status *game){
  const char init_board[9][9] = {{'L','N','G','U','K','U','G','N','L'},
				 {' ','R',' ',' ',' ',' ',' ','B',' '},
				 {'P','P','P','P','P','P','P','P','P'},
				 {' ',' ',' ',' ',' ',' ',' ',' ',' '},
				 {' ',' ',' ',' ',' ',' ',' ',' ',' '},
				 {' ',' ',' ',' ',' ',' ',' ',' ',' '},
				 {'p','p','p','p','p','p','p','p','p'},
				 {' ','b',' ',' ',' ',' ',' ','r',' '},
				 {'l','n','g','u','k','u','g','n','l'}};
  memcpy(game->board,init_board,sizeof(init_board));

  game->player = 1;
  
  int i;
  for (i=0; i<38; i++){
    game->graveyard.challenging[i] = '\0';
    game->graveyard.reigning[i] = '\0';
  }
}

int main(void){
  struct gm_status game;
  init_game(&game);
  dispBoard(&game);
  return 0;
}
