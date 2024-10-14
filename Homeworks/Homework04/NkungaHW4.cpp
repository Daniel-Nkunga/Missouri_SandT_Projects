/*
    Programmer: Daniel Nkunga
    Date: 09/30/2024
    File: NkungaHW4.cpp
    Assignment: Homework 4
    Purpose: This program plays a game of Blackjack between the Dealer and the
   player in completetion of Homework 4. This program currenlty has a set random
   seed for both the generation of cards and inital money the player starts with
   of 5300. This program does not actually remmber a full deck of cards and
   instead just generates a random card so hands that may not be possible in a
   real game may exist here (e.g., two Aces of Spades). Additional Notes:
        - Most prompts use "?" instead of ":" for thematic reasons
        - I believe Mr. Gonsell said he was fine with us not implementing the
   overloaded function for generating random cards but I'm not sure anymore;
   either way, that aspect of the function was not implemented
*/

#include "NkungaHW4.h"
#include <iostream>
using namespace std;

// Includes
#include <vector>

int main() {
  // Variables
  int roundCount = 1;
  string name;
  float money;
  float wager;
  vector<card> dealerHand;
  vector<card> playerHand;
  int playerAction;
  bool isInitialAction = true;
  char playAgain = 'x';
  float startingBalance;

  // Starting Message
  initializeMoney(money);
  startingBalance = money;
  cout << "\033[1;33mDealer:\033[0m Hey! Care to play a game? What's your "
          "name? \033[1;35m";
  cin >> name;
  name = "\033[1;35m" + name + "\033[0m";
  cout << "\033[1;33mDealer:\033[0m Well, " << name
       << ", I see you came to the casino with no money, but I'm feeling "
          "generous so I'll start you out with, let's say, \033[1;32m$"
       << money << "\033[0m" << endl;

  // Game Loop
  do {
    displayRound(roundCount);
    wager = getWager(money);
    // Game
    dealerHand = generateDealerHand(dealerHand);
    playerHand = generatePlayerHand(playerHand);
    displayPlayerTurn();
    playerAction = getPlayerAction(isInitialAction, money, wager);
    if (playerAction == 0) {
      while (playerAction == 0) {
        isInitialAction = false;
        hit(playerHand);
        playerAction = getPlayerAction(isInitialAction, money, wager);
      }
    } else if (playerAction == 2) {
      wager *= 2;
      hit(playerHand);
    }
    dealerTurn(dealerHand);

    cout << endl;
    roundOutcome(money, wager, dealerHand, playerHand);
    playAgain = yesNo();
    reset(dealerHand, playerHand, wager, isInitialAction);
  } while (playAgain != 'n');
  cout << endl;
  endGame(startingBalance, money);
  return 0;
}