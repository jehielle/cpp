// ----------------------------------------------------------------------------
// File name: hw16-5.cpp                                                      -
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
	int info;
	nodeType *next;
};

//PROTOTYPES
void ChooseFromMenu(char &choice);
void AddNode(nodeType *&head, nodeType *&node, nodeType *&tail);
void DeleteNode(nodeType *&head, nodeType *&node);
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
					  AddNode(head, node, tail);
			break;

			case 'D': //FUNCTION - Deletes a book
					  DeleteNode(head, node);
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
	cout << "* HW16-5:   ORDERED LINKED LIST *" << endl;
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
			cout << "* HW16-5:   ORDERED LINKED LIST *" << endl;
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
void AddNode(nodeType *&head, nodeType *&node, nodeType *&tail)
{
	int      info;
	nodeType *current;

	info    = 0;
	current = NULL;

	cout << "\nInfo new node(integer): ";
	cin  >> info;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//build node
	node = new nodeType;
	(*node).info  = info;
	(*node).next  = NULL;

    //if statement for sorting the linked list
    if (head == NULL || (head->info >= node->info))
    {
        node->next = head;
        head       = node;
    }
    else
    {
        current = head;
		
        while ((current->next != NULL) && (current->next->info < node->info))
        {
            current = current->next;
        }
		
        node->next    = current->next;
        current->next = node;
    }
	
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


/*************************************************************************
* FUNCTION - PrintNode
*************************************************************************/
void PrintNode(nodeType *&head, nodeType *&currentP, nodeType *&currentB, nodeType *&node)
{
	cout << "\nPrinting Linked List...\n\n";

	currentP = head;
	while(currentP != NULL)
	{
		cout << currentP->info << " ";
		currentP = currentP->next;
	}

	cout << endl << endl;
	system("PAUSE");
	system("CLS");

}
