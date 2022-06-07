/******************************************************************************
 * AUTHOR        : JJ David & Justice Flenniken
 * STUDENT ID    : 1083135 & 1071976
 * ASSIGNMENT #9 : Functions
 * CLASS	     : CS1A
 * SECTION	     : TTh: 1pm
 * DUE DATE	     : 11/21/17
 *****************************************************************************/

#include "myheader.h"

/**************************************************************************
* FUNCTION - IntSum
* -------------------------------------------------------------------------
* This function receives the integer array and array size to then sum the array.
* ==> This will return the sum of all of the values in INT_AR.
*  -------------------------------------------------------------------------
*PRE-CONDITIONS
* 		This function receives the integer array and array size.
*
* POST-CONDITIONS
*	  ==> This will return the sum of all of the values in INT_AR.
**************************************************************************/

int IntSum(const int INT_AR[], const int AR_SIZE)
{
	int index;
	int sum;

	sum = 0;

	for(index = 0; index < AR_SIZE; index++)
		{
			sum = sum + INT_AR[index];
		}//END FOR(index = 0; index < AR_SIZE; index++)

	return sum;
}
