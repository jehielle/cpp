/******************************************************************************
* AUTHOR      : JJ David
* STUDENT ID  : 1083135
* LAB #19     : Problem #5
* CLASS  	  : TTh: 1:00p - 2:50p
* DUE DATE	  : 10/31/17
******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/******************************************************************************
 * LAB #19 - PROBLEM #5
 *****************************************************************************/

int main()
{
	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * OUTPUT - USED FOR CLASS HEADING
	 * ------------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * CLASS	  : Student's Course
	 * SECTION	  : Class Days and Times
	 * LAB_NAME	  : Title of the Assignment
	 *************************************************************************/

	const char PROGRAMMER[] = "JJ David";
	const char CLASS[]		= "CS1A";
	const char SECTION[]	= "TTh: 1:00p - 2:50p";
	const char LAB_NAME[]	= "Problem #5";

	int rank; // the rank of a user

	// OUTPUT - Class Heading
	cout << left;
	cout << "**************************************************************\n";
	cout << "* PROGRAMMED BY :  "  << PROGRAMMER << endl;
	cout << "* "       << setw(14) << "CLASS"    << ":  " << CLASS    << endl;
	cout << "* "	   << setw(14) << "SECTION"  << ":  " << SECTION  << endl;
	cout << "* " 	   << setw(14) << "LAB #19"  << ":  " << LAB_NAME << endl;
	cout << "*********************************************************** \n\n";
	cout << right;

	rank = 0;

	cout << "Please input your class rank: ";
	cin  >> rank;
	cout << endl;

	while(rank > -1)
		{

rank <= 3?            cout << "You are in the lower class."  << endl << endl
		 : rank >= 7? cout << "You are in the upper class."  << endl << endl
				    : cout << "You are in the middle class." << endl << endl;

		cout << "Please input your class rank: ";
		cin  >> rank;
		cout << endl;

		} // end of while loop

	return 0;
}


