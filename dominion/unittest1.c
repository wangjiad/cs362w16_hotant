#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  //testing Supply count
  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");
  int goldSupply = 0;
  int r = initializeGame(2, k, 123, &G);

  goldSupply = G.supplyCount[gold] = 5;

  assert (goldSupply == 5);
  printf("Gold Supply is: %i\n", goldSupply);
  assert (r == 0);
  return 0;
}
