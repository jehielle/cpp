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
 * FUNCTION InitializeBothAr
 * ____________________________________________________________________________
 * This function initializes both arrays in one function
 * ==> returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		Needs string array and int array.
 * POST-CONDITIONS
 * 		<none>
 *****************************************************************************/

void InitializeBothAr(int intAr[],
					  string stringAr[],
					  const int AR_SIZE)
{
	 InitializeIntAr(intAr, AR_SIZE);

	 InitializeStrAr(stringAr, AR_SIZE);
}
