// ----------------------------------------------------------------------------
// File name: main.cpp                                                        -
// Project name: Serendipity                                                  -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 4/26/18                                                     -
// Date of Last Modification: 5/08/18                                         -
// ----------------------------------------------------------------------------
// Purpose: Serendipity                                                       -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Make various instructions for the computer to help it create a     -
//         book.                                                              -
// Step 2: Make the book and print it out.                                    -
// Step 3: Make a transaction object and print it out.                        -
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// ----------------------------------------------------------------------------
#include "bookdata.h"
#include "inventoryBook.h"
#include "soldBook.h"

#include "linkedList.h"
#include "orderedLinkedList.h"

#include<cstdlib>

//PROTOTYPES
void cashier();

void invmenu();
void lookUpBook(int bookCount);
void addBook();
void editBook();
void deleteBook(InventoryBook *&head);

void reports(orderedLinkedList<InventoryBook> tList, orderedLinkedList<InventoryBook>  qohList, 
			 orderedLinkedList<InventoryBook> wpList, orderedLinkedList<InventoryBook> daList);
void repListing(orderedLinkedList<InventoryBook> tList);
void repWholesale(orderedLinkedList<InventoryBook> tList);
void repRetail(orderedLinkedList<InventoryBook> tList);
void repQty(orderedLinkedList<InventoryBook> qohList);
void repCost(orderedLinkedList<InventoryBook> wpList);
void repAge(orderedLinkedList<InventoryBook> daList);

int main()
{
	int choice;
	int bookCount; //number of books in database
	
	bookCount = 0;
	
	orderedLinkedList<InventoryBook> tList;   //title list
	tList.initializeList();

	orderedLinkedList<InventoryBook> qohList; //qty o/h list
	qohList.initializeList();
	
	orderedLinkedList<InventoryBook> wpList;  //wholesale price list
	wpList.initializeList();
	
	orderedLinkedList<InventoryBook> daList;  //date added list
	daList.initializeList();

	system("CLS");
	
	//HARDCODE THE BOOKS
	InventoryBook *book1 = new InventoryBook ("Star Wars", "0345260791", "George Lucas", "Del Rey", "10/18/2017", 5, 59.95, 100.00);
	tList.insert(*book1);
	(*book1).setSortCode(0);
	qohList.insert(*book1);
	(*book1).setSortCode(1);
	wpList.insert(*book1);
	(*book1).setSortCode(2);
	daList.insert(*book1);
	(*book1).setSortCode(3);
	
	InventoryBook *book2 = new InventoryBook ("The Empire Strikes Back (Star Wars)", "034529209X", "George Lucas", "Ballantine", "04/01/2017", 2, 179.58, 185.00);
	tList.insert(*book2);
	(*book2).setSortCode(0);
	qohList.insert(*book2);
	(*book2).setSortCode(1);
	wpList.insert(*book2);
	(*book2).setSortCode(2);
	daList.insert(*book2);
	(*book2).setSortCode(3);
	
	InventoryBook *book3 = new InventoryBook ("Splinter of the Mind's Eye (Star Wars)", "0345320239", "George Lucas", "Del Rey", "11/08/2017", 3, 24, 26.50);
	tList.insert(*book3);
	(*book3).setSortCode(0);
	qohList.insert(*book3);
	(*book3).setSortCode(1);
	wpList.insert(*book3);
	(*book3).setSortCode(2);
	daList.insert(*book3);
	(*book3).setSortCode(3);
	
	InventoryBook *book4 = new InventoryBook ("Return of the Jedi (Star Wars)", "0345307674", "George Lucas", "Del Rey", "10/09/2017", 4, 2.94, 6.50);
	tList.insert(*book4);
	(*book4).setSortCode(0);
	qohList.insert(*book4);
	(*book4).setSortCode(1);
	wpList.insert(*book4);
	(*book4).setSortCode(2);
	daList.insert(*book4);
	(*book4).setSortCode(3);
	
	InventoryBook *book5 = new InventoryBook ("Heir to the Empire (Star Wars: The Thrawn Trilogy, Vol. 1)", "0553296124", "Timothy Zahn", "Bantam", "11/01/2017", 10, 25.38, 27.00);
	tList.insert(*book5);
	(*book5).setSortCode(0);
	qohList.insert(*book5);
	(*book5).setSortCode(1);
	wpList.insert(*book5);
	(*book5).setSortCode(2);
	daList.insert(*book5);
	(*book5).setSortCode(3);

	//DO WHILE - repeat until user exits
	do
	{
		cout << "*****************************************" << endl;
		cout << "*        SERENDIPITY BOOKSELLERS        *" << endl;
		cout << "*               MAIN MENU               *" << endl;
		cout << "*****************************************" << endl;
		cout << "* <1> Cashier Module                    *" << endl;
		cout << "* <2> Inventory Database Module         *" << endl;
		cout << "* <3> Report Module                     *" << endl;
		cout << "* <4> Exit                              *" << endl;
		cout << "*****************************************" << endl;
		cout << " > CHOICE: ";
		
		//CHECKING FOR INVALID INPUT
		do
		{
			cin >> choice;
			cin.ignore(1000, '\n');
			cin.clear();
			
			if(choice != 1 && choice != 2 && choice != 3 && choice != 4)
			{
				cout << "\n\n*** ERROR - PLEASE INPUT 1-4 ***\n\n";
			}
		}while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
		
		system("CLS");
		
		//SWITCH
		switch(choice)
		{
			case 1: cashier();
			break;
			
			case 2: invmenu();
			break;
			
			case 3: reports(tList, qohList, wpList, daList);
			break;
		}
	}while(choice != 4);
	
	return 0;
}





/*********************************************************************
* 
* FUNCTIONS
* 
*********************************************************************/
/*********************************************************************
* FUNCTION - CASHIER
*********************************************************************/
void cashier()
{
	system("PAUSE");
	system("CLS");
}

/*********************************************************************
* FUNCTION - INVMENU
*********************************************************************/
void invmenu()
{
	int choice;
	
	choice = 0;
	
	do
	{
		cout << "*****************************************"  << endl;
		cout << "*        SERENDIPITY BOOKSELLERS        *"  << endl;
		cout << "*          INVENTORY DATABASE           *"  << endl;
		cout << "*****************************************"  << endl;
		cout << "* <1> Look Up a Book                    *"  << endl;
		cout << "* <2> Add a Book                        *"  << endl;
		cout << "* <3> Edit a Book\'s Record              *" << endl;
		cout << "* <4> Delete a Book                     *"  << endl;
		cout << "* <5> Return to the Main Menu           *"  << endl;
		cout << "*****************************************"  << endl;
		cout << " > CHOICE: ";
		
		//CHECKING FOR INVALID INPUT
		do
		{
			cin >> choice;
			cin.ignore(1000, '\n');
			cin.clear();
			
			if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
			{
				cout << "\n\n*** ERROR - PLEASE INPUT 1-5 ***\n\n";
			}
		}while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
		
		system("CLS");
		
		//SWITCH
		switch(choice)
		{
			case 1: lookUpBook(bookCount);
			break;
			
			case 2: addBook();
			break;
			
			case 3: editBook();
			break;
			
			case 4: deleteBook(book1);
			break;
		}
		
		system("PAUSE");
		system("CLS");
		
	}while(choice != 5);
}

/*********************************************************************
* FUNCTION - LOOK UP BOOK
*********************************************************************/
void lookUpBook(int bookCount)
{
	string searchlookUpBook;
	int    location;
	int    index;
	
	location = -1;
	
	//use ISBN AND title
	//print out info
	
	cout << ">>> BOOK LOOK UP <<<";
	cout << endl << endl;
	cout << "> Search by title or ISBN: ";
	getline(cin, searchlookUpBook);
	
	for(index = 0; index < bookCount; index++)
	{
		location = tList.bookTitle.find(searchlookUpBook);

		if(location != -1)
		{
			
		}
	}
}

/*********************************************************************
* FUNCTION - ADD BOOK
*********************************************************************/
void addBook()
{
	
}

/*********************************************************************
* FUNCTION - EDIT BOOK
*********************************************************************/
void editBook()
{
	
}

/*********************************************************************
* FUNCTION - DELETE BOOK
*********************************************************************/
void deleteBook(InventoryBook *&head)
{
	InventoryBook *previous;
	InventoryBook *current;
	string    deleteNode; //node the user wants to delete
	bool      found;
	
	
	//need to learn how to search thru the linked list before this.
	//also, prolly should use strcmp to compare the strings.
	
	
	
	

	previous = NULL;
	found    = false;
	
	cout << "SERENDIPITY BOOKSELLERS" << endl;
	cout << "     DELETE BOOK       " << endl;
	cout <<                              endl << endl;
	cout << " CURRENT BOOK COUNT: "   << bookCount + 1;
	
	cout << ">Search: ";
	getline(cin, deleteNode);

	if(head == NULL)
	{
		cout << "\n*** LIST IS EMPTY. ABORTING DELETE OPERATION ***\n\n";

		system("PAUSE");
	}

	//SEARCH - Begin to search through linked list
	current = head;

	while(current != NULL && current->info != deleteNode && found != true)
	{
		previous = current;
		current  = current->next;
	}

	//if deleteNode is found
	if(current->info == deleteNode)
	{
		cout << endl << endl;
		cout << deleteNode << " IS FOUND.\n";

		previous->next = current->next;

		//DELETING THE NODE...
		delete current;

		cout << deleteNode << " HAS BEEN DELETED.\n\n";

		system("PAUSE");
	}
}

/*********************************************************************
* FUNCTION - REPORTS
*********************************************************************/
void reports(orderedLinkedList<InventoryBook> tList, orderedLinkedList<InventoryBook> qohList, orderedLinkedList<InventoryBook> wpList, orderedLinkedList<InventoryBook> daList)
{
	int choice;
	
	choice = 0;
	
	do
	{
		cout << "*****************************************" << endl;
		cout << "*        SERENDIPITY BOOKSELLERS        *" << endl;
		cout << "*            REPORTS MENU               *" << endl;
		cout << "*****************************************" << endl;
		cout << "* <1> Inventory Listing                 *" << endl;
		cout << "* <2> Inventory Wholesale Value         *" << endl;
		cout << "* <3> Inventory Retail Value            *" << endl;
		cout << "* <4> Listing by Quantity               *" << endl;
		cout << "* <5> Listing by Cost                   *" << endl;
		cout << "* <6> Listing by Age                    *" << endl;
		cout << "* <7> Return to the Main Menu           *" << endl;
		cout << "*****************************************" << endl;
		cout << " > CHOICE: ";
		
		//CHECKING FOR INVALID INPUT
		do
		{
			cin >> choice;
			cin.ignore(1000, '\n');
			cin.clear();
			
			if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
			{
				cout << "\n\n*** ERROR - PLEASE INPUT 1-7 ***\n\n";
			}
		}while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7);
		
		system("CLS");
		
		//SWITCH
		switch(choice)
		{
			case 1: repListing(tList);
			break;
			
			case 2: repWholesale(tList);
			break;
			
			case 3: repRetail(tList);
			break;
			
			case 4: repQty(qohList);
			break;
			
			case 5: repCost(wpList);
			break;
			
			case 6: repAge(daList);
			break;
		}
		
		system("PAUSE");
		system("CLS");
		
	}while(choice != 7);
	
}

/*********************************************************************
* FUNCTION - REPLISTING
*********************************************************************/
void repListing(orderedLinkedList<InventoryBook> tList)
{
	cout << "     SERENDIPITY BOOKSELLERS" << endl;
	cout << "          REPORT LISTING    " << endl << endl;
	
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
	
	cout << fixed << setprecision(2);

	//CREATE ITERATOR
	linkedListIterator<InventoryBook> myIterator;
	
	//OUTPUT - linked list
	for(myIterator = tList.begin(); myIterator != tList.end(); ++myIterator)
	{
		cout << left;
		cout <<         setw(26) << (*myIterator).getTitle().substr(0, 24);
		cout <<         setw(11) << (*myIterator).getIsbn().substr(0, 10);
		cout <<         setw(16) << (*myIterator).getAuthor().substr(0, 15);
		cout <<         setw(16) << (*myIterator).getPub().substr(0, 15);
		cout <<         setw(11) << (*myIterator).getDateAdded().substr(0, 10);
		cout <<         setw(8)  << (*myIterator).getQtyOnHand();
		cout << "$ " << setw(15) << (*myIterator).getWholesale();
		cout << "$ " << setw(13) << (*myIterator).getRetail();
		cout << endl;
	}
	
	cout << endl;
}

/*********************************************************************
* FUNCTION - repWholesale
*********************************************************************/
void repWholesale(orderedLinkedList<InventoryBook> tList)
{
	double subtotal;
	double grandTotal;
	
	subtotal   = 0;
	grandTotal = 0;
	
	cout << "     SERENDIPITY BOOKSELLERS  " << endl;
	cout << "     REPORT WHOLESALE LISTING " << endl << endl;
	
	cout << left;
	cout << setw(26) << "TITLE";
	cout << setw(11) << "ISBN";
	cout << setw(8)  << "QTY O/H";
	cout << setw(15) << "WHOLESALE COST";
	cout << endl;
	
	cout << setw(26) << "-------------------------";
	cout << setw(11) << "----------";
	cout << setw(8)  << "-------";
	cout << setw(15) << "--------------";
	cout << endl;
	
	cout << fixed << setprecision(2);

	//CREATE ITERATOR
	linkedListIterator<InventoryBook> myIterator;
	
	//OUTPUT - linked list
	for(myIterator = tList.begin(); myIterator != tList.end(); ++myIterator)
	{
		cout << left;
		cout <<         setw(26) << (*myIterator).getTitle().substr(0, 24);
		cout <<         setw(11) << (*myIterator).getIsbn().substr(0, 10);
		cout <<         setw(8)  << (*myIterator).getQtyOnHand();
		cout << "$ " << setw(15) << (*myIterator).getWholesale();
		cout << endl;
		
		//CALC - subtotal and grandTotal
		subtotal   = (*myIterator).getQtyOnHand() * (*myIterator).getWholesale();
		grandTotal = grandTotal + subtotal;
	}
	
	cout << endl;
	cout << "TOTAL: $" << grandTotal;
	cout << endl       << endl;
}


/*********************************************************************
* FUNCTION - repRetail
*********************************************************************/
void repRetail(orderedLinkedList<InventoryBook> tList)
{
	double subtotal;
	double grandTotal;

	subtotal   = 0;
	grandTotal = 0;

	cout << "     SERENDIPITY BOOKSELLERS" << endl;
	cout << "      REPORT RETAIL LISTING " << endl << endl;
	
	cout << left;
	cout << setw(26) << "TITLE";
	cout << setw(11) << "ISBN";
	cout << setw(8)  << "QTY O/H";
	cout << setw(15) << "RETAIL COST";
	cout << endl;
	
	cout << setw(26) << "-------------------------";
	cout << setw(11) << "----------";
	cout << setw(8)  << "-------";
	cout << setw(15) << "--------------";
	cout << endl;
	
	cout << fixed << setprecision(2);

	//CREATE ITERATOR
	linkedListIterator<InventoryBook> myIterator;
	
	//OUTPUT - linked list
	for(myIterator = tList.begin(); myIterator != tList.end(); ++myIterator)
	{
		cout << left;
		cout <<         setw(26) << (*myIterator).getTitle().substr(0, 24);
		cout <<         setw(11) << (*myIterator).getIsbn().substr(0, 10);
		cout <<         setw(8)  << (*myIterator).getQtyOnHand();
		cout << "$ " << setw(15) << (*myIterator).getRetail();
		cout << endl;
		
		//CALC - subtotal and grandTotal
		subtotal   = (*myIterator).getQtyOnHand() * (*myIterator).getRetail();
		grandTotal = grandTotal + subtotal;
	}
	
	cout << endl;
	cout << "TOTAL: $" << grandTotal;
	cout << endl       << endl;
}


/*********************************************************************
* FUNCTION - repQty
*********************************************************************/
void repQty(orderedLinkedList<InventoryBook> qohList)
{
	cout << "     SERENDIPITY BOOKSELLERS" << endl;
	cout << "     REPORT QTY O/H LISTING " << endl << endl;
	
	cout << left;
	cout << setw(26) << "TITLE";
	cout << setw(11) << "ISBN";
	cout << setw(8)  << "QTY O/H";
	cout << endl;
	
	cout << setw(26) << "-------------------------";
	cout << setw(11) << "----------";
	cout << setw(8)  << "-------";
	cout << endl;
	
	//CREATE ITERATOR
	linkedListIterator<InventoryBook> myIterator;
	
	//OUTPUT - linked list
	for(myIterator = qohList.begin(); myIterator != qohList.end(); ++myIterator)
	{
		cout << left;
		cout <<         setw(26) << (*myIterator).getTitle().substr(0, 24);
		cout <<         setw(11) << (*myIterator).getIsbn().substr(0, 10);
		cout <<         setw(8)  << (*myIterator).getQtyOnHand();
		cout << endl;
	}
	
	cout << endl;
}


/*********************************************************************
* FUNCTION - repCost
*********************************************************************/
void repCost(orderedLinkedList<InventoryBook> wpList)
{
	cout << "     SERENDIPITY BOOKSELLERS  " << endl;
	cout << "     REPORT WHOLESALE LISTING " << endl << endl;
	
	cout << left;
	cout << setw(26) << "TITLE";
	cout << setw(11) << "ISBN";
	cout << setw(8)  << "QTY O/H";
	cout << setw(15) << "WHOLESALE COST";
	cout << endl;
	
	cout << setw(26) << "-------------------------";
	cout << setw(11) << "----------";
	cout << setw(8)  << "-------";
	cout << setw(15) << "--------------";
	cout << endl;
	
	cout << fixed << setprecision(2);

	//CREATE ITERATOR
	linkedListIterator<InventoryBook> myIterator;
	
	//OUTPUT - linked list
	for(myIterator = wpList.begin(); myIterator != wpList.end(); ++myIterator)
	{
		cout << left;
		cout <<         setw(26) << (*myIterator).getTitle().substr(0, 24);
		cout <<         setw(11) << (*myIterator).getIsbn().substr(0, 10);
		cout <<         setw(8)  << (*myIterator).getQtyOnHand();
		cout << "$ " << setw(15) << (*myIterator).getWholesale();
		cout << endl;
	}
	
	cout << endl;
}


/*********************************************************************
* FUNCTION - repAge
*********************************************************************/
void repAge(orderedLinkedList<InventoryBook> daList)
{
	cout << "     SERENDIPITY BOOKSELLERS  " << endl;
	cout << "       REPORT AGE LISTING     " << endl << endl;
	
	cout << left;
	cout << setw(26) << "TITLE";
	cout << setw(11) << "ISBN";
	cout << setw(8)  << "QTY O/H";
	cout << setw(11) << "DATE ADDED";
	cout << endl;
	
	cout << setw(26) << "-------------------------";
	cout << setw(11) << "----------";
	cout << setw(8)  << "-------";
	cout << setw(11) << "----------";
	cout << endl;
	
		//CREATE ITERATOR
	linkedListIterator<InventoryBook> myIterator;
	
	//OUTPUT - linked list
	for(myIterator = daList.begin(); myIterator != daList.end(); ++myIterator)
	{
		cout << left;
		cout <<         setw(26) << (*myIterator).getTitle().substr(0, 24);
		cout <<         setw(11) << (*myIterator).getIsbn().substr(0, 10);
		cout <<         setw(8)  << (*myIterator).getQtyOnHand();
		cout <<         setw(11) << (*myIterator).getDateAdded();
		cout << endl;
	}
	
	cout << endl;
	
}

