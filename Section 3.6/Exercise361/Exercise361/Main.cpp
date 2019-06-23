// Exercise 3.6.1 - Bounds Checking Array
//
// by Scott Sidoli
//
// 5-18-19
//
// Main.cpp
// 
// In this exercise, we change the array class to throw exceptions. In the functions SetElement() and GetElement(),
// and index operator, we have the functions throw -1 if the input index is outside the bounds. In the main program,
// we access an element outside of the bounds of the array and find an error. Using a catch try block we have the 
// program throw an error message when the index is outside of the bounds.

#include <iostream>
#include "Array.hpp"
#include "Circle.hpp"
#include "Line.hpp"
using namespace ssidoli::CAD;
using namespace ssidoli::Containers;

int main()
{
	Array arr = Array(3);
	// cout << arr[-1] << endl;							// We have a runtime error

	try
	{
		cout << arr[-1] << endl;						// Accessing element outside of bounds of array
	}
	catch (int error)
	{
		if (error == -1)
			cout << "Array index not allowed." << endl; // Error message for when we access array element outside of bounds.
	}
	catch (...)											
	{
		cout << "An unhandled exception has occurred..." << endl;
	}

	cout << arr.GetElement(2) << endl;

	return 0;
}
	