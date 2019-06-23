// Exercise 2.3.4 - Const Functions
//
// by Scott Sidoli
//
// 4-20-19
//
// Main.cpp
//
// The goal of this exercise is to demonstrate the necessity for const functions when working
// with const objects. We create a const point, denoted const_A. We attempt to change the x-
// value using the setter function, which produces a compiler error. We also try to print the
// x-value using the getter funtion but the same compiler error occurs. To avoid these errors,
// we turn our getter, distance, and toString function into const functions. In this way, the
// the compiler will know that we are not attempting to change the point. These changes are
// made in Exercise234.hpp and Exercise234.cpp.

#include "Exercise234.hpp"
#include <iostream>

using namespace std;

int main()
{
	const Point const_A(1.5, 3.9);			
	//const_A.x(0.3);						// Running this code produces error C2663

	//cout << const_A.x() << endl;			// Running this code produces error C2663 (is x() is not a const function)
											// Now we run this with const functions
	cout << const_A.x() << endl;
	cout << const_A.y() << endl;
	cout << const_A.distance() << endl;
	cout << const_A.toString() << endl;
	return 0;
}