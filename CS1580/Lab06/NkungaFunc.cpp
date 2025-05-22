#include "NkungaLab06.h"
#include <time.h>

using namespace std;

int positionOfBug() {
  int position;
  srand(time(0));
  int lowerBound = 1, upperBound = 100;
  position = rand() % (upperBound - lowerBound + 1) + lowerBound;
  return position;
}

int getUserGuess(int guess, int bugPosition) {
  static int playerGuesses = 1;

  // Initial case
  if (playerGuesses == 1) {
    cout << "There's a bug! HIT IT! Guess where to hit [1, 100]: ";
    cin >> guess;
  }

  // Game Loop
  while (playerGuesses < 4) {
    if (catchTheBug(guess, bugPosition) > 0) {
      cout << "You missed! the bug is to the left of where you hit! New guess "
              "[1, 100]: ";
      cin >> guess;
      playerGuesses++;
      getUserGuess(guess, bugPosition);
    } else if (catchTheBug(guess, bugPosition) < 0) {
      cout << "You missed! the bug is to the right of where you hit! New guess "
              "[1, 100]: ";
      cin >> guess;
      playerGuesses++;
      getUserGuess(guess, bugPosition);
    } else {
      cout << "You hit the bug!" << endl;
      playerGuesses = 1;
      return 0;
    }
  }

  return guess;
}

int catchTheBug(int guess, int bugPosition) {
  int score = guess - bugPosition;
  return score;
}