#ifndef NKUNGA
#define NKUNGA

#include <iostream>
#include <vector>
using namespace std;

// Structures
/* card
    Description: Represents a playing card with a display name (e.g., "Ace",
   "King"), a suit (e.g., "Hearts", "Spades"), and a value (numerical
   representation of the card).
*/
struct card {
  string displayName;
  string suit;
  int value;
};

// Functions in Main
/* Initialize Money
    Description: Starts the player with a random amount of money between $12.00
   and $7,000.00. Precondition: N/A Postcondition:
        - Returns a random float between 12.00 and 7,000.00 rounded to two
   decimal places.
*/
void initializeMoney(float &money);

/* Display Round
    Description: Displays a graphic showing which round/hand the player is on.
    Precondition: N/A
    Postcondition:
        - Outputs a string displaying which round the player is on.
*/
void displayRound(int &roundCount);

/* Get Wager
    Description: Prompts the player for a wager and validates the input.
    Precondition:
        - money: A float variable representing the player's current balance.
    Postcondition:
        - Prompts the player for the amount they want to wager.
        - Repeats prompt until valid input is received.
*/
float getWager(float money);

/* Generate Dealer Hand
    Description: Creates a vector of two cards representing the dealer's hand.
   Reveals the dealer's first card and hides the second. Precondition:
        - dealerHand: An empty vector of cards.
    Postcondition:
        - Fills dealerHand with two newly generated cards.
*/
vector<card> generateDealerHand(vector<card> &dealerHand);

/* Generate Player Hand
    Description: Creates a vector of two cards representing the player's hand
   and displays both cards. Precondition:
        - playerHand: An empty vector of cards.
    Postcondition:
        - Fills playerHand with two newly generated cards.
*/
vector<card> generatePlayerHand(vector<card> &playerHand);

/* Display Player Turn
    Description: Displays a graphic indicating it is the player's turn.
    Precondition: N/A
    Postcondition:
        - Outputs a string showing it is the player's turn to act.
*/
void displayPlayerTurn();

/* Get Player Action
    Description: Prompts the player to choose an action (hit, stand, or double
   down) and validates the input. Precondition:
        - isInitialAction: A boolean indicating if this is the player's first
   action of the turn, allowing the option to double down.
        - money: A float representing the player's current balance.
        - wager: A float representing the current wager.
    Postcondition: Returns an integer representing the player's choice:
        - 0: The player chooses to hit.
        - 1: The player chooses to stand.
        - 2: The player chooses to double down, available only if
   isInitialAction is true.
*/
int getPlayerAction(bool isInitialAction, float money, float wager);

/* Hit
    Description: Adds a new card to the player's hand.
    Precondition:
        - hand: A vector of cards with two or more cards.
    Postcondition:
        - Adds a newly generated card to the hand.
        - Displays all cards in the hand and their total value.
*/
int hit(vector<card> &hand);

/* Dealer Turn
    Description: Forces the dealer to keep hitting until their hand value
   reaches 17 or more. Precondition:
        - dealerHand: A vector of cards with two or more cards.
    Postcondition:
        - Displays the dealer's full hand.
        - Adds any newly generated cards to dealerHand as needed.
*/
void dealerTurn(vector<card> &dealerHand);

/* Round Outcome
    Description: Displays the outcome of the round based on the dealer's and
   player's hands, and updates game statistics. Precondition:
        - money: A float representing the player's current balance.
        - wager: A float representing the current wager.
        - dealerHand: A vector of two or more cards.
        - playerHand: A vector of two or more cards.
    Postcondition:
        - Displays the round's outcome and any changes to the player's balance.
        - Updates relevant game statistics (e.g., number of wins, blackjacks,
   etc.).
*/
void roundOutcome(float &money, float wager, vector<card> dealerHand,
                  vector<card> playerHand);

/* Yes/No Prompt
    Description: Prompts the player to answer a yes or no question, returning
   their response as a char. Precondition: N/A Postcondition:
        - Returns the player's input (either 'y' or 'n').
*/
char yesNo();

/* Reset
    Description: Resets the dealer's and player's hands, the wager, and the
   action state for the next round. Precondition:
        - dealerHand: A vector of cards with two or more cards.
        - playerHand: A vector of cards with two or more cards.
        - wager: A float representing the current wager.
        - isInitialAction: A boolean indicating if this is the player's first
   action of the turn. Postcondition:
        - Clears the dealerHand and playerHand.
        - Sets the wager to 0.
        - Resets isInitialAction to true.
*/
void reset(vector<card> &dealerHand, vector<card> &playerHand, float &wager,
           bool &isInitialAction);

/* End Game
    Description: Displays the final game results, showing the player's net
   gain/loss. Precondition:
        - startingBalance: A float representing the player's starting balance.
        - currentBalance: A float representing the player's current balance at
   the end of the game. Postcondition:
        - Outputs the final results, including all relevant game statistics and
   net gain/loss.
*/
void endGame(float startingBalance, float currentBalance);

// Helper Functions
/* Generate Random Card
    Description: Generates a new random card.
    Precondition: N/A
    Postcondition:
        - Returns a card with a random suit, display name, and value.
*/
card generateRandomCard();

/* Display Card
    Description: Outputs the suit and display name of a card.
    Precondition:
        - card: A card object.
    Postcondition:
        - Outputs the card's display name and suit as a string.
*/
string displayCard(card card);

/* Sort Hand
    Description: Sorts the hand so that any aces appear at the end.
    Precondition:
        - hand: A vector of cards with two or more cards.
    Postcondition:
        - Returns the hand with aces moved to the end, reversing the order of
   the other cards.
*/
vector<card> sortHand(vector<card> &hand);

/* Hand Value
    Description: Returns the total value of a hand of cards.
    Precondition:
        - hand: A vector of cards with two or more cards.
    Postcondition:
        - Returns the total value of the cards. If the total exceeds 21 and the
   hand contains an ace, the ace's value is reduced to 1.
*/
int handValue(vector<card> hand);

/* Dealer Hit
    Description: Forces the dealer to hit until their hand value is at least 17.
    Precondition:
        - dealerHand: A vector of cards with two or more cards.
    Postcondition:
        - Adds new cards to dealerHand as needed.
        - Displays the dealer's cards and their value.
*/
int dealerHit(vector<card> &dealerHand);

/* Display Dealer Turn
    Description: Displays a graphic indicating it is the dealer's turn.
    Precondition: N/A
    Postcondition:
        - Outputs a string showing it is the dealer's turn to act.
*/
void displayDealerTurn();

/* Display Game Summary
    Description: Displays the final game results using static member variables.
    Precondition:
        - totalWins: A static integer representing the player's total wins.
        - blackjackWins: A static integer representing the player's blackjack
   wins.
        - totalLosses: A static integer representing the player's total losses.
        - blackjackLosses: A static integer representing the player's blackjack
   losses.
        - currentBalance: A float representing the player's current balance.
        - startingBalance: A float representing the player's starting balance.
    Postcondition:
        - Displays the total wins, blackjack wins, losses, blackjack losses,
   final balance, and net gain/loss of the player.
*/
void displayGameSummary(int totalWins, int blackjackWins, int totalLosses,
                        int blackjackLosses, int totalTies, int blackjackTies,
                        float currentBalance, float startingBalance);

#endif