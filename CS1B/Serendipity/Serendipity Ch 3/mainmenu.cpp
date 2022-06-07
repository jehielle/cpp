// ----------------------------------------------------------------------------
// File name: mainmenu.cpp                                                    -
// Project name: Serendipity                                                  -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 1/17/18                                                     -
// Date of Last Modification: 1/17/18                                         -
// ----------------------------------------------------------------------------
// Purpose: Serendipity                                                       -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Let the user enter a value.                                        -
// Step 2: Check if the value is acceptable (1-4).                            -
// Step 3: If not acceptable, tell user to enter another value.               -
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
// - invalid           bool         0                                         -
// - userChoice        char         0                                         -
// ----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	const int CENTER_TITLE    = 25;
	const int HORIZONTAL_LINE = 51;

	bool invalid;
	char userChoice;

	cout << 		 setw(CENTER_TITLE) << "Serendipity "
		 << left  << setw(CENTER_TITLE) << "Booksellers"
		 << endl;

	cout << right << setw(CENTER_TITLE) << "Main "
		 << left  << setw(CENTER_TITLE) << "Menu"
		 << right
		 << endl
		 << setw(HORIZONTAL_LINE)
		 << " "
		 << endl;

	cout << setw(30) << "1.   Cashier Module\n"
		 << setw(41) << "2.   Inventory Database Module\n"
		 << setw(29) << "3.   Report Module\n"
		 << setw(21) << "4.   Exit\n\n"
		 << setw(30) << "Enter Your Choice: ";

	do
	{
		cin.get(userChoice);

		invalid = userChoice != '1' && userChoice != '2' &&
				  userChoice != '3' && userChoice != '4';

		if(invalid)
		{
			cout << endl
				 << setw(43) << "***INVALID INPUT - MUST BE 1-4***\n\n";

			cout << setw(30) << "Enter Your Choice: ";
			cin.get(userChoice);
		}

	}while(invalid);


	return 0;
}




