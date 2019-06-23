// Exercise 2.3.1 - Copy Constructors
//
// by Scott Sidoli
//
// 4-20-19
//
// Exercise231.cpp
//
// Declarations. See Main.cpp for details about program goals and descriptions.

#include <iostream>
#include <sstream>
#include "Exercise231.hpp"
#include <cmath>								// For the square root function.

using namespace std;

// Conditional Compilation
#ifndef Exercise231_CPP
#define Exercise231_CPP

Point::Point() : m_x(0), m_y(0)
{
	cout << "A point is born!" << endl; // We initialize the object to have x = y = 0. The default point.
}

Point::Point(const Point& pt)			// Copy Constructor with print statement. Const makes it so the member
{										// data of the input point is unaltered. 
	m_x = pt.m_x;
	m_y = pt.m_y;
	cout << "Makin' Copies!" << endl;
}

Point::Point(double xval, double yval) // Constructor creates an instance without using set functions. We can
{									   // create the objects using the user input for the member data. Here
	m_x = xval;						   // we also include a print statement.
	m_y = yval;
	cout << "I am a constructor!" << endl;
}

Point::~Point()						// Destructor. Prints statement when called.
{
	cout << "A point is destroyed!" << endl;
}

double Point::get_x()				// Getter functions.
{
	return m_x;
}

double Point::get_y()
{
	return m_y;
}

void Point::set_x(double newX)		// Setter functions.
{
	m_x = newX;
}

void Point::set_y(double newY)
{
	m_y = newY;
}

std::string Point::toString()		// String description function.
{
	std::stringstream point_string;
	point_string << "A(" << m_x << ", " << m_y << ")" << endl;
	return point_string.str();		// Retrieves string.
}

double Point::distance_origin()		// Finds distance from the point to the origin using Pythagorean Theorem
{
	return std::sqrt(m_x*m_x + m_y * m_y);
}

double Point::distance(Point p)		// Finds distance from the point to the point p using Pythagorean Theorem
{
	return std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
}

#endif