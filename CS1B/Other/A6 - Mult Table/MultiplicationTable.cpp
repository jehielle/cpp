// ----------------------------------------------------------------------------
// File name: MultiplicationTable.cpp                                         -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 2/1/18                                                      -
// Date of Last Modification: 2/6/18                                          -
// ----------------------------------------------------------------------------
// Purpose: 2D Arrays                                                         -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Create a 2D array.                                                 -
// Step 2: Let the user input 4 numbers for each row & check for valid input. -
// Step 3: Calculate the highest and lowest values per row.                   -
// Step 4: Multiply the values per row and put into the 5th column.           -
// Step 5: Output everything.                                                 -
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// - ROW			   integer      5                                         -
// - COL               integer      5                                         -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// - rowIndex          integer      0                                         -
// - colIndex          integer      0                                         -
// ----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

//GLOBAL CONSTANTS
const int ROW = 5;
const int COL = 5;

int main()
{
	int multTable[ROW][COL];// the 2D array
	int rowIndex;			// index number within a row
	int colIndex;			// index number within a column
	int max[ROW];			// the largest int
	int min[ROW];			// the smallest int

	colIndex  = 0;
	rowIndex  = 0;
	max[ROW]  = {0};
	min[ROW]  = {0};
	
	cout << "*** WELCOME TO THE MULTIPLICATION TABLE! ***\n";
	
/******************************************************************************
 * INPUT   - user input into 2D array
 *****************************************************************************/
	for(rowIndex = 0; rowIndex < ROW; rowIndex++)
	{
		cout << endl;
		cout << "Please enter 4 integers for row " << rowIndex << ".";
		cout << endl << endl;
		
		multTable[rowIndex][COL - 1] = 1;

		for(colIndex = 0; colIndex < COL - 1; colIndex++)
		{
			cout << "Enter integer for column #" << colIndex << ": ";
			cin  >> multTable[rowIndex][colIndex];
			cin.ignore(1000, '\n');

			multTable[rowIndex][COL - 1] *= multTable[rowIndex][colIndex];
		}

		cout << endl;
	}
	
/******************************************************************************
 * PROCESSING - calculates largest and smallest ints for each row
 *****************************************************************************/
	for(rowIndex = 0; rowIndex < ROW; rowIndex++ )
	{
		min[rowIndex] = multTable[rowIndex][0];
		max[rowIndex] = multTable[rowIndex][0];

		for(colIndex = 0; colIndex < COL - 1; colIndex++ )
		{
			if(min[rowIndex] > multTable[rowIndex][colIndex])
			{
			min[rowIndex] = multTable[rowIndex][colIndex];
			}

			if(max[rowIndex] < multTable[rowIndex][colIndex])
			{
				max[rowIndex] = multTable[rowIndex][colIndex];
			}
		}//END FOR
	}//END FOR
	
/******************************************************************************
 * OUTPUT     - outputs the chart
 *****************************************************************************/
	cout << "    0   1   2   3   * "    << endl;
	cout << "   ----------------------" << endl;

	for (rowIndex = 0; rowIndex < ROW; rowIndex++)
	{
		cout << rowIndex;

		for (colIndex = 0; colIndex < COL; colIndex++)
		{
			cout << setw(2) << "|" <<
					setw(2) << multTable[rowIndex][colIndex];
		}

		cout << "		"
			 << "Highest Value: " << max[rowIndex] << "	"
			 << "Lowest Value: "  << min[rowIndex] << endl;
	}

	return 0;
}
