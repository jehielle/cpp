// ----------------------------------------------------------------------------
// File name: linearbinary.cpp                                                -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 2/19/18                                                     -
// Date of Last Modification: 2/20/18                                         -
// ----------------------------------------------------------------------------
// Purpose: Linear/Binary Search                                              -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Create the menu for the user to choose from.                       -
// Step 2: Depending on which number the user entered, do that.               -
// Step 3: If they choose a linear or binary search, open/use/close file.     -
// Step 4: Keep showing the user the menu until they select "Quit".           -
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// - SIZE              int          200000                                    -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// - currentTarget     int          -1                                        -
// - menuChoice        int          0                                         -
// - invalid           bool         menuChoice < 1 || menuChoice > 4          -
// - linCompare        int          0                                         -
// - binCompare        int          0                                         -
// - sorted            bool         true                                      -
// - fin               ifstream     none                                      -
// -                                                                          -
// ----------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <stdlib.h> // FOR SYSTEM COMMANDS
#include <fstream>  // FOR FILES
#include <limits>   // FOR CIN.IGNORE(NUMERIC_LIMITS....);

using namespace std;

//FUNCTION PROTOTYPES;
void binary(double list[], int currentTarget, int& binCompare);
void linear(double list[], int currentTarget, int& linCompare);
void selectionSort(double list[]);
void fileIntoArray(double list[], ifstream& inputFile);

//GLOBAL CONSTANTS
const int SIZE = 200000;

//MAIN
int main()
{

	int  currentTarget;    // current target
	int  menuChoice;       // number inputed by user to choose from menu
	bool invalid;          // the cases in which menuChoice would be invalid
	int  linCompare;       // number of comparisons for linear search
	int  binCompare;       // number of comparisons for binary search
	bool sorted;		   // whether the array is sorted or not
	
	ifstream fin;          // allows for READING FROM a file
	
	double list[SIZE];	   // array of floating pt values

	currentTarget    = -1; // default target
	linCompare       = 0;  // default: 0 comparisons
	binCompare       = 0;  // default: 0 comparisons
	menuChoice       = 0;  // initializing menuChoice to 0 so the loop works
	sorted           = true;
	
	/********************************************************************
	* SEARCH ALGORITHM COMPARISONS MENU
	********************************************************************/
	// CLEAR THE SCREEN
	system("CLS");
	
	do
	{
		cout << setfill('*') << setw(47) << "*";
		cout << setfill(' ') << endl;
		
		cout << left;
		cout << "* ";			 // LEFT  COLUMN *
		cout << right;
		cout << setw(37) << "Search Algorithm Comparisons";
		cout << setw(8) << "*"; // RIGHT COLUMN *
		cout << endl;
		
		cout << left;
		cout << "* ";			 // LEFT  COLUMN *
		cout << "CURRENT TARGET: " << currentTarget;
		cout << endl << endl;	 // NO * BC OF UNSPECIFIED DIGITS IN currentTarget
		
		cout << "*";			 // LEFT COLUMN
		cout << right;
		cout << setw(31) << "Search Metrics";
		cout << setw(15) << "*"; // RIGHT COLUMN
		cout << endl;
		
		cout << "* ";
		cout << "Linear: ";
		cout << setw(5) << " ";
		cout << linCompare   << " comparisons";
		cout << endl;
		
		cout << "* ";
		cout << "Binary: ";
		cout << setw(5) << " ";
		cout << binCompare   << " comparisons";
		cout << endl << endl;
		
		cout << "* ";			// LEFT COLUMN
		cout << "<1> Enter Integer to Search";
		cout << setw(18) << "*";// RIGHT COLUMN
		cout << endl;
		
		cout << "* ";			// LEFT COLUMN
		cout << "<2> Linear Search";
		cout << setw(28) << "*";// RIGHT COLUMN
		cout << endl;
		
		cout << "* ";			// LEFT COLUMN
		cout << "<3> Binary Search";
		cout << setw(28) << "*";// RIGHT COLUMN
		cout << endl;


		cout << "* ";			// LEFT COLUMN
		cout << "<4> Quit";
		cout << setw(37) << "*";// RIGHT COLUMN
		cout << endl;
		
		cout << setfill('*') << setw(47) << "*";
		cout << setfill(' ');
		cout << endl;
		
		cout << "* Choose from the menu: ";
		cin  >> menuChoice;		// INPUT FROM USER
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		/********************************************************************
		* PROCESSING - necessary calculations
		********************************************************************/
		
		// PROCESSING - CHECKS FOR INVALID INPUT
		do
		{
			invalid = menuChoice < 1 || menuChoice > 4;
			
			if(invalid)
			{
				cout << endl;
				cout << "*** INVALID INPUT - PLEASE CHOOSE A NUMBER 1-4 ***";
				cout << endl << endl;
				
				cout << "* Choose from the menu: ";
				cin  >> menuChoice;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				cout << endl << endl;
			}
		}while(invalid);

	fin.open("numbers2.dat");		// OPEN FILE
	
	fileIntoArray(list, fin); // PUTS FILE NUMS INTO ARRAY
	
		// PROCESSING - if menuChoice is valid, picks the option the user entered
		switch(menuChoice)
		{
			case 1: cout << "* Please enter a new value to search: ";	// ENTER NEW INT TO SEARCH
					cin  >> currentTarget;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << endl;
					
					// CLEAR THE SCREEN
					system("CLS");
			break;
			
			case 2: cout << "* Calling linear/sequential search...\n";	// LINEAR
					linear(list, currentTarget, linCompare);
					
					// PAUSE
					system("PAUSE");
					
					// CLEAR THE SCREEN
					system("cls");
			break;
			
			case 3: if(!sorted)
					{
						cout << "Binary search requires the array to be sorted, please wait for array to sort." << endl;
						cout << "... Calling selectionSort ..." << endl;
						selectionSort(list);
						sorted = true;
					}
					else
					{
						binary(list, currentTarget, binCompare);	// BINARY
					}
					
					// PAUSE
					system("PAUSE");
					
					// CLEAR THE SCREEN
					system("CLS");
			break;

			case 4: system("CLS");										// QUIT
			break;
		}

	}while(menuChoice != 4);

	fin.close();				// CLOSE FILE
	
	return 0;
}

	/********************************************************************
	* FUNCTIONS - fileIntoArray, binary, linear, selection sort
	********************************************************************/
	
	/********************************************************************
	* FUNCTIONS - fileIntoArray - puts numbers in file into the array
	********************************************************************/
	void fileIntoArray(double list[], ifstream& inputFile)
	{
		int index;
		
		for(index = 0; index < SIZE; index++)
		{
			inputFile >> list[index];
			inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
	}
	
	/********************************************************************
	* FUNCTIONS - binary - calculates # of comparisons for binary search
	********************************************************************/
	void binary(double list[], int currentTarget, int& binCompare)
	{
		int  first;
		int  last;
		int  mid;
		bool found;
		
		binCompare  = 0;
		first       = 0;		// FIRST IN INDEX
		last        = SIZE - 1;	// LAST IN INDEX
		found       = false;
		
		while(first <= last && !found)
		{
			binCompare++;

			mid = (first + last) / 2;

			if(list[mid] == currentTarget)
			{
				found = true;
			}
			else if(list[mid] > currentTarget)
			{
				last = mid - 1;
			}
			else
			{
				first = mid + 1;
			}
		}

		cout << "* Calling binary search..." << endl;
		cout << "The binary search made "    << binCompare      << " comparisons." << endl;
		
		if(found ==true)
		{
			cout << "Target: " << currentTarget  << " is element #" << mid << " in the array.";
		}
		else
		{
			cout << "Target was not found.";
		}
		
		cout << endl;
	}
	
	/********************************************************************
	* FUNCTIONS - linear - calculates # of comparisons for linear search
	********************************************************************/
	void linear(double list[], int currentTarget, int& linCompare)
	{
		int  index;
		bool found;

		index       = 0;
		linCompare  = 0;
		found       = false;

		while(index < SIZE && !found)
		{
			if(list[index] == currentTarget)
			{
				found = true;
			}
			else
			{
				index++;
			}//END IF THEN ELSE

			linCompare++;

		}//END WHILE
		
		cout << "The linear search made "   << linCompare << " comparisons." << endl;
		
		if(found == true)
		{
			cout << "Target: " << currentTarget << " is element #" << index << " in the array.";
		}
		else
		{
			cout << "Target was not found.";
		}
		
		cout << endl;
		
	}
	
	/********************************************************************
	* FUNCTIONS - selectionSort - uses selection sort to sort array
	********************************************************************/
	void selectionSort(double list[])
	{
		int index;
		int smallestIndex;
		int location;
		int temp;

		for(index = 0; index < SIZE; index++)
		{
			smallestIndex = index;

			for(location = index + 1; location < SIZE; location++)
			{
				if(list[location] < list[smallestIndex])
				{
					smallestIndex = location;
				}//END IF
			}// END FOR

		temp = list[smallestIndex];
		list[smallestIndex] = list[index];
		list[index] = temp;

		}//END FOR

	}
	
	
	
