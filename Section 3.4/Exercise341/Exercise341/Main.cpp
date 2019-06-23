// Exercise 3.4.1 - Colon Syntax
//
// by Scott Sidoli
//
// 5-15-19
//
// Main.cpp
// 
// In this exercise, we test colon syntax and its effect on constructor performance. We run the test code
// line L; and find that without the colon syntax, the default point constructor and point destructor are
// each called four times. The default line constructor is called once and the line destructor is also
// called once. The assignment operator is called twice. Once we introduce the colon syntax, the default point
// constructor is called twice, the point destructor is called twice, the line constructor is called once
// and the line destructor is called once. The assignment operator is not called. Colon syntax was applied to 
// the point class and circle class, as well.

#include <iostream>
#include "Line.hpp"

using namespace ssidoli::CAD;

int main()
{
	Line L1;									// Point default constructor is called 2 times and default line constructor called once
	Line L2 = L1;								// Point copy constructor is called 2 times and line copy constructor called once
	Line L3(Point(1.0, 2.0), Point(3.0, 4.0));	// Point constructor with coordinates is called 2 times and line constructor is called once
												// Point copy constructor is called 2 times and line constructor with set points is called once
	L3 = L2;									// Point assignment operator is called 2 times and line assignment operator is called 
												// Point destructor is called 8 times: l1, l2, l3, Point(1.0,2.0), Point(3.0,4.0)
	return 0;
}