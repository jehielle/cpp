using namespace std;

//FUNCTION - AddTwoInts
// This function adds two integers together.
int AddTwoInts(int num1, int num2)
{
	return num1 + num2;
}

//FUNCTION - MultiTwoInts
// This function multiplies two integers together.
double MultiTwoInts(int num1, int num2)
{
	return double(num1 * num2);
}

//FUNCTION - LargestTwoInts
// This function outputs the larger of the two integers.
int LargestTwoInts(int num1, int num2)
{
	if(num1 > num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}

//FUNCTION - AverageTwoInts
//This function calculates the average of two integers.
double AverageTwoInts(int num1, int num2)
{
	return double(num1 + num2) / 2;
}

