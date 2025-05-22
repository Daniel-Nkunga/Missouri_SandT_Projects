#ifndef NKUNGA
#define NKUNGA

#include <iostream>
using namespace std;

/*
    Definition: This a void function taht return the position of a bug an a 1D timeline
    Precondition: The function takes in no parameters
    Postcondiditon: The function returns the position of the bug which is a random interger between [1, 100]
*/
int positionOfBug();
/*
    Definition: This in an interger function that takes in the bug's position and the user's guess and allows the user to guess again if they didn't hit the bug. Ends the program if they hit the bug. Calls itself recursivly to preform the game. 
    Precondition: 
        - guess: the user inputed guess of where the bug is; interger
        - bugPosition: the positoin of the bug; interger [1, 100]
    Postcondiditon: Returns the user's guess
*/
int getUserGuess(int guess, int bugPosition);
/*
    Definition: This is a interger, helper function for getUserGuess() that returns how far off the user was from hitting the bug.  
    Precondition: 
        - guess: the user inputed guess of where the bug is; interger
        - bugPosition: the positoin of the bug; interger [1, 100]
    Postcondiditon:
        - 0: The user has hit the bug
        - return < 0: the user has guessed to the left of the bug
        - return > 0: the user has guessed to the right of the bug
*/
int catchTheBug(int guess, int bugPosition);
#endif

