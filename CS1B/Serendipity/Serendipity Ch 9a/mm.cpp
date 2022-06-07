// ----------------------------------------------------------------------------
// File name: mm.cpp                                                          -
// Project name: Serendipity                                                  -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 1/17/18                                                     -
// Date of Last Modification: 3/15/18                                         -
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
// - DBSIZE            integer      20                                        -
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
#include <cstring>

using namespace std;

//STRUCTS
struct BookData
{
	string bookTitle;
	string isbn;
	string author;
	string publisher;
	string dateAdded;
	int	   qtyOnHand;
	double wholesale;
	double retail;
};

//GLOBAL CONSTANTS
const int DBSIZE = 20; //the number of book records the arrays can handle

//FUNCTION PROTOTYPES
void cashier(int bookCount,
			 BookData book[]);

void invmenu(int      bookCount,
			 BookData book[]);

void reports(BookData book[]);

void bookInfo(string isbn,
			  string title,
			  string author,
			  string publisher,
			  string dateAdded,
			  int    qtyOnHand,
			  double wholesale,
			  double retail);

//FUNCTIONS FOR INVMENU
void lookUpBook(BookData book[]);
void addBook(int &bookCount,
			 BookData book[]);
void editBook(int &bookCount,
			  BookData book[]);
void deleteBook(int &bookCount,
				BookData book[]);

//FUNCTIONS FOR REPORTS
void repListing(BookData book[]);
void repWholesale(BookData book[]);
void repRetail(BookData book[]);
void repQty(BookData book[]);
void repCost(BookData book[]);
void repAge(BookData book[]);

//"SET"-FUNCTIONS
void setTitle(BookData book[], string *titleCopy, int subscript);
void setISBN(BookData book[], string *isbnCopy, int subscript);
void setAuthor(BookData book[], string *authorCopy, int subscript);
void setPub(BookData book[], string *pubCopy, int subscript);
void setDateAdded(BookData book[], string *dateCopy, int subscript);
void setQty(BookData book[], int qtyCopy, int subscript);
void setWholesale(BookData book[], double wholesaleCopy, int subscript);
void setRetail(BookData book[], double retailCopy, int subscript);
void removeBook(BookData book[], int subscript);

int main()
{
	const int CENTER_TITLE    = 25;
	const int HORIZONTAL_LINE = 51;

	bool     invalid;
	char     userChoice;
	int      bookCount; //number of books currently in database

	BookData book[DBSIZE]; //array holding 20 values

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
		case '1': cashier(bookCount, book);
				break;
		case '2': invmenu(bookCount, book);
				break;
		case '3': reports(book);
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

void invmenu(int    bookCount,
			 BookData book[])
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
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
		case '1': lookUpBook(book);
			break;
		case '2': addBook(bookCount, book);
			break;
		case '3': editBook(bookCount, book);
			break;
		case '4': deleteBook(bookCount, book);
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
void lookUpBook(BookData book[])
{
	string searchlookUpBook;
	char   viewRecord;
	int    index;
	int    location;

	index    = 0;
	location = -1;

	cout << ">>> BOOK LOOK UP <<<";
	cout << endl << endl;
	cout << "> Search: ";
	getline(cin, searchlookUpBook);

	while(location == -1 && index < DBSIZE)
	{
		location = book[index].bookTitle.find(searchlookUpBook);

		if(location != -1)
		{
			cout << endl << endl;
			cout << "> RESULT: " << book[index].bookTitle;
			cout << endl;

			cout << "View this book record? (y/n)";
			cin.get(viewRecord);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			do
			{
				if(viewRecord != 'y' && viewRecord != 'Y' && viewRecord != 'n' && viewRecord != 'N')
				{
					cout << "\n\n*** INVALID INPUT - PLEASE TYPE Y OR N ***\n\n";

					cout << "View this book record? (y/n)";
					cin.get(viewRecord);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}while(viewRecord != 'y' && viewRecord != 'Y' && viewRecord != 'n' && viewRecord != 'N');

			if(viewRecord == 'y' || viewRecord == 'Y')
			{
				bookInfo(book[index].isbn,
						 book[index].bookTitle,
						 book[index].author,
						 book[index].publisher,
						 book[index].dateAdded,
						 book[index].qtyOnHand,
						 book[index].wholesale,
						 book[index].retail);
				system("PAUSE");
				break;
			}//ENDIF
		}//ENDIF
		index++;
	}

	if(index == 20)
	{
		cout << "\n\n> BOOK WAS NOT FOUND.\n\n";
		system("PAUSE");
	}

}

//addBook
void addBook(int     &bookCount,
			 BookData book[])
{

	int  userChoiceAddBook;
	bool invalidAddBook;

	//pointers for strings in BookData
	string *titleCopy;
	string *isbnCopy;
	string *authorCopy;
	string *pubCopy;
	string *dateAddedCopy;

	string titleInput;
	string isbnInput;
	string authorInput;
	string publisherInput;
	string dateAddedInput;
	int    qtyOnHandInput;
	double wholesaleInput;
	double retailInput;

	while(bookCount < 20 && userChoiceAddBook != 0)
	{
		system("CLS");

		cout << right    << setprecision(2) << fixed;
		cout << setw(55) << "SERENDIPITY BOOKSELLERS";
		cout << endl;
		cout << setw(50) << "ADD BOOK";
		cout << endl << endl;
		cout << setw(65) << "DATABASE SIZE: " << DBSIZE << " CURRENT BOOK COUNT: " << bookCount;
		cout << endl << endl;
		cout << setw(68) << "-- PENDING VALUES";
		cout << endl;

		cout << left;
		cout << setw(36) << " <1>  Enter Book Title"              << "> --" << book[bookCount].bookTitle;
		cout << endl;
		cout << setw(36) << " <2>  Enter ISBN"                    << "> --" << book[bookCount].isbn;
		cout << endl;
		cout << setw(36) << " <3>  Enter Author"                  << "> --" << book[bookCount].author;
		cout << endl;
		cout << setw(36) << " <4>  Enter Publisher"               << "> --" << book[bookCount].publisher;
		cout << endl;
		cout << setw(36) << " <5>  Enter Date Added (mm/dd/yyyy)" << "> --" << book[bookCount].dateAdded;
		cout << endl;
		cout << setw(36) << " <6>  Enter Quantity On Hand"        << "> --" << book[bookCount].qtyOnHand;
		cout << endl;
		cout << setw(36) << " <7>  Enter Wholesale Cost"          << "> --$"<< book[bookCount].wholesale;
		cout << endl;
		cout << setw(36) << " <8>  Enter Retail Price"            << "> --$"<< book[bookCount].retail;
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
				getline(cin, titleInput);
				titleCopy = &titleInput;
				//FUNCTION CALL
				setTitle(book, titleCopy, bookCount);
		break;
		case 2: cout << "\nEnter ISBN number: ";
				getline(cin, isbnInput);
				isbnCopy = &isbnInput;
				//FUNCTION CALL
				setISBN(book, isbnCopy, bookCount);
		break;
		case 3: cout << "\nEnter author name: ";
				getline(cin, authorInput);
				authorCopy = &authorInput;
				//FUNCTION CALL
				setAuthor(book, authorCopy, bookCount);
		break;
		case 4: cout << "\nEnter publisher: ";
				getline(cin, publisherInput);
				pubCopy = &publisherInput;
				//FUNCTION CALL
				setPub(book, pubCopy, bookCount);
		break;
		case 5: cout << "\nEnter date: ";
				getline(cin, dateAddedInput);
				dateAddedCopy = &dateAddedInput;
				//FUNCTION CALL
				setDateAdded(book, dateAddedCopy, bookCount);
		break;
		case 6: cout << "\nEnter quantity on hand: ";
				cin  >> qtyOnHandInput;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//FUNCTION CALL
				setQty(book, qtyOnHandInput, bookCount);
		break;
		case 7: cout << "\nEnter wholesale cost: ";
				cin  >> wholesaleInput;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//FUNCTION CALL
				setWholesale(book, wholesaleInput, bookCount);
		break;
		case 8: cout << "\nEnter retail price: ";
				cin  >> retailInput;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//FUNCTION CALL
				setRetail(book, retailInput, bookCount);
		break;
		case 9: bookCount++;
		break;
		}//END SWITCH
	}

	if(bookCount == DBSIZE)
	{
		cout << "\n*** ERROR - NUMBER OF BOOKS STORED HAS REACHED ITS LIMIT ***\n\n";

		system("PAUSE");
	}

}//END ADDBOOK FUNCTION

//editBook
void editBook(int     &bookCount,
			  BookData book[])
{
	string searchEditBook;//user's input for searching the value
	int    index;
	char   viewRecord;    //whether or not the user wants to view a book's record (Y/N)
	int    location;
	char   editThisBook;  //whether or not the user wants to edit a book (Y/N)

	index    = 0;
	location = -1;

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
		location = book[index].bookTitle.find(searchEditBook);

		if(location != -1)
		{
			cout << endl << endl;
			cout << "> RESULT: " << book[index].bookTitle;
			cout << endl;

			//VIEW BOOK RECORD
			do
			{
				cout << "View this book record? (y/n)";
				cin.get(viewRecord);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				//ERROR CHECK FOR VIEWING THE BOOK RECORD (Y/N)
				if(viewRecord != 'y' && viewRecord != 'Y' && viewRecord != 'n' && viewRecord != 'N')
				{
					cout << "\n\n*** INVALID INPUT - PLEASE TYPE Y OR N ***\n\n";

					cout << "View this book record? (y/n)";
					cin.get(viewRecord);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}while(viewRecord != 'y' && viewRecord != 'Y' && viewRecord != 'n' && viewRecord != 'N');

			//IF YES TO VIEW BOOK RECORD
			if(viewRecord == 'y' || viewRecord == 'Y')
			{
				bookInfo(book[index].isbn,
						 book[index].bookTitle,
						 book[index].author,
						 book[index].publisher,
						 book[index].dateAdded,
						 book[index].qtyOnHand,
						 book[index].wholesale,
						 book[index].retail);

				//ERROR CHECK FOR EDITING THE BOOK (Y/N)
				cout << "\n\nEdit this book? (y/n) ";
				cin.get(editThisBook);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				do
				{
					if(editThisBook != 'y' && editThisBook != 'Y' && editThisBook != 'n' && editThisBook != 'N')
					{
						cout << "\n\n*** INVALID INPUT - PLEASE INPUT Y OR N ***\n\n";

						cout << "\n\nEdit this book? (y/n) ";
						cin.get(editThisBook);
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}while(editThisBook != 'y' && editThisBook != 'Y' && editThisBook != 'n' && editThisBook != 'N');

				//IF YES TO EDIT THE BOOK
				if(editThisBook == 'y' || editThisBook == 'Y')
				{
					while(editThisBook != '9')
					{
						system("CLS");

						cout << right    << setprecision(2) << fixed;
						cout << setw(55) << "SERENDIPITY BOOKSELLERS";
						cout << endl;
						cout << setw(50) << "EDIT BOOK";
						cout << endl << endl;
						cout << setw(65) << "DATABASE SIZE: " << DBSIZE << " CURRENT BOOK COUNT: " << bookCount;
						cout << endl << endl;
						cout << setw(68) << "-- PENDING VALUES";
						cout << endl;

						cout << left;
						cout << setw(36) << " <1>  Enter Book Title"              << "> --" << book[bookCount].bookTitle;
						cout << endl;
						cout << setw(36) << " <2>  Enter ISBN"                    << "> --" << book[bookCount].isbn;
						cout << endl;
						cout << setw(36) << " <3>  Enter Author"                  << "> --" << book[bookCount].author;
						cout << endl;
						cout << setw(36) << " <4>  Enter Publisher"               << "> --" << book[bookCount].publisher;
						cout << endl;
						cout << setw(36) << " <5>  Enter Date Added (mm/dd/yyyy)" << "> --" << book[bookCount].dateAdded;
						cout << endl;
						cout << setw(36) << " <6>  Enter Quantity On Hand"        << "> --" << book[bookCount].qtyOnHand;
						cout << endl;
						cout << setw(36) << " <7>  Enter Wholesale Cost"          << "> --$"<< book[bookCount].wholesale;
						cout << endl;
						cout << setw(36) << " <8>  Enter Retail Price"            << "> --$"<< book[bookCount].retail;
						cout << endl;
						cout << setw(36) << " <9>  Save Book to Database";
						cout << endl;

						cout << "> CHOICE: ";
						cin.get(editThisBook);
						cin.ignore(1000, '\n');

						do
						{
							if(editThisBook != '1' && editThisBook != '2' &&
							   editThisBook != '3' && editThisBook != '4' &&
							   editThisBook != '5' && editThisBook != '6' &&
							   editThisBook != '7' && editThisBook != '8')
							{
								cout << "\n\n*** INVALID INPUT - PLEASE INPUT 1-9 ***\n\n";

								cout << "> CHOICE: ";
								cin.get(editThisBook);
								cin.ignore(1000, '\n');
							}//END IF
						}while(editThisBook != '1' && editThisBook != '2' &&
							   editThisBook != '3' && editThisBook != '4' &&
							   editThisBook != '5' && editThisBook != '6' &&
							   editThisBook != '7' && editThisBook != '8');
						//END DO WHILE

						switch (editThisBook)//SWITCH FOR FUNCTIONS WITHIN EDITBOOK
						{
							case '1' : cout << endl << "Enter Book Title: ";
									   getline(cin, book[index].bookTitle);
									   break;

							case '2' : cout << endl << "Enter ISBN: ";
									   getline(cin, book[index].isbn);
									   break;

							case '3' : cout << endl << "Enter Author: ";
									   getline(cin, book[index].author);
									   break;

							case '4' : cout << endl << "Enter Publisher: ";
									   getline(cin, book[index].publisher);
									   break;

							case '5' : cout << endl << "Enter Date Added: ";
									   getline(cin, book[index].dateAdded);
									   break;

							case '6' : cout << endl << "Enter Quantity: ";
									   cin  >> book[index].qtyOnHand;
									   cin.ignore(numeric_limits<streamsize>::max(), '\n');
									   break;

							case '7' : cout << endl << "Enter Wholesale Cost: ";
									   cin  >> book[index].wholesale;
									   cin.ignore(numeric_limits<streamsize>::max(), '\n');
									   break;

							case '8' : cout << endl << "Enter Retail Price: ";
									   cin  >> book[index].retail;
									   cin.ignore(numeric_limits<streamsize>::max(), '\n');
									   break;
						} // END SWITCH
					}//END WHILE
				}//END IF(editThisBook == 'y' || editThisBook == 'Y')
			}//ENDIF(viewRecord == 'y' || viewRecord == 'Y')
		}//ENDIF(location != -1)

		index++; //UPDATES INDEX TO CONTINUE TO SEARCH FOR BOOK

	}//END WHILE(location == -1 && index < DBSIZE)

	if(index == DBSIZE)
	{
		cout << "\n\n> BOOK WAS NOT FOUND.\n\n";
		system("PAUSE");
	}

}

//deleteBook
void deleteBook(int     &bookCount,
				BookData book[])
{
	string searchDeleteBook;
	char viewRecord;
	char deleteChoice;
	int  location;
	int  index;

	location = -1;
	index    = 0;

	system("CLS");

	cout << right    << setprecision(2) << fixed;
	cout << setw(55) << "SERENDIPITY BOOKSELLERS";
	cout << endl;
	cout << setw(50) << "DELETE BOOK";
	cout << endl << endl;
	cout << setw(65) << "DATABASE SIZE: " << DBSIZE << " CURRENT BOOK COUNT: " << bookCount + 1;
	cout << endl << endl;

	cout << ">Search: ";

	getline(cin, searchDeleteBook);

	while(location == -1 && index < DBSIZE)
	{

		location = book[index].bookTitle.find(searchDeleteBook);

		if(location != -1)
		{
			cout << endl << "RESULT: " << book[index].bookTitle << endl;

			//VIEW BOOK RECORD
			cout << "View this book record? (y/n)";
			cin.get(viewRecord);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			do
			{
				//ERROR CHECK FOR VIEWING THE BOOK RECORD (Y/N)
				if(viewRecord != 'y' && viewRecord != 'Y' && viewRecord != 'n' && viewRecord != 'N')
				{
					cout << "\n\n*** INVALID INPUT - PLEASE TYPE Y OR N ***\n\n";

					cout << "View this book record? (y/n)";
					cin.get(viewRecord);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}while(viewRecord != 'y' && viewRecord != 'Y' && viewRecord != 'n' && viewRecord != 'N');

			//IF YES TO VIEW BOOK RECORD
			if(viewRecord == 'y' || viewRecord == 'Y')
			{
				bookInfo(book[index].isbn,
						 book[index].bookTitle,
						 book[index].author,
						 book[index].publisher,
						 book[index].dateAdded,
						 book[index].qtyOnHand,
						 book[index].wholesale,
						 book[index].retail);

				//DO WHILE FOR DELETING BOOK
					cout << "\n\nDelete this book? (y/n) ";
					cin.get(deleteChoice);
					cin.ignore(100,'\n');
				do
				{
					if(deleteChoice != 'y' && deleteChoice != 'Y' && deleteChoice != 'n' && deleteChoice != 'N')
					{
						cout << "\n\n*** INVALID INPUT - PLEASE INPUT Y OR N ***\n\n";

						cin.get(deleteChoice);
						cin.ignore(100,'\n');
					}
				}while(deleteChoice != 'y' && deleteChoice != 'Y' && deleteChoice != 'n' && deleteChoice != 'N');

				if(deleteChoice == 'y' || deleteChoice == 'Y')
				{
					book[index].bookTitle = "";
					book[index].isbn = "";
					book[index].author = "";
					book[index].publisher = "";
					book[index].dateAdded = "";
					book[index].qtyOnHand = 0;
					book[index].wholesale = 0;
					book[index].retail = 0;

					bookCount--;

					cout << "\n\nBOOK DELETED.\n\n<<";
					system("PAUSE");
				}
			}
		}

		index++;
	}
	if(index == 20)
	{
		cout << "\n\nBOOK WAS NOT FOUND.\n\n";
		system("PAUSE");
	}
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

void reports(BookData book[])
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
		case '1': repListing(book);
				break;
		case '2': repWholesale(book);
				break;
		case '3': repRetail(book);
				break;
		case '4': repQty(book);
				break;
		case '5': repCost(book);
				break;
		case '6': repAge(book);
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
void repListing(BookData book[])
{
	cout << "\nYou selected Inventory Listing.\n\n";
}

//repWholesale
void repWholesale(BookData book[])
{
	cout << "\nYou  selected Inventory Wholesale Value.\n\n";
}

//repRetail
void repRetail(BookData book[])
{
	cout << "\nYou selected Inventory Retail Value.\n\n";
}

//repOty
void repQty(BookData book[])
{
	cout <<  "\nYou  selected  Listing By Quantity.\n\n";
}

//repCost
void repCost(BookData book[])
{
	cout << "\nYou  selected  Listing By Cost.\n\n";
}

//repAge
void repAge(BookData book[])
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

void cashier(int bookCount,
			 BookData book[])
{
	const int HORIZONTAL_LINE = 78;

	bool invalidCashier;
	char repeatC;
	float subtotalC;
	float taxC;
	float totalC;
	float priceC;

	cout << endl;

	do
	{
		// INPUT FROM USER
		cout << left
			 << "Serendipity Booksellers\n"
			 << "Cashier Module\n\n";

		cout << "Date: ";
		getline(cin, book[bookCount].dateAdded);

		cout << "Quantity of Book: ";
		cin  >> book[bookCount].qtyOnHand;
		cin.ignore(1000, '\n');
		cin.clear();

		cout << "ISBN: ";
		getline(cin, book[bookCount].isbn);

		cout << "Title: ";
		getline(cin, book[bookCount].bookTitle);

		cout << "Price: ";
		cin  >> priceC;
		cin.ignore(1000, '\n');
		cin.clear();

		cout << endl << endl << endl;

		// CALCULATION FOR SALES SLIP
		subtotalC = book[bookCount].qtyOnHand * priceC;
		taxC      = subtotalC * 0.06;
		totalC    = subtotalC + taxC;

		// SALES SLIP
		cout << "Serendipity Booksellers\n\n";

		cout << "Date: " << book[bookCount].dateAdded
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
			 << setw(5)  << book[bookCount].qtyOnHand
			 << setw(15) << book[bookCount].isbn
			 << setw(21) << book[bookCount].bookTitle
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
		system("PAUSE");
		system("CLS");
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



/******************************************************************************
 * "SET" FUNCTIONS
 *****************************************************************************/
void setTitle(BookData book[], string *titleCopy, int subscript)
{
	book[subscript].bookTitle = *titleCopy;
}

void setISBN(BookData book[], string *isbnCopy, int subscript)
{
	book[subscript].isbn = *isbnCopy;
}

void setAuthor(BookData book[], string *authorCopy, int subscript)
{
	book[subscript].author = *authorCopy;
}

void setPub(BookData book[], string *pubCopy, int subscript)
{
	book[subscript].publisher = *pubCopy;
}

void setDateAdded(BookData book[], string *dateCopy, int subscript)
{
	book[subscript].dateAdded = *dateCopy;
}

void setQty(BookData book[], int qtyCopy, int subscript)
{
	book[subscript].qtyOnHand = qtyCopy;
}

void setWholesale(BookData book[], double wholesaleCopy, int subscript)
{
	book[subscript].wholesale = wholesaleCopy;
}

void setRetail(BookData book[], double retailCopy, int subscript)
{
	book[subscript].retail = retailCopy;
}

void removeBook(BookData book[], int subscript)
{
	book[subscript].bookTitle[0] = 0;
	book[subscript].isbn[0] = 0;
}
