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
 * FUNCTION CalcRowAvg
 * __________________________________________________________________________
 * 	 This function receives the row and the ratings array. It will calculate
 * 	 the average of the numbers in the row.
 *   ==> returns the average of the row.
 * __________________________________________________________________________
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to
 * 		calling the function:
 * 			ratingsAr : the two dimensional array which contains the data
 * 						required
 * 			fRow       : the numbers in a row in the input file
 *
 * POST-CONDITIONS
 * 		==> returns the average of the row.
 *****************************************************************************/

double CalcRowAvg(int fRow,							// IN - the row of numbers
				  int ratingsAr[][TOTAL_MOVIES])	// IN - The 2D array
{
	int sum;		// CALC - The sum of all the numbers in a row
	double avg;		// CALC - The average of all the numbers in a row


	sum = 0;
		for(int col = 0; col < TOTAL_MOVIES; col++)
		{
			sum += ratingsAr[fRow][col];
		}
		cout << setprecision(1) << fixed;
		avg = sum/ double(TOTAL_MOVIES);

		return avg;

}
