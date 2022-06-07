// ----------------------------------------------------------------------------
// File name: reports.cpp                                                     -
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
// Step 1: Create the text for the menu screen.                               -
// Step 2: Align the text so it looks nice and readable.                      -
// Step 3: Create the box around the menu screen.                             -
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// - CENTER_TITLE      integer      25                                        -
// - HORIZONTAL_LINE   integer      51                                        -
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
	const int CENTER_TITLE    = 25;
	const int HORIZONTAL_LINE = 51;

	cout << " ";
	cout << setfill('_') << setw(HORIZONTAL_LINE)
		 << " "
		 << endl;
	cout << setfill(' ');

	cout << "|"   << setw(HORIZONTAL_LINE)
		 << "|"
		 << endl;

	cout << "|"
		 <<          setw(CENTER_TITLE) << "Serendipity "
		 << left  << setw(CENTER_TITLE) << "Booksellers"
		 << "|"
		 << endl;

	cout << "|"
		 << right
		 << setw(28) << "Reports"
		 << setw(23) << "|"
		 << endl
		 << "|"   << setw(HORIZONTAL_LINE)
		 << "|"
		 << endl;

	cout << "|"
		 << setw(33) << "1.   Inventory Listing"
		 << setw(18) << "|"
		 << endl;

	cout << "|"
		 << setw(41) << "2.   Inventory Wholesale Value"
		 << setw(10) << "|"
		 << endl;

	cout << "|"
		 << setw(38) << "3.   Inventory Retail Value"
		 << setw(13) << "|"
		 << endl;

	cout << "|"
		 << setw(35) << "4.   Listing by Quantity"
		 << setw(16) << "|"
		 << endl;

	cout << "|"
		 << setw(31) << "5.   Listing by Cost"
		 << setw(20) << "|"
		 << endl;

	cout << "|"
		 << setw(30) << "6.   Listing by Age"
		 << setw(21) << "|"
		 << endl;

	cout << "|"
		 << setw(39) << "7.   Return to the Main Menu"
		 << setw(12) << "|"
		 << endl;

	cout << left
		 << setw(HORIZONTAL_LINE) << "|" << "|"
		 << endl;

	cout << right
		 << "|"
		 << setw(29) << "Enter Your Choice:"
		 << setw(22) << "|"
		 << endl;

	cout << left
		 << setw(HORIZONTAL_LINE) << "|" << "|"
		 << endl;

	cout << setfill('_') << setw(HORIZONTAL_LINE)
		 << " "
		 << endl;
	cout << setfill(' ');


	return 0;
}
