#include "assert.h"
#include "dominion.h"
#include "interface.c"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define MAX_TESTS 10000

int main (int argc, char** argv) {
  //testing steward
  struct gameState G;

  int i, j, players, player, handCount, deckCount, discardCount, handPos, difference, numActions, seed, coinBefore, coinAfter, testPass, testFail;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  for (i = 0; i < MAX_TESTS; i++)
  {
    //printf("-------------------------------------\n");
    players = (rand() % 4) + 1;
		player = rand() % players;
		seed = rand();
		initializeGame(players, k, seed, &G);

    G.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		G.discardCount[player] = rand() % MAX_DECK;
		G.handCount[player] = rand() % MAX_HAND;

		//Copy state variables
		handCount = G.handCount[player];
		deckCount = G.deckCount[player];

    if (seed % 3 == 0) {
      G.deckCount[player] = 0;
    }

    int numCards = numHandCards(&G);
    //printf("numCards before: %i\n", numCards);
    cardEffect(adventurer, 0,0,0, &G ,0,0);
    int numCardsAfter = numHandCards(&G);
    //printf("numCards after: %i\n", numCardsAfter);

    if(numCardsAfter - numCards == 2){
      testPass++;
    } else testFail++;
  }
  //printf("-------------------------------------\n");
  printf("Tests passed: %i\n", testPass);
  printf("Tests fails: %i\n", testFail);
  return 0;
}
