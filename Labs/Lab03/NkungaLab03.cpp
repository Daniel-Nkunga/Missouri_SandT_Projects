// Programmer: Daniel Nkunga
// Student ID: dsnf6z
// Section: 301
// Date: 10/09/2024
// File: NkungaLab03
// Purpose: A program running all the assignments for Lab 03. This is a grader
// that tell the amount of students passed, failed, and the aveage score of the
// class.

#include <iostream>
using namespace std;

int main() {
  // Variables
  bool endProgram = false;
  char yesNo;
  int students;   // Number of students in the class
  int score;      // Score for each students
  int passed = 0; // Total number of students that passed
  int failed = 0; // Total number of studnets that failed
  int total = 0;  // Total score of the class to be used by the average later
  float average;  // Average score of the class

  // Loop the program
  do {

    // Initial question of students in class
    cout << "How many students are in your class: ";
    cin >> students;

    // Checking and getting valid input
    if (students < 0 || students > 100) {
      do {
        cout << "Invalid input. How many students are in your class [1, 100]: ";
        cin >> students;
      } while (students < 0 || students > 100);
    }

    for (int i = 0; i < students; i++) {
      // Score per student
      cout << "Please enter the score of student " << i + 1
           << ": "; // Adding one to each studnet so the indexing of students is
                    // more human readable
      cin >> score;
      while (score < 0 || score > 100) {
        cout << "Invalid score. Please enter the score of student " << i + 1
             << " [0, 100]: ";
        cin >> score;
      }

      total += score;
      // Determining pass or fail
      if (score >= 60) {
        passed++;
      } else {
        failed++;
      }
    }

    // Getting the average
    average = total * 1.0 / students;

    // Printing out the facts
    cout << "Class statistics:" << endl;
    cout << "Acerage class score: " << average << endl;
    cout << "Total studnets passed: " << passed << endl;
    cout << "Total students failed: " << failed << endl << endl;

    // Determining if the program should continue
    cout << "Do you want to continue the program (y/n): ";
    cin >> yesNo;
    if (yesNo == 'n') {
      endProgram = true;
    }
    total = 0;
    passed = 0;
    failed = 0;
  } while (endProgram == false);

  return 0;
}
