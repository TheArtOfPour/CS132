// 12.1-SeparateCompilation.cpp
//

#include "stdafx.h"
#include <iostream>
#include <string>
// include the header file
#include "12.1-SeparateCompilation.h"

using namespace std;

// This is the implementation file

// constructors
Coffee::Coffee(int ounces, string type)
{
	sizeInOunces = ounces;
	typeOfCoffee = type;
}

Coffee::Coffee(int ounces)
{
	sizeInOunces = ounces;
	typeOfCoffee = "Black";
}

Coffee::Coffee(string type)
{
	sizeInOunces = 12;
	typeOfCoffee = type;
}

Coffee::Coffee()
{
	sizeInOunces = 12;
	typeOfCoffee = "Black";
}

// class functions
void Coffee::setSize(int ounces)
{
	sizeInOunces = ounces;
}

void Coffee::setType(string type)
{
	typeOfCoffee = type;
}

istream& operator >>(istream& ins, Coffee& coffee)
{
	cout << "What size would you like (oz):";
	ins >> coffee.sizeInOunces;
	cout << "And what kind (eg. Americano):";
	ins >> coffee.typeOfCoffee;
	return ins;
}

ostream& operator <<(ostream& ost, Coffee& coffee)
{
	cout << coffee.sizeInOunces << "oz. " << coffee.typeOfCoffee;
	return ost;
}
