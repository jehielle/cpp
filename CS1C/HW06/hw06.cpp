/**************************************************************************
 *  AUTHOR     : Jehielle David
 *  HW #4      : recursion
 *  CLASS      : CS 1C
 *  SECTION    : Tu,Th 12:30-2:50pm
 *  DUE DATE   : 9-20-18
 **************************************************************************/

#include "hw06.h"

int main()
{
	char endProgram;
	int fIndex;  //first index
	int lIndex;  //last index
	int length;

	length = 27; //26 elements + 27 for null terminator
	char alphabet[length] = "abcdefghijklmnopqrstuvwxyz";

	cout << "*******************************************" << endl;
	cout << "      FUNCTION TO REVERSE ALPHABET         " << endl;
	cout << "*******************************************" << endl;

	while(endProgram != 'n' && endProgram != 'N')
	{
		cout << "ENTER INDICES (0-25) TO REVERSE THAT SECTION OF THE ALPHABET." << endl;
		cout << "(eg. 0 = a, 25 = z, inputting 0 and 25 as the indices will reverse entire alphabet)" << endl << endl;

		cout << "First index: ";
		cin  >> fIndex;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();

		cout << "Last index: ";
		cin  >> lIndex;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
		cin.clear();

		cout << "> REVERSING ALPHABET..." << endl;

		//FUNCTION - reverses alphabet
		reverseIt(alphabet, fIndex, lIndex);
		//output here

		cout << endl << endl;
		cout << "> Would you like to print out another reversed string? (Y/N): ";
		cin  >> endProgram;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();
	}


	return 0;
}
