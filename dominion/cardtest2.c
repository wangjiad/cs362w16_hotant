#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  //testing village
  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  printf ("*** Starting village Unit Test. ***\n");
  int r = initializeGame(2, k, 123, &G);
  int numActions = G.numActions;
  printf("numActions before: %i\n", numActions);

  int numCards = numHandCards(&G);
  printf("numCards before: %i\n", numCards);
  printf("Using Village card.\n");
  cardEffect(village, 0,0,0,&G,4,0);

  int numActionsAfter = G.numActions;
  printf("numActions after: %i\n", numActionsAfter);

  int numCardsAfter = numHandCards(&G);
  printf("numCards after: %i\n", numCardsAfter);
  assert(numCardsAfter == numCards);
  assert(numActionsAfter - numActions == 2);
  printf("Test passed\n");

  assert (r == 0);
  return 0;
}
