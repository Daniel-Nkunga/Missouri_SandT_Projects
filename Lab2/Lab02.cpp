// Programmer: Daniel Nkunga
// Student ID: dsnf6z
// Section: 301
// Date: 03/09/2024
// File: Lab02
// Purpose: A program running all the assignments for Lab 02.
// The program will first ask you to toggle between different
// parts of the assignment then proccede with the following part.

#include <iostream>
using namespace std;

float AVG_FLIGHT_HOURS = 65.5; //Average flight hours per week the airline 
// expirences; set amount

int main()
{
    //Sention Title
    cout << "Lab 2-2: Airlines Ratings Calculator" << endl << endl;

    //Variables
    int travelers; //Number of travelers on the airline this week
    int tags; //Number of social media tags of the airline this week
    int cancelations; //Number of airline flight cancellations this week
    float rating; //The rating of the airline

    //Querying
    cout << "How many travelers were there this week? Enter interger: ";
    cin >> travelers;
    cout << "How many times was the airline tagged this week? Enter interger: ";
    cin >> tags;
    cout << "How many times did the airline cancel flights this week? Enter interger: ";
    cin >> cancelations;

    //Calculations
    rating = (travelers + tags + AVG_FLIGHT_HOURS)/cancelations;
    cout << "The rating of the airline is " << rating << "." << endl;

    //Section Title
    cout << endl << "Lab 2-3: Conversion Calculator" << endl << endl; //miles to kilometers

    //Variables
    float KM_TO_MILES = 1.60934;
    float MILES_TO_YARDS = 1759.995625;
    float PI = 3.14159;
    int num_of_yards = 100;
    float input;
    float distance; //In kilometers
    float time; 
    float football_fields;
    float square;
    float circumference;

    //Querying
    cout << "Please enter the distance in miles: ";
    cin >> input;

    //Assignments
    distance = input * KM_TO_MILES;
    time = input / 60;
    football_fields = input * MILES_TO_YARDS / num_of_yards;
    square = distance * distance;
    circumference = PI *distance;

    cout << "1. Distance in kilometers:" << distance << " kilometers." << endl;
    cout << "2. Time to cover the distance at 60 miles per hour: " << time << " hours." << endl;
    cout << "3. Equivalent number of football fields: " << football_fields << " football fields." << endl;
    cout << "4. Area of a square with side length equal to the converted distance: " << square << " square kilometers." << endl;
    cout << "5. Circumference of a circle with a radius equal to half the converted distance: " << circumference << " kilometers." << endl;


    return 0;
}

// Concept of global and local constant not captured - 10
// 90