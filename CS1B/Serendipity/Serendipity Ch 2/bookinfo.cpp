// ----------------------------------------------------------------------------
// File name: bookinfo.cpp                                                     -
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

	// not using CENTER_TITLE here because we don't want it to line up
	// exactly like "Serendipity Booksellers"
	cout << "|"
		 << right << setw(21) << "Book "
		 << left  << setw(29) << "Information"
		 << right
		 << "|"
		 << endl
		 << "|"   << setw(HORIZONTAL_LINE)
		 << "|"
		 << endl;

	cout << "|"
		 << setw(8) << "ISBN: "
		 << setw(43) << "|"
		 << endl;

	cout << "|"
		 << setw(9) << "Title: "
		 << setw(42) << "|"
		 << endl;

	cout << "|"
		 << setw(10) << "Author: "
		 << setw(41) << "|"
		 << endl;

	cout << "|"
		 << setw(13) << "Publisher: "
		 << setw(38) << "|"
		 << endl;

	cout << "|"
		 << setw(14) << "Date Added: "
		 << setw(37) << "|"
		 << endl;

	cout << "|"
		 << setw(20) << "Quantity-On-Hand: "
		 << setw(31) << "|"
		 << endl;

	cout << "|"
		 << setw(18) << "Wholesale Cost: "
		 << setw(33) << "|"
		 << endl;

	cout << "|"
		 << setw(16) << "Retail Price: "
		 << setw(35) << "|"
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
