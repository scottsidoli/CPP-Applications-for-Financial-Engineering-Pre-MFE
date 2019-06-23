// Exercise 3.5.1 - Polymorphic toString() Function
//
// by Scott Sidoli
//
// 5-15-19
//
// Main.cpp
//
// In this exercise, we notice that when a base class pointer that holds an instance of 
// a derived class, the toString() function is called from the base class. When we declare
// the toString() function in the base class as virtual, it knows that the object held in 
// pointer is from a derived class and calls the toString() function from the derived class.

#include "Line.hpp"
#include <iostream>

using namespace ssidoli::CAD;

int main()
{
	Shape s;									// Create shape.
	Point p(10, 20);							// Create point.
	Line l(Point(1.0, 2.0), Point(3.0, 4.0));   // Create line.

	cout << s.toString() << endl;			// Print shape.
	cout << p.toString() << endl;			// Print point.
	cout << l.toString() << endl;			// Print line

	cout << "Shape ID: " << s.id() << endl;	// ID of the shape.
	cout << "Point ID: " << p.id() << endl;	// ID of the point. Yes, this works.
	cout << "Line ID: " << l.id() << endl;	// ID of the line. Yes, this works.
											// Both work because they are both instances of derived class and we
											// are using base functionality.

	Shape* sp;								// Create pointer to a shape variable.
	sp = &p;								// Point in a shape variable. Possible? Yes.
	cout << sp->toString() << endl;         // What is printed? Point(10,20)
	cout << sp->Shape::toString() << endl;  /* ID of Point p is printed. When we add a print statement
											to the point toString() function we can tell that we are using the
											toString() function from Point.*/

											// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.id() << endl;  // Is the ID copied if you do not call the base class assignment
											// in point? No, without calling the base class assignment, only
											// the data members of the derived class are copied, and the data
											// member of the base class is assigned by the system.

	return 0;
}