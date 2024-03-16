/******************************************
* Edgardo Richard Ventura                 *
* Week 8                                  *
* Assignment 3                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    /************************************
    * ln = last name                    *
    * cr = credits taken                *
    * tu = tuition owed                 *
    * tt = total tuition collected      *
    * ns = number of students           *
    *************************************/

    string ln;      // Last name of the student
    int cr;         // Credits taken by the student
    double tu;      // Tuition owed by the student
    double tt = 0;  // Total tuition collected from all students
    int ns = 0;     // Number of students who entered data
    const double ratePerCredit = 250.0; // Charge $250 per credit hour
    cout << fixed << setprecision(2); // Setting the decimal precision for money

    /* Input Phase */
    // Loop to take inputs until Ctrl+Z is entered
    while (true) {
        cout << "(Press Ctrl+Z then Enter to stop)\n";
        cout << "    Enter last name: ";
        if (!(cin >> ln)) break; // Check for EOF (Ctrl+Z) to stop the loop

        cout << "Enter credits taken: ";
        cin >> cr;
        // Validate numeric input for credits taken
        while (cin.fail() || cr < 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input.\nEnter a valid number of credits taken: ";
            cin >> cr;
        }

        /* Process Phase before (ctrl+z) */
        tu = cr * ratePerCredit; // Calculate tuition for the current student directly

        /* Output Phase for Each Entry */
        cout << "\nStudent: " << ln << endl;
        cout << "Credits: " << cr << endl;
        cout << "Tuition: $" << tu << "\n" << endl;

        /* Process Phase after (ctrl+z) */
        tt += tu; // Accumulate total tuition
        ns++;     // Increment student count
    }

    /* Summary Output Phase */
    cout << "\nTotal Tuition for All Students: $" << tt << endl;
    cout << "      Total Number of Students: " << ns << endl;

    return 0;
}
