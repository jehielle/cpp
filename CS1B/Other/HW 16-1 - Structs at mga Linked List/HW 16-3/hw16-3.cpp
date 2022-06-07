// ----------------------------------------------------------------------------
// File name: hw16-3.cpp                                                      -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 3/13/18                                                     -
// Date of Last Modification: 3/13/18                                         -
// ----------------------------------------------------------------------------

#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <limits>

using namespace std;

struct nodeType
{
	int info;
	nodeType *next;
};

//PROTOTYPES
void ChooseFromMenu(char &choice);
void AddNode(nodeType *&head, nodeType *&currentB, nodeType *&node);
void DeleteNode(nodeType **head, nodeType *&currentB, nodeType *&node);
void PrintNode(nodeType *&head, nodeType *&currentP, nodeType *&currentB, nodeType *&node);

int main()
{
	nodeType *head;
	nodeType *tail;
	nodeType *node;
	nodeType *currentB;	//current for building
	nodeType *currentP;	//current for printing
	char     choice;	//user choice inputed from menu

	head     = NULL;
	tail     = NULL;
	node     = NULL;
	currentB = NULL;
	currentP = NULL;

	do
	{
		system("CLS");

		//FUNCTION - Display menu & let user input a choice
		ChooseFromMenu(choice);

		//SWITCH STATEMENT
		switch(toupper(choice))
		{
			case 'A': //FUNCTION - Adds a node to linked list
					  AddNode(head, currentB, node);
			break;
			
			case 'D': //FUNCTION - Deletes a book
					  DeleteNode(&head, currentB, node);
			break;

			case 'P': //FUNCTION - Prints the linked list
					  PrintNode(head, currentP, currentB, node);
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
	cout << "* HW15-2: UNORDERED LINKED LIST *" << endl;
	cout << "*                               *" << endl;
	cout << "*-------------------------------*" << endl;
	cout << "*                               *" << endl;
	cout << "* <A>dd Node                    *" << endl;
	cout << "* <D>elete Node                 *" << endl;
	cout << "* <P>rint Linked List           *" << endl;
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
				  choice != 'd' && choice != 'D';

		if(invalid)
		{
			cout << "\n*** INVALID INPUT - PLEASE CHOOSE FROM MENU ***\n\n";

			system("PAUSE");
			system("CLS");

			cout << "*********************************" << endl;
			cout << "*                               *" << endl;
			cout << "* HW15-2: UNORDERED LINKED LIST *" << endl;
			cout << "*                               *" << endl;
			cout << "*-------------------------------*" << endl;
			cout << "*                               *" << endl;
			cout << "* <A>dd Node                    *" << endl;
			cout << "* <D>elete Node                 *" << endl;
			cout << "* <P>rint Linked List           *" << endl;
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
void AddNode(nodeType *&head, nodeType *&currentB, nodeType *&node)
{
	int info;

	cout << "\nInfo new node(integer): ";
	cin  >> info;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//build node
	node = new nodeType;
	(*node).info  = info;
	(*node).next  = NULL;

	//IF-THEN-ELSE -> if there is a previous node
	if(head == NULL)
	{
		head = node;
	}
	else
	{
		currentB->next = node;
	}

	currentB = node; //updates current

	cout << info << " Successfully Added to Linked List\n\n";
	system("PAUSE");
	system("CLS");
}

/*************************************************************************
* FUNCTION - DeleteNode
*************************************************************************/
void DeleteNode(nodeType **head, nodeType *&currentB, nodeType *&node)
{
	nodeType **previous;
	int      deleteNode; //node the user wants to delete
	bool     found;
	
	previous = NULL;
	found    = true;
	
	cout << "\nEnter integer you want to delete: ";
	cin  >> deleteNode;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	if((*head) == NULL)
	{
		cout << "\n*** LIST IS EMPTY. ABORTING DELETE OPERATION ***\n\n";
		
		system("PAUSE");
	}
	
	//SEARCH - Begin to search through linked list
	previous = head;
	currentB = *head;
	
	while(currentB != NULL && currentB->info != deleteNode)
	{
		previous = &currentB->next;
		currentB =  currentB->next;
	}
	
	if(currentB != NULL)
	{
		cout << endl << endl;
		cout << deleteNode << " IS FOUND.\n";
		
		*previous = currentB->next;
		
		//DELETING THE NODE...
		delete currentB;
		
		cout << deleteNode << " HAS BEEN DELETED.\n\n";
		
		found = true;
		
		system("PAUSE");
	}
}


/*************************************************************************
* FUNCTION - PrintNode
*************************************************************************/
void PrintNode(nodeType *&head, nodeType *&currentP, nodeType *&currentB, nodeType *&node)
{
	cout << "\nPrinting Linked List...\n\n";

	currentP = head;
	while(currentB != NULL)
	{
		cout << currentP->info << " ";
		currentB = currentP->next;
		currentP = currentP->next;
	}

	cout << endl << endl;
	system("PAUSE");
	system("CLS");

}
