/******************************************
* Edgardo Richard Ventura                 *
* Week 8                                  *
* Assignment 1                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <limits> // Needed for std::numeric_limits
#include <stdio.h> //Needed for the getline() function
using namespace std;

int main() {
    /************************************
    * dc = destination city             *
    * mt = miles traveled               *
    * gu = gallons used                 *
    * mpg = miles per gallon            *
    * tmt = total miles traveled        *
    * tc = trip count                   *
    *************************************/
    string dc;
    double mt, gu, mpg;
    double tmt = 0;
    int tc = 0;

    cout << fixed << setprecision(2);

    /* Input Phase */
    while (true) {
        cout << "(Press Ctrl+Z then Enter to stop at anytime)"; 
        cout << "\nEnter destination city : ";
        // Use cin >> for string input, note that this won't allow spaces in the city name
        if (!(cin >> dc)) break; // Check for EOF (Ctrl+Z)

        cout << "   Enter miles traveled: ";
        cin >> mt;
        // Validate numeric input
        while (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input."; 
            cout << "Please enter a valid number for miles traveled: ";
            cin >> mt;
        }

        cout << "     Enter gallons used: ";
        cin >> gu;
        // Validate numeric input and avoid division by zero
        while (cin.fail() || gu == 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input.";
            cout << "Please enter a valid number for gallons used (greater than 0): ";
            cin >> gu;
        }



        /* Process Phase Before (Ctrl+Z) */
        mpg = mt / gu; // Calculate miles per gallon directly

        /* Process Phase After (Ctrl+Z) */
        tmt += mt; // Calculate nTotal Miles Traveled
        tc++; // Calculate Number of Trips



        /* Output Phase Before (Ctrl+Z) */
        cout << "\nDestination City: " << dc << endl;
        cout << "Miles per Gallon: " << mpg << "\n" << endl;
    }



    /* Output Phase After (Ctrl+Z) */
    cout << "\nTotal Miles Traveled: " << tmt << endl;
    cout << "     Number of Trips: " << tc << endl;

    return 0;
}
