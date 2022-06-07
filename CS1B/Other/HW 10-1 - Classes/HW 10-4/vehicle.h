#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <windows.h>

using namespace std;

/********************************************************************************
* CLASS - VEHICLE
********************************************************************************/
class Vehicle
{
	private:
		string make;
		string model;
		int    year;
		string color;
		int    numDoors;

		void setMake(string);
		void setModel(string);
		void setYear(int);

	public:
		//setters
		void setColor(string);

		//getters
		string getMake();
		string getModel();
		int    getYear();
		string getColor();
		int    getNumDoors();

	protected:
		void setNumDoors(int);

	public:
		//CONSTRUCTORS
		/*********************
		 * FUNCTION: Vehicle
		 * ------------------
		 * - initializes all of the variables to nothing
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
		Vehicle() //sets it to some default vehicle
		{
			setMake("Ford");
			setModel("Mustang");
			setYear(2018);
			setColor("Black");
			setNumDoors(4);
		}

		/*********************
		 * FUNCTION: Vehicle
		 * ------------------
		 * - initializes 2 variables, but the rest to nothing
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
		Vehicle(string make, string model, int year)
		{
			setMake(make);
			setModel(model);
			setYear(year);
			setColor("NULL");
			setNumDoors(0);
		}

		/*********************
		 * FUNCTION: Vehicle
		 * ------------------
		 * - initializes all variables
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
		Vehicle(string make, string model, int year, string color, int numDoors)
		{
			setMake(make);
			setModel(model);
			setYear(year);
			setColor(color);
			setNumDoors(numDoors);
		}

		//PRINT FUNCTION
		void print(int count, Vehicle vehicles[]);


};



#endif /* VEHICLE_H_ */
