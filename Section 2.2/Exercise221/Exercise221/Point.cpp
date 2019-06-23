// Exercise 2.2.1 - Declarations for Point Class
//
// by Scott Sidoli
//
// 4-15-19
//
// Point.cpp
// The goal of this file is to declare our functions and set defaults. We initialize the 
// constructor and destructor. We also write the declaration of our getter and setter functions.
// Finally we write our toString() function.

// Preprocessor Directives
#include <iostream>
#include <sstream>
#include "Point.hpp"

using namespace std;

// Conditional Compilation
#ifndef Point_CPP
#define Point_CPP

Point::Point() : m_x(0), m_y(0)		// Default constructor initialized using colon syntax
{
	// We initialize the object to have x = y = 0. The default point.
}

Point::~Point()						// Destructor. Prints statement when called.
{
	cout << "Point Destroyed!";
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
	point_string << "Point(" << m_x << ", " << m_y << ")" << endl;
	return point_string.str();		// Retrieves string.
}

#endif