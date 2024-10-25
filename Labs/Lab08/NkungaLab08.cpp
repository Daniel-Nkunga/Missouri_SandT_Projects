/*
    Programmer: Daniel Nkunga
    Date: 10/08/2024
    File: NkungaLab08.cpp
    Assignment: Lab 08
    Purpose:
*/

#include "NkungaLab08.h"
#include <iostream>
using namespace std;

int main() {
  // Variables
  int studentCount = 999;

  cout << "Enter the number of students: ";
  cin >> studentCount;
  Student studentData[999];
  double averages[999][3]; // Assuming you want to store the grades as averages

  inputStudentData(studentCount, studentData);
  storeGrades(studentData, averages, studentCount);
  displayStudents(studentData, averages, studentCount);

  return 0;
}

/// 100