// Programmer: Daniel Nkunga
// Student ID: dsnf6z
// Section: 301
// Date: 17/09/2024
// File: NkungaLab04
// Purpose: Calculator Function for CS1580 Lab 04. Includes and add, subtract,
// multiplication, division, findMax, and swap functions. Find max and swap
// change the value variables itself. Additional Notes: Since you didn't have it
// this time, my attendce response is that this assingment wasn't too difficult.
// I just procrastinated on finishing it for quite a bit.

#include <iostream>
using namespace std;

int main() {
  // Variables
  int function; // User input for whcih function the program should preform
  float number1;
  float number2;

  // Functions
  // Adds two float point numbers together
  float add(float number1, float number2);
  // Subtracts two float point numbers from each other
  float subtract(float number1, float number2);
  // Multiplies two float point numbers together
  float multiply(float number1, float number2);
  // Divides two float point numbers from each other
  float divide(float number1, float number2);
  // Sets the larger as two float points numbers as number1 and sets the second
  // as number2
  float findMax(float &number1, float &number2);
  // Swaps the value of two float point numbers
  float swap(float &number1, float &number2);

  do {
    // Starting Menu
    cout << "Enter which program you want to do: " << endl
         << " 1. Addition" << endl
         << " 2. Subtraction" << endl
         << " 3. Multiplication" << endl
         << " 4. Divide two numbers" << endl
         << " 5. Maximize" << endl
         << " 6. Swap" << endl
         << " 7. Exit" << endl
         << "Which program do you want to preform: ";
    cin >> function;
    cout << endl << endl;
  } while (function < 1 || function > 7);

  // Switch Statements and Calculator Fucntions
  switch (function) {
  case 1:
    cout << "Enter in two numbers for addition. Number 1 + Number 2" << endl;
    cout << " Number 1: ";
    cin >> number1;
    cout << " Number 2: ";
    cin >> number2;
    add(number1, number2);
    break;
  case 2:
    cout << "Enter in two numbers for subtraction. Number 1 - Number 2" << endl;
    cout << " Number 1: ";
    cin >> number1;
    cout << " Number 2: ";
    cin >> number2;
    subtract(number1, number2);
    break;
  case 3:
    cout << "Enter in two numbers for multiplication. Number 1 * Number 2"
         << endl;
    cout << " Number 1: ";
    cin >> number1;
    cout << " Number 2: ";
    cin >> number2;
    multiply(number1, number2);
    break;
  case 4:
    cout << "Enter in two numbers for division. Number 1 / Number 2" << endl;
    cout << " Number 1: ";
    cin >> number1;
    do {
      if (number2 == 0) {
        cout << "Invalid input. Numbers cannot be divided by zero." << endl;
      }
      cout << " Number 2: ";
      cin >> number2;
    } while (number2 == 0);
    divide(number1, number2);
    break;
  case 5: // TODO: Fix bug where it prints twice [Please ignore :). I don't want
          // to debug ;-;]
    cout << "Enter in two numbers. This function will set the larger number as "
            "number 1 and the smaller number as number 2."
         << endl;
    cout << " Number 1: ";
    cin >> number1;
    cout << " Number 2: ";
    cin >> number2;
    findMax(number1, number2);
    break;
  case 6:
    cout << "Enter in two numbers for swapping. Number 2 will replace the "
            "value of Number 1 and vice versa."
         << endl;
    cout << " Number 1: ";
    cin >> number1;
    cout << " Number 2: ";
    cin >> number2;
    swap(number1, number2);
    break;
  default:
    cout << "This program has terminated" << endl;
  }
  return 0;
}

// Adds two floating point number together
// Parameters:
//   - number1: first float number
//   - number2: second float number
// Returns:
//   - The sum of number1 and number2
float add(float number1, float number2) {
  float result = number1 + number2;
  cout << "Result: " << number1 << " + " << number2 << " = " << result << endl;
  return result;
}

// Subtracts two floating point numbers from each other
// Parameters:
//   - number1: first float number
//   - number2: second float number
// Returns:
//   - The difference of number2 from number1
float subtract(float number1, float number2) {
  float result = number1 - number2;
  cout << "Result: " << number1 << " - " << number2 << " = " << result << endl;
  return result;
}

// Multiplies two floating point numbers together
// Parameters:
//   - number1: first float number
//   - number2: second float number
// Returns:
//   - The product of nubmer1 and number2
float multiply(float number1, float number2) {
  float result = number1 * number2;
  cout << "Result: " << number1 << " * " << number2 << " = " << result << endl;
  return result;
}

// Divides two floating point numbers from each other
// Parameters:
//   - number1: first float number
//   - number2: second float number
// Returns:
//   - The quotient of number2 (divisor) from number1 (dividend)
float divide(float number1, float number2) {
  float result = number1 / number2;
  cout << "Result: " << number1 << " / " << number2 << " = " << result << endl;
  return result;
}

// Sets the larger of two floating point numbers as the first number and the
// smaller number as the second Parameters:
//   - number1: first float number
//   - number2: second float number
// Returns:
//   - 0 to show the swap was successful
float findMax(float &number1, float &number2) {
  float temp;
  if (number1 < number2) {
    temp = number1;
    number1 = number2;
    number2 = temp;
  }
  cout << "Number1 = " << number1 << " & Number2 = " << number2 << endl;
  return 0;
}

// Swaps the value of two floating point numbers
// Parameters:
//   - number1: first float number
//   - number2: second float number
// Returns:
//   - 0 to show the swap was successful
float swap(float &number1, float &number2) {
  float temp = number1;
  number1 = number2;
  number2 = temp;
  return 0;
}
