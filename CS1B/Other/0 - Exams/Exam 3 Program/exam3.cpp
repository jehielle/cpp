// ----------------------------------------------------------------------------
// File name: exam3.cpp                                                       -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 5/22/18                                                     -
// Date of Last Modification: 5/22/18                                         -
// ----------------------------------------------------------------------------
// Purpose: Exam 3 Program                                                    -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Create a menu for the user & let user choose from menu.            -
// Step 2: Based on user's choice from menu, do whatever the user wants (such -
//         as creating/deleting/searching a node, etc).                       -
// Step 3: Continue to repeat the program until the user wants to quit.       -
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// - info              integer      0                                         -
// - *next             nodeType     NULL                                      -
// - *head             nodeType     NULL                                      -
// - *tail             nodeType     NULL                                      -
// - *node             nodeType     NULL                                      -
// - *current          nodeType     NULL                                      -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// -                                                                          -
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
void ChooseFromMenu(int &choice);

void CreateNode(nodeType *&head, nodeType *&node, nodeType *&tail);
void InsertFirst(nodeType *&head, nodeType *&tail, nodeType *&node);
void InsertLast(nodeType *&head, nodeType *&tail, nodeType *&node);

void DeleteNode(nodeType *&head, nodeType *&tail);

void Search(nodeType *&head);

void DisplayList(nodeType *&head, nodeType *&current);

void DeleteList(nodeType *&head);


int main()
{
	nodeType *head;
	nodeType *tail;
	nodeType *node;
	nodeType *current;	//current for displaying
	int      choice;	//user choice inputed from menu

	head     = NULL;
	tail     = NULL;
	node     = NULL;
	current  = NULL;

	system("CLS");

	do
	{
		//FUNCTION - Display menu & let user input a choice
		ChooseFromMenu(choice);

		//SWITCH STATEMENT
		switch(choice)
		{
			case 1: //Clear the Screen
					 system("CLS");
			break;

			case 2: //FUNCTION - Adds a node to linked list
					  CreateNode(head, node, tail);
			break;

			case 3: //FUNCTION - Deletes a node from linked list
					  DeleteNode(head, tail);
			break;

			case 4: //FUNCTION - Search
					  Search(head);
			break;

			case 5: //FUNCTION - Displays the linked list
					  DisplayList(head, current);
			break;

			case 6: //FUNCTION - Deletes the linked list
					  DeleteList(head);
			break;
		}

	}while(choice != 7);

	return 0;
}

/*************************************************************************
* FUNCTION - ChooseFromMenu
*************************************************************************/
void ChooseFromMenu(int &choice)
{
	bool invalid;

	do
	{
		cout << "*********************************" << endl;
		cout << "*        EXAM 3 PROGRAM         *" << endl;
		cout << "*-------------------------------*" << endl;
		cout << "* <1> Clear the Screen          *" << endl;
		cout << "* <2> Create Node               *" << endl;
		cout << "* <3> Delete Node               *" << endl;
		cout << "* <4> Search                    *" << endl;
		cout << "* <5> Display Linked List       *" << endl;
		cout << "* <6> Delete Linked List        *" << endl;
		cout << "* <7> Quit                      *" << endl;
		cout << "*********************************" << endl;
		cout << "CHOICE: ";

		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();

		invalid = choice != 1 && choice != 2 && choice != 3 && choice != 4 &&
				  choice != 5 && choice != 6 && choice != 7;

		if(invalid)
		{
			cout << "\n*** INVALID INPUT - PLEASE CHOOSE FROM MENU ***\n\n";
		}
	}while(invalid);
}


/*************************************************************************
* FUNCTION - CreateNode
*************************************************************************/
void CreateNode(nodeType *&head, nodeType *&node, nodeType *&tail)
{
	int      info;
	char     choice;

	info    = 0;

	cout << "\nCreate new node (integer): ";
	cin  >> info;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//build node
	node = new nodeType;
	(*node).info  = info;
	(*node).next  = NULL;

	do
	{
		cout << "\nInsert <F>irst or Insert <L>ast in list: ";
		cin.get(choice);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();

		if(choice != 'F' && choice != 'f' && choice != 'L' && choice != 'l')
		{
			cout << "\n\n*** ERROR - PLEASE INPUT F OR L ***\n\n";
		}

		switch(toupper(choice))
		{
			case 'F': InsertFirst(head, tail, node);
			break;

			case 'L': InsertLast(head, tail, node);
			break;
		}

	}while(choice != 'F' && choice != 'f' && choice != 'L' && choice != 'l');
}

/*************************************************************************
* FUNCTION - InsertFirst
*************************************************************************/
void InsertFirst(nodeType *&head, nodeType *&tail, nodeType *&node)
{
	node->next = head;
	head       = node;

	if(tail == NULL)
	{
		tail = node;
	}

	cout << (*node).info << " Successfully Added to Linked List\n\n";
	system("PAUSE");
}

/*************************************************************************
* FUNCTION - InsertLast
*************************************************************************/
void InsertLast(nodeType *&head, nodeType *&tail, nodeType *&node)
{
	//IF-THEN-ELSE -> if there is a previous node
	if(head == NULL)
	{
		head = node;
		tail = node;
	}
	else
	{
		tail->next = node;
		tail       = node;
	}

	cout << node->info << " Successfully Added to Linked List\n\n";
	system("PAUSE");
}

/*************************************************************************
* FUNCTION - DeleteNode
*************************************************************************/
void DeleteNode(nodeType *&head, nodeType *&tail)
{
	nodeType *current; //pointer to traverse the list
    nodeType *trailCurrent; //pointer just before current
    bool found;
	int  deleteItem;
	
	cout << "\n>Search integer to delete: ";
	cin  >> deleteItem;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (head == NULL)    //Case 1; the list is empty. 
	{
        cout << "\nCannot delete from an empty list.\n\n";
	}
    else
    {
        if (head->info == deleteItem) //Case 2 
        {
            current = head;
            head    = head->next;
            if (head == NULL)    //the list has only one node
                tail = NULL;
            delete current;
			cout << "\n\nItem deleted.\n\n";
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = head;  //set trailCurrent to point
                                   //to the head node
            current = head->next; //set current to point to 
                                   //the second node

            while (current != NULL && !found)
            {
                if (current->info != deleteItem) 
                {
                    trailCurrent = current;
                    current = current-> next;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->next = current->next;

                if (tail == current)   //node to be deleted 
                                       //was the tail node
                    tail = trailCurrent; //update the value 
                                         //of tail
                delete current;  //delete the node from the list
				cout << "\n\nItem deleted.\n\n";
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}

/*************************************************************************
* FUNCTION - Search
*************************************************************************/
void Search(nodeType *&head)
{
	nodeType *current; //pointer to traverse the list
    bool     found;
	int      searchItem;

	found   = false;

	cout << "\n\n>SEARCH (integer): ";
	cin  >> searchItem;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

    current = head; //set current to point to the first
                     //node in the list

    while (current != NULL && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->next; //make current point to
                                     //the next node

    if(found == true)
	{
		cout << "\n*** " << searchItem << " IS IN THE LIST ***\n\n";
	}
	else if(found == false)
	{
		cout << "\n*** " << searchItem << " IS NOT IN THE LIST ***\n\n";
	}
}

/*************************************************************************
* FUNCTION - DisplayList
*************************************************************************/
void DisplayList(nodeType *&head, nodeType *&current)
{
	cout << "\nDisplaying Linked List...\n\n";

	current = head;
	if(current == NULL)
	{
		cout << "LIST IS EMPTY.\n\n";
	}
	
	while(current != NULL)
	{
		cout << current->info << " ";
		current = current->next;
	}

	cout << endl << endl;
	system("PAUSE");

}

/*************************************************************************
* FUNCTION - DeleteList
*************************************************************************/
void DeleteList(nodeType *&head)
{
	nodeType *current;

	cout << "\n\nDeleting list...\n";

	current = head;
	
    if(head == NULL)    //Case 1; the list is empty. 
	{
        cout << "\nCannot delete from an empty list.\n\n";
	}
    else
    {
        DeleteList(current->next);
		
		delete current;
		
		current = NULL;
    }
}


