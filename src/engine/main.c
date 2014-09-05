#include <shogi.h>

struct droppable{
  char challenging[38];
  char reigning[38];
};
  
struct gm_status{
  char board[9][9];
  int player;
  struct droppable graveyard;
  bool check;
};

void init_game(struct gm_status *game);

int main(void){
  struct gm_status game;
  init_game(&game);
  printf("%c",game.board[0][0]);
  return 0;  
}

void init_game(struct gm_status *game){
  const char init_board[9][9] = {{'L','N','G','A','K','A','G','N','L'},
				 {' ','R',' ',' ',' ',' ',' ','B',' '},
				 {'P','P','P','P','P','P','P','P','P'},
				 {' ',' ',' ',' ',' ',' ',' ',' ',' '},
				 {' ',' ',' ',' ',' ',' ',' ',' ',' '},
				 {' ',' ',' ',' ',' ',' ',' ',' ',' '},
				 {'p','p','p','p','p','p','p','p','p'},
				 {' ','b',' ',' ',' ',' ',' ','r',' '},
				 {'l','n','g','a','k','a','g','n','l'}};
  memcpy(game->board,init_board,sizeof(init_board));

  game->player = 1;
  
  int i;
  for (i=0; i<38; i++){
    game->graveyard.challenging[i] = '\0';
    game->graveyard.reigning[i] = '\0';
  }
}
