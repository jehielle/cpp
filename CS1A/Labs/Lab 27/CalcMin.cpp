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
 * FUNCTION CalcMin
 * __________________________________________________________________________
 * 	 This function receives the ratings array.
 *   ==> returns the smallest integer.
 * __________________________________________________________________________
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to
 * 		calling the function:
 * 			ratingsAr : the two dimensional array which contains the data
 * 						required
 * POST-CONDITIONS
 * 		==> returns the smallest integer.
 *****************************************************************************/

int CalcMin(int ratingsAr[][TOTAL_MOVIES])    // IN - the column of numbers
{

	int smallestInt;			// CALC - the smallest integer in the array
	int fRow; 					// CALC - the row of numbers in the array
	int fCol; 					// CALC - the column of numbers in the array

	smallestInt = ratingsAr[0][0];

	for( fRow = 0; fRow < TOTAL_USERS; fRow++)
	{
		for( fCol = 0; fCol < TOTAL_MOVIES; fCol++)
		{
			if (smallestInt > ratingsAr[fRow][fCol])
			{
				smallestInt = ratingsAr[fRow][fCol];
			} //END IF
		}
	}

	return smallestInt;
}
