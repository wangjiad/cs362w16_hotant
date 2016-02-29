#include "assert.h"
#include "dominion.h"
#include "interface.c"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "interface.h"
#include "dominion_helpers.h"
#include <time.h>

void arrayShuffle(int *array, size_t n);
const char* cardName(int cardNum);

int main (int argc, char** argv) {
  //testing steward
  struct gameState *G = newGame();
  srand(time(NULL));

  int allKingdomCards[20] = {gardens, adventurer, council_room, feast, great_hall, mine, remodel, smithy, village, baron, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};

  arrayShuffle(allKingdomCards, 20);
  int k[10];
  for (int i = 0; i < 10; i++)
  		k[i] = allKingdomCards[i];

  int seed = rand();
  int i;
  int j;
  int init;
  int player;

  int playerNum = (rand() % 2) + 2;//initialize random num players

  printf("Starting Random Game Test!\n");
  printf("Number of Players: %i\n", playerNum);

  init = initializeGame(playerNum, k, seed, G);
  if (init != 0){
    printf("Initialization failed\n");
  }

  printf("Kingdom Cards Are: ");
  for (i = 0; i < 10; i++){
      printf("|%s", cardName(k[i]));
  }
  printf("\n");

  int actionFlag = 0;
  int buyResult;
  int cardToPlay;
  int handPos = 0;

  printf("--------------END INITIALIZATION----------------\n");
  while (!isGameOver(G)){
     player = whoseTurn(G);
     printf("It's player %i's turn.\n", player);
     printHand(player, G);
     printf("Number of Actions: %i\n", G->numActions);

     printf("Searching through hand for an action to play...\n");
     int x = 0;
     for (x = 0; x < G->handCount[player]; x++){
        for (i = 0; i < 10; i++){
           if(k[i] == G->hand[player][x]){
             printf("Playing an action called %s from hand position %i\n", cardName(k[i]), x);
             cardToPlay = k[i];
             handPos = x;
             actionFlag = 1;
             //break out of loops
             i = 10;
             x = G->handCount[player];
           }
        }
     }
     if (actionFlag == 1){
       playCard(handPos, 1, 1, 1, G);
     }
     //add if else to play action of not based on random

     if (actionFlag == 0){
       printf("No actions found, end action phase, start buy phase\n");
     }

     printf("Number of Buys: %i\n", G->numBuys);
     int buyPos = rand() % 10; //randomize spot to buy from
     printf("Player wants to buy %s\n", cardName(k[buyPos]));
     buyResult = buyCard(k[buyPos], G);
     if (buyResult != 0){
       printf("Buy Unsuccessful\n");
     } else {
       printf("Buy successful\n");
     }

     endTurn(G);
     //  printDeck(player, G);
     //  printDiscard(player, G);
     printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, G), scoreFor(1, G));
     printf("----------------END TURN--------------------\n");
     actionFlag = 0;
  }
  printf ("Finished game.\n");
  printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, G), scoreFor(1, G));
  printf("Kingdom Cards Are: ");
  for (i = 0; i < 10; i++){
      printf("|%s", cardName(k[i]));
  }
  printf("\n");
}

void arrayShuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

const char* cardName(int cardNum) {
	switch (cardNum) {
		case curse:
      return "Curse";
		case estate:
      return "Estate";
		case duchy:
      return "Duchy";
		case province:
      return "Province";
		case copper:
      return "Copper";
		case silver:
      return "Silver";
		case gold:
      return "Gold";
		case gardens:
      return "Gardens";
		case adventurer:
      return "Adventurer";
		case council_room:
      return "Council Room";
		case feast:
      return "Feast";
		case great_hall:
      return "Great Hall";
		case mine:
      return "Mine";
		case remodel:
      return "Remodel";
		case smithy:
      return "Smithy";
		case village:
      return "Village";
		case baron:
      return "Baron";
		case minion:
      return "Minion";
		case steward:
      return "Steward";
		case tribute:
      return "Tribute";
		case ambassador:
      return "Ambassador";
		case cutpurse:
      return "Cutpurse";
		case embargo:
      return "Embargo";
		case outpost:
      return "Outpost";
		case salvager:
      return "Salvager";
		case sea_hag:
      return "Sea Hag";
		case treasure_map:
      return "Treasure Map";
		default: return "";
	}
}
