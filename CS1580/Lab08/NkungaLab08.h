#ifndef NKUNGA
#define NKUNGA

#include <iostream>
#include <vector>
using namespace std;

struct Student
{
    string name;
    int id;
    int grades[3];
};  

/*
    Definition: Fills in the Array of Student Data
    Precondition:
        - studentCount: interger total number of studnets the user is filling in
        - studentData: array of Students that will be filled
    Postcondition:
        - Will modify studentData to be filled in with information prompted
*/
void inputStudentData(int studentCount, Student studentData[]);
/*
    Definition: Stores grades in 2D Array
    Precondition:
        - studentData: array of Students that will be referenced
        - averages: 2D array of of Strings and Arrays that will be modified
        - studentCount: interger total number of studnets the user is filling in
    Postcondition:
        - Will modify averages to include the student name and their three respective grades
*/
void storeGrades(Student studentData[], double averages[][3], int studentCount);
/*
    Definition: Displays the student information from a array of students
    Precondition:
        - studentData: array of Students that will be referenced
        - averages: array of Student names and individual grades that will be referenced
        - studentCount: interger total number of studnets the user is filling in
    Postcondition:
        - Will print out a message showing the student name, id, grades across all subjects, and average grade
*/
void displayStudents(Student studentData[], double averages[][3], int studentCount);

#endif