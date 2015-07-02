#include "shogi.h"

time_t updateClock(struct gm_status *game){
  struct time_s clock;
  memcpy(&clock, &game->clock, sizeof(clock));

  int p = game->player - 1;

  time_t curr_t = time(NULL);
  int diff_t = difftime(curr_t, clock.last_t);
  
  clock.player_t[p] -= (int) abs(diff_t);

  clock.last_t = curr_t;

  memcpy(&game->clock, &clock, sizeof(clock));

  return curr_t;
}

void incrementClock(struct gm_status *game){
  struct time_s clock;
  memcpy(&clock, &game->clock, sizeof(clock));

  int p = game->player - 1;

  clock.player_t[p] += clock.advance_t;
}

#ifdef CLOCK_DEBUG

int main(){

}

#endif
