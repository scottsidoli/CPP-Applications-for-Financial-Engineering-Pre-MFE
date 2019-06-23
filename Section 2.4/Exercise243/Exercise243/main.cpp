// Exercise 2.4.3 - Constructors as Conversion Operators
//
// by Scott Sidoli
//
// 5-5-19
//
// main.cpp
// 
// The goal of this file is to test the new constructor and explore
// its uses as a conversion operator. When we run the code given in
// the exercise, we find that it does compile. The point constructor
// taking a single double as an argument can take the value 1.0, in the
// if statement, and convert it to a point object. Thus, we see that
// constructors can also act as conversion operators. To prevent this,
// we declare the constructor as explicit. It can still be used for
// conversion, but it must be done explicitly, as demonstrated below.


#include "Point.hpp"
#include <iostream>

int main()
{
	// This is code from the exercise. If we run this with an explicit constructor
	// we get error C2678. It cannot find the point!
	/*
	Point p(1.0, 1.0); 
	
	if (p == 1.0) 
		cout << "Equal!" << endl; 
	else cout << "Not equal" << endl;
	*/


	Point p(1.0, 1.0);

	if (p == (Point)1.0)				// Explicit type conversion using constructor.
		cout << "Equal!" << endl;
	else cout << "Not equal" << endl;

	return 0;
}