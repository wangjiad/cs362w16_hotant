#include "assert.h"
#include "dominion.h"
#include "interface.c"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define MAX_TESTS 1

int main (int argc, char** argv) {
  //testing steward
  struct gameState G;

  int i, j, players, player, handCount, deckCount, discardCount, handPos, difference, numActions, seed, coinBefore, coinAfter, testPass, testFail;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  printf ("*** Starting Steward Random Tester ***\n");
  for (i = 0; i < MAX_TESTS; i++)
  {

    int timeseed = time(NULL);
    srand(timeseed);
    //printf("-------------------------------------\n");
    players = 2;
		player = rand() % players;
    seed = rand();
    printf("timeseed: %i\n", timeseed);
    printf("players: %i\n", players);
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

    G.hand[player][0] = steward;

		//Copy state variables
		handCount = G.handCount[player];
		deckCount = G.deckCount[player];

    if (seed % 3 == 0) {
      G.deckCount[player] = 0;
    }

    int numCards = numHandCards(&G);
    //printf("numCards before: %i\n", numCards);
    //printf("Using steward with choice = 1\n");
    cardEffect(steward, 1,0,0,&G,0,0);
    int numCardsAfter = numHandCards(&G);
    //printf("numCards after: %i\n", numCardsAfter);
    if(numCardsAfter - numCards == 1){
      printf("-------------PASS1---------\n");
      printf("timeseed: %i\n", timeseed);
      printf("players: %i\n", players);
      printf("player turn: %i\n", player);
      printf("numCards before: %i\n", numCards);
      printf("Using steward with choice = 1\n");
      printf("numCards after: %i\n", numCardsAfter);
      testPass++;
      printf("----------------------\n");
    } else {
      printf("------------FAIL1----------\n");
      printf("timeseed: %i\n", timeseed);
      printf("players: %i\n", players);
      printf("player turn: %i\n", player);
      printf("numCards before: %i\n", numCards);
      printf("Using steward with choice = 1\n");
      printf("numCards after: %i\n", numCardsAfter);
      testFail++;
      printf("----------------------\n");
    }
    //printf("*************\n");
    numCards = numHandCards(&G);
    //printf("numCards before: %i\n", numCards);
    numCardsAfter = numHandCards(&G);
    //printf("numCards after: %i\n", numCardsAfter);

    G.hand[player][0] = steward;

    //printf("Coins before: %i\n", G.coins);
    coinBefore = G.coins;
    //printf("Using steward with choice = 2\n");
    cardEffect(steward, 2,0,0,&G,0,0);
    coinAfter = G.coins;
    //printf("Coins after: %i\n", G.coins); (numCardsAfter == numCards)
    if((coinAfter-coinBefore == 2)){
      printf("------------PASS2----------\n");
      printf("timeseed: %i\n", timeseed);
      printf("players: %i\n", players);
      printf("player turn: %i\n", player);
      printf("coin before: %i\n", coinBefore);
      printf("Using steward with choice = 1\n");
      printf("coin after: %i\n", coinAfter);
      testPass++;
      printf("----------------------\n");
    } else {
      printf("------------FAIL2----------\n");
      printf("timeseed: %i\n", timeseed);
      printf("players: %i\n", players);
      printf("player turn: %i\n", player);
      printf("Coins before: %i\n", coinBefore);
      printf("Using steward with choice = 2\n");
      printf("Coins after: %i\n", coinAfter);
      testFail++;
      printf("----------------------\n");
    }
    //printf("Test passed\n");

    G.hand[player][0] = steward;

    //printf("*************\n");
    numCards = numHandCards(&G);
    //printf("numCards before: %i\n", numCards);
    //printf("Using steward with choice = 3\n");
    cardEffect(steward, 3,0,0,&G,0,0);
    numCardsAfter = numHandCards(&G);
    //printf("numCards after: %i\n", numCardsAfter);
    if(numCards - numCardsAfter == 3){
      printf("------------PASS3----------\n");
      printf("timeseed: %i\n", timeseed);
      printf("players: %i\n", players);
      printf("player turn: %i\n", player);
      printf("numCards before: %i\n", numCards);
      printf("Using steward with choice = 3\n");
      printf("numCards after: %i\n", numCardsAfter);
      testPass++;
      printf("----------------------\n");
    } else {
      printf("------------FAIL3----------\n");
      printf("timeseed: %i\n", timeseed);
      printf("players: %i\n", players);
      printf("player turn: %i\n", player);
      printf("numCards before: %i\n", numCards);
      printf("Using steward with choice = 3\n");
      printf("numCards after: %i\n", numCardsAfter);
      testFail++;
      printf("----------------------\n");
    }
  }
  //printf("-------------------------------------\n");
  printf("Tests passed: %i\n", testPass);
  printf("Tests fails: %i\n", testFail);
  return 0;
}
