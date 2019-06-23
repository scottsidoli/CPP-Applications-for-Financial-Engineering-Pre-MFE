// Exercise 2.3.7 - Inline Functions
//
// by Scott Sidoli
//
// 4-28-19
//
// Point.cpp
// 
// Point Class with inline functions. Notice that declarations of our inline
// functions are not in this source file, but are rather in the header.

#include <iostream>
#include <sstream>
#include "Point.hpp"
#include <cmath>								

using namespace std;


Point::Point() : m_x(0), m_y(0)
{
	//cout << "A point is born!" << endl; // We initialize the object to have x = y = 0. The default point.
}

Point::Point(const Point& pt)			// Copy Constructor with print statement. Const makes it so the member
{										// data of the input point is unaltered. 
	m_x = pt.m_x;
	m_y = pt.m_y;
	//	cout << "Makin' Copies!" << endl;
}

Point::Point(double xval, double yval) // Constructor creates an instance without using set functions. We can
{									   // create the objects using the user input for the member data. Here
	m_x = xval;						   // we also include a print statement.
	m_y = yval;
	//	cout << "I am a constructor!" << endl;
}

Point::~Point()						// Destructor. Prints statement when called.
{
	//	cout << "A point is destroyed!" << endl;
}

std::string Point::toString() const		// String description function.
{
	std::stringstream point_string;
	point_string << "Point(" << m_x << ", " << m_y << ")" << endl;
	return point_string.str();		// Retrieves string.
}

double Point::distance() const		// Finds distance from the point to the origin using Pythagorean Theorem (overloaded)
{
	return std::sqrt(m_x*m_x + m_y * m_y);
}

double Point::distance(const Point& p) const		// Finds distance from the point to the point p using Pythagorean Theorem (overloaded)
{
	return std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
}