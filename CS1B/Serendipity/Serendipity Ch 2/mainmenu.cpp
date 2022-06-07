// ----------------------------------------------------------------------------
// File name: mainmenu.cpp                                                    -
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

	cout << "|" << setw(HORIZONTAL_LINE)
		 << "|"
		 << endl;

	cout << "|"
		 <<          setw(CENTER_TITLE) << "Serendipity "
		 << left  << setw(CENTER_TITLE) << "Booksellers"
		 << "|"
		 << endl;

	cout << "|"
		 << right << setw(CENTER_TITLE) << "Main "
		 << left  << setw(CENTER_TITLE) << "Menu"
		 << right
		 << "|"
		 << endl
		 << "|"   << setw(HORIZONTAL_LINE)
		 << "|"
		 << endl;

	cout << "|"
		 << setw(30) << "1.   Cashier Module"
		 << setw(21) << "|"
		 << endl

		 << "|"
		 << setw(41) << "2.   Inventory Database Module"
		 << setw(10) << "|"
		 << endl

		 << "|"
		 << setw(29) << "3.   Report Module"
		 << setw(22) << "|"
		 << endl

		 << "|"
		 << setw(20) << "4.   Exit"
		 << setw(31) << "|"
		 << endl

		 << left
		 << setw(HORIZONTAL_LINE) << "|" << "|"
		 << endl

		 << right
		 << "|"
		 << setw(29) << "Enter Your Choice:"
		 << setw(22) << "|"
		 << endl;

	cout << " "
		 << setfill('_') << setw(HORIZONTAL_LINE)
		 << " "
		 << endl;
	cout << setfill(' ');


	return 0;
}




