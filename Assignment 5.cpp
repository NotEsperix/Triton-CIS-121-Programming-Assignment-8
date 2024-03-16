/******************************************
* Edgardo Richard Ventura                 *
* Week 8                                  *
* Assignment 5                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cctype> // For character manipulation functions
using namespace std;

int main() {
    /************************************
    * dep = department                  *
    * code = course code                *
    * lf = lab fee                      *
    * tlf = total lab fees collected    *
    * nc = number of courses            *
    * avgLf = average lab fee           *
    *************************************/

    string dep, code; // Department and course code
    double lf;        // Lab fee
    double tlf = 0;   // Total lab fees
    int nc = 0;       // Number of courses
    cout << fixed << setprecision(2);

    /* Input Phase */
    while (true) {
        cout << "(Enter 'SOS' for Table of Codes, Ctrl+Z then Enter to stop)\n\n";
        cout << " Enter department: ";
        if (!(cin >> dep)) break; // Check for EOF (Ctrl+Z) to stop the loop

        // Convert department input to uppercase to check for 'SOS'
        string depUpper = dep;
        for (char& c : depUpper) c = toupper(c);

        if (depUpper == "SOS") {
            cout << "\nTable of Codes:\n";
            cout << "Department   Course Code    Lab Fee" << endl;
            cout << "   CIS          101         $50.00 " << endl;
            cout << "   CIS          121         $100.00" << endl;
            cout << "   MAT          111         $25.00 " << endl;
            cout << "   MAT          112         $35.00 " << endl;
            cout << "   ENG          100         $55.00 " << endl;
            cout << "All Others      ---         $50.00 \n" << endl;
            continue;
        }

        bool validDep = dep.length() == 3;
        for (char& c : dep) {
            if (!isalpha(c)) {
                validDep = false;
                break;
            }
            c = toupper(c); // Capitalize department code
        }

        if (!validDep) {
            cout << "Invalid department. Must be 3 letters.\n";
            continue;
        }

        cout << "Enter course code: ";
        cin >> code;

        // Convert course code input to uppercase to check for 'SOS'
        string codeUpper = code;
        for (char& c : codeUpper) c = toupper(c);

        if (codeUpper == "SOS") {
            cout << "\nTable of Codes:\n";
            cout << "Department   Course Code    Lab Fee" << endl;
            cout << "   CIS          101         $50.00 " << endl;
            cout << "   CIS          121         $100.00" << endl;
            cout << "   MAT          111         $25.00 " << endl;
            cout << "   MAT          112         $35.00 " << endl;
            cout << "   ENG          100         $55.00 " << endl;
            cout << "All Others      ---         $50.00 \n" << endl;
            continue;
        }

        bool validCode = code.length() == 3;
        for (char c : code) {
            if (!isdigit(c)) {
                validCode = false;
                break;
            }
        }

        if (!validCode) {
            cout << "Invalid course code. Must be 3 digits.\n";
            continue;
        }

        /* Process Phase  */
        if (dep == "CIS" && code == "101") lf = 50.00;
        else if (dep == "CIS" && code == "121") lf = 100.00;
        else if (dep == "MAT" && code == "111") lf = 25.00;
        else if (dep == "MAT" && code == "112") lf = 35.00;
        else if (dep == "ENG" && code == "100") lf = 55.00;
        else lf = 50.00; // Default lab fee for other courses

        /* Output Phase for Each Entry */
        cout << "\n Department: " << dep << endl;
        cout << "Course Code: " << code << endl;
        cout << "    Lab Fee: $" << lf << "\n" << endl;

        /* Process Phase */
        tlf += lf; // Accumulate total lab fees
        nc++; // Increment course count
    }

    /* Summary Output Phase */
    double avgLf = (nc > 0) ? tlf / nc : 0; // Compute average lab fee
    cout << "\nTotal Lab Fees for All Courses: $" << tlf << endl;
    cout << "               Average Lab Fee: $" << avgLf << endl;

    return 0;
}
