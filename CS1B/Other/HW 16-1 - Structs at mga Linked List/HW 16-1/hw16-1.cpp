// ----------------------------------------------------------------------------
// File name: hw16-1.cpp                                                      -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 3/8/18                                                      -
// Date of Last Modification: 3/8/18                                          -
// ----------------------------------------------------------------------------
// Purpose: HW 15-1                                                           -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Assign numbers to values in the list.                              -
// Step 2: Print them out in different ways.                                  -
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
// - info              int (nodeType)    -                                    -
// - *next             pointer(nodeType) -                                    -
// - *head             nodeType          -                                    -
// - *node             nodeType          -
// - node1             nodeType          -                                    -
// - node2             nodeType          -                                    -
// - node3             nodeType          -                                    -
// - node4             nodeType          -                                    -
// -                                                                          -
// ----------------------------------------------------------------------------


#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodeType
{
	int info;
	nodeType *next;
};

int main()
{
	nodeType *head;
	nodeType *node;
	
	nodeType node1;
	nodeType node2;
	nodeType node3;
	nodeType node4;
	
	system("CLS");
	
	//establish the head of the linked list
	head = &node1;
	
	//x = number of current node
	
	//build node1 
	node1.info = 5;
	node1.next = NULL;
	
	//if there is a previous node
	//then nodex-1.next = &nodex;
	
	node2.info = 7;
	node2.next = NULL;
	
	//if there is a previous node
	//then nodex-1.next = &nodex;
	node1.next = &node2;
	
	node3.info = -5;
	node3.next = NULL;
	
	//if there is a previous node
	//then nodex-1.next = &nodex;
	node2.next = &node3;
	
	node4.info = 33;
	node4.next = NULL;
	
	//if there is a previous node
	//then nodex-1.next = &nodex;
	node3.next = &node4;
	
	/**************************************************************/
	
	cout << "Very crude way: " 	  << endl << endl;
	
	cout << "Value of node1 is: " << node1.info;
	cout << endl;
	cout << "Value of node2 is: " << node1.next->info;
	cout << endl;
	cout << "Value of node3 is: " << node1.next->next->info; 
	cout << endl;
	cout << "Value of node4 is: " << node1.next->next->next->info;
	cout << endl << endl;
	
	/**************************************************************/
	
	cout << "More advanced way: " << endl << endl;
	
	cout << "Value of node1 is: " << (*head).info;
	cout << endl;
	cout << "Value of node2 is: " << (*head).next->info;
	cout << endl;
	cout << "Value of node3 is: " << (*head).next->next->info; 
	cout << endl;
	cout << "Value of node4 is: " << (*head).next->next->next->info;
	cout << endl << endl;
	
	/**************************************************************/
	
	cout << "Best way: " 		  << endl << endl;
	
	//reset the head
	head = NULL;
	
	//build new node 1
	node->info = 205;
	node->next = NULL;
	
	//if there is a previous node
	if(head != NULL)
	{
		head->next = node;
	}
	else
	{
		head = node;	
	}
	
	//print 1
	cout << "Value of new node 1 is: " << head->info;
	cout << endl;
	
	//node 2
	node->info = 305;
	node->next = NULL;
	
	//if there is a previous node
	if(head != NULL)
	{
		head->next = node;
	}
	else
	{
		head = node;	
	}
	
	//print 2
	cout << "Value of new node 2 is: " << head->next->info;
	cout << endl;
	
	//node 3
	node->info = 405;
	node->next = NULL;
	
	//if there is a previous node
	if(head != NULL)
	{
		head->next = node;
	}
	else
	{
		head = node;	
	}
	
	//print 3
	cout << "Value of new node 3 is: " << head->next->info; 
	cout << endl;
	
	//node 4
	node->info = 505;
	node->next = NULL;
	
	//if there is a previous node
	if(head != NULL)
	{
		head->next = node;
	}
	else
	{
		head = node;	
	}
	
	//print 4
	cout << "Value of new node 4 is: " << head->next->info;
	cout << endl << endl;
	
	return 0;
}