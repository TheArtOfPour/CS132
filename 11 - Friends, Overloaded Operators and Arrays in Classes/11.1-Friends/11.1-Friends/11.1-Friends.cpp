// 11.1-Friends.cpp : Why can't we be friends?
// Sample code for friends and const

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// A friend is not a member (no type qualifier :: or dot notation)
class WorkOut
{
public:
	// The const parameter modifier ensures that workout will not be mutated
	friend string lastWorkout(const WorkOut& workout);
	void addWorkout(string workout);
private:
	string workout;
};

int main()
{
	cout << "What was your last workout? ";
	WorkOut workout = WorkOut();
	string myLastWorkout;
	cin >> myLastWorkout;
	workout.addWorkout(myLastWorkout);
	// Friend functions can access private members
	cout << "Your last workout was " << lastWorkout(workout) << "!\n";
	// Friends are used when a method is related to an Object (WorkOut)
	// but does not mutate it directly
	system("pause");
    return 0;
}

string lastWorkout(const WorkOut& workout)
{
	return workout.workout;
}

void WorkOut::addWorkout(string workout)
{
	this->workout = workout;
}
