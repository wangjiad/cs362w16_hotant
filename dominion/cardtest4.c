#include "assert.h"
#include "dominion.h"
#include "interface.c"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  //testing steward
  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  printf ("*** Starting Steward Unit Test. ***\n");
  int r = initializeGame(2, k, 123, &G);

  int numCards = numHandCards(&G);
  printf("numCards before: %i\n", numCards);
  printf("Using steward with choice = 1\n");
  cardEffect(steward, 1,0,0,&G,4,0);
  int numCardsAfter = numHandCards(&G);
  printf("numCards after: %i\n", numCardsAfter);
  assert(numCardsAfter - numCards == 1);
  printf("Test passed\n");

  printf("Coins before: %i\n", G.coins);
  printf("Using steward with choice = 2\n");
  cardEffect(steward, 2,0,0,&G,4,0);
  printf("Coins after: %i\n", G.coins);
  assert(numCardsAfter - numCards == 1);
  printf("Test passed\n");

  assert (r == 0);
  return 0;
}
