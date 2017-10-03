// 11.2-Overload.cpp : Sample code for overloading operators
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Force
{
public:
	// Overload the addition and equal operators for the Force class
	friend Force operator +(const Force& force1, const Force& force2);
	friend bool operator ==(const Force& force1, const Force& force2);

	// Unary operators can be overloaded as well
	friend Force operator -(const Force& force1);

	// Even input and output streams can be overloaded
	friend ostream& operator <<(ostream& outs, const Force& force1);
	friend istream& operator >>(istream& ins, Force& force1);

	Force();
	Force(int power);
private:
	int power;
};

int main()
{
	Force forcePush = Force(595);
	Force forceLightning = Force(742);

	// now we can add forces using +
	Force forcePushLightning = forcePush + forceLightning;

	// we can compare forces using ==
	if (forcePush == forceLightning)
		cout << "We are evenly matched\n";
	else
		cout << "This is not a fair fight\n";

	// we can negate forces with -
	Force negativeForcePush = -forcePush;

	// we can directly interact with the input and output streams
	cout << "Now I shall use my force push lightning" << forcePushLightning << "\n";
	cin >> forcePushLightning;
	cout << "Once again, I shall use my force push lightning" << forcePushLightning << "\n";
	
	system("pause");
	return 0;
}

Force operator+(const Force & force1, const Force & force2)
{
	cout << "With our forces combined...\n";
	return Force(force1.power + force2.power);
}

bool operator==(const Force & force1, const Force & force2)
{
	cout << "Can anything match this force?\n";
	return force1.power == force2.power;
}

Force operator-(const Force & force1)
{
	cout << "The force is fading...\n";
	return Force(-force1.power);
}

ostream & operator<<(ostream & outs, const Force & force1)
{
	outs << " Power:" << force1.power << " ";
	// The output stream must be returned
	return outs;
}

istream & operator>>(istream & ins, Force & force1)
{
	cout << "What power? : ";
	ins >> force1.power;
	return ins;
}

Force::Force()
{
}

Force::Force(int power)
{
	this->power = power;
}
