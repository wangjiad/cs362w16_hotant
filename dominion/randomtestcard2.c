#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1000

int main() {
  int i;

  for (i = 0; i<MAX_TESTS; i++){
    players = rand() % 4;
    seed = rand();		//pick random seed
    initializeGame(players, k, seed, &state);	//initialize Gamestate
    return 0;
  }
}
