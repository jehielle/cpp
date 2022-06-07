/******************************************************************************
 * AUTHOR        : JJ David & Justice Flenniken
 * STUDENT ID    : 1083135 & 1071976
 * ASSIGNMENT #9 : Functions
 * CLASS	     : CS1A
 * SECTION	     : TTh: 1pm
 * DUE DATE	     : 11/21/17
 *****************************************************************************/

#include <iostream>
#include<iomanip>
#include <string>
using namespace std;

/******************************************************************************
 * FUNCTION PrintHeader
 * ____________________________________________________________________________
 * This function receives an assignment name, type, and number,
 * then outputs the appropriate header. It returns nothing.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to
 * 		calling the function:
 * 			asName: Assignment Name
 * 			asNum : Assignment Number
 * 			asType: Assignment Type ==> THIS SHOULD CONTAIN:
 * 										'L' for Labs
 * 										'A' for Assignments
 *
 * POST-CONDITIONS
 * 		This function will output the class heading.
 *****************************************************************************/

void PrintHeader(string asName,      // IN & OUT - name of the lab/assignment
				 int    asNum,       // IN & OUT - number of the lab/assignment
				 char   asType = 'L')// IN       - whether lab or assignment)
									 // 		   ('L' = Lab,
									 // 		    'A' = Assignment)
{
	cout << left;
	cout << "******************************************************\n";
	cout << "*  PROGRAMMED BY : JJ David & Justice Flenniken\n";
	cout << "*  " << setw(14) << "STUDENT ID" << ": 1083135 & 1071976\n";
	cout << "*  " << setw(14) << "CLASS"      << ": CS1A TTh - 1pm\n";
	cout << "*  ";

	// PROCESSING - This will adjust setws and format appropriately
	// 			    based on if this is a lab ('L') or assignment.

	if(toupper(asType) == 'L')
	{
		cout << "LAB #" << setw(9);
	}
	else
	{
		cout << "ASSIGNMENT #" << setw(2);
	}
	cout << asNum << ": " << asName << endl;
	cout << "******************************************************\n";
	cout << right;
}
