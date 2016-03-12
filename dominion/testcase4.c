#include "assert.h"
#include "dominion.h"
#include "interface.c"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  struct gameState G;

  int i, j, players, player, handCount, deckCount, discardCount, handPos, difference, numActions, seed, coinBefore, coinAfter, testPass, testFail;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  int timeseed = 1457764120;
  //passing seeds: 1457763919, 1457764029, 1457764086, 1457764120, 1457764222, 1457764246
  //failing seeds: 1457764002, 1457764064, 1457764169, 1457764183, 1457764197, 1457764270

  srand(timeseed);
  players = 2;
	player = rand() % players;
  seed = rand();

  initializeGame(players, k, seed, &G);

  G.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
	G.discardCount[player] = rand() % MAX_DECK;
	G.handCount[player] = rand() % MAX_HAND;

  for (j = 0; j < G.deckCount[player]; j++) {
    G.deck[player][j] = rand() % (treasure_map + 1);
  }
  for (j = 0; j < G.handCount[player]; j++) {
    G.hand[player][j] = rand() % (treasure_map + 1);
  }
  for (j = 0; j < G.discardCount[player]; j++) {
    G.discard[player][j] = rand() % (treasure_map + 1);
  }

  //Copy state variables
  handCount = G.handCount[player];
  deckCount = G.deckCount[player];

  //test option 1
  G.hand[player][0] = steward;

  if (seed % 3 == 0) {
    G.deckCount[player] = 0;
  }

  int numCards = numHandCards(&G);
  cardEffect(steward, 1,0,0,&G,0,0);
  int numCardsAfter = numHandCards(&G);

  if(numCardsAfter - numCards == 1){
    testPass++;
  } else {
    testFail++;
  }
  //test option 2
  G.hand[player][0] = steward;

  coinBefore = G.coins;
  cardEffect(steward, 2,0,0,&G,0,0);
  coinAfter = G.coins;

  if((coinAfter-coinBefore == 2)){
    testPass++;
  } else {
    testFail++;
  }
  //test option 3
  G.hand[player][0] = steward;

  numCards = numHandCards(&G);
  cardEffect(steward, 3,0,0,&G,0,0);
  numCardsAfter = numHandCards(&G);

  if(numCards - numCardsAfter == 3){
    testPass++;
  } else {
    testFail++;
  }

  if (testFail > 0){
    printf("F\n");
  } else {
    printf("P\n");
  }
  return 0;
}
