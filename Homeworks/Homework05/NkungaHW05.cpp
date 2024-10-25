/*
    Programmer: Daniel Nkunga
    Date: 21/10/2024
    File: NkungaHW05.cpp
    Assignment: Homework 5
    Purpose:
*/

#include "NkungaHW05.h"
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
  card dealerHand[20];
  card playerHand[20];
  int playerAction;
  bool isInitialAction = true;
  char playAgain = 'x';
  float startingBalance;

  // Initial Deck
  card deck[52];
  generateDeck(deck);
  shuffleDeck(deck);
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
    generateDealerHand(dealerHand, deck);
    generatePlayerHand(playerHand, deck);
    displayPlayerTurn();
    playerAction = getPlayerAction(isInitialAction, money, wager);
    if (playerAction == 0) {
      while (playerAction == 0) {
        isInitialAction = false;
        hit(playerHand, deck);
        playerAction = getPlayerAction(isInitialAction, money, wager);
      }
    } else if (playerAction == 2) {
      wager *= 2;
      hit(playerHand, deck);
    }
    dealerTurn(dealerHand);

    cout << endl;
    roundOutcome(money, wager, dealerHand, playerHand);
    playAgain = yesNo();
    reset(wager, isInitialAction, deck, playerHand, dealerHand);
  } while (playAgain != 'n');
  cout << endl;
  endGame(startingBalance, money);
  return 0;
}
