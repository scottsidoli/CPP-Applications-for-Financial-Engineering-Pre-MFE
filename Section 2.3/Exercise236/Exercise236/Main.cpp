// Exercise 2.3.6 - Circle Class
//
// by Scott Sidoli
//
// 4-26-19
//
// Main.cpp
//
// The goal of this program is to test the functionality of our circle class.
// The class is declared in Circle.hpp and functions are defined in Circle.cpp.
// We must include Point.hpp and Point.cpp because the center point of the
// circle is part of the member data. We create a circle, and print a description
// using the toString() function. We also print a description using the getter
// functions. We also change the data of the circle using the setter functions and
// print the description of the circle with new member data. Finally, we test the
// area, diameter, and circumference functions.

#include "Circle.hpp"
#include <iostream>

int main()
{
	Point A;
	Circle C(A, 1.0);

	cout << C.toString() << endl;				// Uses toString()
	cout << "The center of the circle is " << (C.center()).toString() << endl;		// Tests getter functions
	cout << "The radius of the circle is " << C.radius() << endl;


	// Change the circle parameters to new center and new radius
	Point B(1.0,5.0);
	C.center(B);
	C.radius(4.0);
	cout << C.toString() << endl;

	// Diameter, Area, and circumference test
	cout << "The diameter of the circle is " << C.diameter() << endl;
	cout << "The area of the circle is " << C.area() << endl;
	cout << "The circumference of the circle is " << C.circumference() << endl;
	cout << endl;

	return 0;
}