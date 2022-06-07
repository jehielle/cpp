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
* FUNCTION - FirstIntInstance
* -------------------------------------------------------------------------
* 	This function receives the integer array, array size, and searchAge to then
* 	  find the number of times the user inputed integer appears.
* 	 ==> This will return the first instance of an age.
* -----------------------------------------------------------------------------
*PRE-CONDITIONS
 * 		This function receives the integer array, array size, and searchInt.
 *
 * POST-CONDITIONS
 * 	   ==> This will return the first instance of an age.
**************************************************************************/

int FirstIntInstance(const int INT_AR[],
					 const int AR_SIZE,
					 int searchInt)
{
	int index;
	bool found;

	index = 0;
	found = false;

	while(index < AR_SIZE && !found)
	{
		if(INT_AR[index] == searchInt)
		{
			found = true;
		}
		else
		{
			index++;
		}

	}

	return index;
}
