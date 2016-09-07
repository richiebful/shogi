/**\file*/

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "shogi.h"

long int updateClock(struct time_s *clock, int player){
  time_t curr_t = time(NULL);
  int diff_t = difftime(curr_t, clock->last_t);
  
  clock->player_t[player - 1] -= (int) abs(diff_t);

  clock->last_t = curr_t;

  return curr_t;
}

void dispClock(struct time_s *clock, int player){
  updateClock(clock, player);

  int seconds = clock->player_t[0] % 60;
  int minutes = clock->player_t[0] / 60;

  printf("Player 1: %i:%.2i\n",  minutes, seconds);

  seconds = clock->player_t[1] % 60;
  minutes = clock->player_t[1] / 60;
  
  printf("Player 2: %i:%.2i\n\n", minutes, seconds);
	 
}

#ifdef CLOCK_DEBUG

int main(){

}

#endif
