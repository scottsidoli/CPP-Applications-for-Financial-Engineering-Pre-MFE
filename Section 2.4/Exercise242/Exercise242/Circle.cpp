// Exercise 2.4.2 - Ostream << Operator
//
// by Scott Sidoli
//
// 5-5-19
//
// Circle.cpp
//
// Function declarations for the Circle Class with Ostream << Operator.

#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
#include "Circle.hpp"
#include <cmath>	


using namespace std;


Circle::Circle() : c(), r(0)				// Default Constructor with colon syntax
{
	//	cout << "Default Circle Constructor" << endl;
}

Circle::Circle(const Circle& circ) : c(circ.c), r(circ.r)			// Copy Constructor
{
	//	cout << "Copy Circle Constructor" << endl;
}

Circle::Circle(const Point& center, const double& radius)	// Initialized Constructor
{
	c = center;
	r = radius;
	//	cout << "User Circle Constructor" << endl;
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
	circlestring << "center (" << c.x() << ", " << c.y() << ") and radius " << r << endl;
	return circlestring.str();
}

Circle& Circle::operator = (const Circle& circ)		// Assignment Operator
{
	if (this == &circ)
		return *this;

	c = circ.c;
	r = circ.r;

	return *this;
}

ostream& operator << (ostream& os, const Circle& circ)
{
	// return toString output of the circle class directly to cout
	return os << circ.toString() << "\n";
}