// Exercise 4.2b.2 - Numeric Array (generic inheritance)
//
// by Scott Sidoli
//
// 5-22-19
//
// Main.cpp
//
// In this exercise we add numeric functionality to the array class. To leave the array
// class as general, we put this numeric functionality in a derived class. This
// functionality includes addition, scalar multiplication, and the dot product of numeric
// arrays. However, we keep the derived class a template class to accommodate the
// different numeric data types. This is an example of generic inheritance. We test
// the class. The assumptions that we make when we are testing the numeric array is 
// that it contains only numeric data. While it is possible to create numeric arrays
// with point objects, we cannot use the full functionality of the numeric array class.
// In particular, we cannot use the dot product.

#include "NumericArray.hpp"
#include "Point.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace ssidoli::CAD;
using namespace ssidoli::Containers;
using namespace std;

int main()
{
	NumericArray<int> intArray1;					// Default Constructor
	NumericArray<int> intArray2(5);				// Constructor with size
	NumericArray<int> intArray3(intArray2);		// Copy Constructor
	NumericArray<int> intArray4(12);				// Array with different size
	
	// Check default size and size()
	cout << "Default size of intArray1 is " << intArray1.DefaultSize() << endl;
	cout << "Size of intArray1 is " << intArray1.Size() << endl;


	// setting values of intArray1
	for (int i = 0; i < intArray1.Size(); i++)
	{
		intArray1[i] = i;
	}

	// setting values of intArray2 
	for (int i=0; i<intArray2.Size();i++)
	{
		intArray2[i] = (intArray2.Size() - i);
	}

	cout << "Testing operator + () and operator = ()..." << endl;
	// Testing Addition
	cout << "intArray1 + intArray2 = intArray3 " << endl;
	
	for (int i = 0; i<intArray1.Size(); i++)
		cout << setw(7) << intArray1[i] << setw(8) << " + " << setw(6) 
		<< intArray2[i] << setw(9) << " = " << intArray1[i] + intArray2[i] << endl;

	intArray3 = intArray1 + intArray2;
	intArray1 = intArray3;

	
	cout << "intArray1[i]       intArray3[i]" << endl;
	for (int i = 0; i < intArray3.Size(); i++)
	{
		cout << setw(7) << intArray1[i]              // Check if intArray1[i] = intArray3[i]
			<< setw(14) << intArray3[i] << endl;
	}
	cout << endl;

	// Testing Global operator overloading
	cout << "Testing operator * :" << endl;

	intArray2 = intArray3 * 3.0;                     // Scale intArray3 by 3 and assign it to intArray2

	cout << "intArray2[i] = intArray3[i] * 3" << endl;
	for (int i = 0; i < intArray3.Size(); i++)
	{
		cout << setw(7) << intArray2[i]              // Check if intArray2[i] = 3*intArray3[i]
			<< setw(14) << intArray3[i] << endl;
	}
	cout << endl;

	// Test of Dot()
	cout << "Testing Dot(): " << endl;
	double dot_prod = intArray2.Dot(intArray3);		// Dot product of intArray2 and intArray3
	cout << "intArray2.intArray3: " << dot_prod << "\n" << endl;
	
	// Exception Catching
	try
	{
		cout << intArray1[-1] << endl;
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage();
	}
	catch (...)
	{
		cout << "An unhandled exception has occurred." << endl;
	}

	// Size difference exception
	try
	{
		cout << "Size of intArray3: " << intArray3.Size() << endl;
		cout << "Size of intArray4: " << intArray4.Size() << endl;
		NumericArray<int> intArray5 = intArray4 + intArray3;
	}
	catch (ArrayException& size)
	{
		cout << size.GetMessage();
	}
	catch (...)
	{
		cout << "An unhandled exception has occurred." << endl;
	}
	
	// Try to create numeric arrays with Point objects and do some tests
	NumericArray<Point> points1;								   // Default constructor
	NumericArray<Point> points2(12);							   // Constructor with size
	NumericArray<Point> points3(points1);						   // Copy constructor
	NumericArray<Point> points4(14);							   // Constructor with a different size

	cout << "Size of points1: " << points1.DefaultSize() << endl;  // Check size of pts1: default size
	cout << "pts3[10]: " << points3[4] << endl;				       // Element of array from copy constructor
	
	points2 = points1 * 2;										   // OK, Point has operator * () defined
	points2 = points1 + points2;								   // OK, Point has operator + () defined
	//Point p = pts1.Dot(pts2);									   // NOT OK, Point * Point operation does not exist/	//cout << p << endl;
	
	
	return 0;
}