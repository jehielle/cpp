 // ----------------------------------------------------------------------------
// File name: main.cpp                                                        -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 4/10/18                                                     -
// Date of Last Modification: 4/19/18                                         -
// ----------------------------------------------------------------------------
// Purpose: "Classes" HW                                                      -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Hold information for 5 people, including their name, address, etc. -
// Step 2: Print out the information neatly.
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
// - count             integer      0                                         -
// - fName             string       nothing                                   -
// - lName             string       nothing                                   -
// - address           double       0.0                                       -
// - DOB               string       nothing                                   -
// - gender            char         nothing                                   -
// -                                                                          -
// ----------------------------------------------------------------------------

#include "person.h"

//MAIN
int main()
{
	const int SIZE = 5;

	Person * people[SIZE];
	int    index;
	int    count;     //makes sure the number of people made is only 5
	
	string firstName;
	string lastName;
	string addr;
	double ht;
	string dob;
	char   sex;
	
	int    id;
	double gpa;
	string classification;
	
	string dept;
	string degree;
	
	int  choice;
	bool invalidChoice;
	
	index = 0;
	
	system("CLS");
	
	for(count = 0; count < SIZE; count++)
	{
		cout << "****************************************" << endl;
		cout << "               HW 10-6                  " << endl;
		cout << " -------------------------------------- " << endl;
		cout << " > CREATE A...                          " << endl;
		cout << "                                        " << endl;
		cout << " <1> PERSON                             " << endl;
		cout << " <2> STUDENT                            " << endl;
		cout << " <3> PROFESSOR                          " << endl;
		cout << "****************************************" << endl;
		cout << " CHOICE: ";
		
		//INVALID INPUT LOOP
		do
		{
			cin >> choice;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			invalidChoice = choice != 1 && choice != 2 && choice != 3;
			
			if(invalidChoice)
			{
				cout << "\n\n*** ERROR - PLEASE ENTER 1, 2, OR 3 ***\n\n";
			}
		}while(invalidChoice);
		
		//SWITCH STATEMENT
		switch(choice)
		{
			case 1: 
				cout << endl;
				cout << "First Name: ";
				getline(cin, firstName);
				
				cout << endl;
				cout << "Last Name: ";
				getline(cin, lastName);
				
				cout << endl;
				cout << "Address: ";
				getline(cin, addr);
				
				cout << endl;
				cout << "Height: ";
				cin  >> ht;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				
				cout << endl;
				cout << "Date of Birth: ";
				getline(cin, dob);
				
				cout << endl;
				cout << "Gender: ";
				cin.get(sex);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				
				people[index] = new Person(firstName, lastName, addr, ht, dob, sex);
			break;
			
			case 2: 
				cout << endl;
				cout << "Student ID: ";
				cin  >> id;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				
				cout << endl;
				cout << "Student GPA: ";
				cin  >> gpa;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				
				cout << endl;
				cout << "Classification: ";
				getline(cin, classification);
				
				people[index] = new Student(firstName, lastName, addr, ht, dob, sex, gpa, classification, id);
			break;
			
			case 3: 
				cout << endl;
				cout << "Employee ID: ";
				cin  >> id;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				
				cout << endl;
				cout << "Department: ";
				getline(cin, dept);
				
				cout << endl;
				cout << "Degree: ";
				getline(cin, degree);
				
				people[index] = new Professor(firstName, lastName, addr, ht, dob, sex, id, dept, degree);
			break;
		}
		
		index++; //updates the amount of people made
		
	}//END FOR
	
	cout << endl << endl;
	system("PAUSE");
	system("CLS");
	
	//OUTPUTTING EVERYTHING
	for(count = 0; count < SIZE; count++)
	{
		cout << "*************************************" << endl;
		cout << " DETAILS: "                            << endl;
		cout << "*************************************" << endl << endl;
		people[count]->Person::print(people, SIZE, count); //count is the index here
		cout << "*************************************" << endl << endl;
		/*if(//if person is student)
		{
			//if the person is a prof or student, then output extra info
			people[count].print(student);
		}*/
		
	}
	
	
	
	cout << endl << endl;
	system("PAUSE");
	
	return 0;
}


