/*
    Programmer: Daniel Nkunga
    Date: 01/10/2024
    File: NkungaLab06.cpp
    Assignment: Lab 06
    Purpose: A nubmer guessing game in a creepy craly package.
*/

#include "NkungaLab06.h"
#include <iostream>
using namespace std;

/*TODO:
    - Static member variable
*/

int main() {
  char yesNo = 'x';
  do {
    getUserGuess(0, positionOfBug());
    cout << "Play again (y/n): ";
    cin >> yesNo;
  } while (yesNo != 'n');

  return 0;
}

// 100
