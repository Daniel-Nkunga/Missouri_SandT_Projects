/*
    Programmer: Daniel Nkunga
    Date: 10/22/2024
    File: NkungaLab09.cpp
    Assignment: Lab 09
    Purpose:
*/

#include <fstream>
#include <iostream>
using namespace std;

string processData(string data);

int main() {
  // Variables
  string stringVariable;
  char charVariable[200];
  ifstream fin;
  ofstream fout; // TODO: Make same as input
  string fileArray[15][200];
  string nextLine;
  int vIndex = 0; // Vercial index

  // Read file
  fin.open("input.txt");
  while (!fin.eof()) {
    getline(fin, nextLine, '\n');
    fileArray[vIndex][0] = nextLine;
    cout << fileArray[vIndex][0] << endl;
    vIndex++;
  }

  cout << "Enter a sentence (up  to 200 characters): ";
  getline(cin, stringVariable);
  fileArray[vIndex][0] = stringVariable;
  vIndex++;
  cout << stringVariable << endl;
  cout << "Enter another sentence (up to the first space): ";
  cin >> stringVariable;
  fileArray[vIndex][0] = stringVariable;
  vIndex++;
  cout << stringVariable << endl;
  cout << "Enter another sentence (character by character): ";
  cin.ignore();
  cin.get(charVariable, 200);
  fileArray[vIndex][0] = charVariable;
  vIndex++;
  cout << charVariable << endl;

  // Close file
  fin.close();

  // Output File
  fout.open("output.txt");
  for (int i = 0; i < 15; i++) {
    fout << fileArray[i][0] << endl
         << processData(fileArray[i][0]) << endl; // ERROR HERE
  }
  fout.close();

  return 0;
}

string processData(string data) {
  int vowels = 0, words = 1;
  for (int j = 0; j < 200; j++) {
    if (data[j] == 65 || data[j] == 69 || data[j] == 73 || data[j] == 79 ||
        data[j] == 85 || data[j] == 97 || data[j] == 101 || data[j] == 105 ||
        data[j] == 111 || data[j] == 117) {
      vowels++;
    }
    if (data[j] == 32) {
      words++;
    }
  }
  return "Vowels: " + to_string(vowels) + " Words: " + to_string(words);
}