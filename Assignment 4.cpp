/******************************************
* Edgardo Richard Ventura                 *
* Week 8                                  *
* Assignment 4                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype> // For std::tolower function
using namespace std;

int main() {
    /************************************
    * pc = product code                 *
    * qty = quantity                    *
    * up = unit price                   *
    * sh = shipping                     *
    * ep = extended price               *
    * to = total order                  *
    * tt = total of all entries         *
    *************************************/

    char pc;        // Product code
    int qty;        // Quantity of the product
    double up, sh;  // Unit price and shipping
    double ep, to;  // Extended price and total order
    double tt = 0;  // Total of all entries
    cout << fixed << setprecision(2);

    /* Input Phase */
    while (true) {
        cout << "(Press Ctrl+Z then Enter to stop)\n";
        bool validProductCode;
        do {
            cout << "Enter product code (W, C, G): ";
            if (!(cin >> pc)) return 0; // Check for EOF (Ctrl+Z) to stop the loop

            pc = tolower(pc); // Convert product code to lowercase for flexibility
            validProductCode = pc == 'w' || pc == 'c' || pc == 'g';

            if (!validProductCode) {
                cout << "Invalid product code. Please try again.\n";
            }
        } while (!validProductCode);

        cout << "              Enter quantity: ";
        cin >> qty;
        // Validate numeric input for quantity
        while (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "               Invalid input\n      Enter a valid quantity: ";
            cin >> qty;
        }

        /* Process Phase */
        switch (pc) {
        case 'w': up = 10.00; sh = 2.00; break;
        case 'c': up = 15.00; sh = 5.00; break;
        case 'g': up = 20.00; sh = 7.00; break;
        }

        /* Process Phase before (ctrl+z) */
        ep = up * qty;   // Calculate extended price
        to = ep + sh;    // Calculate total order

        /* Output Phase for Each Entry */
        cout << "  Product name: ";
        if (pc == 'w')
            cout << "20lb pack of brittish chips" << endl;
        else if (pc == 'c')
            cout << "20lb pack of Dino Nuggies" << endl;
        else if (pc == 'g')
            cout << "20lb pack of Grimace Shake" << endl;
        cout << "\n  Product Code: " << pc << endl;
        cout << "    Unit Price: $" << up << endl;
        cout << "      Shipping: $" << sh << endl;
        cout << "Extended Price: $" << ep << endl;
        cout << "   Total Order: $" << to << "\n" << endl;

        /* Process Phase after (ctrl+z) */
        tt += to; // Accumulate total of all entries
    }

    /* Summary Output Phase */
    cout << "\nTotal of All Orders: $" << tt << endl;

    return 0;
}
