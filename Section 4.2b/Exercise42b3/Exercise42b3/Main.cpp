// Exercise 4.2b.3- Point Array (concrete inheritance)
//
// by Scott Sidoli
//
// 5-24-19
//
// Main.cpp
// 
// In this exercise we create the class PointArray. This class is derived from
// the template class, Array. We fix the type to point, making this an example of 
// concrete inheritance. This class has added functionality of Length() which
// finds the total length of the point array. We created new source and header files
// and define constructors, destructors, and assignment operator. We add a total length
// exception for arrays of size one. In Main.cpp, we test the class.

#include "PointArray.hpp"
using namespace ssidoli::Containers;
using namespace ssidoli::CAD;

int main()
{
	// Testing Constructors
	PointArray array_of_points1;						// Default Constructor
	PointArray array_of_points2(7);						// Constructor with size
	PointArray array_of_points3(array_of_points2);		// Copy Constructor
	PointArray array_of_points4(1);						// Constructor with different size

	// Checking Size
	cout << "The default size is " << array_of_points1.DefaultSize() << "." << endl;
	cout << "The size of array_of_points_1 is " << array_of_points1.Size() << "." << endl;

	// Assign Arbitrary Values to array_of_points1 and array_of_points2
	for (int i = 0; i != array_of_points1.Size(); i++)
	{
		array_of_points1[i] = Point((rand()%100), (rand()%100));		// Random points with coordinate values range
																		// from 0 to 99.
	}

	for (int i = 0; i != array_of_points2.Size(); i++)
	{
		array_of_points2[i] = Point((rand() % 100), rand() % 100);
	}

	// Printing the two arrays
	cout << "array_of_points1: " << endl;
	for (int i = 0; i != array_of_points1.Size(); i++)
	{
		cout << array_of_points1[i] << endl;
	}

	cout << "array_of_points2: " << endl;
	for (int i = 0; i != array_of_points2.Size(); i++)
	{
		cout << array_of_points2[i] << endl;
	}

	// Determining the total length of the two arrays
	cout << "The total length of array_of_points1 is " << array_of_points1.Length() << endl;
	cout << "The total length of array_of_points2 is " << array_of_points2.Length() << endl;

	// Test the Assignment Operator
	cout << "array_of_points3 is: " << endl;
	for (int i = 0; i != array_of_points3.Size(); i++)
	{
		cout << array_of_points3[i] << endl;
	}
	
	array_of_points3 = array_of_points1;					// Assignment Operator

	cout << "Now array_of_points3 = array_of_points1!" << endl;
	cout << "array_of_points3:" << endl;

	for (int i = 0; i != array_of_points3.Size(); i++)
	{
		cout << array_of_points3[i] << endl;
	}

	// Test Total Length Exception catching
	try
	{
		cout << array_of_points4.Length() << endl;
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}
	catch (...)
	{
		cout << "An unhandled exception has occurred..." << endl;
	}


	return 0;
}