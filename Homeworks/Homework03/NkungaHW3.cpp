// Programmer: Daniel Nkunga
// Date: 09/21/2024
// File: NkungaHW3.cpp
// Assignment: Homework 3
// Purpose:

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
  // Functions
  /* Prints a welcome message for the game.
   * Parameters: None.
   * Returns: None.
   */
  void printWelcomeMessage();

  /* Displays the game menu with options for board size or quitting.
   * Parameters: None.
   * Returns: None.
   */
  void displayMenu();

  /* Initializes the game board with default values.
   * Parameters:
   *   - board: string reference to hold the initialized board.
   *   - boardSize: the dimensions of the board (boardSize x boardSize).
   * Returns: The initialized board as a string.
   */
  string initializeBoard(string & board, int boardSize);

  /* Prints the current state of the game board.
   * Parameters:
   *   - board: string representing the current board state.
   *   - boardSize: dimensions of the board (boardSize x boardSize).
   * Returns: None.
   */
  void printBoard(string board, int boardSize);

  /* Updates the board at a specified position with a player's marker.
   * Parameters:
   *   - board: string reference representing the board to be updated.
   *   - value: the position on the board the player wants to update.
   *   - replacement: the marker (player's symbol) to replace the value.
   * Returns: The updated board as a string.
   */
  string updateBoard(string & board, string & value, string replacement);

  /* Checks if any player has won by forming a valid sequence on the board.
   * Parameters:
   *   - board: string representing the current state of the board.
   *   - boardSize: dimensions of the board.
   *   - value: the player’s marker being checked for a win.
   * Returns:
   *   - 0: No player has won.
   *   - 1: Player 1 has won.
   *   - 2: Player 2 has won.
   */
  int checkWin(string board, int boardSize, char value);

  /* Determines which player won based on their marker.
   * Parameters:
   *   - value: character representing the player’s marker ('S' or 'T').
   * Returns:
   *   - 1: Player 1 ('S') has won.
   *   - 2: Player 2 ('T') has won.
   */
  int whoWon(char value);
  /* Checks if the game has ended in a tie (no more valid moves).
   * Parameters:
   *   - board: string representing the current board state.
   * Returns:
   *   - true: Game is a tie (no valid moves left).
   *   - false: Game is not yet a tie (there are still valid moves).
   */
  bool checkTie(string board);

  /* Displays a message indicating which player won or if the game ended in a
   * tie. Parameters:
   *   - board: string representing the current state of the board.
   *   - boardSize: dimensions of the board.
   *   - player1: string containing the name of Player 1.
   *   - player2: string containing the name of Player 2.
   * Returns: None.
   */
  void printWinMessage(string board, int boardSize, string player1,
                       string player2);

  // Variables
  bool endProgram = false;
  char yesNo = 'x';
  string player1;
  string player2;
  int playerChoice; // Initial player choice on whether or not they want to play
                    // the game or quit
  int boardSize;
  string board = ""; // Initialized to empty string for ease of use
  string value;

  // Getting player names
  printWelcomeMessage();
  cout << "Player 1, enter in your name: ";
  cin >> player1;
  cout << "Player 2, enter in your name: ";
  cin >> player2;

  // Program
  do {
    // Start menu
    displayMenu();
    cout << "What do you want to do: ";
    cin >> playerChoice;
    switch (playerChoice) {
    case 1:
      boardSize = 3;
      break;
    case 2:
      boardSize = 4;
      break;
    case 3:
      boardSize = 5;
      break;
    case 4:
      boardSize = 6;
      break;
    case 5:
      boardSize = 7;
      break;
    case 6:
      boardSize = 8;
      break;
    case 7:
      boardSize = 9;
      break;
    default: // Don't check for eight; All other options end the program
      cout << "Goodbye!" << endl;
      return 0;
    }
    initializeBoard(board, boardSize);

    // Gameplay loop
    do {
      printBoard(board, boardSize);
      cout << player1 << "'s Turn" << endl;
      cout << "Where would you like to play: ";
      cin >> value;
      if (board.find(value) == string::npos) {
        while (board.find(value) == string::npos) {
          cout << "Invalid input. Please enter in the exact positions "
                  "(including any leading zeros) that you want to play: ";
          cin >> value;
        }
      }
      updateBoard(board, value, "SS");
      if (checkWin(board, boardSize, 'S') == true) {
        printBoard(board, boardSize);
        break;
      }
      checkTie(board);

      printBoard(board, boardSize);
      cout << player2 << "'s Turn" << endl;
      cout << "Where would you like to play: ";
      cin >> value;
      if (board.find(value) == string::npos) {
        while (board.find(value) == string::npos) {
          cout << "Invalid input. Please enter in the exact positions "
                  "(including any leading zeros) that you want to play: ";
          cin >> value;
        }
      }
      updateBoard(board, value, "TT");
      if (checkWin(board, boardSize, 'T') == true) {
        printBoard(board, boardSize);
        break;
      }
      checkTie(board);
    } while (checkWin(board, boardSize, 1) == 0 &&
             checkTie(board) == false); // Arbitrary win value
    printWinMessage(board, boardSize, player1, player2);

    cout << "Do you want to play " << endl;
    cout
        << "\n __  __     __         ______   __     __    __     ______     "
           "______   ______    \n/\\ \\/\\ \\   /\\ \\       /\\__  _\\ /\\ \\ "
           "  /\\ \"-./  \\   /\\  __ \\   /\\__  _\\ /\\  ___\\   \n\\ \\ "
           "\\_\\ \\  \\ \\ \\____  \\/_/\\ \\/ \\ \\ \\  \\ \\ \\-./\\ \\  \\ "
           "\\  __ \\  \\/_/\\ \\/ \\ \\  __\\   \n \\ \\_____\\  \\ \\_____\\ "
           "   \\ \\_\\  \\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_\\ \\_\\    \\ "
           "\\_\\  \\ \\_____\\ \n  \\/_____/   \\/_____/     \\/_/   \\/_/   "
           "\\/_/  \\/_/   \\/_/\\/_/     \\/_/   \\/_____/ \n                 "
           "                                                                 "
        << endl;
    cout << " ______   __     ______        ______   ______     ______        "
            "______   ______     ______    \n/\\__  _\\ /\\ \\   /\\  ___\\    "
            "  /\\__  _\\ /\\  __ \\   /\\  ___\\      /\\__  _\\ /\\  __ \\   "
            "/\\  ___\\   \n\\/_/\\ \\/ \\ \\ \\  \\ \\ \\____     \\/_/\\ \\/ "
            "\\ \\  __ \\  \\ \\ \\____     \\/_/\\ \\/ \\ \\ \\/\\ \\  \\ \\  "
            "__\\   \n   \\ \\_\\  \\ \\_\\  \\ \\_____\\       \\ \\_\\  \\ "
            "\\_\\ \\_\\  \\ \\_____\\       \\ \\_\\  \\ \\_____\\  \\ "
            "\\_____\\ \n    \\/_/   \\/_/   \\/_____/        \\/_/   "
            "\\/_/\\/_/   \\/_____/        \\/_/   \\/_____/   \\/_____/ \n    "
            "                                                                  "
            "                         "
         << endl;
    cout << "again? (y/n): ";
    cin >> yesNo;
    if (yesNo == 'n') // The illusion of choice is only checking for no
    {
      cout << "Thanks for playing " << player1 << " and " << player2 << "!"
           << endl;
      endProgram = true;
    }
    board = "";
    cout << endl << endl;
  } while (endProgram == false);
}

void printWelcomeMessage() {
  cout << "Welcome to ";
  cout << "\n __  __     __         ______   __     __    __     ______     "
          "______   ______    \n/\\ \\/\\ \\   /\\ \\       /\\__  _\\ /\\ \\  "
          " /\\ \"-./  \\   /\\  __ \\   /\\__  _\\ /\\  ___\\   \n\\ \\ \\_\\ "
          "\\  \\ \\ \\____  \\/_/\\ \\/ \\ \\ \\  \\ \\ \\-./\\ \\  \\ \\  __ "
          "\\  \\/_/\\ \\/ \\ \\  __\\   \n \\ \\_____\\  \\ \\_____\\    \\ "
          "\\_\\  \\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_\\ \\_\\    \\ \\_\\  \\ "
          "\\_____\\ \n  \\/_____/   \\/_____/     \\/_/   \\/_/   \\/_/  "
          "\\/_/   \\/_/\\/_/     \\/_/   \\/_____/ \n                         "
          "                                                         "
       << endl;
  cout << " ______   __     ______        ______   ______     ______        "
          "______   ______     ______    \n/\\__  _\\ /\\ \\   /\\  ___\\      "
          "/\\__  _\\ /\\  __ \\   /\\  ___\\      /\\__  _\\ /\\  __ \\   /\\ "
          " ___\\   \n\\/_/\\ \\/ \\ \\ \\  \\ \\ \\____     \\/_/\\ \\/ \\ \\ "
          " __ \\  \\ \\ \\____     \\/_/\\ \\/ \\ \\ \\/\\ \\  \\ \\  __\\   "
          "\n   \\ \\_\\  \\ \\_\\  \\ \\_____\\       \\ \\_\\  \\ \\_\\ "
          "\\_\\  \\ \\_____\\       \\ \\_\\  \\ \\_____\\  \\ \\_____\\ \n   "
          " \\/_/   \\/_/   \\/_____/        \\/_/   \\/_/\\/_/   \\/_____/    "
          "    \\/_/   \\/_____/   \\/_____/ \n                                "
          "                                                               "
       << endl;
}

void displayMenu() {
  cout << "Choose the size of the Tic-Tac-Toe board or Quit: " << endl;
  cout << " 1. 3x3 Board\n 2. 4x4 Board\n 3. 5x5 Board\n 4. 6x6 Board\n 5. 7x7 "
          "Board\n 6. 8x8 Board\n 7. 9x9 Board\n 8. Quit the Program"
       << endl;
}

string initializeBoard(string &board, int boardSize) {
  for (int i = 1; i <= boardSize * boardSize; i++) {
    if (i < 10) {
      board += "0";
    }
    board += to_string(i) + " ";
  }
  return board;
}

void printBoard(string board, int boardSize) {
  boardSize = boardSize * 3;
  for (size_t i = 0; i < board.size(); i++) {
    if (i % boardSize == 0 && i != 0) {
      cout << endl;
    }
    cout << board.at(i);
  }
  cout << endl; // For convinece
}

string updateBoard(string &board, string &value, string replacement) {
  size_t pos = board.find(value);
  if (pos != string::npos) {
    board.replace(pos, value.length(),
                  replacement); // updateBoard the substring with "T"
  }
  return board;
}

int whoWon(char value) {
  if (value == 'S') {
    return 1;
  } else {
    return 2;
  }
}

int checkWin(string board, int boardSize, char value) {
  // Checking for vertical wins
  // Visualization A
  for (int i = 0; i < (static_cast<int>(board.size()) - boardSize * 6);
       i += 3) {
    if (board.at(i) == value && board.at(i + 3 * boardSize) == value &&
        board.at(i + 6 * boardSize) == value) {
      if (whoWon(value) == 1) {
        return 1;
      } else {
        return 2;
      }
    }
  }

  // Checking for horizontal wins
  // Visualization B
  for (int i = 0; i < static_cast<int>(board.size()) - 6; i += 3) {
    if (board.at(i) == value && board.at(i + 3) == value &&
        board.at(i + 6) == value && (i + 3) % boardSize != 0 &&
        (i + 6) % boardSize) // Making sure the second and third terms in a
                             // sequence cannot be in the first column prevents
                             // "jank wins" as shown in Visualization C
    {
      if (whoWon(value) == 1) {
        cout << "WINNER WINNER CHICKEN DINNER!" << endl;
        return 1;
      } else {
        cout << "WINNER WINNER CHICKEN DINNER!" << endl;
        return 2;
      }
    }
  }

  // Checking for diagonal wins
  // Visualization D
  for (int i = 0; i <= static_cast<int>(board.size()) - (boardSize * 6) - 9;
       i += 3) // This for loop is "less than or equal to" to account for a 3x3
  {
    if (board.at(i) == value && board.at((i + 3 * boardSize) + 3) == value &&
        board.at((i + 6 * boardSize) + 6) == value) {
      if (whoWon(value) == 1) {
        return 1;
      } else {
        return 2;
      }
    }
  }

  // Checking for diagonal wins
  // Visualization E
  for (int i = static_cast<int>(board.size()) - 1; i >= (boardSize * 6) + 9;
       i -= 3) // This for loop is "greater than or equal to" to account for a
               // 3x3; Iterating in reverse for convience
  {
    if (board.at(i) == value && board.at((i + 3 * boardSize) - 3) == value &&
        board.at((i + 6 * boardSize) - 6) == value) {
      if (whoWon(value) == 1) {
        return 1;
      } else {
        return 2;
      }
    }
  }

  return 0;
}

bool checkTie(string board) {
  for (size_t i = 0; i < board.size(); i++) {
    if (board.at(i) != 'S' && board.at(i) != 'T' && board.at(i) != ' ') {
      return false;
    }
  }
  cout << "It was a tie!" << endl;
  return true;
}

void printWinMessage(string board, int boardSize, string player1,
                     string player2) {
  if (checkWin(board, boardSize, 'S') == 1) {
    cout << player1 << " has Won! It's just that easy! B)" << endl;
  } else if (checkWin(board, boardSize, 'T') == 2) {
    cout << player2 << " has Won! They're just that good! BD" << endl;
  } else {
    cout << "It was a tie! How'd you manage that?" << endl;
  }
}

// Visualization A
//  1 | X | 3
// -----------
//  4 | X | 6
// -----------
//  7 | X | 9

// Visualization B
//  1 | 2 | 3
// -----------
//  X | X | X
// -----------
//  7 | 8 | 9

// Visualization C
//  1 | 2 | 3
// -----------
//  4 | X | X
// -----------
//  X | 8 | 9

// Visualization D
//  X | 2 | 3
// -----------
//  4 | X | 6
// -----------
//  7 | 8 | X

// Visualization E
//  1 | 2 | X
// -----------
//  4 | X | 6
// -----------
//  X | 8 | 9
