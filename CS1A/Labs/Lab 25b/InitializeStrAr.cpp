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
 * FUNCTION InitializeStrAr
 * ____________________________________________________________________________
 * This function initializes string array to str.clear()
 * ==> returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		Needs string array and int array.
 * POST-CONDITIONS
 * 		<none>
 *****************************************************************************/

void InitializeStrAr(string stringAr[],
					 const int AR_SIZE)
{
	string myStr;
	int index;

	for(index = 0; index < AR_SIZE; index++)
	{
		stringAr[index] = myStr;
		myStr.clear();
		stringAr[index] = myStr;
	}// END FOR
}
