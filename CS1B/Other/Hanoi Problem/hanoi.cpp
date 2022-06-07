/***************************
* DIRECT RECURSION - hanoi
***************************/

#include <iostream>

using namespace std;

void moveDisks(int, int, int, int);

int main()
{
	int disks = 0;
	
	cout << "Enter the number of disks on needle 1: ";
	cin  >> disks;
	cin.ignore(1000, '\n');
	moveDisks(disks, 1, 2, 3);
	
	return 0;
}

void moveDisks(int count, int n1, int n3, int n2)
{
	if(count > 0)
	{
		moveDisks(count - 1, n1, n2, n3);
		
		cout << "Move disk " << count << " from " << n1 << " to " << n3 << "." << endl;
		
		moveDisks(count - 1, n2, n3, n1);
	}
}