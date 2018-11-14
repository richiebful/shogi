#include <cctype>
#include <cmath>
#include <cstdio>
#include "Shogi.hpp"

int relativeDir(int player);

using namespace std;

bool inRange(int loc[2]){
  for (int i = 0; i < 2; i++){
    if (loc[i] > 8 || loc[i] < 0){
      return false;
    }
  }
  return true;
}

bool legalSrc(int player, char piece, int loc[2]){
  if (inRange(loc) == false){
#ifdef DEBUG
    printf("rangeFail");
#endif
    return false;
  }
  else if (player == WHITE && islower(piece)){
    return true;
  }
  else if (player == BLACK && isupper(piece)){
    return true;
  }
  else{
    return false;
  }
}

bool legalDest(int player, char piece, int loc[2]){
  if (inRange(loc) == false){
    return false; 
  }
  else if ((player == WHITE && isupper(piece)) || piece == ' '){
    return true;
  }
  else if ((player == BLACK && islower(piece)) || piece == ' '){
    return true;
  }
  else{
    return false;
  }
}

bool kingLegalMove(int player, int src[2], int dst[2]) {
  int possible[8][2] = {{src[0] + 1, src[1] + 1}, {src[0] + 1, src[1]},
                        {src[0] + 1, src[1] - 1}, {src[0], src[1] + 1},
                        {src[0], src[1] - 1},     {src[0] - 1, src[1] + 1},
                        {src[0] - 1, src[1]},     {src[0] - 1, src[1] - 1}};
  uint i;
  for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++)
    if (possible[i][0] == dst[0] && possible[i][1] == dst[1])
      return true;
  return false;
}

bool silverLegalMove(int player, int src[2], int dst[2]) {
  int rel_dir = relativeDir(player);
  int possible[5][2] = {{src[0] + rel_dir, src[1] - 1},
                        {src[0] + rel_dir, src[1]},
                        {src[0] + rel_dir, src[1] + 1},
                        {src[0] - rel_dir, src[1] - 1},
                        {src[0] - rel_dir, src[1] + 1}};
  uint i;
  for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++) {
    if (possible[i][0] == dst[0] && possible[i][1] == dst[1]) {
      return true;
    }
  }
  return false;
}

/**
 * \fn relativeDir
 * Determines the direction of the player, up or down, for lances/pawns
 * \param player the player making the move
 * \return -1 for down, 1 for up
 */
int relativeDir(int player) { return (player == BLACK) ? 1 : -1; }

/**
 * \fn movesLikeGold
 * Tells whether a piece moves like it is a gold general.
 */
bool movesLikeGold(char piece) {
  piece = std::tolower(piece);
  return (piece == 'u' || piece == 'h' ||
	  piece == 'q' || piece == 'm' ||
          piece == 'o');
}

/**
 *
 */
bool goldLegalMove(int player, int src[2], int dst[2]) {
  int rel_dir = relativeDir(player);
  int possible[6][2] = {{src[0] + rel_dir, src[1] - 1},
			{src[0] + rel_dir, src[1]},
                        {src[0] + rel_dir, src[1] + 1},
			{src[0], src[1] - 1},
                        {src[0], src[1] + 1},
			{src[0] - rel_dir, src[1]}};
  uint i;
  for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++) {
    if (possible[i][0] == dst[0] && possible[i][1] == dst[1]) {
      return true;
    }
  }
  return false;
}

bool upRookLegalMove(int player, int src[2], int dst[2]){
  int possible[4][2] = { {src[0] + 1, src[1]},
			 {src[0] - 1, src[1]},
			 {src[0], src[1] + 1},
			 {src[0], src[1] - 1} };
  uint i;
  for (i = 0; i < sizeof(possible)/sizeof(possible[0]); i++){
    if (possible[i][0] == dst[0] && possible[i][1] == dst[1]){
      return true;
    }
  }
  return false;
}

bool upBishopLegalMove(int player, int src[2], int dst[2]){
  int  possible[4][2] = { {src[0] + 1, src[1]},
			  {src[0] - 1, src[1]},
			  {src[0], src[1] + 1},
			  {src[0], src[1] - 1} };
  uint i;
  for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++)
    if (possible[i][0] == dst[0] && possible[i][1] == dst[1])
      return true;
  return false;
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

int sign(int value){
  return value / abs(value);
}
