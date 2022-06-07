// ----------------------------------------------------------------------------
// File name: recursion.cpp                                                   -
// Project name: recursion hw                                                 -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 5/10/18                                                     -
// Date of Last Modification: 5/10/18                                         -
// ----------------------------------------------------------------------------
// Purpose: hw                                                                -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// - Step 1: Let the user pick how many asterisks to print in one line.
// - Step 2: Print it out.
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
// - numAster          int          0
// - count             int          0
// ----------------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>

using namespace std;

void printAster(int numAster);

int main()
{
	system("CLS");
	
	int  numAster; //number of asterisks (eg. 3 = ***)
	
	numAster = 0;
	
	//CHECK FOR INVALID INPUT
	do
	{
		cout << "Enter a nonnegative number of asterisks to print out: ";
		cin  >> numAster;
		cin.ignore(1000, '\n');
		cin.clear();
	
		if(numAster <= 0)
		{
			cout << "\n*** ERROR - PLEASE ENTER A NONNEGATIVE NUMBER ***\n\n";
		}
	}while(numAster <= 0);
	
	cout << endl;
	
	//FUNCTION CALL
	printAster(numAster);

	return 0;
}

void printAster(int numAster)
{
	for(int count = 0; count < numAster; count++)
	{
		cout << "*";
	}
	cout << endl;
	
	if(numAster > 1)
	{
		printAster(numAster - 1);
	}
	
	for(int count = 0; count < numAster; count++)
	{
		cout << "*";
	}
	cout << endl;
	
}
