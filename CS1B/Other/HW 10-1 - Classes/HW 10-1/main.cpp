// ----------------------------------------------------------------------------
// File name: main.cpp                                                        -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 4/10/18                                                     -
// Date of Last Modification: 4/10/18                                         -
// ----------------------------------------------------------------------------
// Purpose: "Classes" HW                                                      -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Create the code to hold information in a class.                    -
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// -                                                                          -
// ----------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

//CLASSES
class Person
{
	private:
	
	string fName;
	string lName;
	string address;
	double height; //in inches
	string DOB;
	char gender;
	
	public:
	
	//constructors
	Person();
	Person(firstName, lastName);
	Person(fName, lName, address, height, DOB, gender);
	
	//setters
	string setFName();
	string setLName();
	string setAddress();
	double setHeight();
	string setDOB();
	char   setGender();
	
	//getters
	string getFName();
	string getLName();
	string getAddress();
	double getHeight();
	string getDOB();
	char   getGender();
	
	//PRINT FUNCTION
	void PrintPerson(fName, lName, address, height, DOB, gender);
};

//MAIN
int main()
{
	int  userInput;
	bool invalidInput;
	
	cout << "*** WELCOME TO THE INFORMATION DATABASE. ***\n\n";
	
	cout << "<1> ENTER NEW PERSON'S INFO"                << endl;
	cout << "<2> PRINT ALL PERSONS INFO IN THE DATABASE" << endl << endl;
	cout << "<3> EXIT"                                   << endl;
	
	//CHECKS FOR VALID INPUT
	do
	{
		cout << "CHOICE: ";
		cin  >> userInput;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();
		
		invalidInput = userInput != 1 && userInput != 2 && userInput != 3;
		
		if(invalidInput)
		{
			cout << "\n\n*** ERROR - PLEASE ENTER AN INTEGER 1-3. ***\n\n";
		}
	}while(invalidInput);
	
	switch(userInput)
	{
		case 1: Person(fName, lName, address, height, DOB, gender);
		break;
		
		case 2: PrintPerson(fName, lName, address, height, DOB, gender);
		break;
	}
	
	return 0;
}


/********************************************************************************
* FUNCTIONS
********************************************************************************/
/********************************************************************************
* PERSON - (setFName, setLName, setAddress, setHeight, setDOB, setGender);
********************************************************************************/
Person(fName, lName, address, height, DOB, gender)
{
	setFName();
	setLName();
	setAddress();
	setHeight();
	setDOB();
	setGender();
}

/********************************************************************************
* SETTERS
********************************************************************************/
string setFName()
{
	Person.fName = NULL;
}

string setLName()
{
	Person.lName = NULL;
}
string setAddress()
{
	cout << "Enter address: ";
	getline(cin, Person.address);
}
double setHeight()
{
	cout << "Enter height (in inches): ";
	cin  >> Person.height;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
}
string setDOB()
{
	cout << "Enter date of birth: ";
	getline(cin, Person.DOB);
}

char setGender()
{
	cout << "Enter gender: ";
	cin.get(Person.gender);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
}

/********************************************************************************
* FUNCTIONS - PRINT PERSON
********************************************************************************/
void PrintPerson(fName, lName, address, height, DOB, gender)
{
	getFName();
	getLName();
	getAddress();
	getHeight();
	getDOB();
	getGender();
}

/********************************************************************************
* GETTERS
********************************************************************************/
string getFName()
{
	cout << "Enter first name: ";
	getline(cin, Person.fName);
}

string getLName()
{
	cout << "Enter last name: ";
	getline(cin, Person.lName);
}
string getAddress()
{
	cout << "Enter address: ";
	getline(cin, Person.address);
}
double getHeight()
{
	cout << "Enter height (in inches): ";
	cin  >> Person.height;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
}
string getDOB()
{
	cout << "Enter date of birth: ";
	getline(cin, Person.DOB);
}

char getGender()
{
	cout << "Enter gender: ";
	cin.get(Person.gender);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
}