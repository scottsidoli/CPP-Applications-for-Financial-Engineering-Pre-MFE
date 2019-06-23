// Exercise 2.5.3 - Array Class
//
// by Scott Sidoli
//
// 5-10-19
//
// Main.cpp
// 
// Testing the array class. We call the constructors, getter and setter functions.
// We also test our assignment operator and our bracket operator.

#include "Array.hpp"
#include <iostream>

using namespace std;

int main()
{
	Array arr_1;		// Default Constructor
	Array arr_2(7);		// Size constructor
	Array arr_3(arr_2); // Copy constructor

	// testing size function assignment operator
	cout << "Size of arr_1: " << arr_1.Size() << endl;
	arr_1 = arr_2;		// Assignment Operator
	cout << "size of arr_1: " << arr_1.Size() << endl;

	// testing getter and setter functions
	cout << "arr_1[0]: " << arr_1.GetElement(0) << endl;

	Point p1(1.0, 2.0);
	arr_1.SetElement(6, p1);
	cout << "arr_1[6]: " << arr_1.GetElement(6) << endl;

	// Square Brackets
	Point p2 = arr_1[0];	// p2 is set to the first element of arr_1
	cout << p2 << endl;

	cout << p1 << endl;
	arr_1[0] = p1;			// non-constant []

	/* Adding the const version allows us to return a constant reference
	to a point. The value cannot be changed and this will not modify any
	member in the class. It leaves the original array intact which is
	useful in practice.*/
	
	return 0;
}