// Exercise 2.3.6 - Circle Class
//
// by Scott Sidoli
//
// 4-26-19
//
// Circle.cpp
//
// The goal of this file is to define our member functions in the circle class.
// Here we define the constructors, destructors, getter functions, setter functions,
// diameter, area, circumference, and toString(). We have print statements in our 
// constructors, but to make the test program output more readible, we have commented
// out the print statements for submission. We use _USE_MATH_DEFINES to access a value
// for pi (M_PI). We use const and call by reference when appropriate.

#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
#include "Point.hpp"
#include "circle.hpp"

#include <cmath>	


using namespace std;

#ifndef Circle_CPP
#define Circle_CPP

Circle::Circle() : c(0, 0), r(0)				// Default Constructor with colon syntax
{
//	cout << "Default Constructor" << endl;
}

Circle::Circle(const Circle& circ)				// Copy Constructor
{
	c = circ.center();
	r = circ.radius();
//	cout << "Copy Constructor" << endl;
}

Circle::Circle(const Point& center, const double& radius)	// Initialized Constructor
{
	c = center;
	r = radius;
//	cout << "User Constructor" << endl;
}

Circle::~Circle()							// Destructor
{
//	cout << "Destructor" << endl;
}

Point Circle::center() const				// getter functions
{
	return c;
}

double Circle::radius() const
{
	return r;
}

void Circle::center(const Point& C)			// setter functions
{
	c = C;
}

void Circle::radius(const double& R)
{
	r = R;
}

double Circle::diameter() const				// Diameter
{
	return 2 * r;
}

double Circle::area() const					// Area
{
	return M_PI * r * r;
}

double Circle::circumference() const		// Circumference
{
	return 2 * M_PI * r;
}

string Circle::toString() const				// toString() function for string description of
{											// the circle.
	stringstream circlestring;
	circlestring << "The center point is (" << c.x() << ", " << c.y() << ") and the radius is " << r << endl;
	return circlestring.str();
}


#endif
