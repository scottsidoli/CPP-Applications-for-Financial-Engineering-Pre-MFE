// Exercise 3.5.3 - Virtual Destructors
//
// by Scott Sidoli
//
// 5-16-19
//
// Main.cpp
//
// In this exercise, we check destructor calls wth pointers to instances
// of derived classes. We add print statements to destructors to check
// which destructors are called and then we declare the Shape destructor as
// virtual and make a comparison. We notice that the first time we run the
// application, only the shape destructor is called, but once the shape
// destructor is declared virtual, the destructors from the derived classes
// are declared as well.

#include <iostream>
#include "Line.hpp"
using namespace ssidoli::CAD;

int main()
{
	Shape* shapes[3];
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;

	for (int i = 0; i != 3; i++)
		delete shapes[i];

	return 0;
}