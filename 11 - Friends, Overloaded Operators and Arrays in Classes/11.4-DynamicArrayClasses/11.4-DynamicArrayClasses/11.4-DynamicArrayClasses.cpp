// 11.4-DynamicArrayClasses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

// setting #define NDEBUG disables all assert statements in the code
#define NDEBUG
// cassert includes the assert macro, which is useful for debugging
#include <cassert>

using namespace std;

class Grocery
{
public: 
	Grocery();
	Grocery(const char name[]);
	// copy constructor
	Grocery(const Grocery& grocery);
	// return dynamic memory to the freestore
	~Grocery();
	int length() const;
	string name() const;

private:
	char *label;
	int max_length;
};

Grocery grocery_list[10];

int main()
{
	// create groceries
	Grocery nameless = Grocery();
	Grocery banana = Grocery("banana");
	Grocery banene = Grocery(banana);

	// add to list
	grocery_list[0] = nameless;
	grocery_list[1] = banana;
	grocery_list[2] = banene;

	// print list
	cout << "I need to buy ";
	for (int i = 0; i < 3; i++) {
		cout << grocery_list[i].name() << ", ";
	}
	cout << " and always milk.";

	// the destructor ~ will automatically free up memory 
	// once the groceries are out of scope!

	system("pause");
	return 0;
}

Grocery::Grocery() : max_length(100)
{
	label = new char[max_length + 1]; // allow for terminal null byte '\0'
	label[0] = '\0';
}

Grocery::Grocery(const char name[]) : max_length(strlen(name))
{
	label = new char[max_length + 1];
	strcpy(label, name);
}

Grocery::Grocery(const Grocery & grocery) : max_length(grocery.length())
{
	label = new char[max_length + 1];
	strcpy(label, grocery.label);
}

Grocery::~Grocery()
{
	// release any dynamically allocated memory.f
	//delete[] label;
}

int Grocery::length() const
{
	return strlen(label);
}

string Grocery::name() const
{
	return label;
}
