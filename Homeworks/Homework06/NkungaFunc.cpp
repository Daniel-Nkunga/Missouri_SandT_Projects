#include "NkungaHW06.h"

using namespace std;

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void displayBoard(char board[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << "+ - ";
    }
    cout << "+ " << endl;
    for (int j = 0; j < 10; j++) {
      cout << "| ";
      switch (board[i][j]) {
      case ('B'):
        cout << "\033[1;33m";
        cout << board[i][j];
        cout << " \033[0m";
        break;
      case ('W'):
        cout << "\033[1;31m";
        cout << board[i][j];
        cout << " \033[0m";
        break;
      case ('T'):
        cout << "\033[1;35m";
        cout << board[i][j];
        cout << " \033[0m";
        break;
      default:
        cout << "  ";
      }
    }
    cout << "|" << endl;
  }
  for (int j = 0; j < 10; j++) {
    cout << "+ - ";
  }
  cout << "+ " << endl;
}

void getBoard(char board[10][10]) {
  ifstream fin("input.txt");
  char ch;
  int i = 0, j = 0;

  while (i < 10 && fin.get(ch)) {
    if (isgraph(ch)) {
      board[i][j] = ch;
      j++;
      if (j == 10) {
        j = 0;
        i++;
      }
    }
  }
  fin.close();
}

void update(char board[10][10], int xPosition, int yPosition) {

  switch (board[xPosition][yPosition]) {
  case ('_'):
    board[xPosition][yPosition] = 'B';
    break;
  case ('B'):
    board[xPosition][yPosition] = 'W';
    break;
  case ('W'):
    board[xPosition][yPosition] = 'T';
    break;
  default:
    break;
  }
}

void update(char board[10][10], int xPosition, int yPosition, char target) {
  if (board[xPosition][yPosition] == '_') {
    while (board[xPosition][yPosition] != target) {
      update(board, xPosition, yPosition);
    }
  } else {
    update(board, xPosition, yPosition);
  }
}

void infest(char board[10][10], int xPosition, int yPosition) {
  if (board[xPosition][yPosition] == '_') {
    update(board, xPosition, yPosition);
  } else {
    // TODO: Ugly code; Please fix ;-;
    if (xPosition != 0) {
      update(board, xPosition - 1, yPosition, board[xPosition][yPosition]);
    }
    if (xPosition != 9) {
      update(board, xPosition + 1, yPosition, board[xPosition][yPosition]);
    }
    if (yPosition != 0) {
      update(board, xPosition, yPosition - 1, board[xPosition][yPosition]);
    }
    if (yPosition != 9) {
      update(board, xPosition, yPosition + 1, board[xPosition][yPosition]);
    }
    if (xPosition != 0 && yPosition != 0) {
      update(board, xPosition - 1, yPosition - 1, board[xPosition][yPosition]);
    }
    if (xPosition != 9 && yPosition != 0) {
      update(board, xPosition + 1, yPosition - 1, board[xPosition][yPosition]);
    }
    if (xPosition != 0 && yPosition != 9) {
      update(board, xPosition - 1, yPosition + 1, board[xPosition][yPosition]);
    }
    if (xPosition != 9 && yPosition != 9) {
      update(board, xPosition + 1, yPosition + 1, board[xPosition][yPosition]);
    }
  }
}

void saveBoard(char board[10][10]) {
  ofstream fout;
  fout.open("output.txt");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      fout << board[i][j];
    }
    fout << endl;
  }
}

// P.S. I swear at one point this code was beautiful. I don't know what went
// wrong. ;-; - Daniel