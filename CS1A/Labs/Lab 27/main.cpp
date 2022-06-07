/***************************************************************************
 * AUTHER     : JJ David & Negin Mashhadi
 * STUDENT ID : 1083135  & 1084104
 * LAB #27    : Multidimensional Arrays - Movie Ratings
 * CLASS      : CS1A
 * SECTION    : TTH: 1pm - 4:20pm
 * DUE DATE   : 12/05/17
 ***************************************************************************/

#include "myheader.h"

/*******************************************************************************
* 	Multidimensional Arrays - Movie Ratings
*------------------------------------------------------------------------------
* 	This program will average the stars for each of the top five movies in a
* 	2D array. The ratings are read in an input file. Each row represents the
* 	reviews of 5 movies by 1 reviewer.
* 	It will also calculate the average star rating for each reviewer and the
* 	average stars for each movie, as well as output the winning movie based on
* 	the averages. The highest and lowest ratings are also calculated.
* -----------------------------------------------------------------------------
* 	INPUT
* 		The following information will be input for program:
*
* 		ratingsAr : 2D array that is input from file
* 		row       : the row of numbers in the array
* 		col       : the column of numbers in the array
* 		avg       : the average of stars given by user and each movie
* 		max       : the maximum star rating
* 		min       : the minimum star rating
* 		movieNum  : the number of the movie with the highest rating
* 		largestAvg: the highest rating of the movies
*
* 	OUTPUT
*		- average of the stars given by user
* 	    - the average of the stars given by each movie
* 		- the maximum stars rating
* 		- the minimum stars rating
*******************************************************************************/

int main()
{
	int ratingsAr[TOTAL_USERS][TOTAL_MOVIES];// IN     - the 2D array
	int row;								 // CALC    - the row of numbers
											 //		      in the array
	int col;								 // CALC    - the column of numbers
											 //		      in the array
	double avg;								 // CALC/OUT- the average of stars
											 //			  given by user and each
											 // 		  movie
	int max;								 // CALC/OUT- The maximum star rate
	int min;								 // CALC/OUT- The minimum star rate
	int movieNum;							 // CALC/OUT- the number of the
											 //			  movie with the highest
											 // 		  rating
	double largestAvg;						 // CALC/OUT- the highest rating of
											 // 		  the movies

	largestAvg=0;
	col = 0;

	//OUTPUT - Prints header to console
	PrintHeader("Multidimensional Arrays - Movie Ratings", 26, 'L');

	cout << "**************************************\n"
		 << "* MOVIE STARS - RATING ANALYSIS TOOL *\n"
		 << "**************************************\n\n";

	/**************************************************************************
	 * INPUT - nothing is inputed by the user
	 * 		   The function ReadInput will get the data from input file
	 * 		   and will read it into a 2D array
	 **************************************************************************/
	 ReadInputToAr(ratingsAr);

	 /**************************************************************************
	 * PROCESSING - Will calculate the average of the stars given by user
	 * 				Will calculate the average of the stars given by each movie
	 * 				Will calculate the maximum stars rating
	 * 				Will calculate the minimum stars rating
	 **************************************************************************/

	 cout << "The average rating given by each reviewer is...\n";
	 for(row = 0; row < TOTAL_USERS; row++)
	 {
		avg = CalcRowAvg( row ,ratingsAr);
	/**************************************************************************
	 * OUTPUT - the average of the stars given by user
	 **************************************************************************/
		cout << "Reviewer #" << row+1 << " gave an average of " << avg
			 				<< " stars.\n";
	 }//END of For loop for average of movie reviews
	 cout << endl << endl;

	 cout << "The average stars for each movie is...\n";
		for(col = 0; col < TOTAL_MOVIES; col++)
		{
			avg = CalcColAvg( col ,ratingsAr);
	/**************************************************************************
	 * OUTPUT - the average of the stars given by each movie
	 **************************************************************************/
			cout << "Movie #" << col + 1 << " earned " << avg
				 << " stars!\n";
			if ( largestAvg < avg)
			{
				movieNum = col + 1;
				largestAvg = avg;
			} //END If
		} // END of For loop for average of movie stars
	 cout << endl;
	 /**************************************************************************
	 * OUTPUT - the movie with the largest average of stars given
	 * 			the highest star rating of movies
	 * 			the lowest star rating of movies
	 **************************************************************************/
	 cout << "The winner is (drum roll please)...\n";
	 cout << "Movie #" << movieNum << " with " << largestAvg << " stars!!";
	 cout << endl << endl << endl;
	 max = CalcMax(ratingsAr);
	 cout << "The highest rating given to any movie is " << max << " stars!\n";
	 min = CalcMin(ratingsAr);
	 cout << "The lowest rating given to any movie is " << min << " stars!\n";

	return 0;
}
