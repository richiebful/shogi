#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include "Moves.hpp"
#include "Shogi.hpp"

class Graveyard {
  std::array<std::vector<char>, 2> graveyard;

public:
  void bury(bool player, char piece);
};

/**
 * Places the given piece in the player's graveyard
 *
 * @param player, either 0 or 1, the player id
 * @param piece, the char id of the piece captured
 *
 */
void Graveyard::bury(bool player, char piece) {
  graveyard[player].push_back(piece);
}

class ShogiBoard {
  char *board;
  Graveyard graveyard;
  bool currPlayer;

public:
  ShogiBoard();
  ShogiBoard(const ShogiBoard& other);
  void move(int[2], int[2]);
  void drop(int[2], char);
  bool legalMove(bool player, int src[2], int dst[2], bool from_check_f);
  bool legalMove(int src[2], int dst[2]);
  bool legalUpgrade(char piece, bool player, int rank);
  bool legalDrop(int dst[2], char piece);
  bool isCheck(bool player);
  bool isMate(bool player);
  void print();

private:
  bool rookLegalMove(int src[2], int dst[2]);
  bool bishopLegalMove(int src[2], int dst[2]);
  bool lanceLegalMove(bool player, int src[2], int dst[2]);
  bool pawnLegalMove(bool player, int src[2], int dst[2], char dpiece);
  char getPiece(int loc[2]);
  bool getPieceLocation(int loc[2], char piece);
};

ShogiBoard::ShogiBoard() {
  board = new char[82];
  const char init_board[82] = {"LNGUKUGNL"
                               " R     B "
                               "PPPPPPPPP"
                               "         "
                               "         "
                               "         "
                               "ppppppppp"
                               " b     r "
                               "lngukugnl"};
  std::copy(init_board, init_board + 81, board);
  currPlayer = WHITE;
}

ShogiBoard::ShogiBoard(const ShogiBoard& other){
  board = new char[82];
  std::copy(other.board, other.board + 81, board);
  currPlayer = other.currPlayer;
}

bool ShogiBoard::legalMove(int src[2], int dst[2]){
  return legalMove(currPlayer, src, dst, false);
}

bool ShogiBoard::legalMove(bool player, int src[2], int dst[2], bool from_check_f) {
  int s_idx, d_idx;
  s_idx = src[0] * 9 + src[1];
  d_idx = dst[0] * 9 + dst[1];

  char piece = board[s_idx];
  char dpiece = board[d_idx];
#ifdef DEBUG
  printf("P%i with %c from %i, %i to %i, %i \n", player, piece, src[0], src[1], dst[0], dst[1]);
#endif

  // See if we can test for check later
  ShogiBoard test_board = *this;
  test_board.move(src, dst);
  // memcpy(&test_board, board, sizeof(test_board));
  // makeMove(test_board, blank, player, src, dst, 0); 
  
  if (legalDest(player, dpiece, dst) == false) {
    return false;
  } else if (legalSrc(player, piece, src) == false) {
    return false;
  } else if (dst[0] == src[0] && dst[1] == src[1]) {
    return false;
  } else if (from_check_f == false && test_board.isCheck(player)) {
     return false;
  } else if (piece == 'P' || piece == 'p') {
    return pawnLegalMove(player, src, dst, dpiece);
  } else if (piece == 'R' || piece == 'r') {
    return rookLegalMove(src, dst);
  } else if (piece == 'S' || piece == 's') {
    return (rookLegalMove(src, dst) ||
	    upRookLegalMove(player, src, dst));
  } else if (piece == 'B' || piece == 'b') {
    return bishopLegalMove(src, dst);
  } else if (piece == 'C' || piece == 'c') {
    return (bishopLegalMove(src, dst) ||
	    upBishopLegalMove(player, src, dst));
  } else if (piece == 'L' || piece == 'l') {
    return lanceLegalMove(player, src, dst);
  } else if (piece == 'K' || piece == 'k') {
    return kingLegalMove(player, src, dst);
  } else if (piece == 'G' || piece == 'g') {
    return silverLegalMove(player, src, dst);
  } else if (movesLikeGold(piece)) {
    return goldLegalMove(player, src, dst);
  } else {
    return false;
  }
}

bool ShogiBoard::legalDrop(int dst[2], char piece) {
  return false;
}

void ShogiBoard::move(int src[2], int dst[2]) {
  char piece = board[src[1] + 9 * src[0]];
  board[src[1] + 9 * src[0]] = EMPTY_SQUARE;
  board[dst[1] + 9 * dst[0]] = piece;
  currPlayer = !currPlayer;
}

void ShogiBoard::drop(int dst[2], char piece) {
  board[dst[1] + 9 * dst[0]] = piece;
}

void ShogiBoard::print() {
  for (int rank = 0; rank < 9; rank++) {
    for (int file = 0; file < 9; file++) {
      if (file == 8) {
	printf("%c\n", board[file + rank * 9]);
      } else {
	printf("%c ", board[file + rank * 9]);
      }
    }
  }
}

bool ShogiBoard::rookLegalMove(int src[2], int dst[2]){
  //if not moving orthogonally
  if ((!(dst[0] != src[0] && dst[1] == src[1]) &&
       !(dst[0] == src[0] && dst[1] != src[1]))){
    return false;
  }
  else if (dst[0] != src[0]){
    int rook_dir = sign(dst[0] - src[0]);
    int loc[2] = {0, src[1]};
    for (loc[0] = src[0]+rook_dir; loc[0] != dst[0]; loc[0] = loc[0]+rook_dir){
      if (getPiece(loc) != ' ') {
	return false;
      }
    }
  }
  else{
    int rook_dir = sign(dst[1] - src[1]);
    int loc[2] = {src[0], 0};
    for (loc[1] = src[1]+rook_dir; loc[1] != dst[1]; loc[1] = loc[1]+rook_dir){
      if (getPiece(loc) != ' ') {
	return false;
      }
    }
  }
  return true;
}

bool ShogiBoard::lanceLegalMove(bool player, int src[2], int dst[2]) {
  int dir = relativeDir(player);
  if (src[1] != dst[1]) {
    return false;
  } else if ((dst[0] - src[0]) * dir < 0) {
    return false;
  } else {
    int loc[2] = {0, src[1]};
    for (loc[0] = src[0] + dir; loc[0] != dst[0]; loc[0] += dir) {
      if (getPiece(loc) != ' ') {
	return false;
      }
    }
    return true;
  }
}

bool ShogiBoard::pawnLegalMove(bool player, int src[2], int dst[2], char dpiece){
  int player_dir = relativeDir(player);
  return src[0] + player_dir == dst[0] && src[1] == dst[1];
}

bool ShogiBoard::bishopLegalMove(int src[2], int dst[2]) {
#ifdef DEBUG
  std::printf("%i, %i to %i, %i", src[0], src[1], dst[0], dst[1]);
#endif
  int slope;
  int direction;
  slope = (dst[0] - src[0]) / (dst[1] - src[1]);
  if (slope != 1 && slope != -1)
    return false;
  else if (dst[1] < src[1])
    direction = -1;
  else
    direction = 1;

  int i, rankInt = src[0] - slope * src[1];
#ifdef DEBUG
  std::printf("%f*x+%i=y, %i", slope, rankInt, direction);
#endif
  for (i = src[1] + direction; i != dst[1]; i += direction) {
    if (board[(slope * i + rankInt) * 9 + i] != ' ') {
      return false;
    }
  }
  return true;
}
 
bool ShogiBoard::legalUpgrade(char piece, bool player, int rank) {
  if (player == WHITE && rank < 3 && isUpgradablePiece(piece)) {
    return true;
  } else if (player == BLACK && rank > 5 && isUpgradablePiece(piece)) {
    return true;
  } else {
    return false;
  }
}

char ShogiBoard::getPiece(int loc[2]){
  return board[loc[0] * 9 + loc[1]];
}

bool ShogiBoard::getPieceLocation(int loc[2], char piece){
  for (loc[0] = 0; loc[0] < 9; loc[0]++){
    for (loc[1] = 0; loc[1] < 9; loc[1]++){
      if (getPiece(loc) == piece){
	return true;
      }
    }
  }
  return false;
}

/**\fn ischeck
 * \param game the current game state
 * \param player, the player being evaluated for being in check
 */
bool ShogiBoard::isCheck(bool player){
  bool otherPlayer = !player;

  int dst[2];
  char king = (player == 1) ? 'k' : 'K';
  getPieceLocation(dst, king);
#ifdef DEBUG
  printf("%i, %i is king\n", dst[0], dst[1]);
#endif
  int src[2];
  for (src[0] = 0; src[0] < 9; src[0]++){
    for (src[1] = 0; src[1] < 9; src[1]++){
      if (legalMove(otherPlayer, src, dst, true)){
	return true;
      }
    }
  }
  return false;
}

//@todo currently does not undo moves properly. Write helper for this
bool ShogiBoard::isMate(bool player){
  bool otherPlayer;
  otherPlayer = currPlayer;

  /*Player must be in check to be in mate*/
  if (isCheck(otherPlayer) == false){
    return false;
  }
  /*test all possible following moves, then determine 
   *whether check still
   *exists under the new game state*/
  int src[2], dst[2];
  /*Assume checkmate until it is disproven*/
  for(src[0]= 0; src[0] < 9; src[0]++){
    for (src[1] = 0; src[1] < 9; src[1]++){
      for (dst[0] = 0; dst[0] < 9; dst[0]++){
	for (dst[1] = 0; dst[1] < 9; dst[1]++){
	  if (legalMove(player, src, dst, true) == true){
	    move(src, dst);
	    if (isCheck(player) == false){
	      return false;
	    }
	    //undo last move
	    move(dst, src);
	  }
	}
      }
    }
  }
  return true;
}

int main(void) {
  ShogiBoard sg;
  sg.print();
  
  //test that pawns can move forward onto blank
  int src[2] = {6, 2};
  int dst[2] = {5, 2};
  assert(sg.legalMove(src, dst));
  sg.move(src, dst);
  sg.print();

  int src1[2] = {0, 6};
  int dst1[2] = {1, 5};
  assert(sg.legalMove(src1, dst1));
  sg.move(src1, dst1);
  sg.print();
  
  //test that pawns can't move sideways ever
  int src2[2] = {6, 3};
  assert(sg.legalMove(src2, dst) == false);

  //ensure bishop can't move onto own team's piece
  int src3[2] = {7, 1};
  int dst3[2] = {8, 2};
  assert(sg.legalMove(src3, dst3) == false);

  //ensure bishop can't move sideways
  int src4[2] = {7, 1};
  int dst4[2] = {8, 1};
  assert(sg.legalMove(src4, dst4) == false);

  //ensure bishop can't jump over pieces
  int src4a[2] = {7, 1};
  int dst4a[2] = {1, 7};
  assert(sg.legalMove(src4a, dst4a) == false);
  sg.print();
  
  //check bishop can attack properly
  int src5[2] = {7, 1};
  int dst5[2] = {2, 6};
  assert(sg.legalMove(src5, dst5));
  sg.move(src5, dst5);
  sg.print();

  int src6[2] = {2, 3};
  int dst6[2] = {3, 3};
}
