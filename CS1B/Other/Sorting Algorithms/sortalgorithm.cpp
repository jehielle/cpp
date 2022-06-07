// ----------------------------------------------------------------------------
// File name: sortalgorithm.cpp                                               -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 2/20/18                                                     -
// Date of Last Modification: 2/20/18                                         -
// ----------------------------------------------------------------------------
// Purpose: Sorting Algorithms                                                -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Create code using three different types of sorting methods.        -
// Step 2: Compare them.                                                      -
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// - SIZE              const int    200000                                    -
// - ASTERISKS         const int    70
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE                INITIAL VALUE                 -
// - ---------------   ----------               -------------                 -
// - list              int array                read from file                -
// - selCompare        unsigned long long int   0                             -
// - insCompare        unsigned long long int   0                             -
// - bubCompare        unsigned long long int   0                             -
// - selWrite          unsigned long long int   0                             -
// - insWrite          unsigned long long int   0                             -
// - bubWrite          unsigned long long int   0                             -
// - selTime                              int   0                             -
// - insTime                              int   0                             -
// - bubTime                              int   0                             -
// -                                                                          -
// ----------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <stdlib.h> // FOR SYSTEM COMMANDS
#include <fstream>  // FOR FILES
#include <limits>   // FOR CIN.IGNORE(NUMERIC_LIMITS....);
#include <time.h>	// FOR TIME

using namespace std;

//FUNCTION PROTOTYPES;
void selectionSort(int list[], unsigned long long int &c, unsigned long long &w);
void bubbleSort(int list[], unsigned long long int &c, unsigned long long int &w);
void insertionSort(int list[], unsigned long long int &c, unsigned long long int &w);
void fileIntoArray(int list[]);

//GLOBAL CONSTANTS
const int SIZE      = 200000;

//MAIN
int main()
{
	const int ASTERISKS = 70;

	int list[SIZE];  	   // array of floating pt values
	unsigned long long int selCompare;
	unsigned long long int insCompare;
	unsigned long long int bubCompare;
	unsigned long long int selWrite;
	unsigned long long int insWrite;
	unsigned long long int bubWrite;
	int selTime;
	int insTime;
	int bubTime;

	time_t start;
	time_t end;

	selCompare = 0;
	insCompare = 0;
	bubCompare = 0;
	selWrite   = 0;
	insWrite   = 0;
	bubWrite   = 0;
	selTime    = 0;
	insTime    = 0;
	bubTime    = 0;

	//CLEAR THE SCREEN
	system("CLS");

	cout << setfill('*') << setw(ASTERISKS) << "*";
	cout << setfill(' ') << endl;

	cout << "*";
	cout << setw(49) << "Sorting Algorithm Comparisons";
	cout << setw(20) << "*" << endl;

	cout << "*";
	cout << setw(50) << "Comparisons = (C), Writes = (W)";
	cout << setw(19) << "*" << endl;

	cout << "*";
	cout << setw(56) << "200,000-element UNSORTED ARRAY of integers";
	cout << setw(13) << "*" << endl;

	cout << "*";
	cout << setw(69) << "*";
	cout << endl;

	fileIntoArray(list);       // PUTS FILE NUMS INTO ARRAY

	/********************************************************************
	* SELECTION SORT
	********************************************************************/
	cout << "* ";
	cout << "Calling Selection Sort...";
	cout << setw(43) << "*" << endl;

	time(&start);
	selectionSort(list, selCompare, selWrite);
	time(&end);

	selTime = end - start;

	cout << "* ";
	cout << "Selection Sort - (C): " << setw(12) << selCompare;
	cout << "  (W): "                << setw(10) << selWrite;
	cout << "  TIME: "               << setw(4)  << selTime << " secs" << endl;

	cout << "*";
	cout << setw(69) << "*";
	cout << endl;

	/********************************************************************
	* INSERTION SORT
	********************************************************************/
	fileIntoArray(list);       // PUTS FILE NUMS INTO ARRAY

	cout << "* ";
	cout << "Calling Insertion Sort...";
	cout << setw(43) << "*" << endl;

	time(&start);
	insertionSort(list, insCompare, insWrite);
	time(&end);

	insTime = end - start;

	cout << "* ";
	cout << "Insertion Sort - (C): " << setw(12) << insCompare;
	cout << "  (W): "                << setw(10) << insWrite;
	cout << "  TIME: "               << setw(4)  << insTime << " secs" << endl;

	cout << "*";
	cout << setw(69) << "*";
	cout << endl;

	/********************************************************************
	* BUBBLE SORT
	********************************************************************/
	fileIntoArray(list);       // PUTS FILE NUMS INTO ARRAY

	cout << "* ";
	cout << "Calling Bubble Sort...";
	cout << setw(46) << "*" << endl;

	time(&start);
	bubbleSort(list, bubCompare, bubWrite);
	time(&end);

	bubTime = end - start;

	cout << "* "             << left << setw(14)<< "Bubble Sort" << right;
	cout << " - (C): "               << setw(12) << bubCompare;
	cout << "  (W): "                << setw(10) << bubWrite;
	cout << "  TIME: "               << setw(4)  << bubTime << " secs" << endl;

	cout << "*";
	cout << setw(69) << "*";
	cout << endl;

	cout << setfill('*') << setw(ASTERISKS) << "*";
	cout << setfill(' ') << endl << endl;

	system("PAUSE");

	return 0;
}

	/********************************************************************
	* FUNCTIONS - fileIntoArray, selectionSort, insertionSort, bubbleSort
	********************************************************************/

	/********************************************************************
	* FUNCTIONS - fileIntoArray - puts numbers in file into the array
	********************************************************************/
	void fileIntoArray(int list[])
	{
		ifstream inputFile;
		int index;

		inputFile.open("numbers2.dat");		// OPEN FILE

		for(index = 0; index < SIZE; index++)
		{
			inputFile >> list[index];
		}

		inputFile.close();
	}

	/********************************************************************
	* FUNCTIONS - selectionSort - uses selection sort to sort array
	********************************************************************/
	void selectionSort(int list[], unsigned long long int &c, unsigned long long &w)
	{
		int index;
		int smallestIndex;
		int location;
		int temp;

		c = 0;
		w = 0;

		for(index = 0; index < SIZE - 1; index++)
		{
			smallestIndex = index;

			for(location = index + 1; location < SIZE; location++)
			{
				c++;

				if(list[location] < list[smallestIndex])
				{
					smallestIndex = location;
					w++;
				}//END IF
			}// END FOR

		temp                = list[smallestIndex];
		w++;
		list[smallestIndex] = list[index];
		w++;
		list[index]         = temp;
		w++;

		}//END FOR

	}

	/********************************************************************
	* FUNCTIONS - insertionSort - uses insertion sort to sort array
	********************************************************************/
	void insertionSort(int list[], unsigned long long int &c, unsigned long long int &w)
	{
		int  firstOutOfOrder;
		int  temp;
		int  location;

		c = 0;
		w = 0;

		for(firstOutOfOrder = 1; firstOutOfOrder < SIZE; firstOutOfOrder++)
		{
			c++;

			if(list[firstOutOfOrder] < list[firstOutOfOrder - 1])
			{
				temp     = list[firstOutOfOrder];
				w++;
				location = firstOutOfOrder;

				do
				{
					c++;
					list[location] = list[location - 1];
					w++;
					location--;

				}while(location > 0 && list[location - 1] > temp);

				list[location] = temp;
				w++;
			}//END IF
		}//END FOR
	}

	/********************************************************************
	* FUNCTIONS - bubbleSort - uses bubble sort to sort array
	********************************************************************/
	void bubbleSort(int list[], unsigned long long int &c, unsigned long long int &w)
	{
		int iteration;
		int index;
		int temp;

		c = 0;
		w = 0;

		for(iteration = 1; iteration < SIZE; iteration++)
		{
			for(index = 0; index < SIZE; index++)
			{
				c++;

				if(list[index] > list[index + 1])
				{
					temp            = list[index];
					w++;
					list[index]     = list[index + 1];
					w++;
					list[index + 1] = temp;
					w++;
				}
			}
		}
	}
