#include "NkungaHW4.h"
#include <time.h>
#include <vector>

using namespace std;

// Variables
static int totalWins, blackjackWins, totalLosses, blackjackLosses, totalTies,
    blackjackTies;

void initializeMoney(float &money) {
  // srand(time(0));
  srand(5300);
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
  // srand(time(0));
  srand(5300);
  int lowerBound = 1, upperBound = 13;
  int suitLower = 0, suitUpper = 3;
  int suitValue;

  card newCard;
  newCard.value = rand() % (upperBound - lowerBound + 1) + lowerBound;
  suitValue = rand() % (suitUpper - suitLower + 1) + suitLower;

  // Assign Suite
  switch (suitValue) {
  case 0:
    newCard.suit = "Spades";
    break;
  case 1:
    newCard.suit = "Clubs";
    break;
  case 2:
    newCard.suit = "Hearts";
    break;
  case 3:
    newCard.suit = "Diamonds";
    break;
  default:
    newCard.suit = "Null";
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

bool isBlackjack(vector<card> hand) {
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
      cout << "New Balance: \033[1;32m$" << money + wager * 1.5 << "\033[0m"
           << endl;
    } else {
      cout << "Balance Update: \033[1;32m+" << wager * 2 << "\033[0m" << endl;
      cout << "New Balance: \033[1;32m$" << money + wager * 2 << "\033[0m"
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
    cout << "Balance Update: \033[1;32m+0"
         << "\033[0m" << endl;
    cout << "New Balance: \033[1;32m$" << money << "\033[0m" << endl;
  }
}

vector<card>
sortHand(vector<card> &
             hand) // TODO: Maybe fix how it reverses the start of the string
                   // every term; counter argument: it's not a bug, its a feature
{
  vector<card> sortedHand;

  for (int i = 0; i < static_cast<int>(hand.size()); i++) {
    if (hand[i].displayName == "Ace") {
      sortedHand.push_back(hand[i]);
    } else {
      sortedHand.insert(sortedHand.begin(), hand[i]);
    }
  }

  hand = sortedHand;
  return hand;
}

int handValue(
    vector<card> hand) // TODO: Check this function; somtimes things are off
                       // when dealing with Aces [mostly can be fixed by seting
                       // the parameters to be: (vector<card> & hand)]
{
  sortHand(hand);
  int handValue = 0;
  for (int i = 0; i < static_cast<int>(hand.size()); i++) {
    handValue += hand[i].value;
    if (handValue > 21 && hand[hand.size() - 1].displayName == "Ace") {
      hand[hand.size() - 1].value = 1;
      handValue -= 10;
    }
  }
  return handValue;
}

int hit(vector<card> &hand) {
  card newCard = generateRandomCard();
  hand.push_back(newCard);
  cout << "\033[1;33mDealer:\033[0m You now have a \n";
  for (int i = 0; i < static_cast<int>(hand.size()); i++) {
    cout << displayCard(hand[i]);
    if (i < static_cast<int>(hand.size() - 1)) {
      cout << " and a "; // A better person would follow proper gamatical
                         // structure and edit this loop to go one less while
                         // using commas and have the last one say "and", I am
                         // not a better person
    }
  }
  cout << " valued at " << handValue(hand) << endl;
  return handValue(hand);
}

int dealerHit(vector<card> &dealerHand) {
  card newCard;
  while (handValue(dealerHand) < 17) {
    newCard = generateRandomCard();
    dealerHand.push_back(newCard);
    cout << "\033[1;33mDealer:\033[0m Now let me draw. My new hand is a "
         << endl;
    for (int i = 0; i < static_cast<int>(dealerHand.size()); i++) {
      cout << displayCard(dealerHand[i]);
      if (i < static_cast<int>(dealerHand.size() - 1)) {
        cout << " and a ";
      }
    }
    cout << " valued at " << handValue(dealerHand) << endl;
  }
  return handValue(dealerHand);
}

void dealerTurn(vector<card> &dealerHand) {
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

void roundOutcome(
    float &money, float wager, vector<card> dealerHand,
    vector<card> playerHand) // TODO: Multiple messages from the dealer?
{
  cout << endl
       << " ============ \033[1;4;37m Round Results \033[0m ============ "
       << endl;
  ;
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
    displayOutcome(isBlackjack(playerHand), 0, wager, money);
    money += 2 * wager;
    totalWins++;
  } else if (handValue(playerHand) > 21) {
    cout << "\033[1;33mDealer:\033[0m Did you forget the rules or did you just "
            "get greedy? Either way, it's going to cost you."
         << endl;
    displayOutcome(isBlackjack(playerHand), 1, wager, money);
    money -= wager;
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
    money -= wager;
    blackjackLosses++;
    totalLosses++;
  } else if (isBlackjack(playerHand)) {
    cout << "\033[1;33mDealer:\033[0m Well lucky you! Congrats on the perfect "
            "hand! Now how much do I owe you?"
         << endl;
    displayOutcome(isBlackjack(playerHand), 0, money, wager);
    money += 1.5 * wager;
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
    money += 2 * wager;
    totalWins++;
  } else if (handValue(playerHand) < handValue(dealerHand)) {
    cout << "\033[1;33mDealer:\033[0m Ooohhh! I would say unlucky, but I don't "
            "actually care that much. Sorry, but you gotta pay up."
         << endl;
    displayOutcome(isBlackjack(playerHand), 1, money, wager);
    money -= wager;
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

vector<card> generateDealerHand(vector<card> &dealerHand) {
  cout << "\033[1;33mDealer:\033[0m Alright. Let's see what I have here: "
       << endl;
  dealerHand.push_back(generateRandomCard());
  dealerHand.push_back(generateRandomCard());
  cout << displayCard(dealerHand[0]) << " and a [HIDDEN CARD]" << endl << endl;
  return dealerHand;
}

vector<card> generatePlayerHand(vector<card> &playerHand) {
  cout << "\033[1;33mDealer:\033[0m And you have: " << endl;
  playerHand.push_back(generateRandomCard());
  playerHand.push_back(generateRandomCard());
  cout << displayCard(playerHand[0]) << " and a " << displayCard(playerHand[1])
       << " valued at " << handValue(playerHand) << endl;
  return playerHand;
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

void reset(vector<card> &dealerHand, vector<card> &playerHand, float &wager,
           bool &isInitialAction) {
  vector<card> newDealerHand;
  vector<card> newPlayerHand;

  // Reset
  dealerHand = newDealerHand;
  playerHand = newPlayerHand;
  wager = 0;
  isInitialAction = true;
}
