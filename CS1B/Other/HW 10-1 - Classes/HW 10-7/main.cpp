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

#include "vehicle.h"

//MAIN
int main()
{
	const int SIZE = 5;

	Vehicle * vehicle[SIZE];
	int    index;
	int    count;     //makes sure the number of vehicles made is only 5
	
	string make;
	string model;
	int    year;
	string color;
	int    numDoors;
	
	string bedSize;
	double towingCapacity; //in pounds
	int    numberOfWheels;
	
	double trunkSize;
	
	int  choice;
	bool invalidChoice;
	
	index = 0;
	
	system("CLS");
	
	for(count = 0; count < SIZE; count++)
	{
		cout << "****************************************" << endl;
		cout << "               HW 10-7                  " << endl;
		cout << " -------------------------------------- " << endl;
		cout << " > CREATE A...                          " << endl;
		cout << "                                        " << endl;
		cout << " <1> VEHICLE                            " << endl;
		cout << " <2> TRUCK                              " << endl;
		cout << " <3> CAR                                " << endl;
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
				cout << "Make: ";
				getline(cin, make);
				
				cout << endl;
				cout << "Model: ";
				getline(cin, model);
				
				cout << endl;
				cout << "Year: ";
				cin  >> year;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				
				cout << endl;
				cout << "Color: ";
				getline(cin, color);
				
				cout << endl;
				cout << "# of Doors: ";
				cin  >> numDoors;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				
				vehicle[index] = new Vehicle(make, model, year, color, numDoors);
			break;
			
			case 2: 
				cout << endl;
				cout << "Bed Size: ";
				getline(cin, bedSize);
				
				cout << endl;
				cout << "Towing Capacity: ";
				cin  >> towingCapacity;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				
				cout << endl;
				cout << "# of Wheels: ";
				cin  >> numberOfWheels;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				
				vehicle[index] = new Truck(make, model, year, color, numDoors,
										   bedSize, towingCapacity, numberOfWheels);
			break;
			
			case 3: 
				cout << endl;
				cout << "Trunk Size: ";
				cin  >> trunkSize;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				
				vehicle[index] = new Car(make, model, year, color,
										 numDoors, trunkSize);
			break;
		}
		
		index++; //updates the amount of vehicles made
	
		cout << endl << endl;
		system("PAUSE");
		system("CLS");

		//OUTPUTTING EVERYTHING
		cout << "*************************************" << endl;
		cout << " VEHICLE MADE: "                       << endl;
		cout << "*************************************" << endl << endl;
		vehicle[count]->Vehicle::print(*vehicle, SIZE, index);
		cout << "*************************************" << endl << endl;

		system("PAUSE");
		system("CLS");
	}//END FOR
	
	return 0;
}


