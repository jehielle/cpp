// ----------------------------------------------------------------------------
// File name: mainmenu.cpp                                                    -
// Project name: Serendipity                                                  -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 1/17/18                                                     -
// Date of Last Modification: 1/22/18                                         -
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
#include "mainmenu.h"
#include <stdlib.h>

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

	//INPUT FROM USER
	cin.get(userChoice);
	cin.ignore(1000, '\n');

	//WHILE LOOP - MENU REPEAT
	while(userChoice != '4')
	{
		//CHECKS IF INVALID
		do
		{
			invalid = userChoice != '1' && userChoice != '2' &&
					  userChoice != '3' && userChoice != '4';

			if(invalid)
			{
				cout << endl
					 << setw(43) << "***INVALID INPUT - MUST BE 1-4***\n\n";

				cout << setw(30) << "Enter Your Choice: ";
				cin.get(userChoice);
				system("PAUSE");
				system("CLS");
				cin.ignore(1000, '\n');
			}
		}while(invalid);//END DO WHILE

	// SWITCH STATEMENT
		switch(userChoice)
		{
		case '1': cashier();
				break;
		case '2': invmenu();
				break;
		case '3': reports();
				break;
		}

		cout << endl;
		cout << setw(30) << "1.   Cashier Module\n"
			 << setw(41) << "2.   Inventory Database Module\n"
			 << setw(29) << "3.   Report Module\n"
			 << setw(21) << "4.   Exit\n\n"
			 << setw(30) << "Enter Your Choice: ";

		cin.get(userChoice);
		cin.ignore(1000, '\n');
	}//END WHILE

	return 0;
}


/******************************************************************************
 * FUNCTIONS - INVMENU, REPORTS, CASHIER, BOOKINFO
 *****************************************************************************/

/******************************************************************************
 * FUNCTIONS - INVMENU
 *****************************************************************************/
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
// - invalidInvMenu    bool         0                                         -
// - userChoiceInvMenu char         0                                         -
// ----------------------------------------------------------------------------

void invmenu()
{
	const int CENTER_TITLE    = 25;
	const int HORIZONTAL_LINE = 51;

	bool invalidInvMenu;
	char userChoiceInvMenu;

	cout << endl;
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

	//INPUT FROM USER
	cin.get(userChoiceInvMenu);
	cin.ignore(1000, '\n');

	//WHILE LOOP - MENU REPEAT
	while(userChoiceInvMenu != '5')
	{
		do
		{
			invalidInvMenu = userChoiceInvMenu != '1' &&
							 userChoiceInvMenu != '2' &&
							 userChoiceInvMenu != '3' &&
							 userChoiceInvMenu != '4' &&
							 userChoiceInvMenu != '5';

			if(invalidInvMenu)
			{
				cout << endl
					 << setw(43) << "***INVALID INPUT - MUST BE 1-5***\n\n"
					 << setw(30) << "Enter Your Choice: ";

				cin.get(userChoiceInvMenu);
				system("PAUSE");
				system("CLS");
				cin.ignore(1000, '\n');
			}
		}while(invalidInvMenu);

		// SWITCH STATEMENT
		switch(userChoiceInvMenu)
		{
		case '1': lookUpBook();
			break;
		case '2': addBook();
			break;
		case '3': editBook();
			break;
		case '4': deleteBook();
			break;
		}//END SWITCH

		cout << setw(30) << "1.   Look Up a Book\n"
			 << setw(26) << "2.   Add a Book\n"
			 << setw(36) << "3.   Edit a Book’s Record\n"
			 << setw(29) << "4.   Delete a Book\n"
			 << setw(40) << "5.   Return to the Main Menu\n\n"
			 << setw(30) << "Enter Your Choice: ";

		cin.get(userChoiceInvMenu);
		cin.ignore(1000, '\n');

}//END WHILE

}

/******************************************************************************
 * INVMENU STUB FUNCTIONS
 *****************************************************************************/
//lookUpBook
void lookUpBook()
{
	cout << "\nYou selected Look Up Book.\n\n";
}

//addBook
void addBook()
{
	cout << "\nYou selected Add Book.\n\n";
}

//editBook
void editBook()
{
	cout << "\nYou selected Edit Book.\n\n";
}

//deleteBook
void deleteBook()
{
	cout << "\nYou selected Delete Book.\n\n";
}


/******************************************************************************
 * FUNCTIONS - REPORTS
 *****************************************************************************/
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
// - invalidReports    bool         0                                         -
// - userChoiceReports char         0                                         -
// ----------------------------------------------------------------------------

void reports()
{
	const int CENTER_TITLE    = 25;
	const int HORIZONTAL_LINE = 51;

	bool invalidReports;
	char userChoiceReports;

	cout << endl;
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

	//INPUT FROM USER
	cin.get(userChoiceReports);
	cin.ignore(1000, '\n');

	//WHILE LOOP - MENU REPEAT
	while(userChoiceReports != '7')
	{
		do
		{
			invalidReports = userChoiceReports != '1' &&
							 userChoiceReports != '2' &&
							 userChoiceReports != '3' &&
							 userChoiceReports != '4' &&
							 userChoiceReports != '5' &&
							 userChoiceReports != '6' &&
							 userChoiceReports != '7';

			if(invalidReports)
			{
				cout << endl
					 << setw(43) << "***INVALID INPUT - MUST BE 1-7***\n\n";

				cout << setw(30) << "Enter Your Choice: ";
				cin.get(userChoiceReports);
				system("PAUSE");
				system("CLS");
				cin.ignore(1000, '\n');
			}
		}while(invalidReports);

		// SWITCH STATEMENT FOR REPORTS
		switch(userChoiceReports)
		{
		case '1': repListing();
				break;
		case '2': repWholesale();
				break;
		case '3': repRetail();
				break;
		case '4': repQty();
				break;
		case '5': repCost();
				break;
		case '6': repAge();
				break;
		}//END SWITCH

		cout << setw(33) << "1.   Inventory Listing\n"
			 << setw(41) << "2.   Inventory Wholesale Value\n"
			 << setw(38) << "3.   Inventory Retail Value\n"
			 << setw(35) << "4.   Listing by Quantity\n"
			 << setw(31) << "5.   Listing by Cost\n"
			 << setw(30) << "6.   Listing by Age\n"
			 << setw(40) << "7.   Return to the Main Menu\n\n"
			 << setw(30) << "Enter Your Choice: ";

		cin.get(userChoiceReports);
		cin.ignore(1000, '\n');

	}//END WHILE
}


/******************************************************************************
 * REPORTS STUB FUNCTIONS
 *****************************************************************************/
//repListing
void repListing()
{
	cout << "\nYou selected Inventory Listing.\n\n";
}

//repWholesale
void repWholesale()
{
	cout << "\nYou  selected Inventory Wholesale Value.\n\n";
}

//repRetail
void repRetail()
{
	cout << "\nYou selected Inventory Retail Value.\n\n";
}

//repOty
void repQty()
{
	cout <<  "\nYou  selected  Listing By Quantity.\n\n";
}

//repCost
void repCost()
{
	cout << "\nYou  selected  Listing By Cost.\n\n";
}

//repAge
void repAge()
{
	cout << "\nYou  selected  Listing By Age.\n\n";
}


/******************************************************************************
 * FUNCTIONS - CASHIER
 *****************************************************************************/
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// - HORIZONTAL_LINE   integer      51                                        -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// - date              string       nothing                                   -
// - invalidCashier    bool         0                                         -
// - isbn              string       nothing                                   -
// - price             float        0.0                                       -
// - repeat            char         nothing                                   -
// - subtotal          float        0.0                                       -
// - tax               float        0.0                                       -
// - title             string       nothing                                   -
// - total             float        0.0                                       -
// - quantity          int          0
// - userChoiceInvMenu char         0                                         -
// ----------------------------------------------------------------------------

void cashier()
{
	const int HORIZONTAL_LINE = 78;

	string date;
	bool invalidCashier;
	string isbn;
	float price;
	char repeat;
	float subtotal;
	float tax;
	string title;
	float total;
	int quantity;

	cout << endl;

	do
	{
		// INPUT FROM USER
		cout << left
			 << "Serendipity Booksellers\n"
			 << "Cashier Module\n\n";

		cout << "Date: ";
		getline(cin, date);

		cout << "Quantity of Book: ";
		cin  >> quantity;
		cin.ignore(1000, '\n');

		cout << "ISBN: ";
		getline(cin, isbn);

		cout << "Title: ";
		getline(cin, title);

		cout << "Price: ";
		cin  >> price;
		cin.ignore(1000, '\n');

		cout << endl << endl << endl;

		// CALCULATION FOR SALES SLIP
		subtotal = quantity * price;
		tax      = subtotal * 0.06;
		total    = subtotal + tax;

		// SALES SLIP
		cout << "Serendipity Booksellers\n\n";

		cout << "Date: " << date
			 << endl << endl;


		cout << setw(5)  << "Qty"
			 << setw(15) << "ISBN"
			 << setw(22) << "Title"
			 <<	setw(12) << "Price"
			 <<	            "Total"
			 << endl;

		// LINE
		cout << right
			 << setfill('_')
			 << setw(HORIZONTAL_LINE) << " "
			 << endl;
		cout << setfill(' ')
			 << endl;

		cout << fixed << showpoint << setprecision(2);

		// VALUES OF QTY, ISBN, TITLE, PRICE, AND TOTAL
		cout << left
			 << setw(5)  << quantity
			 << setw(15) << isbn
			 << setw(21) << title
			 << "$ "
			 << setw(10) << price
			 << "$ "
			 << 			subtotal;

		cout << endl << endl;

		// SUBTOTAL, TAX, AND TOTAL
		cout << right
			 << setw(20) << "Subtotal"
			 << setw(35) << "$ "<<  subtotal
			 << endl

			 << setw(15) << "Tax"
			 << setw(40) << "$ " << tax
			 << endl

			 << setw(17) << "Total"
			 << setw(38) << "$ " << total
			 << endl << endl;

		cout << setw(40)
			 << "Thank You for Shopping at Serendipity!\n";

		//REPEAT
		cout << "Would you like to process another transaction? (y/n)";
		cin.get(repeat);
		cin.ignore(1000, '\n');
		cout << endl;

		invalidCashier = repeat != 'y' &&
				  	     repeat != 'n' &&
						 repeat != 'Y' &&
						 repeat != 'N';

		if(invalidCashier)
		{
			cout << "*** INVALID INPUT - PLEASE TYPE Y OR N ***\n\n";

			cout << "Would you like to process another transaction? (y/n)";
			cin.get(repeat);
			system("PAUSE");
			system("CLS");
			cin.ignore(1000, '\n');
			cout << endl;
		}//END IF

	}while(repeat == 'Y' || repeat == 'y');
}



/******************************************************************************
 * FUNCTIONS - BOOK INFO
 *****************************************************************************/
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// - CENTER_TITLE      integer      25                                        -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// ----------------------------------------------------------------------------

void bookInfo()
{
	const int CENTER_TITLE    = 25;

	cout << endl;
	cout << setw(CENTER_TITLE) << "Serendipity "
		 << left
		 << setw(CENTER_TITLE) << "Booksellers"
		 << endl;

	cout << right << setw(21) << "Book "
		 << left  << setw(29) << "Information"
		 << right
		 << endl << endl;

	cout << setw(8)  << "ISBN: "      << endl;

	cout << setw(9)  << "Title: "     << endl;

	cout << setw(10) << "Author: "    << endl;

	cout << setw(13) << "Publisher: " << endl;

	cout << setw(14) << "Date Added: "<< endl;

	cout << setw(20) << "Quantity-On-Hand: " << endl;

	cout << setw(18) << "Wholesale Cost: "   << endl;

	cout << setw(16) << "Retail Price: "     << endl << endl;

}
