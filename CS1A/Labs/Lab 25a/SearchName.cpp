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
* FUNCTION - SearchName
* -------------------------------------------------------------------------
* This function receives the integer array, array size, and searchName to
* 	  determine if a name is present in the array.
* ==> This will return the index of the found name.
* -------------------------------------------------------------------------
*	PRE-CONDITIONS
*		This function receives the name array, array size, and searchName.
*
*	POST-CONDITIONS
* ==> This will return the index of the found name.
**************************************************************************/

int SearchName(const string NAME_AR[], const int AR_SIZE, string searchName)
{
	int index;
	bool found;

	index = 0;
	found = false;

	while(index < AR_SIZE && !found)
	{
		if(NAME_AR[index] == searchName)
		{
			found = true;
		}
		else
		{
			index++;
		}//END IF THEN ELSE(NAME_AR[index] == searchName)
	}//END WHILE(index < AR_SIZE && !found)

	return index;
}
