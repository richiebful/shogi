#include <shogi.h>

int main(void){
  struct gm_status game;
  init_game(&game);
  bool fatal_f;
  while (fatal_f == 0){
    char[20] command = "NULL";
    int input_f = false;
    printf("Player %i:");
    while (input_f == false){
      scanf("%s", command);
      input_f = processcmd(command);
    }
  }
  return 0;  
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

