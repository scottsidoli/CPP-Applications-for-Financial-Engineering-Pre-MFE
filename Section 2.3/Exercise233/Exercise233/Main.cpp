// Exercise 2.3.3 - Function Overloading
//
// by Scott Sidoli
//
// 4-20-19
//
// Main.cpp
//
// The goal of this exercise is to test function overloading. We rename
// get_x() and set_x() to just x(). Similarly, we rename get_y() and
// set_y() to just y(). We also rename distance_origin to distance()
// Thus we have three cases of overloading. In these instance of overloading
// the argument types are different. We test the new functions in the 
// main. We create Point A taking user input and using the setter functions.
// This point we copy and call it Point B. We print Point A using the 
// getter functions. We change point A and print it again using the getter 
// functions and test the overloaded distance functions.

#include "Exercise233.hpp"
#include <iostream>

using namespace std;

int main()
{
	double x_1, y_1;
	
	Point A;								// Create point A

	cout << "We are going to use function overloading!" << endl;
	cout << "Give me an x and a y!" << endl;// User prompt and input
	cin >> x_1 >> y_1;

	A.x(x_1);								// setter functions
	A.y(y_1);

	Point B = A;							// Copy point A

	cout << "Your point is (" << A.x() << ", " << A.y() << ")" << endl;
	cout << "Now I'm going to change the point!" << endl;	// Print point A using
															// getter functions
	A.x(x_1 - y_1);							// Change point A
	A.y(x_1 + y_1);

	cout << "The point is now (" << A.x() << ", " << A.y() << ")" << endl;
	cout << "The distance from the new point to the origin is" << endl << A.distance() << endl;
	cout << "The distance from the new point to the old point is" << endl << A.distance(B) << endl;
											// We print the new point with getter functions and
											// test the overloaded distance functions.	
	return 0;
}