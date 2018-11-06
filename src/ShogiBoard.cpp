#include <array>
#include <vector>
#include <cstring>
#include <iostream>

class Graveyard {
  std::array<std::vector<char>, 2> gy;
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
void Graveyard::bury(int player, char piece){
  gy[player].push_back(piece);
}

class ShogiBoard {
  const char EMPTY_SQUARE = ' ';
  char *board;
  Graveyard graveyard;
public:
  ShogiBoard();
  ShogiBoard(ShogiBoard& other);
  void move(int[2], int[2]);
  void drop(int[2], char);
  bool legal_move(int src[2], int dst[2]);
  bool legal_drop(int dst[2], char piece);
  void print();
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
  std::strncpy(board, init_board, 81);
}

ShogiBoard::ShogiBoard(const ShogiBoard& other) {
  memncpy(
  
}

bool ShogiBoard::legal_move(int src[2], int dst[2]){
  int srank = src[0], sfile = src[1],
      drank = dst[0], dfile = dst[1];

  char piece = board[srank][sfile];
  eprintf("P%i with %c from %i, %i to %i, %i \n",
          player, piece, srank, sfile, drank, dfile);
 
  
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

bool ShogiBoard::legal_drop(int dst[2], char piece){
  return false;
}

void ShogiBoard::move(int src[2], int dst[2]){
  char piece = board[src[1] + 9 * src[0]];
  board[src[1] + 9 * src[0]] = EMPTY_SQUARE;
  board[dst[1] + 9 * dst[0]] = piece;
}

void ShogiBoard::drop(int dst[2], char piece){
  board[dst[1] + 9 * dst[0]] = piece;
}

void ShogiBoard::print(){
  for (int rank = 0; rank < 9; rank++){
    for (int file = 0; file < 9; file++){
      if (file == 8){
	printf("%c\n", board[file+rank*9]);
      }
      else{
	printf("%c ", board[file+rank*9]);
      }
    }
  }
}

int main(void){
  ShogiBoard sg;
  sg.print();
  int src[2] = {2, 2};
  int dst[2] = {3, 2};
  sg.move(src, dst);
  sg.print();
}
