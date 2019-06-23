// Exercise 3.5.5 - Template Method Pattern
//
// by Scott Sidoli
//
// 5-17-19
//
// Main.cpp
//
// In this exercise, we add the member function Print() to the shape class. In its
// implementation, we send the toString() output to cout. We create a point object 
// and a line object and call Print() on these objects. We notice that the print
// function is able to call the correct toString() method for each object. This is
// because the toString() function in shape was declared virtual. We find that it 
// does print the correct information.

#include "Line.hpp"
#include <iostream>
using namespace ssidoli::CAD;

int main()
{
	Point p(1.0, 2.0);
	Line l(Point(3.0, 4.0), Point(5.0, 6.0));

	p.Print();
	l.Print();
	
	return 0;
}