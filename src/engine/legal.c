#include <shogi.h>

/*Returns true if move is legal, false if not
 *Coordinates must be in absolute terms
 */
bool isLegalMove(struct gm_status *game, int *src, int *dst){
  int srank = src[0];
  int sfile = src[1];
  int drank = dst[0];
  int dfile = dst[1];
  return true;
}

/*Returns true if drop is legal, false if not
 *Coordinates must be in absolute terms
 */
bool isLegalDrop(struct gm_status *game, int *dst){
  int drank = dst[0];
  int dfile = dst[1];
}
