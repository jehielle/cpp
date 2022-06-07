// ----------------------------------------------------------------------------
// File name: cashier.cpp                                                     -
// Project name: Serendipity                                                  -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 1/16/18                                                     -
// Date of Last Modification: 1/17/18                                         -
// ----------------------------------------------------------------------------
// Purpose: Serendipity                                                       -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Create the text for the cashier screen.                            -
// Step 2: Align the text so it looks nice and readable.                      -
// Step 3: Create the box around the menu screen.                             -
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// - HORIZONTAL_LINE   integer      78                                        -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// -                                                                          -
// ----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	const int HORIZONTAL_LINE = 78;

	cout << " ";
	cout << setfill('_')
		 << setw(HORIZONTAL_LINE)
		 << " "
		 << endl;
	cout << setfill(' ');

	cout << "|"
		 << setw(HORIZONTAL_LINE)
		 << "|"
		 << endl;

	cout << left
		 << setw(HORIZONTAL_LINE)
		 << "| Serendipity Booksellers"
		 << "|"
		 << endl
		 << setw(HORIZONTAL_LINE) << "|" << "|"
	     << endl;

	cout << left
		 << setw(HORIZONTAL_LINE)
		 << "| Date:"
		 << "|"
		 << endl
		 << setw(HORIZONTAL_LINE) << "|" << "|"
	     << endl;


    cout << left
    	 << setw(8)  << "| Qty"
		 << setw(14) << "ISBN"
		 << setw(32) << "Title"
		 <<	setw(12) << "Price"
		 <<	setw(12) << "Total"
		 << "|"
		 << endl;

	cout << "|"
		 << right
		 << setfill('_')
		 << setw(HORIZONTAL_LINE)
		 << "|"
		 << endl;
	cout << setfill(' ');

	cout << left
		 << setw(HORIZONTAL_LINE) << "|" << "|"
	     << endl
		 << setw(HORIZONTAL_LINE) << "|" << "|"
		 << endl
		 << setw(HORIZONTAL_LINE) << "|" << "|"
		 << endl;

	cout << right
		 << "|"
		 << setw(18) << "Subtotal"
		 << setw(60) << "|"
		 << endl
		 << "|"
		 << setw(13) << "Tax"
		 << setw(65) << "|"
		 << endl
		 << "|"
		 << setw(15) << "Total"
		 << setw(63) << "|"
		 << endl;

	cout << left
		 << setw(HORIZONTAL_LINE) << "|" << "|"
	     << endl;

	cout << setw(HORIZONTAL_LINE)
		 << "| Thank You for Shopping at Serendipity!"
		 << "|"
		 << endl
		 << setw(HORIZONTAL_LINE) << "|" << "|"
	     << endl
		 << setw(HORIZONTAL_LINE) << "|" << "|"
		 << endl;

	cout << setfill('_')
		 << setw(HORIZONTAL_LINE)
		 << " "
		 << endl;
	cout << setfill(' ');


	return 0;
}




