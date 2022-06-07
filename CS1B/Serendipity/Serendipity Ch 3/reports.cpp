// ----------------------------------------------------------------------------
// File name: reports.cpp                                                     -
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
// Step 2: Check if the value is acceptable (1-7).                            -
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
// - userChoiceReports char         0                                         -
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
	char userChoiceReports;

	cout << 		 setw(CENTER_TITLE) << "Serendipity "
		 << left  << setw(CENTER_TITLE) << "Booksellers"
		 << endl;

	cout << right
		 << setw(28) << "Reports"
		 << endl
		 << setw(HORIZONTAL_LINE)
		 << " "
		 << endl;

	cout << setw(33) << "1.   Inventory Listing\n"
		 << setw(41) << "2.   Inventory Wholesale Value\n"
		 << setw(38) << "3.   Inventory Retail Value\n"
		 << setw(35) << "4.   Listing by Quantity\n"
		 << setw(31) << "5.   Listing by Cost\n"
		 << setw(30) << "6.   Listing by Age\n"
		 << setw(40) << "7.   Return to the Main Menu\n\n"
		 << setw(30) << "Enter Your Choice: ";

	do
	{
		cin.get(userChoiceReports);

		invalid = userChoiceReports != '1' && userChoiceReports != '2' &&
				  userChoiceReports != '3' && userChoiceReports != '4' &&
				  userChoiceReports != '5' && userChoiceReports != '6' &&
				  userChoiceReports != '7';

		if(invalid)
		{
			cout << endl
				 << setw(43) << "***INVALID INPUT - MUST BE 1-7***\n\n";

			cout << setw(30) << "Enter Your Choice: ";
			cin.get(userChoiceReports);
		}

	}while(invalid);

	return 0;
}
