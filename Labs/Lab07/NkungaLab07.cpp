/*
    Programmer: Daniel Nkunga
    Date: 10/08/2024
    File: NkungaLab07.cpp
    Assignment: Lab 07
    Purpose:
*/

#include "NkungaLab07.h"
#include <iostream>
using namespace std;

int main() {
  // Comparison
  cout << "LHS: 8" << endl;
  cout << "RHS: G" << endl;
  if (compareASCII(8, 'G')) {
    cout << "These values have similar ASCII values" << endl;
  } else {
    cout << "These values have wildly different ASCII" << endl;
  }

  cout << endl;
  // Time
  Time time1;
  time1.seconds = 30;
  time1.minutes = 30;
  time1.hours = 10;
  Time time2;
  time2.hours = 10;
  time2.minutes = 10;
  time2.seconds = 10;
  cout << "Time 1: " << time1 << endl << "Time 2: " << time2 << endl;
  Time result = time1 - time2;
  if (time1 > time2) {
    cout << "Time 1 is greater than Time 2" << endl;
  } else {
    cout << "Time 1 is not greater than Time 2" << endl;
  }
  cout << "Time 1 - Time 2 = " << result << endl;
  return 0;
}

// no documentations -15
// input not collected from the user. -3
// 82