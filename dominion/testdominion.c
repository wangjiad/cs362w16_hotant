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
  struct gameState *G = newGame();
  srand(time(NULL));
  //no f
  int allKingdomCards[20] = {gardens, adventurer, council_room, great_hall, mine, remodel, smithy, village, baron, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map}; //initialize an array of all possible kingdom cards

  arrayShuffle(allKingdomCards, 20); //shuffle it and access it 0 to 9, this is our kingdom cards for the game
  int k[10];
  for (int i = 0; i < 10; i++)
  		k[i] = allKingdomCards[i];

  int seed = rand();
  int i;
  int init;
  int player;

  int playerNum = (rand() % 3) + 2; //initialize random num players

  printf("Starting Random Game Test!\n");
  printf("Number of Players: %i\n", playerNum);

  init = initializeGame(playerNum, k, seed, G);
  if (init != 0){
    printf("Initialization failed\n");
  }

  printf("Kingdom Cards Are: "); //print out kingdom cards used in this game
  for (i = 0; i < 10; i++){
      printf("|%s", cardName(k[i]));
  }
  printf("\n");

  int actionFlag = 0; //if an action is found in hand
  int buyResult; //tracks if successful buy or not
  int cardToPlay; //keeps track of card to play
  int playChoice; //whether player decides to play action or not
  int handPos = 0; //keep track of position of card found
  int buyChoice = 0; //whether player tries to buy or not
  int numBuyAttempts; //number of attempted buys
  int ATV = 0; //action treasure or victory
  int CSG = 0; //copper silver or gold
  int EDP = 0; //estate duchy or province
  int numTurns = 0; //keep track of number of turns

  printf("-----------------[END INITIALIZATION]-----------------\n");
  while (!isGameOver(G)){ //till game is over
     player = whoseTurn(G);
     printf("It's player %i's turn.\n", player);
     printHand(player, G);
     //ACTION PHASE BEGIN
     printf("Number of Actions: %i\n", G->numActions);
     printf("Searching through hand for an action to play...\n");
     int x = 0;

     //search hand for action
     for (x = 0; x < G->handCount[player]; x++){
        for (i = 0; i < 10; i++){
           if(k[i] == G->hand[player][x]){
             printf("Found an action called %s from hand position %i\n", cardName(k[i]), x);
             cardToPlay = k[i];
             handPos = x;
             actionFlag = 1;
             //break out of loops
             i = 10;
             x = G->handCount[player];
           }
        }
     }
     //need to mess with the choices still
     if (actionFlag == 1){
       playChoice = rand() % 1; //50% chance to play or not
       if (playChoice == 0){
         printf("Player decided to play the action card\n\n");
         playCard(handPos, 0, 0, 0, G);
       } else {
         printf("Player decided to not play the action card\n\n");
       }
     }
     //if there are no action cards in the hand
     if (actionFlag == 0){
       printf("No actions found, end action phase and start buy phase\n\n");
     }

     //BUY PHASE BEGIN
     printf("Number of Buys: %i\n", G->numBuys);
     numBuyAttempts = G->numBuys;

     //probabilities
     //1 in 3 chance to either buy action/treasure/or victory card
     //1 in 3 change to try and buy copper silver or gold, same for estate duchy or province
     //1 in 2 chance to decide to attempt buy or not buy

     buyChoice = rand() % 2; //whether player tries to buy something or not
     if (buyChoice == 0) {
       printf("Player decided not to buy anything\n\n");
     } else {
       printf("Player decided to try and buy something!\n");
       while (numBuyAttempts > 0){ //while there are still buys left
         ATV = rand() % 3;
         if(ATV == 0){//try to buy an action card
           CSG = rand() % 3;//randomize whether its copper gold of silver
           if (CSG == 0){//copper chosen
             printf("Player wants to buy %s\n", cardName(4));
             buyResult = buyCard(4, G);
             if (buyResult != 0){
               printf("Buy Unsuccessful\n\n");
               numBuyAttempts--;
             } else {
               printf("Buy successful\n\n");
               numBuyAttempts--;
             }
           }else if (CSG == 1){//silver chose
             printf("Player wants to buy %s\n", cardName(5));
             buyResult = buyCard(5, G);
             if (buyResult != 0){
               printf("Buy Unsuccessful\n\n");
               numBuyAttempts--;
             } else {
               printf("Buy successful\n\n");
               numBuyAttempts--;
             }
           }else{//gold chosen
             printf("Player wants to buy %s\n", cardName(6));
             buyResult = buyCard(6, G);
             if (buyResult != 0){
               printf("Buy Unsuccessful\n\n");
               numBuyAttempts--;
             } else {
               printf("Buy successful\n\n");
               numBuyAttempts--;
             }
           }
         }else if(ATV == 1){ //try to buy a treasure card
           EDP = rand() % 3;//randomize whether its copper gold of silver
           if (CSG == 0){//estate chosen
             printf("Player wants to buy %s\n", cardName(1));
             buyResult = buyCard(1, G);
             if (buyResult != 0){
               printf("Buy Unsuccessful\n\n");
               numBuyAttempts--;
             } else {
               printf("Buy successful\n\n");
               numBuyAttempts--;
             }
           }else if (CSG == 1){//duchy chosen
             printf("Player wants to buy %s\n", cardName(2));
             buyResult = buyCard(2, G);
             if (buyResult != 0){
               printf("Buy Unsuccessful\n\n");
               numBuyAttempts--;
             } else {
               printf("Buy successful\n\n");
               numBuyAttempts--;
             }
           }else{//province chosen
             printf("Player wants to buy %s\n", cardName(3));
             buyResult = buyCard(3, G);
             if (buyResult != 0){
               printf("Buy Unsuccessful\n\n");
               numBuyAttempts--;
             } else {
               printf("Buy successful\n\n");
               numBuyAttempts--;
             }
           }
         }else{ //try to buy a kingdom card
           int buyPos = rand() % 10; //randomize spot to buy from
           printf("Player wants to buy %s\n", cardName(k[buyPos]));
           //try to buy the card
           buyResult = buyCard(k[buyPos], G);

           if (buyResult != 0){
             printf("Buy Unsuccessful\n\n");
             numBuyAttempts--;
           } else {
             printf("Buy successful\n\n");
             numBuyAttempts--;
           }
         }
       }
     }
     //  printSupply(G);
     endTurn(G);
    //  printDeck(player, G);
    //  printDiscard(player, G);
     printf ("Player 0: %d\nPlayer 1: %d\nPlayer 2: %d\nPlayer 3: %d\n", scoreFor(0, G), scoreFor(1, G),scoreFor(2, G),scoreFor(3, G));
     printf("-----------------[END TURN]-----------------\n");
     actionFlag = 0;
     numTurns++;
  }

  printf ("Finished game after %i turns.\n", numTurns);
  printf("Number of Players: %i\n", playerNum);
  printf ("Player 0: %d\nPlayer 1: %d\nPlayer 2: %d\nPlayer 3: %d\n", scoreFor(0, G), scoreFor(1, G),scoreFor(2, G),scoreFor(3, G));
  printSupply(G);

  // printf("Kingdom Cards Are: ");
  // for (i = 0; i < 10; i++){
  //     printf("|%s", cardName(k[i]));
  // }
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
