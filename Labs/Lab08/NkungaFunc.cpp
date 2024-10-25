#include "NkungaLab08.h"
#include <vector>

using namespace std;

void inputStudentData(int studentCount, Student studentData[]) {
  // Variables
  Student student;
  string studentName;
  int studentID;
  int mathGrade;
  int scienceGrade;
  int englishGrade;

  for (int i = 0; i < studentCount; i++) // Fixed iteration
  {
    cin.ignore();
    cout << "Name of Student " << (i + 1) << ": ";
    getline(cin, studentName);
    cout << "Student ID: ";
    cin >> studentID;
    cout << "Math Grade: ";
    cin >> mathGrade;
    cout << "Science Grade: ";
    cin >> scienceGrade;
    cout << "English Grade: ";
    cin >> englishGrade;

    student = {studentName, studentID, {mathGrade, scienceGrade, englishGrade}};
    studentData[i] = student; // Fixed indexing
  }
}

void storeGrades(Student studentData[], double averages[][3],
                 int studentCount) {
  for (int i = 0; i < studentCount; i++) {
    for (int j = 0; j < 3; j++) {
      averages[i][j] = studentData[i].grades[j]; // Storing the grades
    }
  }
}

void displayStudents(Student studentData[], double averages[][3],
                     int studentCount) {
  for (int i = 0; i < studentCount; i++) {
    cout << endl
         << "Student " << (i + 1) << " " << studentData[i].name
         << " (ID: " << studentData[i].id << ")" << endl;
    cout << "Math: " << studentData[i].grades[0]
         << ", Science: " << studentData[i].grades[1]
         << ", English: " << studentData[i].grades[2] << endl;
    cout << "Average Grade: "
         << (averages[i][0] + averages[i][1] + averages[i][2]) / 3 << endl;
  }
}