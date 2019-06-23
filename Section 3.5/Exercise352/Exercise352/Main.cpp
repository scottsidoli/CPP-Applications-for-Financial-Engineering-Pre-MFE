// Exercise 3.5.2 - Calling Base Class Functionality
//
// by Scott Sidoli
//
// 5-15-19
//
// Main.cpp
//
// In this exercise, we access base class functionality in our derived classes.
// By calling Shape::toString() in our derived toString() functions in Point,
// Line, and Circle we are able to print the shape ID along with the description.

#include <iostream>
#include "Line.hpp"
using namespace ssidoli::CAD;

int main()
{
	Shape s;					                           // Create shape.
	Point p(10, 20);								       // Create point.
	Line l(Point(1, 2), Point(3, 4));					   // Create line.

	cout << s.toString() << endl;				           // Print shape.
	cout << p.toString() << endl;						   // Print point.
	cout << l.toString() << endl;						   // Print line

	cout << "Shape ID: " << s.id() << endl;				   // ID of the shape.
	cout << "Point ID: " << p.id() << endl;				   // ID of the point.
	cout << "Line ID: " << l.id() << endl;				   // ID of the line.

	Shape* sp;											   // Create pointer to a shape variable.
	sp = &p;											   // Point in a shape variable.
	cout << sp->toString() << endl;						   
	cout << sp->Shape::toString() << endl;

	// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.id() << endl;			       // Is the ID copied if you do not call the base class assignment
														   // in point? No, without calling the base class assignment, only
														   // the data members of the derived class are copied, and the data
														   // member of the base class is assigned by the system.

	// Test the application again. Is now the ID printed when printing a point or line? Yes.
	sp = &l;
	cout << sp->toString() << endl;        // Line l ID along with its description printed
	sp = &p2;
	cout << sp->toString() << endl;        // Point p2 ID along with its description printed

	return 0;
}