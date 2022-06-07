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
// Step 1: Hold information for vehicles.                                     -
// Step 2: Print out the information neatly.                                  -
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
// - vehicles[]        Vehicle      nothing                                   -
// - count             integer      0                                         -
// - make              string       nothing                                   -
// - model             string       nothing                                   -
// - year              integer      0                                         -
// - color             string       nothing                                   -
// - numDoors          integer      nothing                                   -
// -                                                                          -
// ----------------------------------------------------------------------------

#include "vehicle.h"

//MAIN
int main()
{
	Vehicle vehicles[5];
	int     count;
	
	vehicles[0].setColor("Black");

	vehicles[1].setColor("White");

	vehicles[2].setColor("Neon Green");

	vehicles[3].setColor("Purple");

	vehicles[4].setColor("Translucent");


	//OUTPUTTING THE 5 VEHICLES
	for(count = 0; count < 5; count++)
	{
		vehicles[count].print(count, vehicles);
		system("PAUSE");
	}
	
	return 0;
}


