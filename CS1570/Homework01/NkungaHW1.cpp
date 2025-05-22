// Student ID: dsnf6z
// Section: 1570-102
// Date: 09/03/2024
// File: NkungaHW1.cpp
// Purpose: This is a program contain all parts of assignment one in  CS1570

#include <iostream>
using namespace std;

// Extra imports
#include <cmath>
#include <iomanip>
#include <string>

// Chapter 1: Constants in Our Lives
// Global Constants
float PI = 3.14159265;
float EARTH_GRAVITY = 9.80665; // in meters per second-squared
string WISDOM =
    "Love, Kindness, and Integrity. And always eat your vegetables!";

int main() {
  // Constants
  int HOUR = 60; // Number of mintes in a hour
  float DOLLAR_TO_ACD =
      0.425; // Conversion rate of Dollars to Academic Dollars simplified

  // Variables
  int storyCount;
  int storyDuration = 320;
  int totalHours;   // Total hours of stories being told
  int extraMinutes; // Remaining minutes of storeis being told
  float diameter;
  float circumference;
  float radius; // Derived from diameter
  float area;   // Area of a circle
  char userLetter;
  int asciiValue;
  string sentence; // Sentence containing both userLeter and asciiValue
  bool containsLetter = false;
  bool containsAscii = false;
  int lifeNum; // User input for life truth
  bool lifeTruth;
  string firstWord;
  int dollars;
  float acd;

  // Chapter 2: Piecing Together Stories
  cout << "How many stories did your grandparents share with you? ";
  cin >> storyCount;

  // Checking for valid inputs
  while (storyCount < 1 || storyCount > 20) {
    // TODO: Funny switch staments about values go here
    cout << "Invalid storycount. How many stories did your grandparents share "
            "with you? ";
    cin >> storyCount;
  }

  //  Calculate story duration
  totalHours = storyCount * storyDuration / HOUR;
  extraMinutes = storyCount * storyDuration % HOUR;
  cout << "The storytelling time is " << totalHours << " and " << extraMinutes
       << " minutes." << endl;

  // Chapter 3: Drawing Life's Circles
  // Drawing Circles
  cout << "Enter the diameter of the life's circle you want to draw. ";
  cin >> diameter;

  // Calculation circle circumference
  circumference = diameter * PI;
  radius = diameter / 2.0;
  area = PI * pow(radius, 2);
  cout << "Your life's circle has a circumference of " << circumference
       << " and a area of " << area << endl;

  // Chapter 4: Our Words and Actions
  // ASCII Assignment
  cout << "Give me a character, I'll tell you its ASCII value: ";
  cin >> userLetter;
  asciiValue = static_cast<int>(userLetter);
  cout << "\"" << userLetter << "'s\" ASCII value is " << asciiValue << endl;

  // Sentence creation and validation
  cout << "Can you give me a sentence containing both " << userLetter << " and "
       << asciiValue << "?" << endl;
  cout << "Type a sentence here: ";
  cin.ignore(); // Clearing the buffer
  getline(cin, sentence);
  containsLetter = sentence.find(userLetter) != string::npos;
  containsAscii = sentence.find(to_string(asciiValue)) != string::npos;
  while (!containsLetter || !containsAscii) {
    cout << "Invalid sentence. Type a sentence containing both the character "
            "and its ascii: ";
    cin.ignore();
    getline(cin, sentence);
    containsLetter = sentence.find(userLetter) != string::npos;
    containsAscii = sentence.find(to_string(asciiValue)) != string::npos;
  }

  // Chapter 5: Understanding Truths in Life
  cout << "Enter a number. Let's explore its truthiness in the world of "
          "computers. ";
  cin >> lifeNum;
  lifeTruth =
      lifeNum; // lifeTruth does nothing next live but that's the given equation
  cout << "Truthiness of " << lifeNum
       << " in the world of computers: " << lifeTruth * EARTH_GRAVITY << "."
       << endl;

  // Chapter 6: Stringing Along Memories
  cout << "What's your child's first word going to be? ";
  getline(cin, firstWord);
  cin >> firstWord;
  cout << "Your child's legacy will be tied with " + firstWord +
              " and the values of " + WISDOM + "."
       << endl;

  // Chapter 7: The Value of Money
  cout << "Please enter the amount in USD you wish to convert to ACD: ";
  cin >> dollars;
  acd = dollars * DOLLAR_TO_ACD;
  cout << "Your " << dollars << " USD converts to " << std::fixed
       << std::setprecision(2) << acd << " ACD in the world of Academia."
       << endl;

  return 0;
}
