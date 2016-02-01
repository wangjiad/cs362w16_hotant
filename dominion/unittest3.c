#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  //testing isGameOver
  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  printf ("*** Starting isGameOver Unit Test. ***\n");
  int r = initializeGame(2, k, 123, &G);

  int provinceCount = G.supplyCount[province];

  //set provinces to 0
  G.supplyCount[province] = 0;
  provinceCount = G.supplyCount[province];
  assert(provinceCount == 0);

  int status = isGameOver(&G);
  //assert game is over

  assert(status == 1);
  //set supply count of all cards to 10
  int i;
  for (i = 0; i <25; i++){
      G.supplyCount[i] = 10;
      printf("Supply[%i]: %i\n", i, G.supplyCount[i]);
	}
  printf("Testing if game is over.\n");
  //assert game is not over
  status = isGameOver(&G);
  assert(status == 0);
  printf("Setting 3 stacks to 0\n");
  //set 3 supply cards to 0
  for (i = 5; i < 8; i++){
      G.supplyCount[i] = 0;
      printf("Supply[%i]: %i\n", i, G.supplyCount[i]);
  }
  printf("Testing if game is over.\n");
  //assert game is over
  status = isGameOver(&G);
  assert(status == 1);

  printf("Test passed\n");

  assert (r == 0);
  return 0;
}
