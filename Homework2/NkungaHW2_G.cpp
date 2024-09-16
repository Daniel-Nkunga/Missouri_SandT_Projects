// Programmer: Daniel Nkunga
// Date: 09/10/2024
// File: NkungaHW2_G.cpp
// Assignment: HW2
// Purpose: This file implements a  Ceaser Cypher encryption decryption program
// for Homework 2 of CS1570. The program will run until you specify that you
// want it to end. It will just ask if you want to encrypt or decrypt a message,
// allow you enter a message, then ask for your shift value (encryption key).
//
// Aditional Notes: This program is following The Gosnell Advice (tm) and is
// ignoring the special rules. For a completed assignment following all special
// rules, check NkungaHW2 and NkungaHW2.cpp. Also this was worked backwards from
// the completed program so sorry for any confustion. For Bonus 1 - Shift Values
// Adapability, the block of code limiting the valid shift values from [1-40] is
// commented out so all values are valid.

#include <iostream>
using namespace std;

int main() {
  // Variables
  char encryptDecrypt =
      'x'; // User input will be a e or d; This variable will be set back to
           // 'x' while wating for a vailid input
  string message;
  string newMessage;
  int shiftValue;
  int startingValue;
  int localShift;
  int adjustedShift; // Needed for decryption when mod results in a negative
                     // result
  bool endProgram = false; // Short for "End the program?" If set true, the
                           // program will terminate
  char yesNo;              // User answer to if they want to end the program

  // Keep asking
  do {
    cout << "Encrypt or decrypt a message (e/d): ";
    cin >> encryptDecrypt;

    // Checking for valid input
    if (encryptDecrypt != 'e' &&
        encryptDecrypt !=
            'd') // My do command wasn't working the way I wanted it do; This
                 // could probably be excluded if implemented properly
    {
      do {
        cin.ignore();
        cout
            << "Invalid input. Encrypt or decrypt a message (e/d): "; // TODO:
                                                                      // Maybe
                                                                      // find
                                                                      // the
                                                                      // error
                                                                      // here
                                                                      // when
                                                                      // you
                                                                      // input
                                                                      // an
                                                                      // inproper
                                                                      // value;
                                                                      // hopefully
                                                                      // fixed
                                                                      // with
                                                                      // cin
                                                                      // ignore
                                                                      // above
        cin >> encryptDecrypt;
      } while (encryptDecrypt != 'e' && encryptDecrypt != 'd');
    }

    // Getting the message
    cout << "Enter in your message: ";
    cin.ignore();
    getline(cin, message);

    // Getting the shift value
    cout << "Enter in a shift value: ";
    cin >> shiftValue;
    // The rest of this code is commented out for the bonus part of the
    // assignment
    // if (shiftValue < 0 || shiftValue > 40) {
    //  do {
    //    cout << "Invalid input. Enter in a shift value between [1,40]: ";
    //    cin >> shiftValue;
    //  } while (shiftValue < 0 || shiftValue > 40);
    //}

    // Encryption
    if (encryptDecrypt == 'e') {
      for (size_t i = 0; i < message.size(); i++) {
        // Local variables
        startingValue = message.at(i);
        localShift = shiftValue;

        // Switch Tree: Upper Case, Lower Case, Number Case, and Base Case
        if (startingValue >= 97 &&
            startingValue <=
                122) // The lower case [this section heading is a pun]
        {
          // Adjusting values if negative
          adjustedShift = (startingValue + localShift - 97) % 26;
          if (adjustedShift < 0) {
            adjustedShift += 26;
          }
          newMessage += static_cast<char>(adjustedShift + 97);
        } else if (startingValue >= 65 &&
                   startingValue <=
                       90) // The upper case [this section heading is a pun]
        {
          // Adjusting values if negative
          adjustedShift = (startingValue + localShift - 65) % 26;
          if (adjustedShift < 0) {
            adjustedShift += 26;
          }
          newMessage += static_cast<char>(adjustedShift + 65);
        } else if (startingValue >= 48 &&
                   startingValue <= 57) // The number case
        {
          // Adjusting values if negative
          adjustedShift = (startingValue + localShift - 48) % 10;
          if (adjustedShift < 0) {
            adjustedShift += 10;
          }
          newMessage += static_cast<char>(adjustedShift + 48);
        } else { // Base case
          newMessage += message.at(i);
        }
      }
    } else {
      for (size_t i = 0; i < message.size(); i++) {
        // Local variables
        startingValue = message.at(i);
        localShift = -1 * shiftValue;

        // Switch Tree: Upper Case, Lower Case, Number Case, and Base Case
        if (startingValue >= 97 &&
            startingValue <=
                122) // The lower case [this section heading is a pun]
        {
          // Adjusting values if negative
          adjustedShift = (startingValue + localShift - 97) % 26;
          if (adjustedShift < 0) {
            adjustedShift += 26;
          }
          newMessage += static_cast<char>(adjustedShift + 97);
        } else if (startingValue >= 65 &&
                   startingValue <=
                       90) // The upper case [this section heading is a pun]
        {
          // Adjusting values if negative
          adjustedShift = (startingValue + localShift - 65) % 26;
          if (adjustedShift < 0) {
            adjustedShift += 26;
          }
          newMessage += static_cast<char>(adjustedShift + 65);
        } else if (startingValue >= 48 &&
                   startingValue <= 57) // The number case
        {
          // Adjusting values if negative
          if (adjustedShift < 0) {
            adjustedShift += 10;
          }
          newMessage += static_cast<char>(adjustedShift % 10 + 48);
        } else { // Base case
          newMessage += message.at(i);
        }
      }
    }
    cout << newMessage << endl << endl;

    cout << "Do you want to continue the program? (y/n): ";
    cin >> yesNo;
    if (yesNo == 'n') // The illusion of choice is only checking for no
    {
      endProgram = true;
    }

    // Cleaning things out
    cin.ignore();
    newMessage = "";
  } while (endProgram == false);
  return 0;
}
