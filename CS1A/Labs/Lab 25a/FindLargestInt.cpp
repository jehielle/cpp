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
* FUNCTION - FindLargestInt
* -------------------------------------------------------------------------
* This function receives the integer array, and array size to then find the
* 	  largest integer in the array.
* ==> This will return the position in the array of the largest integer.
*  -------------------------------------------------------------------------
*PRE-CONDITIONS
* 		This function receives the integer array and array size.
*
* POST-CONDITIONS
*	  ==> This will return the position in the array of the largest integer.
**************************************************************************/

int FindLargestInt(const int INT_AR[], const int AR_SIZE)
{
	int largestInt;
	int index;
	int position;

	position = 0;
	largestInt = INT_AR[0];

	for(index = 0; index < AR_SIZE; index++)
	{
		if(largestInt < INT_AR[index])
		{
			largestInt = INT_AR[index];
			position = index;
		}//END IF(largestInt < INT_AR[index])
	}//END FOR(index = 0; index < AR_SIZE; index++)


	return position;
}
