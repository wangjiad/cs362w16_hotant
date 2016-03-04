#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  //testing smithy card
  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  printf ("\n*** Starting Smithy Unit Test. ***\n");
  int r = initializeGame(2, k, 123, &G);


  int numCards = numHandCards(&G);
  printf("numCards before: %i\n", numCards);

  //int status = smithyCard(&G, 4);
  cardEffect(smithy,0,0,0,&G,4,0);
  int numCardsAfter = numHandCards(&G);
  printf("numCards after: %i\n", numCardsAfter);
  if(numCardsAfter - numCards == 2){
    printf("Test passed\n");}
  else printf("Test failed\n");

  assert (r == 0);
  return 0;
}
