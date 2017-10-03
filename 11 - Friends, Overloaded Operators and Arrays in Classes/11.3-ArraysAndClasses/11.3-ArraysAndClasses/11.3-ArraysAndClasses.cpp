// 11.3-ArraysAndClasses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

// setting #define NDEBUG disables all assert statements in the code
//#define NDEBUG
// cassert includes the assert macro, which is useful for debugging
#include <cassert>

using namespace std;

struct Car
{
	int year;
	string make;
	string model;
};

Car garage[4];

int main()
{
	// create cars and add to the garage
	Car commuterCar = Car();
	commuterCar.year = 2014;
	commuterCar.make = "Nissan";
	commuterCar.model = "Leaf";
	garage[0] = commuterCar;

	Car familyCar = Car();
	familyCar.year = 1995;
	familyCar.make = "Dodge";
	familyCar.model = "Caravan";
	garage[1] = familyCar;

	Car sportsCar = Car();
	sportsCar.year = 2020;
	sportsCar.make = "Bugatti";
	sportsCar.model = "Veyron";
	garage[2] = sportsCar;

	// assertions allows us to verify
	assert(garage[1].year == 1995);
	assert(garage[0].model == "Leaf");
	assert(garage[2].make == "Bugetti");

	system("pause");
    return 0;
}

