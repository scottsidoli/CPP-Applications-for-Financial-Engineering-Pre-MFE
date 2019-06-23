// Exercise 2.5.1 - Dynamically Creating Objects
//
// by Scott Sidoli
//
// 5-10-19
//
// Main.cpp
// 
// In this exercise, we use the point class to dynamically create objects.
// We create new point objects use the constructors and the keyword 'new'.
// We call the distance function on these new objects, dereferencing the 
// pointers of the arguments. Finally we create an array declaring the size 
// of the array at runtime.

#include "Point.hpp"
#include <iostream>

using namespace std;

int main()
{
	Point *A, *B, *C;						// Pointers to point objects
	A = new Point;							// Default constructor
	B = new Point(6.0);						// One double constructor
	C = new Point(2.0, 3.0);				// Coordinate constructor
	Point *D = new Point(*C);				// Copy Constructor

	cout << (*D).distance(*B) << endl;		// Distance between D and B
	cout << (*C).distance() << endl;		// Distance from C to the origin
	cout << *A << endl;						// Print point A

	delete A; delete B; delete C; delete D;

	// Ask user for the size of the array
	int n;
	cout << "Enter the size of the array of points to be created: " << endl;
	cin >> n;

	/*
	// Create the array on the stack
	Point point_array[n];					// compiler error C2131: expression did not evaluate to a constant
	cout << point_array[1] << endl;			// failure was caused by a read of a variable outside its lifetime
	*/
	
	// Pointer to an array
	Point *point_array;
	point_array = new Point[n];				// Default constructor called when creating the array.
	cout << point_array[1];
	delete[] point_array;
	
	return 0;
}