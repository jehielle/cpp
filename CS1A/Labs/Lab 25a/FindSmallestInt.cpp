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
* FUNCTION - FindSmallestInt
* -------------------------------------------------------------------------
* This function receives the integer array, and array size to then find the
* 	  smallest integer in the array.
* ==> This will return the position in the array of the smallest integer.
* -------------------------------------------------------------------------
*PRE-CONDITIONS
* 		This function receives the integer array and array size.
*
* POST-CONDITIONS
*	  ==> This will return the position in the array of the smallest integer.
**************************************************************************/

int FindSmallestInt(const int INT_AR[], const int AR_SIZE)
{
	int smallestInt;
	int index;
	int position;

	position = 0;
	smallestInt = INT_AR[0];

	for(index = 0; index < AR_SIZE; index++)
	{
		if(smallestInt > INT_AR[index])
		{
			smallestInt = INT_AR[index];
			position = index;
		}//END IF(smallestInt > INT_AR[index])
	}//END FOR(index = 0; index < AR_SIZE; index++)


	return position;
}
