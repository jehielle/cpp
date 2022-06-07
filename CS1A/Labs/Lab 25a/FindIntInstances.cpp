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
* FUNCTION - FindIntInstances
* -------------------------------------------------------------------------
* This function receives the integer array, array size, and searchInt to then
* 	  find the first instance of the user's inputed integer.
* ==> This will return the index of the first instance of an integer.
* -------------------------------------------------------------------------
*PRE-CONDITIONS
* 		This function receives the integer array, array size, and searchInt.
*
* POST-CONDITIONS
*	  ==> This will return the index of the first instance of an integer.
**************************************************************************/

int FindIntInstances(const int INT_AR[], const int AR_SIZE, int searchInt)
{
	int index;
	int instances;

	instances = 0;

	for(index = 0; index < AR_SIZE; index++)
	{
			if(INT_AR[index] == searchInt)
			{
				instances++;
			}
	}//END FOR(index = 0; index < AR_SIZE; index++)

	return instances;
}
