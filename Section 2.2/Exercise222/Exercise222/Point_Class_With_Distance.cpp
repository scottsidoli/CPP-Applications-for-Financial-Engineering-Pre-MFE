// Exercise 2.2.2 - Distance Declarations for Point Class
//
// by Scott Sidoli
//
// 4-15-19
//
// Point_Class_With_Distance.cpp
// The goal of this file is to declare our distance functions. 


#include <iostream>
#include <sstream>
#include "Point_Class_with_Distance.hpp"
#include <cmath>								// For the square root function.

using namespace std;

// Conditional Compilation
#ifndef Point_Class_With_Distance_CPP
#define Point_Class_With_Distance_CPP

Point::Point() : m_x(0), m_y(0)		
{
	// We initialize the object to have x = y = 0. The default point.
}

Point::~Point()						// Destructor.
{
	// The point is deleted.
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
	return std::sqrt(m_x*m_x + m_y*m_y) ;
}

double Point::distance(Point p)		// Finds distance from the point to the point p using Pythagorean Theorem
{
	return std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
}

#endif