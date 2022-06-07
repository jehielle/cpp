/***************************************************************************
 * AUTHER     : JJ David & Negin Mashhadi
 * STUDENT ID : 1083135  & 1084104
 * LAB #27    : Multidimensional Arrays - Movie Ratings
 * CLASS      : CS1A
 * SECTION    : TTH: 1pm - 4:20pm
 * DUE DATE   : 12/05/17
 ***************************************************************************/

#include "myheader.h"

/******************************************************************************
 * FUNCTION CalcMax
 * __________________________________________________________________________
 * 	 This function receives the ratings array.
 *   ==> returns the largest integer.
 * __________________________________________________________________________
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to
 * 		calling the function:
 * 			ratingsAr : the two dimensional array which contains the data
 * 						required
 * POST-CONDITIONS
 * 		==> returns the largest integer.
 *****************************************************************************/

int CalcMax(int ratingsAr[][TOTAL_MOVIES])	// IN - The 2D array
{
	int largestInt;		// CALC - the largest integer in the array
	int fRow;			// CALC - the row of numbers in the array
	int fCol;			// CALC - the column of numbers in the array

	largestInt = 0;

	for( fRow = 0; fRow < TOTAL_USERS; fRow++)
	{
		for( fCol = 0; fCol < TOTAL_MOVIES; fCol++)
		{
			if (largestInt < ratingsAr[fRow][fCol])
			{
				largestInt = ratingsAr[fRow][fCol];
			} //END IF
		}
	}

	return largestInt;
}
