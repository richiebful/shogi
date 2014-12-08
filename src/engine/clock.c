#include <shogi.h>

void clockUpdate(struct gm_status *game){
  //clock = game->clock
  struct time_s clock;
  memcpy(&clock, &game->clock, sizeof(clock));

  //player = existing player
  int p = game->player - 1;

  //get difference between last time and now
  time_t curr_t = time(NULL);
  time_t diff_t = difftime(curr_t, clock.last_t);
  
  //subtracts time from current player
  clock.player_t[p][1] -= (int) diff_t % 60;
  clock.player_t[p][0] -= (int) diff_t / 60;
  if (clock.player_t[p][1] < 0){
    clock.player_t[p][0]--;
    clock.player_t[p][1] = 60 + clock.player_t[p][1];
  }

  //set clock.last_t to curr_t
  clock.last_t = curr_t;
}