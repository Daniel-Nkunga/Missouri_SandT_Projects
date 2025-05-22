#include "NkungaHW05.h"
#include <time.h>
#include <vector>

using namespace std;

// Variables
static int totalWins, blackjackWins, totalLosses, blackjackLosses, totalTies,
    blackjackTies;
static int deckIndex;

void generateDeck(card deck[]) {
  card newCard;
  int index = 0;
  string suits[] = {"Hearts", "Diamonds", "Clubs",
                    "Spades"}; // String representation of suits

  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= 13; j++) {
      // Initial Assignments
      newCard.suit = suits[i];
      newCard.value = j;

      // Assign Display Names
      switch (newCard.value) {
      case 1:
        newCard.displayName = "Ace";
        break;
      case 11:
        newCard.displayName = "Jack";
        break;
      case 12:
        newCard.displayName = "Queen";
        break;
      case 13:
        newCard.displayName = "King";
        break;
      default:
        newCard.displayName = to_string(newCard.value);
      }

      // Fix Values
      if (newCard.value > 10) {
        newCard.value = 10;
      }

      // Set Ace to High Value
      if (newCard.value == 1) {
        newCard.value = 11;
      }

      deck[index] = newCard;
      index++;
    }
  }
}

void shuffleDeck(card deck[]) {
  card temp;
  int lowerBound = 0, upperBound = 51;
  int randomIndex;
  srand(time(0));

  for (int i = 0; i < 52; i++) {
    randomIndex = rand() % (upperBound - lowerBound + 1) + lowerBound;
    temp = deck[i];
    deck[i] = deck[randomIndex];
    deck[randomIndex] = temp;
  }
}

card pullCard(card deck[]) {
  card cardInPlay;
  cardInPlay = deck[deckIndex++];
  return cardInPlay;
}

void initializeMoney(float &money) {
  srand(time(0));
  //   srand(5300);
  int lowerBound = 12, upperBound = 7000;

  int dollars = rand() % (upperBound - lowerBound + 1) + lowerBound;
  int cents = rand() % 100;
  money = dollars + (cents / 100.0f);
}

void displayRound(int &roundCount) {
  cout << " ======================== \033[1;4;37mROUND ";
  cout << roundCount++;
  cout << "\033[0m ======================== " << endl;
}

void displayPlayerTurn() {
  cout << endl
       << " ============ \033[1;4;37m Player's Turn \033[0m ============ "
       << endl;
  ;
}

void displayDealerTurn() {
  cout << endl
       << " ============ \033[1;4;37m Dealer's Turn \033[0m ============ "
       << endl;
  ;
}

card generateRandomCard() {
  srand(time(0) + 1);
  //   srand(5300);
  int lowerBound = 1, upperBound = 13;
  int suitLower = 0, suitUpper = 3;
  int suitValue;

  card newCard;
  newCard.value = rand() % (upperBound - lowerBound + 1) + lowerBound;
  suitValue = rand() % (suitUpper - suitLower + 1) + suitLower;

  // Assign Suite
  switch (suitValue) {
  case 1:
    newCard.suit = Spades;
    break;
  case 2:
    newCard.suit = Clubs;
    break;
  case 3:
    newCard.suit = Hearts;
    break;
  case 4:
    newCard.suit = Diamonds;
    break;
  default:
    newCard.suit = Null;
  }

  // Assign Display Names
  switch (newCard.value) {
  case 1:
    newCard.displayName = "Ace";
    break;
  case 11:
    newCard.displayName = "Jack";
    break;
  case 12:
    newCard.displayName = "Queen";
    break;
  case 13:
    newCard.displayName = "King";
    break;
  default:
    newCard.displayName = to_string(newCard.value);
  }

  // Fix Values
  if (newCard.value > 10) {
    newCard.value = 10;
  }

  // Set Ace to High Value
  if (newCard.value == 1) {
    newCard.value = 11;
  }

  return newCard;
}

string displayCard(card card) {
  return "\033[4;37m" + card.displayName + " of " + card.suit + "\033[0m";
}

bool isBlackjack(card hand[]) { // TODO: FIX THIS?
  if (handValue(hand) == 21) {
    return true;
  } else {
    return false;
  }
}

void displayOutcome(bool isBlackjack, int winStatus, float money, float wager) {
  switch (winStatus) {
  case 0:
    // WIN
    if (isBlackjack) {
      cout << "Balance Update: \033[1;32m+" << wager * 1.5 << "\033[0m" << endl;
      cout << "New Balance: \033[1;32m$" << money + (wager * 1.5) << "\033[0m"
           << endl;
    } else {
      cout << "Balance Update: \033[1;32m+" << wager * 2 << "\033[0m" << endl;
      cout << "New Balance: \033[1;32m$" << money + (wager * 2) << "\033[0m"
           << endl;
    }
    break;
  case 1:
    // LOSS
    cout << "Balance Update: \033[1;32m-" << wager << "\033[0m" << endl;
    cout << "New Balance: \033[1;32m$" << money - wager << "\033[0m" << endl;
    break;
  default:
    // TIE
    cout << "Balance Update: \033[1;32m+0\033[0m" << endl;
    cout << "New Balance: \033[1;32m$" << money << "\033[0m" << endl;
  }
}

int handValue(card hand[]) {
  int handValue = 0;
  for (int i = 0; i < 20; i++) {
    handValue += hand[i].value;
    if (handValue > 21) {
      for (int i = 0; i < 20; i++) {
        if (hand[i].displayName == "Ace" && hand[i].value == 11) {
          hand[i].value = 1;
        }
      }
    }
  }
  return handValue;
}

int hit(card hand[], card deck[]) {
  card newCard = pullCard(deck);
  for (int i = 0; i < 20; i++) {
    if (hand[i].value == 0) {
      hand[i] = newCard;
      break;
    }
  }
  cout << "\033[1;33mDealer:\033[0m You now have a \n";
  for (int i = 0; i < 20; i++) {
    if (hand[i].value != 0) {
      cout << displayCard(hand[i]);
      if (i < 19) {
        cout << " and a "; // A better person would follow proper gamatical
                           // structure and edit this loop to go one less while
                           // using commas and have the last one say "and", I am
                           // not a better person
      }
    }
  }

  cout << " valued at " << handValue(hand) << endl;
  return handValue(hand);
}

int dealerHit(card dealerHand[]) {
  card newCard;
  while (handValue(dealerHand) < 17) {
    newCard = generateRandomCard();
    for (int i = 0; i < 20; i++) {
      if (dealerHand[i].value == 0) {
        dealerHand[i] = newCard;
        break;
      }
    }
    cout << "\033[1;33mDealer:\033[0m Now let me draw. My new hand is a "
         << endl;

    for (int i = 0; i < 20; i++) {
      if (dealerHand[i].value != 0) {
        cout << displayCard(dealerHand[i]);
        if (i < 19) {
          cout << " and a ";
        }
      }
    }
    cout << " valued at " << handValue(dealerHand) << endl;
  }
  return handValue(dealerHand);
}

void dealerTurn(card dealerHand[]) {
  displayDealerTurn();
  int dealerHandValue = handValue(dealerHand);
  cout << "\033[1;33mDealer:\033[0m And my full hand is a " << endl;
  cout << displayCard(dealerHand[0]) << " and a " << displayCard(dealerHand[1])
       << " valued at " << handValue(dealerHand) << endl;
  while (dealerHandValue < 17) {
    dealerHit(dealerHand);
    dealerHandValue = handValue(dealerHand);
  }
}

void roundOutcome(float &money, float wager, card dealerHand[],
                  card playerHand[]) {
  cout << endl
       << " ============ \033[1;4;37m Round Results \033[0m ============ "
       << endl;

  if (handValue(dealerHand) > 21 && handValue(playerHand) > 21) {
    cout << "\033[1;33mDealer:\033[0m Now that's just embarassing for the both "
            "of us. I would say it's a net nothing for you, but embarassment "
            "has to count for something, right?"
         << endl;
    displayOutcome(isBlackjack(playerHand), -1, money, wager);
    totalLosses++;
  } else if (handValue(dealerHand) > 21) {
    cout << "\033[1;33mDealer:\033[0m Lucky you. I swear I'm a better player "
            "when I'm not required to keep drawing until I reach 17. Now, I "
            "owe you, right?"
         << endl;
    displayOutcome(isBlackjack(playerHand), 0, money, wager);
    money += 2 * wager; // Update money here
    totalWins++;
  } else if (handValue(playerHand) > 21) {
    cout << "\033[1;33mDealer:\033[0m Did you forget the rules or did you just "
            "get greedy? Either way, it's going to cost you."
         << endl;
    displayOutcome(isBlackjack(playerHand), 1, money, wager);
    money -= wager; // Update money here
    totalLosses++;
  } else if (isBlackjack(dealerHand) && isBlackjack(playerHand)) {
    cout << "\033[1;33mDealer:\033[0m A tie's always rough becuase it means "
            "most of the time you could've played a bit more risky for more "
            "reward. But a tie with double blackjacks? That's just unlucky. At "
            "least you don't loos any money."
         << endl;
    displayOutcome(isBlackjack(playerHand), -1, money, wager);
    blackjackTies++;
  } else if (isBlackjack(dealerHand)) {
    cout
        << "\033[1;33mDealer:\033[0m Should've played better. I'm just messing "
           "around, but you do have to pay up. Sorry about your bad luck."
        << endl;
    displayOutcome(isBlackjack(playerHand), 1, money, wager);
    money -= wager; // Update money here
    blackjackLosses++;
    totalLosses++;
  } else if (isBlackjack(playerHand)) {
    cout << "\033[1;33mDealer:\033[0m Well lucky you! Congrats on the perfect "
            "hand! Now how much do I owe you?"
         << endl;
    displayOutcome(isBlackjack(playerHand), 0, money, wager);
    money += 1.5 * wager; // Update money here
    totalWins++;
    blackjackWins++;
  } else if (handValue(playerHand) == handValue(dealerHand)) {
    cout << "\033[1;33mDealer:\033[0m One of us should've played a bit more "
            "risker. Though since you didn't loose anything, I'm guessing "
            "you're not too bothered."
         << endl;
    displayOutcome(isBlackjack(playerHand), -1, money, wager);
    totalTies++;
  } else if (handValue(playerHand) > handValue(dealerHand)) {
    cout << "\033[1;33mDealer:\033[0m Congrats on the win! You beat the house! "
            "I guess it's time for me to pay up, isn't it?"
         << endl;
    displayOutcome(isBlackjack(playerHand), 0, money, wager);
    money += 2 * wager; // Update money here
    totalWins++;
  } else if (handValue(playerHand) < handValue(dealerHand)) {
    cout << "\033[1;33mDealer:\033[0m Ooohhh! I would say unlucky, but I don't "
            "actually care that much. Sorry, but you gotta pay up."
         << endl;
    displayOutcome(isBlackjack(playerHand), 1, money, wager);
    money -= wager; // Update money here
    totalLosses++;
  }
}

void displayGameSummary(int totalWins, int blackjackWins, int totalLosses,
                        int blackjackLosses, int totalTies, int blackjackTies,
                        float currentBalance, float startingBalance) {
  cout << " === GAME SUMMARY === " << endl;
  cout << "Total Wins (Regular): " << totalWins << endl;
  cout << "Total Wins (Blackjack): " << blackjackWins << endl;
  cout << "Total Losses (Regular): " << totalLosses << endl;
  cout << "Total Losses (Blackjack): " << blackjackLosses << endl;
  cout << "Total Ties (Regular): " << totalTies << endl;
  cout << "Total Ties (Blackjack): " << blackjackTies << endl;
  cout << "Final Balance: " << currentBalance << endl;
  cout << "Net Gain/Loss: " << currentBalance - startingBalance << endl;
}

void endGame(float startingBalance, float currentBalance) {
  displayGameSummary(totalWins, blackjackWins, totalLosses, blackjackLosses,
                     totalTies, blackjackTies, currentBalance, startingBalance);
}

float getWager(float money) {
  float wager;
  cout << "\033[1;33mDealer:\033[0m How much money would you like to wager? "
          "\033[1;32m";
  cin >> wager;
  cout << "\033[0m";
  while (wager < 0 || wager > money) {
    cout << "\033[1;33mDealer:\033[0m We both know you're not allowed to do "
            "that. So how much money would you acutally like to wager (0, "
            "current balance]? \033[1;32m";
    cin >> wager;
    cout << "\033[0m";
  }
  return wager;
}

int getPlayerAction(bool isInitialAction, float money, float wager) {
  int playerAction;
  if (isInitialAction) {
    cout << "\033[1;33mDealer:\033[0m Now what do you want to do? Hit - 0, "
            "Stand - 1, Double Down - 2"
         << endl;
  } else {
    cout << "\033[1;33mDealer:\033[0m Now what do you want to do? Hit - 0 or "
            "Stand - 1"
         << endl;
  }
  cout << "Player Action: ";
  cin >> playerAction;
  while (money < wager * 2 && playerAction == 2) {
    cout << "\033[1;33mDealer:\033[0m Sorry, but you just don't have enough "
            "money. Now what do you want to do? Hit - 0 or Stand - 1"
         << endl;
    cout << "Player Action: ";
    cin >> playerAction;
  }
  while (playerAction != 0 && playerAction != 1 && playerAction != 2) {
    if (isInitialAction) {
      cout << "\033[1;33mDealer:\033[0m Not an option. Now what do you want to "
              "do? Hit - 0, Stand - 1, Double Down - 2"
           << endl;
    } else {
      cout << "\033[1;33mDealer:\033[0m Not an option. Now what do you want to "
              "do? Hit - 0 or Stand - 1"
           << endl;
    }
    cout << "Player Action: ";
    cin >> playerAction;
  }
  return playerAction;
}

void generateDealerHand(card dealerHand[], card deck[]) {
  cout << "\033[1;33mDealer:\033[0m Alright. Let's see what I have here: "
       << endl;
  dealerHand[0] = pullCard(deck);
  dealerHand[1] = pullCard(deck);
  cout << displayCard(dealerHand[0]) << " and a [HIDDEN CARD]" << endl << endl;
}

void generatePlayerHand(card playerHand[], card deck[]) {
  cout << "\033[1;33mDealer:\033[0m And you have: " << endl;
  playerHand[0] = pullCard(deck);
  playerHand[1] = pullCard(deck);
  cout << displayCard(playerHand[0]) << " and a " << displayCard(playerHand[1])
       << " valued at " << handValue(playerHand) << endl;
}

char yesNo() // In hindsight, this is a very redundant function since I don't
             // (and won't) check for 'y'
{
  char yesNo;
  cout
      << "\n\033[1;33mDealer:\033[0m Do you want to play another round (y/n)? ";
  cin >> yesNo;
  return yesNo;
}

void reset(float &wager, bool &isInitialAction, card deck[], card playerHand[],
           card dealerHand[]) {
  wager = 0;
  isInitialAction = true;

  for (int i = 0; i < 20; i++) {
    playerHand[i].displayName = "";
    playerHand[i].suit = "";
    playerHand[i].value = 0;
    dealerHand[i].displayName = "";
    dealerHand[i].suit = "";
    dealerHand[i].value = 0;
  }
  shuffleDeck(deck);
  deckIndex = 0;
}
