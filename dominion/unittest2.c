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

  printf ("\n*** Starting numHandCards & drawCard Unit Test. ***\n");
  int r = initializeGame(2, k, 123, &G);
  //assert that num cards is equal to 5
  int numCards = numHandCards(&G);
  printf("numCards: %i\n", numCards);
  assert (numCards == 5);
  //draw 1 card
  printf("Drawing a card.\n");
  drawCard(whoseTurn(&G), &G);
  //assert number of cards is now 6
  numCards = numHandCards(&G);
  printf("numCards: %i\n", numCards);
  if (numCards == 6){

    printf("Test passed\n");
  } else {
    printf("Test failed\n");

  }
  assert (r == 0);
  return 0;
}
