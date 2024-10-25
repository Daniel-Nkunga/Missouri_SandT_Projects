/*  Programmer: Daniel Nkunga
    Date: 09/24/2024
    File: NkungaLab05.cpp
    Assignment: CS1580 Lab 05
    Purpose:
*/

#include <iostream>
using namespace std;

// Function prototypes with default arguments
int total(int pizzaCount, string pizzaSize = "medium");
// float calculateSplit(int pizzaCount, int personCount, string pizzaSize);
float calculateSplit(int pizzaCount, int personCount = 4,
                     string pizzaSize = "medium");

int main() {
  // Variables
  char yesNo = 'x'; // Only checks for yes
  int pizzaCount;
  int personCount = -1;
  string pizzaSize = "";

  // Getting variables
  cout << "How many pizzas would you like to buy: ";
  cin >> pizzaCount;
  cout << "Would you like to specify the number of people sharing the pizza(s) "
          "(y/n): ";
  cin >> yesNo;
  if (yesNo == 'y' or yesNo == 'Y') {
    yesNo = 'x';
    cout << "How many people are sharing the pizza: ";
    cin >> personCount;
  }
  cout << "Would you like to specify the size of the pizza(s) (y/n): ";
  cin >> yesNo;
  if (yesNo == 'y' or yesNo == 'Y') {
    yesNo = 'x';
    cout << "What size pizza are you wanting (small/medium/large): ";
    cin >> pizzaSize;
  }

  // Debugging

  // Messages
  cout << "Total cost: " << total(pizzaCount, pizzaSize) << endl;
  if (personCount == -1 && pizzaSize == "") {
    cout << "Cost per person: " << calculateSplit(pizzaCount) << endl;
    ;
  } else if (pizzaSize == "") {
    cout << "Cost per person: " << calculateSplit(pizzaCount, personCount)
         << endl;
  } else {
    cout << "Cost per person: "
         << calculateSplit(pizzaCount, personCount, pizzaSize) << endl;
    ;
  }

  // cout << "Cost per person: " << calculateSplit(pizzaCount, personCount,
  // pizzaSize) << endl;
}

int total(int pizzaCount, string pizzaSize) {
  // Variables
  int total;
  int sizeCost;

  // Establishing pizza size cost
  if (pizzaSize == "small") {
    sizeCost = 10;
  } else if (pizzaSize == "large") {
    sizeCost = 15;
  } else {
    sizeCost = 12;
  }

  total = pizzaCount * sizeCost;
  return total;
}

float calculateSplit(int pizzaCount, int personCount, string pizzaSize) {
  // Variables
  float costPerPerson;
  float sizeCost; // Float to get around interger division later on

  // Establishing pizza size cost
  if (pizzaSize == "small") {
    sizeCost = 10.0;
  } else if (pizzaSize == "large") {
    sizeCost = 15.0;
  } else {
    sizeCost = 12.0;
  }

  // cout << "DEBUG 0 - person count: " << personCount << endl;
  // cout << "DEBUG  1 - pizza size: " << pizzaSize << endl;
  // // cout << "DEBUG: " << personCount << endl;
  costPerPerson = (pizzaCount * sizeCost) / personCount;
  return costPerPerson;
}

/*
Wrong logic, it gave wrong results -15

How many pizzas would you like to buy: 36
Would you like to specify the number of people sharing the pizza(s) (y/n): n
Would you like to specify the size of the pizza(s) (y/n): y
What size pizza are you wanting (small/medium/large): small
Total cost: 360
Cost per person: -360


No proper documentations. -15
Function requirements not met -10

// 60
*/
