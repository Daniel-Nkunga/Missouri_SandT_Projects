/*
    Programmer: Daniel Nkunga
    Date: 24/10/2024
    File: NkungaHW06.cpp
    Assignment: Homework 6
    Purpose: This program is a version of lights out that simulates a bee
   infestation on countries where bees can mutate into wasp and wasp can mutate
   into tarantula hawk wasps. Bees can infest empty cells. If a bee tries to
   infest a cell already occupied, that cell will infest all of its immediate
   neighbors. If an immediate neighbor is already occupied, it will mutate to
   the next instect up the chain of command.
*/

#include "NkungaHW06.h"
#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

int main() {
  // Variables
  ifstream fin;
  ofstream fout;
  char board[10][10];
  string xCoordinate;
  string yCoordinate;

  // Read file [There should probably be protection here]
  fin.open("input.txt");

  // Initial board set up
  getBoard(board);
  displayBoard(board);

  // Ignore first ten lines of the file
  for (int i = 0; i < 10; i++) {
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  // "Gameplay" [in the Conway's Game of Life type "Gameplay"]
  while (!fin.eof()) {
    getline(fin, xCoordinate, ' ');
    getline(fin, yCoordinate, '\n');
    cout << "Infesting: " << xCoordinate << "," << yCoordinate << endl;
    infest(board, stoi(xCoordinate), stoi(yCoordinate));
    displayBoard(board);
    cout << endl;
  }

  // Output
  saveBoard(board);

  return 0;
}