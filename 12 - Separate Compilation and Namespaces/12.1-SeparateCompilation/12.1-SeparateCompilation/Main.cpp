// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
// include the header file
#include "12.1-SeparateCompilation.h"

using namespace std;


int main()
{
	// "Coffee" is accessable through the separate header file (interface), 
	// and the code (implementation) is linked and compiled with our main code.
	// Other implementations of "Coffee" could be created and used so long as they honor
	// the interface.
	Coffee default = Coffee();
	Coffee mocha = Coffee("Mocha");
	Coffee grandeAmericano = Coffee(16, "Americano");
	Coffee justForInstagram = Coffee(31, "Unicorn Frappuccino");

	// we can use Coffee in the input stream
	Coffee fromInput;
	cout << "Let's Input Coffee\n";
	cin >> fromInput;

	// ... and output stream
	cout << "Output Coffee: " << fromInput << endl;

	// we can not access the private properties directly.
	//justForInstagram.sizeInOunces = 9000;

	// but we can through a public function
	fromInput.setSize(9000);
	cout << "After setSize(): " << fromInput << endl;

	system("pause");
	return 0;
}