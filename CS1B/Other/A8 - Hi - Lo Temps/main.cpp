// ----------------------------------------------------------------------------
// File name: mainmenu.cpp                                                    -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 2/8/18                                                      -
// Date of Last Modification: 2/8/18                                          -
// ----------------------------------------------------------------------------
// Purpose: Hi/Low Temps                                                      -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Create the functions.                                              -
// Step 2: Read in the data from the user and put into array.                 -
// Step 3: Calculate the data given by the user.                              -
// Step 4: Tell the user the results of said calculated data.                 -
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// - MONTHS            const int    12                                        -
// - TEMPS             const int    2                                         -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// - avgHigh           double       0.0                                       -
// - avgLow            double       0.0                                       -
// - indexHigh         int          0                                         -
// - indexLow          int          0                                         -
// ----------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

//GLOBAL CONSTANTS
const int MONTHS = 12;
const int TEMPS  = 2;

//FUNCTION PROTOTYPES
void   getData(double tempAr[][TEMPS],
			   string monthsAr[MONTHS]);
double averageHigh(double tempAr[][TEMPS]);
double averageLow(double tempAr[][TEMPS]);
int    indexHighTemp(double tempAr[][TEMPS]);
int    indexLowTemp(double tempAr[][TEMPS]);
void   printOutput(double tempAr[][TEMPS],
				   string monthsAr[MONTHS],
				   double avgHigh,
				   double avgLow,
				   int    indexHigh,
				   int    indexLow);

int main()
{
	string monthsAr[MONTHS] = {"January", "February", "March", "April", "May",
							 "June", "July", "August", "September", "October",
							 "November", "December"};
	double tempAr[MONTHS][TEMPS];

	double avgHigh;
	double avgLow;
	int    indexHigh;
	int    indexLow;

	cout << "*** WELCOME! ***\n"
		 << "This program is designed to get the highest and lowest temperatures"
		 	" and calculate the average high, average low, and the highest and "
		 	"lowest temperatures for the year.\n\n";

/******************************************************************************
 * INPUT      - getData - gets high/low temperatures from user
 *****************************************************************************/
	getData(tempAr, monthsAr);

/******************************************************************************
 * PROCESSING - averageHigh   - calc & avg the highest temp of the year
 * 			  - averageLow    - calc & avg the lowest temp of the year
 * 			  - indexHighTemp - returns index of highest temp in the array
 * 			  - indexLowTemp  - returns index of lowest temp in the array
 *****************************************************************************/
	avgHigh   = averageHigh(tempAr);
	avgLow    = averageLow(tempAr);
	indexHigh =	indexHighTemp(tempAr);
	indexLow  = indexLowTemp(tempAr);

/******************************************************************************
 * OUTPUT     - printOutput   - outputs the above information
 *****************************************************************************/
	printOutput(tempAr, monthsAr, avgHigh, avgLow, indexHigh, indexLow);

	return 0;
}




/******************************************************************************
 * FUNCTIONS - getData
 * 			   averageHigh
 * 			   averageLow
 * 			   indexHighTemp
 * 			   indexLowTemp
 *****************************************************************************/
/******************************************************************************
 * FUNCTION - getData - gets high/low temperatures from user
 *****************************************************************************/
void   getData(double tempAr[][TEMPS],
			   string monthsAr[MONTHS])
{
	int    monthIndex;	// the indexes of the 12 months
	double highTemp;	// the higher temperature
	double lowTemp;		// the lower temperature

	for(monthIndex = 0; monthIndex < MONTHS; monthIndex++)
	{
		cout << monthsAr[monthIndex] << ":\n\n";

			cout << "-- Enter High: ";
			cin  >> highTemp;
			cin.ignore(1000, '\n');

			tempAr[monthIndex][0] = highTemp;

			cout << "-- Enter Low: ";
			cin  >> lowTemp;
			cin.ignore(1000, '\n');

			tempAr[monthIndex][1] = lowTemp;

			cout << endl;
	}//END FOR
}

/******************************************************************************
 * FUNCTION - averageHigh - calc & avg the highest temp of the year
 *****************************************************************************/
double averageHigh(double tempAr[][TEMPS])
{
	int    count;
	double totalHighTemp;
	double avgHigh;

	totalHighTemp = 0;
	avgHigh       = 0;

	for(count = 0; count < MONTHS; count++)
	{
		totalHighTemp += tempAr[count][0];
	}

	avgHigh = totalHighTemp / MONTHS;

	return avgHigh;
}

/******************************************************************************
 * FUNCTION - averageLow - calc & avg the lowest temp of the year
 *****************************************************************************/
double averageLow(double tempAr[][TEMPS])
{
	int    count;
	double totalLowTemp;
	double avgLow;

	totalLowTemp = 0;
	avgLow       = 0;

	for(count = 0; count < MONTHS; count++)
	{
		totalLowTemp += tempAr[count][1];
	}

	avgLow = totalLowTemp / MONTHS;

	return avgLow;
}

/******************************************************************************
 * FUNCTION - indexHighTemp - returns index of highest temp in the array
 *****************************************************************************/
int    indexHighTemp(double tempAr[][TEMPS])
{
	int indexHighTemp;
	int searchHighTemp;
	int count;

	indexHighTemp = 0;
	searchHighTemp = tempAr[0][0];

	for(count = 0; count < MONTHS; count++)
	{
		if(searchHighTemp < tempAr[count][0])
		{
			indexHighTemp  = count;
			searchHighTemp = tempAr[count][0];
		}
	}

	return indexHighTemp;
}

/******************************************************************************
 * FUNCTION - indexLowTemp - returns index of lowest temp in the array
 *****************************************************************************/
int    indexLowTemp(double tempAr[][TEMPS])
{
	int indexLowTemp;
	int searchLowTemp;
	int count;

	indexLowTemp = 0;
	searchLowTemp = tempAr[0][0];

	for(count = 0; count < MONTHS; count++)
	{
		if(searchLowTemp > tempAr[count][0])
		{
			indexLowTemp  = count;
			searchLowTemp = tempAr[count][0];
		}
	}

	return indexLowTemp;
}

/******************************************************************************
 * FUNCTION - printOutput - outputs the above information
 *****************************************************************************/
void   printOutput(double tempAr[][TEMPS],
				   string monthsAr[MONTHS],
				   double avgHigh,
				   double avgLow,
				   int    indexHigh,
				   int    indexLow)
{
	cout << setprecision(2) << fixed;

	cout << "The final results are the following:\n\n";
	cout << "The average of the high temperatures is: " << avgHigh << "\370";
	cout << endl;
	cout << "The average of the low temperatures is: "  << avgLow  << "\370";
	cout << endl;
	cout << "The highest temperature of the year is: "  << tempAr[indexHigh][0];
	cout << "\370 Month: " << monthsAr[indexHigh]       << endl;
	cout << "The lowest temperature of the year is: "   << tempAr[indexLow][1];
	cout << "\370 Month: " << monthsAr[indexLow];
}
