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
* FUNCTION - CalcAverage
* -------------------------------------------------------------------------
* This function receives the integer array and size.
* 	==> This will return the average of the integers.
* -------------------------------------------------------------------------
* PRE-CONDITIONS
 * 		This function will need the integer array and the array size.
 *
 * POST-CONDITIONS
 * 		==> This will return the average of the integers.
**************************************************************************/
double CalcAverage(const int INT_AR[], const int AR_SIZE)
{
	double average;
	int index;
	int sum;

	for(index = 0; index < AR_SIZE; index++)
	{
		sum = sum + INT_AR[index];
	}//END FOR(index = 0; index < AR_SIZE; index++)

	average = double(sum) / double(AR_SIZE);

	return average;
}
