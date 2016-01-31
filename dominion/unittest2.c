#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  //testing numHandCards/drawCard
  struct gameState G;
  struct gameState *p = &G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");
  int r = initializeGame(2, k, 123, &G);

  int numCards = numHandCards(&G);
  printf("numCards: %i\n", numCards);
  assert (numCards == 5);

  drawCard(whoseTurn(&G), &G);

  numCards = numHandCards(&G);
  printf("numCards: %i\n", numCards);

  assert (r == 0);
  return 0;
}
