// ----------------------------------------------------------------------------
// File name: problem 2.cpp                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 2/14/18                                                     -
// Date of Last Modification: 2/15/18                                         -
// ----------------------------------------------------------------------------
// Purpose: Structs Homework                                                  -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Create the code to hold information about a car.                   -
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


#include <string>

using namespace std;

//FUNCTION PROTOTYPES
void   outputTourType(struct tourType); //c
struct inputTourType(struct tourType);  //d

int main()
{
	struct timeType
	{
		int    hr;
		double min;
		int    sec;
	};
	
	struct tourType
	{
		string   cityName;
		int      distance;
		timeType travelTime;
	};
	
	//a
	tourType destination;
	
	//b
	destination.cityName       = "Chicago";
	destination.distance       = 550;
	destination.travelTime.hr  = 9;
	destination.travelTime.min = 30;
	destination.travelTime.sec = 0;
	
	
	
	return 0;
}