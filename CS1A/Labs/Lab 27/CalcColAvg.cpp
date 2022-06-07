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
 * FUNCTION CalcColAvg
 * __________________________________________________________________________
 * 	 This function receives the column and the ratings array. It will calculate
 * 	 the average of the numbers in the column.
 *   ==> returns the average of the column.
 * __________________________________________________________________________
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to
 * 		calling the function:
 * 			ratingsAr : the two dimensional array which contains the data
 * 						required
 * 			fCol       : the numbers in a column in the input file
 *
 * POST-CONDITIONS
 * 		==> returns the average of the column.
 *****************************************************************************/

double CalcColAvg(int fCol, 					   // IN - the column of numbers
				  int ratingsAr[][TOTAL_MOVIES])   // IN - The 2D array
{
	int sum;		// CALC - will sum all the numbers in a column
	double avg;		// CALC - will average all the numbers in a column

		sum = 0;
		for(int row = 0; row < TOTAL_USERS; row++)
		{
			sum += ratingsAr[row][fCol];
		}
		cout << setprecision(1) << fixed;
		avg = sum/ double(TOTAL_USERS);

	return avg;

}
