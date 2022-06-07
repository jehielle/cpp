// ----------------------------------------------------------------------------
// File name: main.cpp                                                        -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 4/10/18                                                     -
// Date of Last Modification: 4/12/18                                         -
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
// - people[]          Person       nothing                                   -
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
	Person people[5];
	int    count;
	
	people[0].setFName("Noah");
	people[0].setLName("Fence");
	people[0].setAddress("28342 Place St");
	people[0].setHeight(80);
	people[0].setDOB("11/30/92");
	people[0].setGender('M');

	people[1].setFName("Daria");
	people[1].setLName("Morgendorffer");
	people[1].setAddress("Lawndale");
	people[1].setHeight(80);
	people[1].setDOB("4/25/78");
	people[1].setGender('F');

	people[2].setFName("Jane");
	people[2].setLName("Lane");
	people[2].setAddress("Lawndale");
	people[2].setHeight(80);
	people[2].setDOB("3/10/78");
	people[2].setGender('F');

	people[3].setFName("Trent");
	people[3].setLName("Lane");
	people[3].setAddress("Lawndale");
	people[3].setHeight(80);
	people[3].setDOB("9/3/74");
	people[3].setGender('M');

	people[4].setFName("I am");
	people[4].setLName("Confusion");
	people[4].setAddress("Whatisthis St");
	people[4].setHeight(80);
	people[4].setDOB("12/29/18");
	people[4].setGender('F');

	//OUTPUTTING THE 5 PEOPLE
	for(count = 0; count < 5; count++)
	{
		people[count].print(count, people);
		system("PAUSE");
	}
	
	return 0;
}


