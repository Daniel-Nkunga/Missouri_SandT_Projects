#ifndef NKUNGA
#define NKUNGA

#include <iostream>
using namespace std;

/* Suit
    Description: Enumerator representing card suits
*/
enum suit {Null, Spades, Clubs, Hearts, Diamonds};

// Structures
/* card
    Description: Represents a playing card with a display name (e.g., "Ace",
   "King"), a suit (e.g., "Hearts", "Spades"), and a value (numerical
   representation of the card).
*/
struct card {
  string displayName;
  string suit;
  int value = 0; // For debugging
};

// Functions in Main
/* Initialize Money
    Description: Starts the player with a random amount of money between $12.00
   and $7,000.00.
    Precondition: N/A
    Postcondition:
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
    Description: Creates an array of two cards representing the dealer's hand.
   Reveals the dealer's first card and hides the second.
    Precondition:
        - dealerHand: An empty array of cards.
    Postcondition:
        - Fills dealerHand with two newly generated cards.
    Note:
        - Since arrays are of fixed size, ensure dealerHand has enough space to hold the cards.
*/
void generateDealerHand(card dealerHand[], card deck[]);

/* Generate Player Hand
    Description: Creates an array of two cards representing the player's hand
   and displays both cards.
    Precondition:
        - playerHand: An empty array of cards.
    Postcondition:
        - Fills playerHand with two newly generated cards.
    Note:
        - Since arrays are of fixed size, ensure playerHand has enough space to hold the cards.
*/
void generatePlayerHand(card playerHand[], card deck[]);

/* Display Player Turn
    Description: Displays a graphic indicating it is the player's turn.
    Precondition: N/A
    Postcondition:
        - Outputs a string showing it is the player's turn to act.
*/
void displayPlayerTurn();

/* Get Player Action
    Description: Prompts the player to choose an action (hit, stand, or double
   down) and validates the input.
    Precondition:
        - isInitialAction: A boolean indicating if this is the player's first
   action of the turn, allowing the option to double down.
        - money: A float representing the player's current balance.
        - wager: A float representing the current wager.
    Postcondition:
        - Returns an integer representing the player's choice:
            - 0: The player chooses to hit.
            - 1: The player chooses to stand.
            - 2: The player chooses to double down, available only if
              isInitialAction is true.
*/
int getPlayerAction(bool isInitialAction, float money, float wager);

/* Hit
    Description: Adds a new card to the player's hand.
    Precondition:
        - hand: An array of cards with two or more cards.
    Postcondition:
        - Adds a newly generated card to the hand.
        - Displays all cards in the hand and their total value.
    Note:
        - Be cautious of array bounds; since arrays cannot be resized, ensure there's space for new cards.
*/
int hit(card hand[], card deck[]);

/* Dealer Turn
    Description: Forces the dealer to keep hitting until their hand value
   reaches 17 or more.
    Precondition:
        - dealerHand: An array of cards with two or more cards.
    Postcondition:
        - Displays the dealer's full hand.
        - Adds any newly generated cards to dealerHand as needed.
    Note:
        - Since arrays have fixed sizes, ensure dealerHand has sufficient capacity.
*/
void dealerTurn(card dealerHand[]);

/* Round Outcome
    Description: Displays the outcome of the round based on the dealer's and
   player's hands, and updates game statistics.
    Precondition:
        - money: A float representing the player's current balance.
        - wager: A float representing the current wager.
        - dealerHand: An array of two or more cards.
        - playerHand: An array of two or more cards.
    Postcondition:
        - Displays the round's outcome and any changes to the player's balance.
        - Updates relevant game statistics (e.g., number of wins, blackjacks,
          etc.).
*/
void roundOutcome(float &money, float wager, card dealerHand[],
                  card playerHand[]);

/* Yes/No Prompt
    Description: Prompts the player to answer a yes or no question, returning
   their response as a char.
    Precondition: N/A
    Postcondition:
        - Returns the player's input (either 'y' or 'n').
*/
char yesNo();

/* Reset
    Description: Resets the dealer's and player's hands, the wager, and the
   action state for the next round.
    Precondition:
        - dealerHand: An array of cards with two or more cards.
        - playerHand: An array of cards with two or more cards.
        - wager: A float representing the current wager.
        - isInitialAction: A boolean indicating if this is the player's first
          action of the turn.
    Postcondition:
        - Clears the dealerHand and playerHand.
        - Sets the wager to 0.
        - Resets isInitialAction to true.
    Note:
        - Clearing arrays involves resetting their elements; arrays cannot be resized or emptied.
*/
void reset(float &wager, bool &isInitialAction, card deck[], card playerHand[], card dealerHand[]);

/* End Game
    Description: Displays the final game results, showing the player's net
   gain/loss.
    Precondition:
        - startingBalance: A float representing the player's starting balance.
        - currentBalance: A float representing the player's current balance at
          the end of the game.
    Postcondition:
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
        - hand: An array of cards with two or more cards.
    Postcondition:
        - Returns the hand with aces moved to the end, reversing the order of
          the other cards.
    Note:
        - Since arrays have fixed sizes, sorting should be done within the bounds of the array.
*/
void sortHand(card hand[]);

/* Hand Value
    Description: Returns the total value of a hand of cards.
    Precondition:
        - hand: An array of cards with two or more cards.
    Postcondition:
        - Returns the total value of the cards. If the total exceeds 21 and the
          hand contains an ace, the ace's value is reduced to 1.
*/
int handValue(card hand[]);

/* Dealer Hit
    Description: Forces the dealer to hit until their hand value is at least 17.
    Precondition:
        - dealerHand: An array of cards with two or more cards.
    Postcondition:
        - Adds new cards to dealerHand as needed.
        - Displays the dealer's cards and their value.
    Note:
        - Ensure dealerHand has enough space to accommodate new cards due to the fixed size of arrays.
*/
int dealerHit(card dealerHand[]);

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
        - totalWins: An integer representing the player's total wins.
        - blackjackWins: An integer representing the player's blackjack wins.
        - totalLosses: An integer representing the player's total losses.
        - blackjackLosses: An integer representing the player's blackjack losses.
        - totalTies: An integer representing the player's total ties.
        - blackjackTies: An integer representing the player's blackjack ties.
        - currentBalance: A float representing the player's current balance.
        - startingBalance: A float representing the player's starting balance.
    Postcondition:
        - Displays the total wins, blackjack wins, losses, blackjack losses, ties,
          blackjack ties, final balance, and net gain/loss of the player.
*/
void displayGameSummary(int totalWins, int blackjackWins, int totalLosses,
                        int blackjackLosses, int totalTies, int blackjackTies,
                        float currentBalance, float startingBalance);

/* Generate Deck
    Description: Generates a standard deck of 52 playing cards.
    Precondition:
        - deck: An empty array of cards with a size of 52.
    Postcondition:
        - Fills the deck array with 52 unique cards representing a standard deck.
    Note:
        - Ensure the deck array has a capacity of at least 52 cards.
*/
void generateDeck(card deck[]);

/* Shuffle Deck
    Description: Randomly shuffles the deck of cards.
    Precondition:
        - deck: An array of cards representing a standard deck.
    Postcondition:
        - The cards in the deck array are shuffled into a random order.
*/
void shuffleDeck(card deck[]);

#endif
