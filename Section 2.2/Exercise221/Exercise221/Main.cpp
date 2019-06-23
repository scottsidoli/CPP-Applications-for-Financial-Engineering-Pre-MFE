// Exercise 2.2.1 - Test Point
//
// by Scott Sidoli
//
// 4-15-19
//
// Main.cpp
// The goal here is to write a test program to test our point class. We take user inputs for the 
// x and y coordinates of the point. We then create a point object and set the coordinates using
// the set_x() and set_y() functions. We then use the toString() function to print a verbal 
// description of the point. Finally, we print the x and y coordinates using the get_x() and get_y()
// functions.

// Preprocessor Directives
#include <iostream>
#include "Point.hpp"

using namespace std;

int main()
{
	double m_x, m_y;				// Declare the x and y coordinate variables

	std::cout << "Tell me the x- and y-coordinates of the point (x, y)!" << endl;
	std::cin >> m_x >> m_y;			// User prompt and input

	Point pt;						// Constructor creates point

	pt.set_x(m_x);					// We set the coordinates to the user inputs.
	pt.set_y(m_y);

	cout << pt.toString() << endl;	// Print the description of point pt using toString().

	std::cout << "The x-coordinate is " << pt.get_x() << endl;	// Print coordinates using get_x()
	std::cout << "The y-coordinate is " << pt.get_y() << endl;	// and get_y().

	return 0;
}