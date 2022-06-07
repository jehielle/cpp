// ----------------------------------------------------------------------------
// File name: exam2.cpp                                                      -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 3/13/18                                                     -
// Date of Last Modification: 3/29/18                                         -
// ----------------------------------------------------------------------------

#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <limits>

using namespace std;

struct nodeType
{
	string    author;
	string    bookTitle;
	int       isbn;
	nodeType *next;
};

//PROTOTYPES
void ChooseFromMenu(char &choice);
void AddNode(nodeType *&head, nodeType *&node, nodeType *&tail, nodeType *&title, nodeType *&authorName);
void CountNodes(nodeType *&head, nodeType *&currentP, int count);
void DeleteNode(nodeType *&head, nodeType *&node);
void PrintNode(nodeType *&head, nodeType *&currentP, nodeType *&node);
void SearchNode(nodeType *&head, nodeType *&node);


int main()
{
	nodeType *head;
	nodeType *tail;
	nodeType *node;
	nodeType *currentP;	//current for printing
	nodeType *title;
	nodeType *authorName;
	char     choice;	//user choice inputed from menu
	int      count;     //used in function CountNodes

	head       = NULL;
	tail       = NULL;
	node       = NULL;
	currentP   = NULL;
	title      = NULL;
	authorName = NULL;
	count      = 0;

	do
	{
		system("CLS");

		//FUNCTION - Display menu & let user input a choice
		ChooseFromMenu(choice);

		//SWITCH STATEMENT
		switch(toupper(choice))
		{
			case 'A': //FUNCTION - Adds a node to linked list
					  AddNode(head, node, tail, title, authorName);
			break;

			case 'C': //FUNCTION - Counts the number of nodes
					  CountNodes(head, currentP, count);
			break;

			case 'D': //FUNCTION - Deletes a book
					  DeleteNode(head, node);
			break;

			case 'P': //FUNCTION - Prints the linked list
					  PrintNode(head, currentP, node);
			break;

			case 'S': //FUNCTION - Searches through the list
					  SearchNode(head, node);
			break;
		}

	}while(choice != 'Q' && choice != 'q');

	return 0;
}

/*************************************************************************
* FUNCTION - ChooseFromMenu
*************************************************************************/

void ChooseFromMenu(char &choice)
{
	bool invalid;

	cout << "*********************************" << endl;
	cout << "*                               *" << endl;
	cout << "* EXAM 2:  ORDERED LINKED LIST  *" << endl;
	cout << "*                               *" << endl;
	cout << "*-------------------------------*" << endl;
	cout << "*                               *" << endl;
	cout << "* <A>dd Node                    *" << endl;
	cout << "* <C>ount Nodes                 *" << endl;
	cout << "* <D>elete Node                 *" << endl;
	cout << "* <P>rint Linked List           *" << endl;
	cout << "* <S>earch Linked List          *" << endl;
	cout << "* <Q>uit                        *" << endl;
	cout << "*                               *" << endl;
	cout << "*********************************" << endl;
	cout << "CHOICE: ";

	do
	{
		cin.get(choice);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();

		invalid = choice != 'A' && choice != 'P' && choice != 'Q' &&
				  choice != 'a' && choice != 'p' && choice != 'q' &&
				  choice != 'd' && choice != 'D' && choice != 'c' &&
				  choice != 'C' && choice != 's' && choice != 'S';

		if(invalid)
		{
			cout << "\n*** INVALID INPUT - PLEASE CHOOSE FROM MENU ***\n\n";

			system("PAUSE");
			system("CLS");

			cout << "*********************************" << endl;
			cout << "*                               *" << endl;
			cout << "* EXAM 2:  ORDERED LINKED LIST  *" << endl;
			cout << "*                               *" << endl;
			cout << "*-------------------------------*" << endl;
			cout << "*                               *" << endl;
			cout << "* <A>dd Node                    *" << endl;
			cout << "* <C>ount Nodes                 *" << endl;
			cout << "* <D>elete Node                 *" << endl;
			cout << "* <P>rint Linked List           *" << endl;
			cout << "* <S>earch Linked List          *" << endl;
			cout << "* <Q>uit                        *" << endl;
			cout << "*                               *" << endl;
			cout << "*********************************" << endl;
			cout << "CHOICE: ";
		}
	}while(invalid);
}//END FUNCTION


/*************************************************************************
* FUNCTION - AddNode
*************************************************************************/
void AddNode(nodeType *&head, nodeType *&node, nodeType *&tail, nodeType *&title, nodeType *&authorName)
{
	int      isbn;
	string   bookTitle;
	string   author;
	nodeType *current;

	isbn    = 0;
	current = NULL;

	//INPUT BOOK TITLE
	cout << "\nEnter Book Title: ";
	getline(cin, bookTitle);
	
	node = new nodeType;
	(*node).bookTitle = bookTitle;
	(*node).next      = NULL;

	//INPUT ISBN NUMBER
	cout << "Enter ISBN: ";
	cin  >> isbn;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	node = new nodeType;
	(*node).isbn  = isbn;
	(*node).next  = NULL;

//-------------------------------------------------------------------------
    //if statement for sorting the linked list
    if (head == NULL || (head->isbn >= node->isbn))
    {
        node->next = head;
        head       = node;
    }
    else
    {
        current = head;

        while ((current->next != NULL) && (current->next->isbn < node->isbn))
        {
            current = current->next;
        }

        node->next    = current->next;
        current->next = node;
    }
//-------------------------------------------------------------------------
	
	//INPUT AUTHOR
	cout << "Enter Author Name: ";
	getline(cin, author);
	
	node = new nodeType;
	(*node).author = author;
	(*node).next   = NULL;

}

/*************************************************************************
* FUNCTION - CountNodes
*************************************************************************/
void CountNodes(nodeType *&head, nodeType *&currentP, int count)
{
	cout << "\nCounting Linked List...\n\n";

	currentP = head;
	while(currentP != NULL)
	{
		count++;
		currentP = currentP->next;
	}

	cout << "You currently have " << count << " nodes in your list.";

	cout << endl << endl;
	system("PAUSE");
	system("CLS");
}


/*************************************************************************
* FUNCTION - DeleteNode
*************************************************************************/
void DeleteNode(nodeType *&head, nodeType *&node)
{
	nodeType *previous;
	nodeType *current;
	int      deleteNode; //node the user wants to delete
	bool     found;

	previous = NULL;
	found    = false;

	cout << "\nEnter integer you want to delete: ";
	cin  >> deleteNode;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if(head == NULL)
	{
		cout << "\n*** LIST IS EMPTY. ABORTING DELETE OPERATION ***\n\n";

		system("PAUSE");
	}

	//SEARCH - Begin to search through linked list
	current = head;

	while(current != NULL && current->isbn != deleteNode && found != true)
	{
		previous = current;
		current  = current->next;
	}

	//if deleteNode is found
	if(current->isbn == deleteNode)
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


/*************************************************************************
* FUNCTION - PrintNode
*************************************************************************/
void PrintNode(nodeType *&head, nodeType *&currentP, nodeType *&node)
{
	cout << "\nPrinting Linked List of Book Info...\n\n";
	
	currentP = head;
	while(currentP != NULL)
	{
		cout << "TITLE:  " << currentP->bookTitle                        << endl;
		
		cout << "ISBN:   " << setfill('0') << setw(10) << currentP->isbn << endl;
		cout <<               setfill(' ');
		
		cout << "AUTHOR: " << currentP->author                           << endl << endl;
		
		currentP   = currentP->next;
	}

	cout << endl << endl;
	system("PAUSE");
	system("CLS");

}

/*************************************************************************
* FUNCTION - SearchNode
*************************************************************************/
void SearchNode(nodeType *&head, nodeType *&node)
{
	int       inputISBN; //node the user wants to search for
	nodeType *previous;
	nodeType *current;
	bool      found;

	previous = NULL;
	current  = NULL;
	found    = false;

	cout << "Please enter the ISBN number for the book you want to search for: ";
	cin  >> inputISBN;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();

	if(head == NULL)
	{
		cout << "\n*** LIST IS EMPTY. ABORTING SEARCH OPERATION ***\n\n";

		system("PAUSE");
	}

	//SEARCH - Begin to search through linked list
	current = head;

	while(current != NULL && current->isbn != inputISBN && found != true)
	{
		previous = current;
		current  = current->next;
	}

	//if inputISBN is found
	if(current->isbn == inputISBN)
	{
		cout << endl << endl;
		cout << inputISBN << " IS FOUND.\n\n";

		system("PAUSE");
	}
	else
	{
		cout << endl << endl;
		cout << inputISBN << " IS NOT IN THE LIST.\n\n";

		system("PAUSE");
	}

}



