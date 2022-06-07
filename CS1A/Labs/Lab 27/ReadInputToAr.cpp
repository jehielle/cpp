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
 * FUNCTION ReadInputToAr
 * __________________________________________________________________________
 * 	 This function receives inputs from the input file and puts it into the
 * 	 array.
 *   ==> returns nothing - This will put inputs into the array.
 * __________________________________________________________________________
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to
 * 		calling the function:
 * 			ratingsAr : the two dimensional array which contains the data
 * 						required
 * POST-CONDITIONS
 * 		This will put inputs into the array.
 *****************************************************************************/

void ReadInputToAr(int ratingsAr[][TOTAL_MOVIES]) // IN - the array that is
												  //	  read from the file
{
	ifstream fin;			//IN	- the input file
	int indexRow;			//CALC	- the LCV for the for loop to go through
							//		  the rows
	int indexCol;			//CALC	- the LCV for the for loop to go through
							//		  the columns

	fin.open("inputFile.txt");

	for(indexRow = 0; indexRow < TOTAL_USERS; indexRow++)
	{
		for( indexCol = 0; indexCol < TOTAL_MOVIES; indexCol++)
		{

		fin >> ratingsAr[indexRow][indexCol];

		}
	}

	fin.close();
}
