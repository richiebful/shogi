#include <array>
#include <cstring>
#include <iostream>

class Graveyard {
  
public:
  void bury(int player, char piece);
};

/**
 * Places the given piece in the player's graveyard
 * 
 * @param player, either 0 or 1, the player id
 * @param piece, the char id of the piece captured
 *
*/
void Graveyard::bury (int player, char piece){

}

class ShogiBoard {
  const char EMPTY_SQUARE;
  char *board;
  Graveyard graveyard;

public:
  ShogiBoard();
  void move(int *, int *);
};

ShogiBoard::ShogiBoard() {
  board = new char[81];
  const char init_board[82] = {"LNGUKUGNL"
                               " R     B "
                               "PPPPPPPPP"
                               "         "
                               "         "
                               "         "
                               "ppppppppp"
                               " b     r "
                               "lngukugnl"};
std:
  strncpy(board, init_board, 81);
}

void ShogiBoard::move(int *src, int *dst) {
  char piece = board[src[1] + 9 * src[0]];
  board[src[1] + 9 * src[0]] = EMPTY_SQUARE;
  board[dst[1] + 9 * dst[0]] = piece;
}
