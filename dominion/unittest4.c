#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  //testing scorefor
  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  printf ("Starting scoreFor Unit Test.\n");
  int r = initializeGame(2, k, 123, &G);

  G.hand[1][0] = curse; //-1
  G.hand[1][1] = estate; //+1
  G.hand[1][2] = duchy; //+3
  G.hand[1][3] = province; //+6
  G.hand[1][4] = great_hall; //+1
  G.handCount[1] = 5;
  //total = 10
  int score = scoreFor(1,&G);
  printf("score %i\n", score);
  assert(score == 10);

  printf("Test passed\n");

  assert (r == 0);
  return 0;
}
