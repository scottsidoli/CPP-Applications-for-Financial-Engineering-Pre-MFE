// Exercise 2.3.7 - Inline Functions
//
// by Scott Sidoli
//
// 4-28-19
//
// Main.cpp
// 
// Point Class with inline functions. The goal of this file is to test the
// inline functions from the header. We use normal inline for the Getter functions
// and default inline for the Setter functions.

#include "Point.hpp"
#include <iostream>

int main()
{
	Point P1;													// Create a point at origin
	cout << "P1 is " << P1.toString() << endl;
	cout << endl;

	
	cout << "Setter using default inline:" << endl;		// Setter function (default inline)
	P1.x(2.34);
	P1.y(1.11);
	cout << "The coordinates of P1 are " << P1.toString() << endl;
	cout << endl;

	
	cout << "Getter using normal inline:" << endl;		// Getter function (normal inline)
	cout << "x-coordinate of p1 is " << P1.x() << endl;
	cout << "y-coordinate of p1 is " << P1.y() << endl;
	cout << endl;

	return 0;
}