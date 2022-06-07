/******************************************************************************
 * AUTHOR        : JJ David & Nathan Smith
 * STUDENT ID    : 1083135 & 387089
 * LAB 25b       : Array Train - Set #2
 * CLASS	     : CS1A
 * SECTION	     : TTh: 1pm
 * DUE DATE	     : 11/28/17
 *****************************************************************************/

#include "myheader.h"

/******************************************************************************
 * FUNCTION InputFromUser
 * ____________________________________________________________________________
 * This function reads from a user into the arrays
* ==> returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		Needs string array and int array.
 * POST-CONDITIONS
 * 		<none>
 *****************************************************************************/

void InputFromUser(string stringAr[],
				int intAr[],
				const int AR_SIZE)
{
	string name;
	int index;

	index = 0;

	cout << "Enter name (enter \'done\' to exit): ";
	getline(cin, name);

	while(index < AR_SIZE && name != "done")
	{
		stringAr[index] = name;

		cout << "Enter age: ";
		cin  >> intAr[index];
		cin.ignore(1000, '\n');

		cout << "Enter name (enter \'done\' to exit): ";
		getline(cin, name);
		index++;

	}// END WHILE

}
