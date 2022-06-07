/******************************************************************************
* AUTHOR      : JJ David
* STUDENT ID  : 1083135
* LAB #19     : Problem #4
* CLASS  	  : TTh: 1:00p - 2:50p
* DUE DATE	  : 10/31/17
******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

/******************************************************************************
 * LAB #19 - PROBLEM #4
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
	const char LAB_NAME[]	= "Problem #4";

	char classCode; // IN   - can either be F, S, J, or R
	bool invalid;   // CALC - when an input is not F, S, J, or R

	// OUTPUT - Class Heading
	cout << left;
	cout << "**************************************************************\n";
	cout << "* PROGRAMMED BY :  "  << PROGRAMMER << endl;
	cout << "* "       << setw(14) << "CLASS"    << ":  " << CLASS    << endl;
	cout << "* "	   << setw(14) << "SECTION"  << ":  " << SECTION  << endl;
	cout << "* " 	   << setw(14) << "LAB #19"  << ":  " << LAB_NAME << endl;
	cout << "*********************************************************** \n\n";
	cout << right;

	do
	{
		cout << "Please input either F, S, J, or R: ";
		cin.get(classCode);
		cin.ignore(1000, '\n');
		classCode = toupper(classCode);
		invalid = classCode != 'F' && classCode != 'S' && classCode != 'J'
			   && classCode != 'R';

		if(invalid)
		{
			cout << endl;
			cout << classCode << " is an INVALID INPUT - Please try again!";
			cout << endl << endl;
		}
	}while(invalid);
		cout << endl;
		cout << classCode << " is valid - thank you!" << endl;

	return 0;
}
