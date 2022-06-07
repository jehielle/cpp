/*******************************
* JEHIELLE DAVID - CS1C
*******************************/

#include<iostream> //for cout, cin
#include<fstream>  //for file IO
#include<stdlib.h> //for srand, rand
#include<time.h>   //because using time as a seed for srand, need time.h
#include<string>   // for strings

using namespace std;

//FUNCTION PROTOTYPES
void reverseNum(int numToBeReversed);
void selectionSort(int list[], const int SIZE);
void printArray(int list[], const int SIZE);

int main()
{
	const int SIZE = 10;

	int count;          //iterator, already initialized in for loops
	int numAr[SIZE];    //array to hold 10 randomized numbers
	int randNum;        //the random value
	int sum;            //sum of the digits of the randomized number
	int tripleNum;      //the tripled number of the randomized number
	int summingRandNum; //copied variable for tripling digits
	int rand();         //rand

	ifstream fin;       //READ FROM FILE
	ofstream fout;      //WRITE INTO FILE

	randNum        = 0;
	sum            = 0;
	tripleNum      = 0;
	summingRandNum = 0;

	srand(time(NULL)); //setting srand 1x to keep the numbers random

	//***********************************************************
	//*******
	//           B: need enum/typedef/string vars
	//*******
	//***********************************************************


	//GENERATE
	cout << "> GENERATING A RANDOM 3-DIGIT NUMBER...\n\n";

	randNum = rand()% 999 + 100; //from 100 to 999
	cout << randNum;
	cout << endl << endl;

	//SUM
	cout << "> SUMMING THE DIGITS...\n\n";

	summingRandNum = randNum; //copying the variable to use for processing
	while(summingRandNum != 0)
    {
        sum            = sum + summingRandNum % 10;
        summingRandNum = summingRandNum / 10;
    }

	cout << sum;
	cout << endl << endl;

	//TRIPLE THE NUMBER
	cout << "> TRIPLING THE NUMBER...\n\n";

	tripleNum = randNum * 3;
	cout << tripleNum;
	cout << endl << endl;

	//REVERSE DIGITS
	cout << "> REVERSING THE DIGITS...\n\n";

	reverseNum(randNum); //FUNCTION CALL - reverses and outputs the number reversed
	cout << endl << endl;

	//STORING IN ARRAY
	cout << "> STORING 10 RANDOM NUMBERS IN THE ARRAY...\n\n";

	for(count = 0; count < SIZE; count++)
	{
		numAr[count] = rand()% 999; //the numbers randomized specifically for the array
	}

	//SORTING ARRAY
	cout << "> SORTING THE ARRAY...\n\n";
	selectionSort(numAr, SIZE); //FUNCTION CALL - sorts array
	printArray(numAr, SIZE);    //FUNCTION CALL - prints array

	cout << endl;

	//WRITING TO FILE
	cout << "> WRITING THE ARRAY TO AN EXTERNAL FILE...\n\n";
	fout.open("fileIO.txt"); //opens file called fileIO.txt

	for(count = 0; count < SIZE; count++)
	{
		fout << numAr[count];
		fout << endl;
	}

	fout.close(); //closes file

	//READING FILE
	cout << "> READING THE FILE...\n\n";

	fin.open("fileIO.txt"); //opens file

	for(count = 0; count < SIZE; count++)
	{
		fin >> numAr[count];
	}

	fin.close(); //closes file

	//PRINTING ARRAY
	cout << "> PRINTING THE ARRAY...\n";
	cout << "> OUTPUT:\n\n";

	printArray(numAr, SIZE); // FUNCTION CALL - to print array


	return 0;
}

/***************************************
* FUNCTIONS
***************************************/
/***************************************
* FUNCTION - reverseNum - reverses a number
***************************************/
void reverseNum(int numToBeReversed)
{
	int numReversed;
	int remainder;

	numReversed = 0;

    while(numToBeReversed != 0)
    {
        remainder   = numToBeReversed%10;
        numReversed = numReversed*10 + remainder;
        numToBeReversed /= 10;
    }

    cout << numReversed;
}

/***************************************
* FUNCTION - selectionSort - sorts an array
***************************************/
void selectionSort(int list[], const int SIZE)
{
	int index;
	int smallestIndex;
	int location;
	int temp;

	for(index = 0; index < SIZE - 1; index++)
	{
		smallestIndex = index;

		for(location = index + 1; location < SIZE; location++)
		{
			if(list[location] < list[smallestIndex])
			{
				smallestIndex = location;
			}//END IF
		}// END FOR

	temp                = list[smallestIndex];
	list[smallestIndex] = list[index];
	list[index]         = temp;

	}//END FOR

}

void printArray(int list[], const int SIZE)
{
	int count;

	for(count = 0; count < SIZE; count++)
	{
		cout << list[count];
		cout << endl;
	}
}

