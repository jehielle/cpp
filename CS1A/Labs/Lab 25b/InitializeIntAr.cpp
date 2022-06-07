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
 * FUNCTION InitializeIntAr
 * ____________________________________________________________________________
 * This function will initialize int array to -1.
 * ==> returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		Needs string array and int array.
 * POST-CONDITIONS
 * 		<none>
 *****************************************************************************/

void InitializeIntAr(int intAr[],
					 const int AR_SIZE)

{
	const int INITIALIZE_INT = -1;
	int index;

	for(index = 0; index < AR_SIZE; index++)
	{
		intAr[index] = INITIALIZE_INT;
	}//END FOR
}
