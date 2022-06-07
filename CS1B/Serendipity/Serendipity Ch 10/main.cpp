// ----------------------------------------------------------------------------
// File name: 9c.cpp                                                          -
// Project name: Serendipity                                                  -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 1/17/18                                                     -
// Date of Last Modification: 4/09/18                                         -
// ----------------------------------------------------------------------------
// Purpose: Serendipity                                                       -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Let the user pick from the menu.                                   -
// Step 2: Check if they made a valid choice, and show another menu.          -
// Step 3: Let the user complete their desired actions based on their choices.-
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// - CENTER_TITLE      integer      25                                        -
// - HORIZONTAL_LINE   integer      51                                        -
// - DBSIZE            integer      20                                        -
// - MAXLEN            int          80                                        -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// - invalid           bool         0                                         -
// - userChoice        char         0                                         -
// -																		  -
// - STRUCT BOOKDATA:														  -
// - bookTitle         string       -                                         -
// - isbn              string       -                                         -
// - author            string       -                                         -
// - publisher         string       -                                         -
// - dateAdded         string       -                                         -
// - qtyOnHand         int          0                                         -
// - wholesale         double       0.0                                       -
// - retail            double       0.0                                       -
// ----------------------------------------------------------------------------
#include "10.h"

//GLOBAL CONSTANTS
const int DBSIZE          = 20; //the number of book records the arrays can handle
const int CENTER_TITLE    = 25;
const int HORIZONTAL_LINE = 51;
const int MAXLEN          = 80; //for time

//DATE AND TIME
const string dateAndTime()
{
	time_t  t = time(0);
	struct  tm  tmstruct;
	char    s[MAXLEN];
	tmstruct = *localtime(&t);

	strftime(s, MAXLEN, "%m/%d/%Y %X", &tmstruct);

	return s;
}

//FUNCTION PROTOTYPES
void cashier(int      bookCount,
			 BookData book[]);

void invmenu(int      &bookCount,
			 BookData book[]);

void reports(int      bookCount,
			 BookData book[]);

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
void addBook(int     &bookCount,
			 BookData book[]);
void editBook(int      bookCount,
			  BookData book[]);
void deleteBook(int     &bookCount,
				BookData book[]);

//FUNCTIONS FOR REPORTS
void repListing(BookData book[], int bookCount);
void repWholesale(BookData book[], int bookCount);
void repRetail(BookData book[], int bookCount);
void repQty(BookData book[], int bookCount);
void repCost(BookData book[], int bookCount);
void repAge(BookData book[], int bookCount);

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

//FUNCTION FOR SORTING
void selectionSort(int list[], unsigned long long int &c, unsigned long long &w);

int main()
{
	bool     invalid;
	char     userChoice;
	int      bookCount; //number of books currently in database

	BookData book[DBSIZE]; //array holding 20 values

	bookCount = 0;	//initializing

	//WHILE LOOP - MENU REPEAT
	while(userChoice != '4')
	{
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

		//CHECKS IF INVALID
		do
		{
			//INPUT FROM USER
			cin.get(userChoice);
			cin.ignore(1000, '\n');

			//CLEAR THE SCREEN
			system("CLS");
	
			invalid = userChoice != '1' && userChoice != '2' &&
					  userChoice != '3' && userChoice != '4';

			if(invalid)
			{
				cout << endl;
				cout << setw(43) << "***INVALID INPUT - MUST BE 1-4***\n\n";
			}
		}while(invalid);//END DO WHILE

	// SWITCH STATEMENT
		switch(userChoice)
		{
		case '1': cashier(bookCount, book);
				break;
		case '2': invmenu(bookCount, book);
				break;
		case '3': reports(bookCount, book);
				break;
		}

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

void invmenu(int    &bookCount,
			 BookData book[])
{
	const int CENTER_TITLE    = 25;
	const int HORIZONTAL_LINE = 51;

	bool invalidInvMenu;
	char userChoiceInvMenu;

	//WHILE LOOP - MENU REPEAT
	while(userChoiceInvMenu != '5')
	{
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
			 
		do
		{
			//INPUT FROM USER
			cin.get(userChoiceInvMenu);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
			invalidInvMenu = userChoiceInvMenu != '1' &&
							 userChoiceInvMenu != '2' &&
							 userChoiceInvMenu != '3' &&
							 userChoiceInvMenu != '4' &&
							 userChoiceInvMenu != '5';

			if(invalidInvMenu)
			{
				cout << endl;
				cout << setw(43) << "***INVALID INPUT - MUST BE 1-5***\n\n";
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
	bool   invalidViewRecord;

	location = -1;

	cout << ">>> BOOK LOOK UP <<<";
	cout << endl << endl;
	cout << "> Search: ";
	getline(cin, searchlookUpBook);

	for(index = 0; index < DBSIZE; index++)
	{
		location = book[index].bookTitle.find(searchlookUpBook);

		if(location != -1)
		{
			cout << endl << endl;
			cout << "> RESULT: " << book[index].bookTitle;
			cout << endl;

			do
			{
				cout << "View this book record? (y/n)";
				cin.get(viewRecord);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				
				invalidViewRecord = viewRecord != 'y' && viewRecord != 'Y' && viewRecord != 'n' && viewRecord != 'N';
			
				if(invalidViewRecord)
				{
					cout << "\n\n*** INVALID INPUT - PLEASE TYPE Y OR N ***\n\n";
				}
			}while(invalidViewRecord);

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
	}//END FOR

	if(index == DBSIZE)
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
			cin.clear();

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
void editBook(int      bookCount,
			  BookData book[])
{
	string searchEditBook;        //user's input for searching the value
	int    index;
	char   viewRecord;            //whether or not the user wants to view a book's record (Y/N)
	int    location;
	char   ifEditThisBook;        //whether or not the user wants to edit a book (Y/N)
	int    editThisBook;          //user choosing which part of the book info to edit
	bool   invalidIfEditThisBook; //if the (Y/N) user input for editing the book is invalid
	bool   invalidEditThisBook;   //if the (0-9) user input for editing the book is invalid
	bool   invalidViewRecord;

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

	for(index = 0; index < DBSIZE; index++)
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
				
				invalidViewRecord = viewRecord != 'y' && viewRecord != 'Y' && viewRecord != 'n' && viewRecord != 'N';

				//ERROR CHECK FOR VIEWING THE BOOK RECORD (Y/N)
				if(invalidViewRecord)
				{
					cout << "\n\n*** INVALID INPUT - PLEASE TYPE Y OR N ***\n\n";

					cout << "View this book record? (y/n)";
					cin.get(viewRecord);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}while(invalidViewRecord);

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
						 
				do
				{
					//ERROR CHECK FOR EDITING THE BOOK (Y/N)
					cout << "\n\nEdit this book? (Y/N) ";
					cin.get(ifEditThisBook);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin.clear();
					
					invalidIfEditThisBook = ifEditThisBook != 'y' && ifEditThisBook != 'Y' && ifEditThisBook != 'n' && ifEditThisBook != 'N';
					
					if(invalidIfEditThisBook)
					{
						cout << "\n\n*** INVALID INPUT - PLEASE INPUT Y OR N ***\n\n";
					}
				}while(invalidIfEditThisBook);

				//IF YES TO EDIT THE BOOK
				if(ifEditThisBook == 'y' || ifEditThisBook == 'Y')
				{
					do
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
						cout << setw(36) << " <1>  Enter Book Title"              << "> --" << book[index].bookTitle;
						cout << endl;
						cout << setw(36) << " <2>  Enter ISBN"                    << "> --" << book[index].isbn;
						cout << endl;
						cout << setw(36) << " <3>  Enter Author"                  << "> --" << book[index].author;
						cout << endl;
						cout << setw(36) << " <4>  Enter Publisher"               << "> --" << book[index].publisher;
						cout << endl;
						cout << setw(36) << " <5>  Enter Date Added (mm/dd/yyyy)" << "> --" << book[index].dateAdded;
						cout << endl;
						cout << setw(36) << " <6>  Enter Quantity On Hand"        << "> --" << book[index].qtyOnHand;
						cout << endl;
						cout << setw(36) << " <7>  Enter Wholesale Cost"          << "> --$"<< book[index].wholesale;
						cout << endl;
						cout << setw(36) << " <8>  Enter Retail Price"            << "> --$"<< book[index].retail;
						cout << endl;
						cout << setw(36) << " <9>  Save Book to Database";
						cout << endl;

						//CHECKING FOR INVALID INPUT - EditThisBook
						do
						{
							cout << "> CHOICE: ";
							cin  >> editThisBook;
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cin.clear();
						
							invalidEditThisBook = editThisBook != 1 && editThisBook != 2 &&
							   editThisBook != 3 && editThisBook != 4 &&
							   editThisBook != 5 && editThisBook != 6 &&
							   editThisBook != 7 && editThisBook != 8 &&
							   editThisBook != 9;
							   
							if(invalidEditThisBook)
							{
								cout << "\n\n*** INVALID INPUT - PLEASE INPUT 1-9 ***\n\n";
							}
						}while(invalidEditThisBook);
						//END DO WHILE

						switch(editThisBook)//SWITCH FOR FUNCTIONS WITHIN EDITBOOK
						{
							case 1:    cout << endl << "Enter Book Title: ";
									   getline(cin, book[index].bookTitle);
									   break;

							case 2:    cout << endl << "Enter ISBN: ";
									   getline(cin, book[index].isbn);
									   break;

							case 3:    cout << endl << "Enter Author: ";
									   getline(cin, book[index].author);
									   break;

							case 4:    cout << endl << "Enter Publisher: ";
									   getline(cin, book[index].publisher);
									   break;

							case 5:    cout << endl << "Enter Date Added: ";
									   getline(cin, book[index].dateAdded);
									   break;

							case 6:    cout << endl << "Enter Quantity: ";
									   cin  >> book[index].qtyOnHand;
									   cin.ignore(numeric_limits<streamsize>::max(), '\n');
									   cin.clear();
									   break;

							case 7:    cout << endl << "Enter Wholesale Cost: ";
									   cin  >> book[index].wholesale;
									   cin.ignore(numeric_limits<streamsize>::max(), '\n');
									   cin.clear();
									   break;

							case 8:    cout << endl << "Enter Retail Price: ";
									   cin  >> book[index].retail;
									   cin.ignore(numeric_limits<streamsize>::max(), '\n');
									   cin.clear();
									   break;
									   
							case 9:    break;
						}// END SWITCH
					}while(editThisBook != 9);
				}//END IF
			}//ENDIF(viewRecord == 'y' || viewRecord == 'Y')
		}//ENDIF(location != -1)
	}//END FOR

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
	char   viewRecord;
	char   deleteChoice;
	int    location;
	int    index;
	bool   invalidViewRecord;
	bool   invalidDeleteChoice;

	location = -1;

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

	for(index = 0; index < DBSIZE; index++)
	{
		location = book[index].bookTitle.find(searchDeleteBook);

		if(location != -1)
		{
			cout << endl << "RESULT: " << book[index].bookTitle << endl;

			do
			{
				//VIEW BOOK RECORD
				cout << "View this book record? (y/n)";
				cin.get(viewRecord);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				
				invalidViewRecord = viewRecord != 'y' && viewRecord != 'Y' && viewRecord != 'n' && viewRecord != 'N';
				
				//ERROR CHECK FOR VIEWING THE BOOK RECORD (Y/N)
				if(invalidViewRecord)
				{
					cout << "\n\n*** INVALID INPUT - PLEASE TYPE Y OR N ***\n\n";
				}
			}while(invalidViewRecord);

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
						 
				do
				{
					//DO WHILE FOR DELETING BOOK
					cout << "\n\nDelete this book? (y/n) ";
					cin.get(deleteChoice);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin.clear();
					
					invalidDeleteChoice = deleteChoice != 'y' && deleteChoice != 'Y' && deleteChoice != 'n' && deleteChoice != 'N';
					
					if(invalidDeleteChoice)
					{
						cout << "\n\n*** INVALID INPUT - PLEASE INPUT Y OR N ***\n\n";
					}
				}while(invalidDeleteChoice);

				if(deleteChoice == 'y' || deleteChoice == 'Y')
				{
					removeBook(book, index);

					bookCount--;

					cout << "\n\nBOOK DELETED.\n\n<<";
					system("PAUSE");
				}
			}
		}
	}
	if(index == DBSIZE)
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

void reports(int bookCount,
			 BookData book[])
{
	const int CENTER_TITLE    = 25;
	const int HORIZONTAL_LINE = 51;

	bool invalidReports;
	char userChoiceReports;

	while(userChoiceReports != '7')
	{
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
			 << setw(40) << "7.   Return to the Main Menu\n\n";

		do
		{
			//INPUT FROM USER
			cout << setw(30) << "Enter Your Choice: ";
			cin.get(userChoiceReports);
			cin.ignore(1000, '\n');
			cin.clear();
			
			invalidReports = userChoiceReports != '1' &&
							 userChoiceReports != '2' &&
							 userChoiceReports != '3' &&
							 userChoiceReports != '4' &&
							 userChoiceReports != '5' &&
							 userChoiceReports != '6' &&
							 userChoiceReports != '7';

			if(invalidReports)
			{
				cout << endl;
				cout << setw(43) << "***INVALID INPUT - MUST BE 1-7***\n\n";
			}
		}while(invalidReports);

		// SWITCH STATEMENT FOR REPORTS
		switch(userChoiceReports)
		{
		case '1': repListing(book, bookCount);
				break;
		case '2': repWholesale(book, bookCount);
				break;
		case '3': repRetail(book, bookCount);
				break;
		case '4': repQty(book, bookCount);
				break;
		case '5': repCost(book, bookCount);
				break;
		case '6': repAge(book, bookCount);
				break;
		}//END SWITCH
	}//END WHILE
}


/******************************************************************************
 * REPORTS STUB FUNCTIONS
 *****************************************************************************/
//repListing
void repListing(BookData book[], int bookCount)
{
	int    pgNum;
	int    index;

	system("CLS");

	for(pgNum = 0; pgNum < 2; pgNum++)
	{
		cout << 		 setw(50) << "SERENDIPITY "
			 << left  << setw(50) << "BOOKSELLERS"
			 << endl;

		cout << right
			 << setw(45) << "REPORT LISTING"
			 << endl;

		cout << "DATE: "  << dateAndTime();
		cout << " PAGE: " << pgNum + 1 << " of 2";
		cout << "     ";
		cout << "DATABASE SIZE: "      << DBSIZE;
		cout << "     ";
		cout << "CURRENT BOOK COUNT: " << bookCount;
		cout << endl << endl;

		cout << left;
		cout << setw(26) << "TITLE";
		cout << setw(11) << "ISBN";
		cout << setw(16) << "AUTHOR";
		cout << setw(16) << "PUBLISHER";
		cout << setw(11) << "DATE ADDED";
		cout << setw(8)  << "QTY O/H";
		cout << setw(15) << "WHOLESALE COST";
		cout << setw(13) << "RETAIL PRICE";
		cout << endl;

		cout << setw(26) << "-------------------------";
		cout << setw(11) << "----------";
		cout << setw(16) << "---------------";
		cout << setw(16) << "---------------";
		cout << setw(11) << "----------";
		cout << setw(8)  << "-------";
		cout << setw(15) << "--------------";
		cout << setw(13) << "------------";
		cout << endl;
		
		if(bookCount == 0)
		{
			cout << "\n\n*** ERROR - THERE ARE NO BOOKS IN THE DATABASE. ***\n\n";
			system("PAUSE");
		}
		
		if(pgNum == 0)
		{
			for(index = 0; index < 10; index++)
			{
				book[index].bookTitle.resize(26);
				book[index].author.resize(14);
				book[index].publisher.resize(14);
				
				cout << right;
				cout << setw(26) << book[index].bookTitle;
				cout << setw(11) << book[index].isbn;
				cout << setw(16) << book[index].author;
				cout << setw(16) << book[index].publisher;
				cout << setw(11) << book[index].dateAdded;
				cout << setw(8)  << book[index].qtyOnHand;
				cout << setw(15) << book[index].wholesale;
				cout << setw(13) << book[index].retail;
				cout << endl;
			}
		}
		else if(pgNum == 1)
		{
			for(index = 10; index < 20; index++)
			{
				book[index].bookTitle.resize(26);
				book[index].author.resize(14);
				book[index].publisher.resize(14);
				
				cout << right;
				cout << setw(26) << book[index].bookTitle;
				cout << setw(11) << book[index].isbn;
				cout << setw(16) << book[index].author;
				cout << setw(16) << book[index].publisher;
				cout << setw(11) << book[index].dateAdded;
				cout << setw(8)  << book[index].qtyOnHand;
				cout << setw(15) << book[index].wholesale;
				cout << setw(13) << book[index].retail;
				cout << endl;
			}
		}
		system("PAUSE");
		system("CLS");
	}//END FOR
}

//repWholesale
void repWholesale(BookData book[], int bookCount)
{
	double subtotal;
	double grandTotal;
	int    pgNum;
	int    index;
	
	grandTotal = 0;
	pgNum      = 0;
	index      - 0;
	
	system("CLS");
	
	for(pgNum = 0; pgNum < 2; pgNum++)
	{
		cout << 		 setw(50) << "SERENDIPITY "
			 << left  << setw(50) << "BOOKSELLERS"
			 << endl;

		cout << right
			 << setw(45) << "REPORT WHOLESALE LISTING"
			 << endl;

		cout << "DATE: "  << dateAndTime();
		cout << " PAGE: " << pgNum + 1 << " of 2";
		cout << "     ";
		cout << "DATABASE SIZE: "      << DBSIZE;
		cout << "     ";
		cout << "CURRENT BOOK COUNT: " << bookCount;
		cout << endl << endl;

		cout << left;
		cout << setw(26) << "TITLE";
		cout << "          ";
		cout << setw(11) << "ISBN";
		cout << "          ";
		cout << setw(8)  << "QTY O/H";
		cout << "          ";
		cout << setw(15) << "WHOLESALE COST";
		cout << endl;

		cout << setw(26) << "-------------------------";
		cout << "          ";
		cout << setw(11) << "----------";
		cout << "          ";
		cout << setw(8)  << "-------";
		cout << "          ";
		cout << setw(15) << "--------------";
		cout << endl;

		if(bookCount == 0)
		{
			cout << "\n\n*** ERROR - THERE ARE NO BOOKS IN THE DATABASE. ***\n\n";

			system("PAUSE");
		}

		if(pgNum == 0)
		{
			for(index = 0; index < 10; index++)
			{
				book[index].bookTitle.resize(24);

				cout << setw(26) << left << setfill(' ') << book[index].bookTitle;
				cout << "           ";
				cout << setw(11) << book[index].isbn;
				cout << "           ";
				cout << setw(8)  << book[index].qtyOnHand;
				cout << "          $";
				cout << setw(15) << right;
				cout << book[index].wholesale;
				cout << endl << endl;

				subtotal = book[index].qtyOnHand * book[index].wholesale;

				grandTotal = grandTotal + subtotal;
			}
		}
		else if(pgNum == 1)
		{
			for(int index = 10; index < 20; index++)
			{
				book[index].bookTitle.resize(24);

				cout << setw(26) << left << setfill(' ') << book[index].bookTitle;
				cout << "           ";
				cout << setw(11) << book[index].isbn;
				cout << "           ";
				cout << setw(8)  << book[index].qtyOnHand;
				cout << "          $";
				cout << setw(15) << right;
				cout << book[index].wholesale;
				cout << endl << endl;

				subtotal = book[index].qtyOnHand * book[index].wholesale;

				grandTotal = grandTotal + subtotal;
			}
			
			cout << endl;
			cout << "TOTAL: $" << grandTotal;
			cout << endl << endl;
			
		}//END IF THEN ELSE IF
		
		system("PAUSE");
		system("CLS");
		
	}//END FOR
	
}

//repRetail
void repRetail(BookData book[], int bookCount)
{
	double subtotal;
	double grandTotal;
	int    pgNum;
	int    index;
	
	grandTotal = 0;
	pgNum      = 0;
	index      - 0;
	
	system("CLS");
	
	for(pgNum = 0; pgNum < 2; pgNum++)
	{
		cout << 		 setw(50) << "SERENDIPITY "
			 << left  << setw(50) << "BOOKSELLERS"
			 << endl;

		cout << right
			 << setw(45) << "REPORT RETAIL LISTING"
			 << endl;

		cout << "DATE: "  << dateAndTime();
		cout << " PAGE: " << pgNum + 1 << " of 2";
		cout << "     ";
		cout << "DATABASE SIZE: "      << DBSIZE;
		cout << "     ";
		cout << "CURRENT BOOK COUNT: " << bookCount;
		cout << endl << endl;

		cout << left;
		cout << setw(26) << "TITLE";
		cout << "          ";
		cout << setw(11) << "ISBN";
		cout << "          ";
		cout << setw(8)  << "QTY O/H";
		cout << "          ";
		cout << setw(15) << "RETAIL COST";
		cout << endl;

		cout << setw(26) << "-------------------------";
		cout << "          ";
		cout << setw(11) << "----------";
		cout << "          ";
		cout << setw(8)  << "-------";
		cout << "          ";
		cout << setw(15) << "--------------";
		cout << endl;

		if(bookCount == 0)
		{
			cout << "\n\n*** ERROR - THERE ARE NO BOOKS IN THE DATABASE. ***\n\n";

			system("PAUSE");
		}

		if(pgNum == 0)
		{
			for(index = 0; index < 10; index++)
			{
				book[index].bookTitle.resize(24);

				cout << setw(26) << left << setfill(' ') << book[index].bookTitle;
				cout << "           ";
				cout << setw(11) << book[index].isbn;
				cout << "           ";
				cout << setw(8)  << book[index].qtyOnHand;
				cout << "          $";
				cout << setw(15) << right;
				cout << book[index].retail;
				cout << endl << endl;

				subtotal = book[index].qtyOnHand * book[index].retail;

				grandTotal = grandTotal + subtotal;
			}
		}
		else if(pgNum == 1)
		{
			for(int index = 10; index < 20; index++)
			{
				book[index].bookTitle.resize(24);

				cout << setw(26) << left << setfill(' ') << book[index].bookTitle;
				cout << "           ";
				cout << setw(11) << book[index].isbn;
				cout << "           ";
				cout << setw(8)  << book[index].qtyOnHand;
				cout << "          $";
				cout << setw(15) << right;
				cout << book[index].retail;
				cout << endl << endl;

				subtotal = book[index].qtyOnHand * book[index].retail;

				grandTotal = grandTotal + subtotal;
			}
			
			cout << endl;
			cout << "TOTAL: $" << grandTotal;
			cout << endl << endl;
			
		}//END IF THEN ELSE IF
		
		system("PAUSE");
		system("CLS");
		
	}//END FOR
}

//repOty
void repQty(BookData book[], int bookCount)
{
	int  maxIndex;
	int* maxValue;
	int* temp;
	int  index;
	int  innerIndex;
	int  countR;
	int  outputIndex;
	int  pgNum;
	
	int* tempPtr[DBSIZE];
	int* qtyPtr[DBSIZE];
	int  id[DBSIZE];
	
	system("CLS");

	for(pgNum = 0; pgNum < 2; pgNum++)
	{
		cout << 		 setw(50) << "SERENDIPITY "
			 << left  << setw(50) << "BOOKSELLERS"
			 << endl;

		cout << right
			 << setw(45) << "REPORT QTY O/H LISTING"
			 << endl;

		cout << "DATE: "  << dateAndTime();
		cout << " PAGE: " << pgNum + 1 << " of 2";
		cout << "     ";
		cout << "DATABASE SIZE: "      << DBSIZE;
		cout << "     ";
		cout << "CURRENT BOOK COUNT: " << bookCount;
		cout << endl << endl;

		cout << left;
		cout << setw(26) << "TITLE";
		cout << "          ";
		cout << setw(11) << "ISBN";
		cout << "          ";
		cout << setw(8)  << "QTY O/H";
		cout << endl;

		cout << setw(26) << "-------------------------";
		cout << "          ";
		cout << setw(11) << "----------";
		cout << "          ";
		cout << setw(8)  << "-------";
		cout << endl;

		if(bookCount == 0)
		{
			cout << "\n\n*** ERROR - THERE ARE NO BOOKS IN THE DATABASE. ***\n\n";

			system("PAUSE");
		}
		
		for(index = 0; index < DBSIZE; index++)
		{
			id[index]      = index;
			tempPtr[index] = &id[index];
			qtyPtr[index]  = &book[index].qtyOnHand;

		}

		for(countR = 0; countR < DBSIZE - 1; countR++)
		{
			maxIndex = countR;
			maxValue = qtyPtr[countR];
			temp     = tempPtr[countR];

			for(innerIndex = countR + 1; innerIndex < DBSIZE; innerIndex++)
			{
				if((*qtyPtr[innerIndex]) > *maxValue)
				{
					maxValue = qtyPtr[innerIndex];
					temp     = tempPtr[innerIndex];
					maxIndex = innerIndex;
				}
			}//END FOR

			qtyPtr[maxIndex]  = qtyPtr[countR];
			tempPtr[maxIndex] = tempPtr[countR];
			qtyPtr[countR]    = maxValue;
			tempPtr[countR]   = temp;
		}//END FOR
		
		if(pgNum == 0)
		{
			for(outputIndex = 0; outputIndex < 10; outputIndex++)
			{
				book[*(tempPtr[outputIndex])].bookTitle.resize(24);

				cout << setw(26) << left << setfill(' ') << book[*(tempPtr[outputIndex])].bookTitle;
				cout << "        ";
				cout << setw(11) << book[*(tempPtr[outputIndex])].isbn;
				cout << "        ";
				cout << setw(8)  << book[*(tempPtr[outputIndex])].qtyOnHand;
				cout << endl     << endl;
			}
		}
		else if(pgNum == 1)
		{
			for(outputIndex = 10; outputIndex < 20; outputIndex++)
			{
				book[*(tempPtr[outputIndex])].bookTitle.resize(24);

				cout << setw(26) << left << setfill(' ') << book[*(tempPtr[outputIndex])].bookTitle;
				cout << "        ";
				cout << setw(11) << book[*(tempPtr[outputIndex])].isbn;
				cout << "        ";
				cout << setw(8)  << book[*(tempPtr[outputIndex])].qtyOnHand;
				cout << endl     << endl;
			}
		}//END IF THEN ELSE IF
		
		system("PAUSE");
		system("CLS");
		
	}//END FOR
	
	
}

//repCost
void repCost(BookData book[], int bookCount)
{
	int     maxIndex;
	double* maxValue;
	int*    temp;
	int     index;
	int     innerIndex;
	int     countW;
	int     outputIndex;
	int     pgNum;
	
	int*    tempPtr[DBSIZE];
	double* wholesalePtr[DBSIZE];
	int     id[DBSIZE];
	
	system("CLS");

	for(pgNum = 0; pgNum < 2; pgNum++)
	{
		cout << 		 setw(50) << "SERENDIPITY "
			 << left  << setw(50) << "BOOKSELLERS"
			 << endl;

		cout << right
			 << setw(45) << "REPORT WHOLESALE LISTING"
			 << endl;

		cout << "DATE: "  << dateAndTime();
		cout << " PAGE: " << pgNum + 1 << " of 2";
		cout << "     ";
		cout << "DATABASE SIZE: "      << DBSIZE;
		cout << "     ";
		cout << "CURRENT BOOK COUNT: " << bookCount;
		cout << endl << endl;

		cout << left;
		cout << setw(26) << "TITLE";
		cout << "          ";
		cout << setw(11) << "ISBN";
		cout << "          ";
		cout << setw(8)  << "QTY O/H";
		cout << "          ";
		cout << setw(15) << "WHOLESALE COST";
		cout << endl;

		cout << setw(26) << "-------------------------";
		cout << "          ";
		cout << setw(11) << "----------";
		cout << "          ";
		cout << setw(8)  << "-------";
		cout << "          ";
		cout << setw(15) << "--------------";
		cout << endl;

		if(bookCount == 0)
		{
			cout << "\n\n*** ERROR - THERE ARE NO BOOKS IN THE DATABASE. ***\n\n";

			system("PAUSE");
		}
		
		for(index = 0; index < DBSIZE; index++)
		{
			id[index]           = index;
			tempPtr[index]      = &id[index];
			wholesalePtr[index] = &book[index].wholesale;
		}

		for(countW = 0; countW < DBSIZE - 1; countW++)
		{
			maxIndex = countW;
			maxValue = wholesalePtr[countW];
			temp     = tempPtr[countW];

			for(innerIndex = countW + 1; innerIndex < DBSIZE; innerIndex++)
			{
				if((*wholesalePtr[innerIndex]) > *maxValue)
				{
					maxValue = wholesalePtr[innerIndex];
					temp     = tempPtr[innerIndex];
					maxIndex = innerIndex;
				}
			}//END FOR

			wholesalePtr[maxIndex] = wholesalePtr[countW];
			tempPtr[maxIndex]      = tempPtr[countW];
			wholesalePtr[countW]   = maxValue;
			tempPtr[countW]        = temp;
		}//END FOR
		
		if(pgNum == 0)
		{
			for(outputIndex = 0; outputIndex < 10; outputIndex++)
			{
				book[*(tempPtr[outputIndex])].bookTitle.resize(24);

				cout << setw(26) << left << setfill(' ') << book[*(tempPtr[outputIndex])].bookTitle;
				cout << "          ";
				cout << setw(11) << book[*(tempPtr[outputIndex])].isbn;
				cout << "          ";
				cout << setw(8)  << book[*(tempPtr[outputIndex])].qtyOnHand;
				cout << "         $";
				cout << setw(8)  << book[*(tempPtr[outputIndex])].wholesale;
				cout << endl     << endl;
			}
		}
		else if(pgNum == 1)
		{
			for(outputIndex = 10; outputIndex < 20; outputIndex++)
			{
				book[*(tempPtr[outputIndex])].bookTitle.resize(24);

				cout << setw(26) << left << setfill(' ') << book[*(tempPtr[outputIndex])].bookTitle;
				cout << "          ";
				cout << setw(11) << book[*(tempPtr[outputIndex])].isbn;
				cout << "          ";
				cout << setw(8)  << book[*(tempPtr[outputIndex])].qtyOnHand;
				cout << "         $";
				cout << setw(8)  << book[*(tempPtr[outputIndex])].wholesale;
				cout << endl     << endl;
			}
		}//END IF THEN ELSE IF
		
		system("PAUSE");
		system("CLS");
		
	}//END FOR
	
}

//repAge
void repAge(BookData book[], int bookCount)
{
	int     maxIndex;
	string* maxValue; //for the date
	int*    temp;
	int     index;
	int     innerIndex;
	int     countRA;
	int     outputIndex;
	int     pgNum;
	
	int    *tempPtr[DBSIZE];
	int     id[DBSIZE];
	string *datePtr[DBSIZE];
	
	system("CLS");

	for(pgNum = 0; pgNum < 2; pgNum++)
	{
		cout << 		 setw(50) << "SERENDIPITY "
			 << left  << setw(50) << "BOOKSELLERS"
			 << endl;

		cout << right
			 << setw(45) << "REPORT AGE LISTING"
			 << endl;

		cout << "DATE: "  << dateAndTime();
		cout << " PAGE: " << pgNum + 1 << " of 2";
		cout << "     ";
		cout << "DATABASE SIZE: "      << DBSIZE;
		cout << "     ";
		cout << "CURRENT BOOK COUNT: " << bookCount;
		cout << endl << endl;

		cout << left;
		cout << setw(26) << "TITLE";
		cout << "          ";
		cout << setw(11) << "ISBN";
		cout << "          ";
		cout << setw(8)  << "QTY O/H";
		cout << "          ";
		cout << setw(15) << "DATE ADDED";
		cout << endl;

		cout << setw(26) << "-------------------------";
		cout << "          ";
		cout << setw(11) << "----------";
		cout << "          ";
		cout << setw(8)  << "-------";
		cout << "          ";
		cout << setw(15) << "--------------";
		cout << endl;

		if(bookCount == 0)
		{
			cout << "\n\n*** ERROR - THERE ARE NO BOOKS IN THE DATABASE. ***\n\n";

			system("PAUSE");
		}
		
		for(index = 0; index < DBSIZE; index++)
		{
			id[index]      = index;
			tempPtr[index] = &id[index];
			datePtr[index] = &book[index].dateAdded;
		}

		for(countRA = 0; countRA < DBSIZE - 1; countRA++)
		{
			maxIndex = countRA;
			maxValue = datePtr[countRA];
			temp     = tempPtr[countRA];

			for(innerIndex = countRA + 1; innerIndex < DBSIZE; innerIndex++)
			{
				if((*datePtr[innerIndex]) > *maxValue)
				{
					maxValue = datePtr[innerIndex];
					temp     = tempPtr[innerIndex];
					maxIndex = innerIndex;
				}
			}//END FOR

			datePtr[maxIndex] = datePtr[countRA];
			tempPtr[maxIndex] = tempPtr[countRA];
			datePtr[countRA]  = maxValue;
			tempPtr[countRA]  = temp;
		}//END FOR
		
		if(pgNum == 0)
		{
			for(outputIndex = 0; outputIndex < 10; outputIndex++)
			{
				book[*(tempPtr[outputIndex])].bookTitle.resize(24);

				cout << setw(26) << left << setfill(' ') << book[*(tempPtr[outputIndex])].bookTitle;
				cout << "          ";
				cout << setw(11) << book[*(tempPtr[outputIndex])].isbn;
				cout << "          ";
				cout << setw(8)  << book[*(tempPtr[outputIndex])].qtyOnHand;
				cout << "          ";
				cout << setw(8)  << book[*(tempPtr[outputIndex])].dateAdded;
				cout << endl     << endl;
			}
		}
		else if(pgNum == 1)
		{
			for(outputIndex = 10; outputIndex < 20; outputIndex++)
			{
				book[*(tempPtr[outputIndex])].bookTitle.resize(24);

				cout << setw(26) << left << setfill(' ') << book[*(tempPtr[outputIndex])].bookTitle;
				cout << "          ";
				cout << setw(11) << book[*(tempPtr[outputIndex])].isbn;
				cout << "          ";
				cout << setw(8)  << book[*(tempPtr[outputIndex])].qtyOnHand;
				cout << "          ";
				cout << setw(8)  << book[*(tempPtr[outputIndex])].dateAdded;
				cout << endl     << endl;
			}
		}//END IF THEN ELSE IF
		
		system("PAUSE");
		system("CLS");
		
	}//END FOR
	
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
// - CASHIER_LINE      integer      78                                        -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// - invalidCashier    bool         0                                         -
// - priceC            float        0.0                                       -
// - repeatC           char         nothing                                   -
// - subtotalC         float        0.0                                       -
// - taxC              float        0.0                                       -
// - totalC            float        0.0                                       -
// - userChoiceInvMenu char         0                                         -
// ----------------------------------------------------------------------------

void cashier(int bookCount,
			 BookData book[])
{
	const int CASHIER_LINE = 78;

	bool   invalidCashier;
	char   repeatC;
	float  taxC;
	float  totalC;
	float  priceC;
	double subtotalC;
	int    countC;	//number of transactions
	int    output;   //number of books outputted on the receipt
	int    bookAmt;  //number of books the user wants to buy
	
	//FOR OUTPUTTING THE RECEIPT
	int    bookIndexAr[DBSIZE];
	double retailAr[DBSIZE];
	string bookTitleAr[DBSIZE];
	string isbnAr[DBSIZE];
	int    qtyOfBooks[DBSIZE];
	double subtotal[DBSIZE];

	//NEEDED FOR SEARCHING FOR THE BOOK
	string bookSearch;
	int    isbnLocation;
	int    titleLocation;
	int    index;
	char   bookResult;
	bool   invalidBookResult;
	char   anotherBook;
	bool   invalidViewRecord;
	char   viewRecord;
	char   completePurchase;
	bool   invalidCompletePurchase;
	char   searchAgain;
	bool   invalidSearchAgain;

	isbnLocation  = -1;
	titleLocation = -1;

	countC             = 0; //initializing countC
	output             = 0;
	taxC               = 0;
	subtotalC          = 0;
	totalC             = 0;

	cout << endl;

	do
	{
		//CLEAR THE SCREEN
		system("CLS");
		
		// INPUT FROM USER
		cout << left
			 << "Serendipity Booksellers\n"
			 << "Cashier Module\n\n";

		cout << "Date: " << dateAndTime();
		cout << endl;

		cout << "\n>> BOOK SEARCH <<\n";
		cout << "Please enter either the book's ISBN or title to search for the book: ";;
		getline(cin, bookSearch);
	

		if(bookCount == 0)
		{
			cout << "\n\n*** ERROR - THERE ARE NO BOOKS IN THE DATABASE RIGHT NOW. ***\n\n";
			
			system("PAUSE");
			break;
		}
	
		//SEARCHING FOR BOOK
		for(index = 0; index < DBSIZE; index++)
		{
			isbnLocation  = book[index].isbn.find(bookSearch);
			titleLocation = book[index].bookTitle.find(bookSearch);

			//IF FOUND
			if(isbnLocation != -1 || titleLocation != -1)
			{
				cout << endl << endl;
				cout << "> RESULT: " << book[index].bookTitle;
				cout << endl;
				
				//VIEW BOOK RECORD
				do
				{
					cout << "View this book record? (Y/N)";
					cin.get(viewRecord);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					
					invalidViewRecord = viewRecord != 'y' && viewRecord != 'Y' && viewRecord != 'n' && viewRecord != 'N';

					//ERROR CHECK FOR VIEWING THE BOOK RECORD (Y/N)
					if(invalidViewRecord)
					{
						cout << "\n\n*** INVALID INPUT - PLEASE TYPE Y OR N ***\n\n";
					}
				}while(invalidViewRecord);

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
					
					do
					{
						cout << "Is this the book you want to buy? (Y/N): ";
						cin.get(bookResult);
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin.clear();
						
						invalidBookResult = bookResult != 'Y' && bookResult != 'y' && bookResult != 'N' && bookResult != 'n';
						
						if(invalidBookResult)
						{
							cout << "\n\n*** ERROR - PLEASE ENTER Y OR N ***\n\n";
						}
					}while(invalidBookResult);
					
					if(bookResult == 'y' || bookResult == 'Y')
					{
						cout << "\nQuantity of Book: ";
						cin  >> bookAmt;
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin.clear();

						if(book[index].qtyOnHand == 0 || bookAmt > book[index].qtyOnHand)
						{
							cout << "\n\n*** SORRY, WE DO NOT HAVE ENOUGH BOOKS. ***\n\n";
						}
						else if(bookAmt < 0)
						{
							cout << "\n\n*** YOU HAVE ENTERED AN INVALID NUMBER. ***\n\n";
						}
					}
					
					//UPDATING countC
					countC++;
					
					//PROCESSING - for the receipt
					book[index].qtyOnHand = book[index].qtyOnHand - bookAmt;
					book[index].bookTitle.resize(22);
					
					bookIndexAr[countC]  = index;
					retailAr[countC]     = book[index].retail;
					bookTitleAr[countC]  = book[index].bookTitle;
					isbnAr[countC]	     = book[index].isbn;
					qtyOfBooks[countC]   = bookAmt;
					
					//REPEAT - ANOTHER TRANSACTION
					do
					{
						cout << "Would you like to add another book to your receipt? (Y/N)";
						cin.get(repeatC);
						system("PAUSE");
						system("CLS");
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin.clear();
						cout << endl;

						invalidCashier = repeatC != 'y' &&
										 repeatC != 'n' &&
										 repeatC != 'Y' &&
										 repeatC != 'N';

						if(invalidCashier)
						{
							cout << "*** INVALID INPUT - PLEASE TYPE Y OR N ***\n\n";
						}//END IF
					}while(invalidCashier);
				}

				if(repeatC == 'N' || repeatC == 'n')
				{
					// SALES SLIP
					cout << "Serendipity Booksellers\n\n";

					cout << "Date: " << dateAndTime()
						 << endl;


					cout << left;
					cout << setw(5)  << "Qty"
						 << setw(15) << "ISBN"
						 << setw(24) << "Title"
						 <<	setw(12) << "Price"
						 <<	            "Total"
						 << endl;

					// LINE
					cout << right
						 << setfill('_')
						 << setw(CASHIER_LINE) << " "
						 << endl;
					cout << setfill(' ')
						 << endl;

					cout << fixed << showpoint << setprecision(2);

					//CALCULATIONS AND OUTPUT
					for(output = 0; output < countC + 1; output++)
					{
						subtotal[output] = qtyOfBooks[output] * retailAr[output];
						subtotalC        = subtotalC + subtotal[output];
						taxC             = subtotalC * 0.06;
						totalC           = subtotalC + taxC;

						cout << left;
						cout << setw(5)  << qtyOfBooks[output];
						cout << left;
						cout << setw(15) << isbnAr[output];
						cout << setw(24) << bookTitleAr[output];
						
						cout << right << fixed << setprecision(2);
						
						cout << "$";
						cout << setw(6) << retailAr[output];
						cout << setw(4) << "$";
						cout << setw(6) << subtotal[output];
						cout << endl    << endl;
					}		

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
						 
					do
					{
						cout << "Complete your purchase? (Y/N): ";
						cin.get(completePurchase);
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin.clear();

						invalidCompletePurchase = completePurchase != 'y' && completePurchase != 'Y' && completePurchase != 'n' && completePurchase != 'N';

						if(invalidCompletePurchase)
						{
							cout << "\n\n*** ERROR - PLEASE ENTER Y OR N. ***\n\n";
						}
					}while(invalidCompletePurchase);
					
					if(completePurchase == 'Y' || completePurchase == 'y')
					{
						cout << "\n\nThank You for Shopping at Serendipity!\n\n";

						system("PAUSE");
					}
					else
					{
						for(output = 0; output < countC + 1; output++)
						{
							book[bookIndexAr[output]].qtyOnHand = book[bookIndexAr[output]].qtyOnHand + bookAmt;
						}
					}
				}//END IF(no repeat)
			}//END IF(found location of book)
		}//END FOR(searching for book)
	}while(repeatC == 'Y' || repeatC == 'y');

	if(index == DBSIZE + 1)
	{
		cout << "\n\n> BOOK WAS NOT FOUND.\n\n";
		system("PAUSE");
		
		do
		{
			cout << "Do you want to search for another book? (Y/N): ";
			cin.get(searchAgain);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();

			invalidSearchAgain = searchAgain != 'Y' && searchAgain != 'y' && searchAgain != 'n' && searchAgain != 'N';

			if(invalidSearchAgain)
			{
				cout << "\n\n*** ERROR - INVALID INPUT. PLEASE ENTER Y OR N. ***\n\n";
			}
		}while(invalidSearchAgain);
	}
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

/********************************************************************
* FUNCTIONS - selectionSort - uses selection sort to sort array
********************************************************************/
void selectionSort(int list[], unsigned long long int &c, unsigned long long &w)
{
	int index;
	int smallestIndex;
	int location;
	int temp;

	c = 0;
	w = 0;

	for(index = 0; index < DBSIZE - 1; index++)
	{
		smallestIndex = index;

		for(location = index + 1; location < DBSIZE; location++)
		{
			c++;

			if(list[location] < list[smallestIndex])
			{
				smallestIndex = location;
				w++;
			}//END IF
		}// END FOR

	temp                = list[smallestIndex];
	w++;
	list[smallestIndex] = list[index];
	w++;
	list[index]         = temp;
	w++;

	}//END FOR

}
