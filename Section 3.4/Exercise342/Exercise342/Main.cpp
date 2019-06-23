// Exercise 3.4.2 - Creating a Shape Base Class
//
// by Scott Sidoli
//
// 5-15-19
//
// Main.cpp
//
// In this exercise, we build a base class Shape for derived classes Point, Line, and Circle.
// We test the functionality.

#include <iostream>
#include "Line.hpp"

using namespace ssidoli::CAD;

int main()
{
	Shape s;										// Create shape. 
	Point p(10, 20);								// Create point. 
	Line l(Point(1,2), Point(3, 4));				// Create line. 
	
	cout<<s.toString()<<endl;						// Print shape. 
	cout<<p.toString()<<endl;						// Print point. 
	cout<<l.toString()<<endl;						// Print line 
	
	cout<<"Shape ID: "<<s.id()<<endl;				// ID of the shape. 
	cout<<"Point ID: "<<p.id()<<endl;				// ID of the point. Yes this works. 
	cout<<"Line ID: "<<l.id()<<endl;				// ID of the line. Yes this works. 
													// These are instances of a derived class and as such have functionality
													// inherited from the base class.
	
	Shape* sp;										// Create pointer to a shape variable. 
	sp=&p;											// Pointer to a shape variable. Possible? Yes.
	cout<<sp->toString()<<endl;						// What is printed? The system prints the ID of point p
													// The base class pointer points to a derived object (p).
													// This pointer will only have access to base class functionality.
	
	// Create and copy Point p to new point. 
	Point p2;
	p2=p; 
	cout<<p2<<"p2 ID: "<<p2.id()<<endl;				// Is the ID copied if you do not call 
													// the base class assignment in point? No. A different ID number is assigned
													// by the system. Only the data from the derived class is copied. Nothing from
													// the base class is copied.
	return 0;
}