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

	public:
		//setters
		void setMake(string);
		void setModel(string);
		void setYear(int);
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

		//DECONSTRUCTOR
		virtual ~Vehicle(void)
		{
			cout << "OBJECT IS PRINTING." << endl;
		}

		//PRINT FUNCTION
		virtual void print(Vehicle vehicle[], const int SIZE, int count);
};


/********************************************************************************
* CLASS - TRUCK
********************************************************************************/
class Truck: public Vehicle
{
	private:
		string bedSize;
		double towingCapacity; //in pounds
		int    numberOfWheels;
		
	public:
		//setters
		void setBedSize(string);
		void setTowingCapacity(double);
		void setNumberOfWheels(int);
		
		//getters
		string getBedSize();
		double getTowingCapacity();
		int    getNumberOfWheels();
	
		//CONSTRUCTORS
		Truck()
		{
			setBedSize("short");
			setTowingCapacity(2900);
			setNumberOfWheels(4);
		}
		
		Truck(string make, string model, int year, string color, int numDoors, string bedSize, double towingCapacity, int numberOfWheels)
		{
			setMake("not set");
			setModel("not set");
			setYear(0);
			setColor("not set");
			setNumDoors(0);
			setBedSize("short");
			setTowingCapacity(2900.0);
			setNumberOfWheels(4);
		}

		//DECONSTRUCTOR
		virtual ~Truck(void)
		{
			cout << "OBJECT IS PRINTING." << endl;
		}
	
		virtual void print();
};

/********************************************************************************
* CLASS - CAR
********************************************************************************/
class Car: public Vehicle
{
	private:
		double trunkSize;
		
	public:
		//setters
		void setTrunkSize(double);
		
		//getters
		double getTrunkSize();
	
		//CONSTRUCTORS
		Car()
		{
			setTrunkSize(0);
		}
		
		Car(string make, string model, int year, string color, int numDoors, double trunkSize)
		{
			setMake("not set");
			setModel("not set");
			setYear(0);
			setColor("not set");
			setNumDoors(0);
			setTrunkSize(0.0);
		}

		//DECONSTRUCTOR
		virtual ~Car(void)
		{
			cout << "OBJECT IS PRINTING." << endl;
		}
	
		virtual void print();
};



#endif /* VEHICLE_H_ */
