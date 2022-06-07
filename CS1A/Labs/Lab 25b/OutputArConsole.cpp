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
 * FUNCTION OutputArConsole
 * ____________________________________________________________________________
 * This function outputs array contents in table format to console
* ==> returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		Needs string array and int array.
 * POST-CONDITIONS
 * 		<none>
 *****************************************************************************/

void OutputArConsole(string stringAr[],
					 int intAr[],
					 const int AR_SIZE)
{
	const int NAME_COL = 14;
	const int AGE_COL = 13;

	int index;

	cout << setw(NAME_COL) << "NAME" << setw(NAME_COL) << "AGE\n";
	cout << endl;

	for(index = 1; index < AR_SIZE; index++)
	{
		cout << setw(NAME_COL) << stringAr[index]
			 << setw(AGE_COL) << intAr[index] << endl;
	}//END FOR
}
