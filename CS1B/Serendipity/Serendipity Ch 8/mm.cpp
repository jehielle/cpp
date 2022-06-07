// ----------------------------------------------------------------------------
// File name: mm.cpp                                                          -
// Project name: Serendipity                                                  -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 1/17/18                                                     -
// Date of Last Modification: 3/2/18                                          -
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
// - NUM_OF_BOOKS      integer      20                                        -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// - invalid           bool         0                                         -
// - userChoice        char         0                                         -
// - bookTitle[]       string       -                                         -
// - isbn[]            string       -                                         -
// - author[]          string       -                                         -
// - publisher[]       string       -                                         -
// - dateAdded[]       string       -                                         -
// - qtyOnHand[]       int          0                                         -
// - wholesale[]       double       0.0                                       -
// - retail[]          double       0.0                                       -
// ----------------------------------------------------------------------------

#include <stdlib.h>
#include <limits>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//GLOBAL CONSTANTS
const int DBSIZE = 20; //the number of book records the arrays can handle

//FUNCTION PROTOTYPES
void cashier(string bookTitle[],
		 	 string isbn[],
			 string author[],
			 string publisher[],
			 string dateAdded[],
			 int    qtyOnHand[],
		 	 double wholesale[],
			 double retail[]);

void invmenu(string bookTitle[],
			 string isbn[],
			 string author[],
			 string publisher[],
			 string dateAdded[],
			 int    qtyOnHand[],
			 double wholesale[],
			 double retail[],
			 int    bookCount);

void reports(string bookTitle[],
		 	 string isbn[],
			 string author[],
			 string publisher[],
			 string dateAdded[],
			 int    qtyOnHand[],
			 double wholesale[],
			 double retail[]);

void bookInfo(string isbn,
			  string title,
			  string author,
			  string publisher,
			  string dateAdded,
			  int    qtyOnHand,
			  double wholesale,
			  double retail);

//STUB FUNCTIONS FOR INVMENU
void lookUpBook(string bookTitle[],
				string isbn[],
				string author[],
				string publisher[],
				string dateAdded[],
				int    qtyOnHand[],
				double wholesale[],
				double retail[]);
void addBook(int &bookCount,
			string bookTitle[],
			string isbn[],
			string author[],
			string publisher[],
			string dateAdded[],
			int    qtyOnHand[],
			double wholesale[],
			double retail[]);
void editBook(int &bookCount,
			  string bookTitle[],
 	 		  string isbn[],
			  string author[],
			  string publisher[],
			  string dateAdded[],
			  int    qtyOnHand[],
			  double wholesale[],
			  double retail[]);
void deleteBook(string bookTitle[],
				string isbn[],
				string author[],
				string publisher[],
				string dateAdded[],
				int    qtyOnHand[],
				double wholesale[],
				double retail[]);

//STUB FUNCTIONS FOR REPORTS
void repListing(string bookTitle[],
				string isbn[],
				string author[],
				string publisher[],
				string dateAdded[],
				int    qtyOnHand[],
				double wholesale[],
				double retail[]);
void repWholesale(string bookTitle[],
				string isbn[],
				string author[],
				string publisher[],
				string dateAdded[],
				int    qtyOnHand[],
				double wholesale[],
				double retail[]);
void repRetail(string bookTitle[],
				string isbn[],
				string author[],
				string publisher[],
				string dateAdded[],
				int    qtyOnHand[],
				double wholesale[],
				double retail[]);
void repQty(string bookTitle[],
				string isbn[],
				string author[],
				string publisher[],
				string dateAdded[],
				int    qtyOnHand[],
				double wholesale[],
				double retail[]);
void repCost(string bookTitle[],
				string isbn[],
				string author[],
				string publisher[],
				string dateAdded[],
				int    qtyOnHand[],
				double wholesale[],
				double retail[]);
void repAge(string bookTitle[],
				string isbn[],
				string author[],
				string publisher[],
				string dateAdded[],
				int    qtyOnHand[],
				double wholesale[],
				double retail[]);

int main()
{
	const int CENTER_TITLE    = 25;
	const int HORIZONTAL_LINE = 51;

	bool invalid;
	char userChoice;
	int  bookCount; //number of books currently in database

	//ARRAYS
	string bookTitle[DBSIZE];
	string isbn[DBSIZE];
	string author[DBSIZE];
	string publisher[DBSIZE];
	string dateAdded[DBSIZE];
	int    qtyOnHand[DBSIZE];
	double wholesale[DBSIZE];
	double retail[DBSIZE];

	bookCount = 0;	//initializing
	
	//CLEAR THE SCREEN
	system("CLS");

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
	
	//CLEAR THE SCREEN
	system("CLS");

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
					 
				cout << right << setw(CENTER_TITLE) << "Serendipity "
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
					 
				cin.get(userChoice);
				system("PAUSE");
				system("CLS");
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}while(invalid);//END DO WHILE

	// SWITCH STATEMENT
		switch(userChoice)
		{
		case '1': cashier(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);
				break;
		case '2': invmenu(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount);
				break;
		case '3': reports(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);
				break;
		}

		//CLEAR THE SCREEN
		system("CLS");

		cout << endl;
		cout << right << setw(CENTER_TITLE) << "Serendipity "
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

void invmenu(string bookTitle[],
			 string isbn[],
			 string author[],
			 string publisher[],
			 string dateAdded[],
			 int    qtyOnHand[],
			 double wholesale[],
			 double retail[],
			 int    bookCount)
{
	const int CENTER_TITLE    = 25;
	const int HORIZONTAL_LINE = 51;

	bool invalidInvMenu;
	char userChoiceInvMenu;
	
	//CLEAR THE SCREEN
	system("CLS");

	cout << right << endl;
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
		 << setw(36) << "3.   Edit a Book\'s Record\n"
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
					 << setw(43) << "***INVALID INPUT - MUST BE 1-5***\n\n";

				cout << right << setw(CENTER_TITLE) << "Serendipity "
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
					 << setw(36) << "3.   Edit a Book\'s Record\n"
					 << setw(29) << "4.   Delete a Book\n"
					 << setw(40) << "5.   Return to the Main Menu\n\n"
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
		case '1': lookUpBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);
			break;
		case '2': addBook(bookCount, bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);
			break;
		case '3': editBook(bookCount, bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);
			break;
		case '4': deleteBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);
			break;
		}//END SWITCH
		
		//CLEAR THE SCREEN
		system("CLS");

		cout << right << endl;
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
			 << setw(36) << "3.   Edit a Book\'s Record\n"
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
void lookUpBook(string bookTitle[],
 	 			string isbn[],
				string author[],
				string publisher[],
				string dateAdded[],
				int    qtyOnHand[],
				double wholesale[],
				double retail[])
{
	string searchlookUpBook;
	char   viewRecord;
	int    index;
	int    location;
	
	index = 0;

	cout << ">>> BOOK LOOK UP <<<";
	cout << endl << endl;
	cout << "> Search: ";
	getline(cin, searchlookUpBook);
	
	while(location == -1 && index < DBSIZE)
	{
		location = bookTitle[index].find(searchlookUpBook);
		
		if(location != -1)
		{
			cout << endl << endl;
			cout << "> RESULT: " << bookTitle[index];
			cout << endl;
		
			do
			{
				cout << "View this book record? (y/n)";
				cin.get(viewRecord);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				if(viewRecord != 'y' || viewRecord != 'Y' || viewRecord != 'n' || viewRecord != 'N')
				{
					cout << "\n\n*** INVALID INPUT - PLEASE TYPE Y OR N ***\n\n";
					
					cout << "View this book record? (y/n)";
					cin.get(viewRecord);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}while(viewRecord != 'y' || viewRecord != 'Y' || viewRecord != 'n' || viewRecord != 'N');
		
			if(viewRecord == 'y' || viewRecord == 'Y')
			{
				bookInfo(isbn[index], 
						 bookTitle[index],
						 author[index],
						 publisher[index],
						 dateAdded[index],
						 qtyOnHand[index],
						 wholesale[index],
						 retail[index]);
			}//ENDIF
		}//ENDIF
	}
	
	if(index == 20)
	{
		cout << endl << endl;
		cout << "> BOOK WAS NOT FOUND.\n\n";
		system("PAUSE");
	}

}

//addBook
void addBook(int   &bookCount,
			string bookTitle[],
			string isbn[],
			string author[],
			string publisher[],
			string dateAdded[],
			int    qtyOnHand[],
			double wholesale[],
			double retail[])
{

	int  userChoiceAddBook;
	bool invalidAddBook;

	qtyOnHand[bookCount] = 0;
	wholesale[bookCount] = 0.0;
	retail[bookCount]    = 0.0;

	do
	{
		system("CLS");

		cout << right    << setprecision(2) << fixed;
		cout << setw(55) << "SERENDIPITY BOOKSELLERS";
		cout << endl;
		cout << setw(50) << "ADD BOOK";
		cout << endl << endl;
		cout << setw(65) << "DATABASE SIZE: " << DBSIZE << " CURRENT BOOK COUNT: " << bookCount + 1;
		cout << endl << endl;
		cout << setw(68) << "-- PENDING VALUES";
		cout << endl;

		cout << left;
		cout << setw(36) << " <1>  Enter Book Title"              << "> --" << bookTitle[bookCount];
		cout << endl;
		cout << setw(36) << " <2>  Enter ISBN"                    << "> --" << isbn[bookCount];
		cout << endl;
		cout << setw(36) << " <3>  Enter Author"                  << "> --" << author[bookCount];
		cout << endl;
		cout << setw(36) << " <4>  Enter Publisher"               << "> --" << publisher[bookCount];
		cout << endl;
		cout << setw(36) << " <5>  Enter Date Added (mm/dd/yyyy)" << "> --" << dateAdded[bookCount];
		cout << endl;
		cout << setw(36) << " <6>  Enter Quantity On Hand"        << "> --" << qtyOnHand[bookCount];
		cout << endl;
		cout << setw(36) << " <7>  Enter Wholesale Cost"          << "> --$"<< wholesale[bookCount];
		cout << endl;
		cout << setw(36) << " <8>  Enter Retail Price"            << "> --$"<< retail[bookCount];
		cout << endl;
		cout << setw(36) << " <9>  Save Book to Database";
		cout << endl;
		cout << setw(36) << " <0>  Return to Inventory Menu";
		cout << endl;
		cout << endl     << endl;

		do
		{
			cout << "Choice <0-9>: ";
			cin  >> userChoiceAddBook;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			invalidAddBook = userChoiceAddBook < 0 || userChoiceAddBook > 9;

			if(invalidAddBook)
			{
				cout << "\n*** ERROR - PLEASE SELECT A VALUE 0-9 ***\n\n";
			}
		}while(invalidAddBook);

		switch(userChoiceAddBook)
		{
		case 1: cout << "\nEnter book title: ";
				getline(cin, bookTitle[bookCount]);
		break;
		case 2: cout << "\nEnter ISBN number: ";
				getline(cin, isbn[bookCount]);
		break;
		case 3: cout << "\nEnter author name: ";
				getline(cin, author[bookCount]);
		break;
		case 4: cout << "\nEnter publisher: ";
				getline(cin, publisher[bookCount]);
		break;
		case 5: cout << "\nEnter date: ";
				getline(cin, dateAdded[bookCount]);
		break;
		case 6: cout << "\nEnter quantity on hand: ";
				cin >> qtyOnHand[bookCount];
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
		break;
		case 7: cout << "\nEnter wholesale cost: ";
				cin >> wholesale[bookCount];
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
		break;
		case 8: cout << "\nEnter retail price: ";
				cin >> retail[bookCount];
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
		break;
		case 9: do
				{
					bookCount++;

					if(bookCount < DBSIZE)
					{
						qtyOnHand[bookCount] = 0;
						wholesale[bookCount] = 0.0;
						retail[bookCount]    = 0.0;
					}
					else if(bookCount >= DBSIZE)
					{
						cout << "\n*** ERROR - NUMBER OF BOOKS STORED HAS REACHED ITS LIMIT ***\n\n";
						bookCount--;
						
						system("PAUSE");
					}
				}while(bookCount > 19);
		break;
		}//END SWITCH
	}while(userChoiceAddBook != 0);
}//END ADDBOOK FUNCTION

//editBook
void editBook(int &bookCount,
			  string bookTitle[],
 	 		  string isbn[],
			  string author[],
			  string publisher[],
			  string dateAdded[],
			  int    qtyOnHand[],
			  double wholesale[],
			  double retail[])
{
	string searchEditBook;
	int    index;
	char   viewRecord;
	int    location;
	
	index = 0;
	
	system("CLS");

	cout << right    << setprecision(2) << fixed;
	cout << setw(55) << "SERENDIPITY BOOKSELLERS";
	cout << endl;
	cout << setw(50) << "EDIT BOOK";
	cout << endl << endl;
	cout << setw(65) << "DATABASE SIZE: " << DBSIZE << " CURRENT BOOK COUNT: " << bookCount + 1;
	cout << endl << endl;
	
	cout << ">Search: ";
	getline(cin, searchEditBook);
	
	while(location == -1 && index < DBSIZE)
	{
		location = bookTitle[index].find(searchEditBook);
		
		if(location != -1)
		{
			cout << endl << endl;
			cout << "> RESULT: " << bookTitle[index];
			cout << endl;
		
			do
			{
				cout << "View this book record? (y/n)";
				cin.get(viewRecord);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				if(viewRecord != 'y' || viewRecord != 'Y' || viewRecord != 'n' || viewRecord != 'N')
				{
					cout << "\n\n*** INVALID INPUT - PLEASE TYPE Y OR N ***\n\n";
					
					cout << "View this book record? (y/n)";
					cin.get(viewRecord);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}while(viewRecord != 'y' || viewRecord != 'Y' || viewRecord != 'n' || viewRecord != 'N');
		
			if(viewRecord == 'y' || viewRecord == 'Y')
			{
				bookInfo(isbn[index], 
						 bookTitle[index],
						 author[index],
						 publisher[index],
						 dateAdded[index],
						 qtyOnHand[index],
						 wholesale[index],
						 retail[index]);
			}//ENDIF
		}//ENDIF
	}
	
	if(index == 20)
	{
		cout << endl << endl;
		cout << "> BOOK WAS NOT FOUND.\n\n";
		system("PAUSE");
	}

}

//deleteBook
void deleteBook(string bookTitle[],
		 	 	string isbn[],
				string author[],
				string publisher[],
				string dateAdded[],
				int    qtyOnHand[],
				double wholesale[],
				double retail[])
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

void reports(string bookTitle[],
		 	 string isbn[],
			 string author[],
			 string publisher[],
			 string dateAdded[],
			 int    qtyOnHand[],
			 double wholesale[],
			 double retail[])
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
		case '1': repListing(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);
				break;
		case '2': repWholesale(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);
				break;
		case '3': repRetail(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);
				break;
		case '4': repQty(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);
				break;
		case '5': repCost(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);
				break;
		case '6': repAge(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);
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
void repListing(string bookTitle[],
		string isbn[],
		string author[],
		string publisher[],
		string dateAdded[],
		int    qtyOnHand[],
		double wholesale[],
		double retail[])
{
	cout << "\nYou selected Inventory Listing.\n\n";
}

//repWholesale
void repWholesale(string bookTitle[],
		string isbn[],
		string author[],
		string publisher[],
		string dateAdded[],
		int    qtyOnHand[],
		double wholesale[],
		double retail[])
{
	cout << "\nYou  selected Inventory Wholesale Value.\n\n";
}

//repRetail
void repRetail(string bookTitle[],
		string isbn[],
		string author[],
		string publisher[],
		string dateAdded[],
		int    qtyOnHand[],
		double wholesale[],
		double retail[])
{
	cout << "\nYou selected Inventory Retail Value.\n\n";
}

//repOty
void repQty(string bookTitle[],
		string isbn[],
		string author[],
		string publisher[],
		string dateAdded[],
		int    qtyOnHand[],
		double wholesale[],
		double retail[])
{
	cout <<  "\nYou  selected  Listing By Quantity.\n\n";
}

//repCost
void repCost(string bookTitle[],
		string isbn[],
		string author[],
		string publisher[],
		string dateAdded[],
		int    qtyOnHand[],
		double wholesale[],
		double retail[])
{
	cout << "\nYou  selected  Listing By Cost.\n\n";
}

//repAge
void repAge(string bookTitle[],
		string isbn[],
		string author[],
		string publisher[],
		string dateAdded[],
		int    qtyOnHand[],
		double wholesale[],
		double retail[])
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
// - dateC             string       nothing                                   -
// - invalidCashier    bool         0                                         -
// - isbnC             string       nothing                                   -
// - priceC            float        0.0                                       -
// - repeatC           char         nothing                                   -
// - subtotalC         float        0.0                                       -
// - taxC              float        0.0                                       -
// - titleC            string       nothing                                   -
// - totalC            float        0.0                                       -
// - quantityC         int          0
// - userChoiceInvMenu char         0                                         -
// ----------------------------------------------------------------------------

void cashier(string bookTitle[],
		 	 string isbn[],
			 string author[],
			 string publisher[],
			 string dateAdded[],
			 int    qtyOnHand[],
		 	 double wholesale[],
			 double retail[])
{
	const int HORIZONTAL_LINE = 78;

	string dateC;
	bool invalidCashier;
	string isbnC;
	float priceC;
	char repeatC;
	float subtotalC;
	float taxC;
	string titleC;
	float totalC;
	int quantityC;

	cout << endl;

	do
	{
		// INPUT FROM USER
		cout << left
			 << "Serendipity Booksellers\n"
			 << "Cashier Module\n\n";

		cout << "Date: ";
		getline(cin, dateC);

		cout << "Quantity of Book: ";
		cin  >> quantityC;
		cin.ignore(1000, '\n');

		cout << "ISBN: ";
		getline(cin, isbnC);

		cout << "Title: ";
		getline(cin, titleC);

		cout << "Price: ";
		cin  >> priceC;
		cin.ignore(1000, '\n');

		cout << endl << endl << endl;

		// CALCULATION FOR SALES SLIP
		subtotalC = quantityC * priceC;
		taxC      = subtotalC * 0.06;
		totalC    = subtotalC + taxC;

		// SALES SLIP
		cout << "Serendipity Booksellers\n\n";

		cout << "Date: " << dateC
			 << endl     << endl;


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
			 << setw(5)  << quantityC
			 << setw(15) << isbnC
			 << setw(21) << titleC
			 << "$ "
			 << setw(10) << priceC
			 << "$ "
			 << 			subtotalC;

		cout << endl << endl;

		// SUBTOTAL, TAX, AND TOTAL
		cout << right
			 << setw(20) << "Subtotal"
			 << setw(35) << "$ "<<  subtotalC
			 << endl

			 << setw(15) << "Tax"
			 << setw(40) << "$ " << taxC
			 << endl

			 << setw(17) << "Total"
			 << setw(38) << "$ " << totalC
			 << endl << endl;

		cout << setw(40)
			 << "Thank You for Shopping at Serendipity!\n";

		//REPEAT
		cout << "Would you like to process another transaction? (y/n)";
		cin.get(repeatC);
		cin.ignore(1000, '\n');
		cout << endl;

		invalidCashier = repeatC != 'y' &&
				  	     repeatC != 'n' &&
						 repeatC != 'Y' &&
						 repeatC != 'N';

		if(invalidCashier)
		{
			cout << "*** INVALID INPUT - PLEASE TYPE Y OR N ***\n\n";

			cout << "Would you like to process another transaction? (y/n)";
			cin.get(repeatC);
			system("PAUSE");
			system("CLS");
			cin.ignore(1000, '\n');
			cout << endl;
		}//END IF

	}while(repeatC == 'Y' || repeatC == 'y');
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

void bookInfo(string isbn,
			  string title,
			  string author,
			  string publisher,
			  string dateAdded,
			  int    qtyOnHand,
			  double wholesale,
			  double retail)
{
	const int CENTER_TITLE    = 25;

	cout << endl;
	cout << setw(CENTER_TITLE) << "Serendipity "
		 << left
		 << setw(CENTER_TITLE) << "Booksellers"
		 << endl;

	cout << right << setw(21)  << "Book "
		 << left  << setw(29)  << "Information"
		 << right
		 << endl  << endl;

	cout << setw(8)  << "ISBN: "             << isbn     		<< endl;

	cout << setw(9)  << "Title: "            << title     		<< endl;
	cout << setw(10) << "Author: "           << author  	    << endl;

	cout << setw(13) << "Publisher: "        << publisher 		<< endl;

	cout << setw(14) << "Date Added: "       << dateAdded      	<< endl;

	cout << setw(20) << "Quantity-On-Hand: " << qtyOnHand       << endl;

	cout << setw(18) << "Wholesale Cost: "   << wholesale 		<< endl;

	cout << setw(16) << "Retail Price: "     << retail  << endl << endl;

}
