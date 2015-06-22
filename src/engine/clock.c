#include <shogi.h>

time_t updateClock(struct gm_status *game){
  struct time_s clock;
  memcpy(&clock, &game->clock, sizeof(clock));

  //player = existing player - 1 for array dim purposes
  int p = game->player - 1;

  //get difference between last time and now
  time_t curr_t = time(NULL);
  int diff_t = difftime(curr_t, clock.last_t);
  
  //subtracts time from current player
  clock.player_t[p] -= (int) abs(diff_t);

  //set clock.last_t to curr_t
  clock.last_t = curr_t;

  //transfer clock back to its rightful position
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
