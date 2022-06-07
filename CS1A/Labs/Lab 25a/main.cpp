/******************************************************************************
 * AUTHOR        : JJ David & Justice Flenniken
 * STUDENT ID    : 1083135 & 1071976
 * ASSIGNMENT #9 : Functions
 * CLASS	     : CS1A
 * SECTION	     : TTh: 1pm
 * DUE DATE	     : 11/21/17
 *****************************************************************************/

#include "myheader.h"

/**************************************************************************
* LAB 25a: ARRAY TRAIN - SET #1
* -------------------------------------------------------------------------
* This program will use parallel arrays and functions in order to output the
* average of the ages, the first instance of an age, the number of instances of
* an age, searching for a person by name (input from user), finding the oldest
* person in the array, finding the youngest person in the array, and the sum of
* the array of ages.
* -------------------------------------------------------------------------
* INPUT:
*		searchInt  : The age the user wants to search for
*		searchName : The name the user wants to search for
*
* OUTPUT:
* 		averageAge    : Average age of the array
* 		instances     : Instances of the age entered by the user
* 		firstInstance : First instance of the name entered by the user
* 		oldest        : Oldest person in the array
* 		youngest      : Youngest person in the array
* 		sum           : Sum of the ages in the array
**************************************************************************/

int main()
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * USED FOR ARRAYS
	 * -------------------------------------------------------------------
	 * INT_AR : The set number of ages for the array
	 * NAME_AR: The set names for the array
	 * AR_SIZE: The size of the array
	 *********************************************************************/

	const int AR_SIZE             = 8;
	const string NAME_AR[AR_SIZE] = {"Zack", "Nikki", "Justice", "Gunner",
									"Billy", "Chris", "James Pelligo",
									"James Packes"};
	const int INT_AR[AR_SIZE]     = {20, 19, 18, 20, 19, 32, 21, 21};

	double averageAge; // CALC & OUT  - Average age of the array
	int searchInt;     // IN   & CALC - The age the user wants to search for
	int instances;     // CALC & OUT  - Instances of the age entered by the user
	int firstInstance; // CALC & OUT  - First instance of the name entered by
					   //               the user
	string searchName; // IN   & CALC - The name the user wants to search for
	int foundName;     // CALC        - The index of the name found in the list
	int oldest;        // CALC & OUT  - Oldest person in the array
	int youngest;      // CALC & OUT  - Youngest person in the array
	int sum;           // CALC & OUT  - Sum of the ages in the array
	bool invalidAge;   // CALC        - Invalid Age



	// OUTPUT - Class heading to the console
	PrintHeader("Array Train - Set #1", 25, 'L');

/******************************************************************************
 * INPUT - user inputs the age and name they want to search for.
 *****************************************************************************/
	do
	{
		cout << "What age do you want to search for? ";
		cin >> searchInt;
		cin.ignore(1000, '\n');

		invalidAge = (searchInt < 0);

		if(invalidAge)
		{
			cout << "Please enter a valid age.\n";
		}//END IF
	}while(invalidAge);

	//searchName
	cout << "Who do you want to search for? ";
	getline(cin, searchName);

	cout << endl;

/******************************************************************************
* PROCESSING - calculates the average of the ages, the first instance of an age,
* the number of instances of an age, searching for a person by name (input from
* user), finding the oldest person in the array, finding the youngest person in
* the array, and the sum of the array of ages.
 *****************************************************************************/
	// PROCESSING - calculates average age
	averageAge = CalcAverage(INT_AR, AR_SIZE);

	// PROCESSING - finds the first instance of the age inputed
	firstInstance = FirstIntInstance(INT_AR, AR_SIZE, searchInt);

	// PROCESSING - finds the amount of instances of the age inputed
	instances = FindIntInstances(INT_AR, AR_SIZE, searchInt);

	// PROCESSING - finds the name inputed
	foundName = SearchName(NAME_AR, AR_SIZE, searchName);

	// PROCESSING - finds the oldest person in the list
	oldest = FindLargestInt(INT_AR, AR_SIZE);

	// PROCESSING - finds the youngest person in the list
	youngest = FindSmallestInt(INT_AR, AR_SIZE);

	// PROCESSING - calculates the sum of the ages in the list
	sum = IntSum(INT_AR, AR_SIZE);


/******************************************************************************
 * OUTPUT - outputs the data processed above.
 *****************************************************************************/

	cout << averageAge << " is the average age.\n";

	if(firstInstance != AR_SIZE)
	{
		cout << NAME_AR[firstInstance] << " is the first instance of the age "
			                           << searchInt << ".\n";
	}
	else
	{
		cout << "There are no instances of the age " << searchInt << ".\n";
	}//END IF THEN ELSE(firstInstance != AR_SIZE)

	if(instances != 0)
	{
	cout << "There are " << instances << " instances of the age "
			             << searchInt << ".\n";
	}//END IF(instances != 0);

	if(foundName != AR_SIZE)
	{
		cout << NAME_AR[foundName] << " is present on this list.\n";
	}
	else
	{
		cout << searchName << " is not present on this list.\n";
	}//END IF THEN ELSE(foundName != AR_SIZE)

	cout << NAME_AR[oldest] << " is the oldest.\n";
	cout << NAME_AR[youngest] << " is the youngest.\n";
	cout << sum << " is the sum of all the ages.";

	return 0;
}
