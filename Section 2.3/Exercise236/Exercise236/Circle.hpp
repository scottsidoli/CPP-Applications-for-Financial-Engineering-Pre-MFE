// Exercise 2.3.6 - Circle Class
//
// by Scott Sidoli
//
// 4-26-19
//
// Circle.hpp
//
// The goal of this file is to declare our private member data and public member functions
// the circle class. Here we declare the constructors, destructors, getter functions, setter
// functions, diameter, area, circumference, and toString(). We use const and call by
// reference when appropriate.


// Conditional Compilation
#ifndef Circle_HPP
#define Circle_HPP

#include "Point.hpp"			// Point class for the center point

using namespace std;

class Circle
{
private:						// center and radius
	Point c;
	double r;

public:
	Circle();							// Constructors
	Circle(const Circle& circ);
	Circle(const Point& center, const double& radius);

	~Circle();							// Destructor

	Point center() const;				// getter functions
	double radius() const;

	void center(const Point& C);		// setter functions
	void radius(const double& r);

	std::string toString() const;		// toString function

	double diameter() const;			// Circle attribute functions
	double area() const;
	double circumference() const;
};

#endif
