/******************************************************************************
 * AUTHOR        : JJ David, Kierstyn Just
 * STUDENT ID    : 1083135, 277791
 * LAB #24       : Introduction to Arrays
 * CLASS	     : CS1A
 * SECTION	     : TTh: 1pm
 * DUE DATE	     : 11/16/17
 *****************************************************************************/
#include "myheader.h"

int main()
{

	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * AR_SIZE - Size for number of names stored in nameAR
	 **************************************************************************/
	const int AR_SIZE = 10;

	//VARIABLES
	int    index;			// CALC - Index number of names in nameAR
	int    instances;		// CALC & OUT - Increments/Outputs number of times
							//  search name is found in nameAR
	string nameAr[AR_SIZE]; // IN - declares an array of 10 names
	string searchName;		// IN - Name the user wishes to search in nameAR

	//OUTPUT - Class Header
	PrintHeader("Introduction to Arrays", 24, 'L');

	//INPUT - Prompts user for 10 names & stores in nameAR
	for(index = 0; index < AR_SIZE; index++)
	{

		cout << "Enter name #" << index + 1 << ": ";
		cin  >> nameAr[index];
		cin.ignore(1000, '\n');

	}// end for(index = 0; index < AR_SIZE; index++)

	///INPUT - Prompts user for name they wish to search
	cout << endl;
	cout << "Who do you want to search for (enter done to exit)? ";
	getline(cin, searchName);

	//Increments index, only when true
	index = 0;
	if(nameAr[index] == searchName)
	{
		index++;
	}

	//PROCESSING - Checks index of nameAR for searchName & increments each
	//             time search is true
	while(searchName != "done")
	{
		//Increments instances, when nameAR == searchName
		instances = 0;
		for(index = 0; index < AR_SIZE; index++)
		{
			if(nameAr[index] == searchName)
			{
				instances++;
			}//end if
		}// end for(index = 0; index < AR_SIZE; index++)

		//OUTPUT - Whether there is 1 instance or multiple of searchName
		if(instances == 1)
		{
			cout << "There is one instance of the name " << searchName << ".";
			cout << endl << endl;
		}
		else if(instances == 0)
		{
			cout << searchName << "\'s name does not exist in this list.";
			cout << endl << endl;
		}
		else
		{
			cout << "There are " << instances << " instances of the name "
                 << searchName << ".";
					cout << endl << endl;
		}


		//INPUT - Prompts user for 10 names
		cout << "Who do you want to search for (enter done to exit)? ";
		getline(cin, searchName);

		index = 0;

		if(nameAr[index] == searchName)
		{
			index++;
		}

	}// end while

	//OUTPUT - Thanks man
	cout << endl;
	cout << "Thank you for using my program.";

	return 0;
}
