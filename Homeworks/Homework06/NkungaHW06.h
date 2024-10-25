#ifndef NKUNGA
#define NKUNGA

#include <iostream>
using namespace std;

/* Display Board
    Description: Prints the current board to the console
    Precondition:
        - board: 10 x 10 character array representing the current state of the board
    Postcondition: N/A
*/
void displayBoard(char board[10][10]);
/* Get Board
    Description: Establishes the board for a separate input file
    Precondition:
        - board: 10 x 10 character array representing the current state of the board
    Postcondition: N/A
*/
void getBoard(char board[10][10]);
/* Update
    Description: Incremenents the current cell up a level
        - Ordering: '_' > 'B' > 'W' > 'T'
        * Overloaded function
    Precondition:
        - board: 10 x 10 character array representing the current state of the board
        - xPosition: target's x position in the board
        - yPosition: target's y position in the board
    Postcondition: N/A
*/
void update(char board[10][10], int xPosition, int yPosition);
/* Update
    Description: Incremenents the current cell up the level of the the target assuming that the cell is empty/'_'
        - Ordering: '_' > 'B' > 'W' > 'T'
        * Overloaded function
    Precondition:
        - board: 10 x 10 character array representing the current state of the board
        - xPosition: target's x position in the board
        - yPosition: target's y position in the board
        - target: desired value of the updated cell
    Postcondition: N/A
*/
void update(char board[10][10], int xPosition, int yPosition, char target);
/* Infest
    Description: Calls a strike of bees on a cell and properly updates surrounding cells and displayes the board as well as the targeted cell
    Precondition:
        - board: 10 x 10 character array representing the current state of the board
        - xPosition: target's x position in the board
        - yPosition: target's y position in the board
    Postcondition: N/A
*/
void infest(char board[10][10], int xPosition, int yPosition);
/* Save Board
    Description: Saves the current board to a file called "output.txt"
    Precondition:
        - board: 10 x 10 character array representing the current state of the board
    Postcondition: N/A
*/
void saveBoard(char board[10][10]);

#endif