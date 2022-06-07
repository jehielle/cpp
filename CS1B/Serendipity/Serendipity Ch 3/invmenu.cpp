// ----------------------------------------------------------------------------
// File name: invmenu.cpp                                                     -
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
// Step 2: Check if the value is acceptable (1-5).                            -
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
// - userChoiceInvMenu char         0                                         -
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
	char userChoiceInvMenu;

	cout << 		 setw(CENTER_TITLE) << "Serendipity "
		 << left  << setw(CENTER_TITLE) << "Booksellers"
		 << endl;

	cout << right << setw(CENTER_TITLE) << "Inventory "
		 << left  << setw(CENTER_TITLE) << "Database"
		 << right
		 << endl
		 << setw(HORIZONTAL_LINE)
		 << " "
		 << endl;

	cout << setw(30) << "1.   Look Up a Book\n"
		 << setw(26) << "2.   Add a Book\n"
		 << setw(36) << "3.   Edit a Book’s Record\n"
		 << setw(29) << "4.   Delete a Book\n"
		 << setw(40) << "5.   Return to the Main Menu\n\n"
		 << setw(30) << "Enter Your Choice: ";


	do
	{
		cin.get(userChoiceInvMenu);

		invalid = userChoiceInvMenu != '1' && userChoiceInvMenu != '2' &&
				  userChoiceInvMenu != '3' && userChoiceInvMenu != '4' &&
				  userChoiceInvMenu != '5';

		if(invalid)
		{
			cout << endl
				 << setw(43) << "***INVALID INPUT - MUST BE 1-5***\n\n"
			 	 << setw(30) << "Enter Your Choice: ";

			cin.get(userChoiceInvMenu);
		}

	}while(invalid);


	return 0;
}
