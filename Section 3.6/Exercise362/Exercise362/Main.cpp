// Exercise 3.6.2 - Exception Objects
//
// by Scott Sidoli
//
// 5-18-19
//
// Main.cpp
// 
// In this exercise, we want to have our exceptions throw objects, instead of just ints.
// We create an ABC, ArrayException, which has a PVMF GetMessage(). In the OutOfBoundsException
// class, a derived class of the ArrayException class, we override the PVMF. In the array class, 
// we have improper indices throw an OutOfBoundsException object, namely the index. In Main, we 
// set up a try-catch block that produces the error message for the given improper index. The 
// error message contains the improper index.

#include <iostream>
#include "OutOfBoundsException.hpp"
#include "Array.hpp"
#include "Shape.hpp"
#include "Point.hpp"
using namespace std;
using namespace ssidoli::CAD;
using namespace ssidoli::Containers;

int main()
{
	Array arr = Array(3);                // Create an array of points with 3 elements

	try
	{
		cout << arr[3] << endl;          // Access an element out of bounds
	}
	catch (ArrayException& ex)           // Catch exception object
	{
		cout << ex.GetMessage() << endl; // Print the error message
	}
	catch (...)							 // For unhandled exceptions
	{
		cout << "An unhandled exception has occurred..." << endl;
	}

	cout << arr.GetElement(2) << endl;   // A test of a proper index

	return 0;
}