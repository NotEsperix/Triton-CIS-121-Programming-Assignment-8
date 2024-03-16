/******************************************
* Edgardo Richard Ventura                 *
* Week 8                                  *
* Assignment 2                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/

#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype> // Needed for std::tolower function
using namespace std;

int main() {
    /************************************
    * ln = last name                    *
    * jc = job code                     *
    * hw = hours worked                 *
    * pay = pay for the current entry   *
    * tp = total pay for all entries    *
    * te = total entries                *
    * avgPay = Average Pay              *
    *************************************/

    string ln;     // Last name of the employee
    char jc;       // Job code of the employee
    double hw;     // Hours worked by the employee
    double pay;    // Pay for the current employee
    double tp = 0; // Total pay for all employees
    int te = 0;    // Total number of entries made by employees
    // avgPay is located at the back to ensure avoidence of dividing 0
    cout << fixed << setprecision(2); // Setting the decimal precision for money

    /* Input Phase */
    // Loop to take inputs until Ctrl+Z is entered
    while (true) {
        cout << "(Press Ctrl+Z then Enter to stop)\n";
        cout << "         Enter last name: ";
        if (!(cin >> ln)) break; // Check for EOF (Ctrl+Z) to stop the loop

        bool validJobCode;
        do {
            cout << "Enter job code (L, A, J): ";
            cin >> jc;
            jc = tolower(jc); // Convert job code to lowercase for flexibility

            // Check for valid job code
            validJobCode = jc == 'l' || jc == 'a' || jc == 'j';
            if (!validJobCode) {
                cout << "Invalid job code.\n";
            }
        } while (!validJobCode);

        cout << "      Enter hours worked: ";
        cin >> hw;
        // Validate numeric input for hours worked
        while (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input.\nEnter a valid number of hours worked: ";
            cin >> hw;
        }

        /* Process Phase before (ctrl+z) */
        // Calculating pay based on job code and hours worked
        if (jc == 'l')
            pay = (hw <= 40) ? hw * 25 : 40 * 25 + (hw - 40) * 25 * 1.5;
        else if (jc == 'a')
            pay = (hw <= 40) ? hw * 30 : 40 * 30 + (hw - 40) * 30 * 1.5;
        else // jc == 'j'
            pay = (hw <= 40) ? hw * 50 : 40 * 50 + (hw - 40) * 50 * 1.5;

        /* Process Phase after (ctrl+z) */
        tp += pay; // Accumulate total pay 
        te++;     // Increment entry count 

        /* Output Phase for Each Entry */
        cout << "\nEmployee: " << ln << endl;
        cout << "     Pay: $" << pay << "\n" << endl;
    }

    /* Summary Output Phase */
    double avgPay = (te > 0) ? tp / te : 0; // Avoid division by zero
    cout << "\nTotal Pay for All Employees: $" << tp << endl;
    cout << "    Total Number of Entries: " << te << endl;
    cout << "                Average Pay: $" << avgPay << endl;

    return 0;
}
