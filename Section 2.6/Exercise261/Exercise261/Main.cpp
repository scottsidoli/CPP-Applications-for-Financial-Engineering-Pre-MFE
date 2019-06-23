// Exercise 2.6.1 - Namespaces
//
// by Scott Sidoli
//
// 5-12-19
//
// Main.cpp
//
/*
To avoid name conflicts, we place our classes in a namespace. 

Thus we place the CAD classes (Circle,Point, Line) in the namespace: ssidoli::CAD
Place the container classes (Array) in the namespace: ssidoli::Containers
We access the classes in this namespace using:

• Full class name including namespace for the Point used in the Array class. 

Note that you can use only the CAD part of the namespace without the YourName 
part because the Point is also in the YourName namespace. 

• In the main program, the full namespace for Point class. 
• In the main program, using declaration for using a single class (Line). 
• In the main program, using declaration for a complete namespace (Containers). 
• In the main program, using the Circle class by creating a shorter alias for the YourName::CAD namespace.
*/

#include <iostream>
#include "Array.hpp"
#include "Circle.hpp"
#include "line.hpp"

int main()
{
	ssidoli::CAD::Point P(1.0, -1.0);					// Access using full namespace for Point
	cout << "Point P is " << P << endl;

	using ssidoli::CAD::Line;							// Access using 'using' declaration for Line
	Line l;												// Create line l
	l.Line::end(P);										// Sets the end point of l to Point P
	cout << "The length of line l is " << l.length() << endl;

	using namespace ssidoli::Containers;				// Access using declaration for complete namespace
	Array array_1 = Array(3);							// Creates an array with three points
	array_1.SetElement(1, P);							// Sets the second element to point P
	cout << "The second element of array_1 is now " << array_1.GetElement(1) << endl;

	namespace SC = ssidoli::CAD;						// Create an alias for namespace ssidoli::CAD
	SC::Circle O(P, 3.0);								// Create a circle centered at point P with radius 3.0
	cout << "The circumference of circle O is " << O.SC::Circle::circumference() << endl;

	return 0;
}