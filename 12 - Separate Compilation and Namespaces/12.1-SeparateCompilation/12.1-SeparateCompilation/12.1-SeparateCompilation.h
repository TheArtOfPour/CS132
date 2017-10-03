// 12.1-SeparateCompilation.h
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// This is the interface (header) file

class Coffee 
{
public:
	// overloaded operators
	friend istream& operator >>(istream& ins, Coffee& coffee);
	friend ostream& operator <<(ostream& outs, Coffee& coffee);
	
	// constructors
	Coffee(int ounces, string type);
	Coffee(int ounces);
	Coffee(string type);
	Coffee();

	// class functions
	void setSize(int ounces);
	void setType(string type);

private:
	int sizeInOunces;
	string typeOfCoffee;
};