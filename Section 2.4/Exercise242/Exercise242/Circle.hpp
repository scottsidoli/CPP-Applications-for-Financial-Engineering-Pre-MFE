// Exercise 2.4.2 - Ostream << Operator
//
// by Scott Sidoli
//
// 5-5-19
//
// Circle.hpp
//
// Circle Class with Ostream << Operator.

#ifndef Circle_HPP
#define Circle_HPP

#include "Point.hpp"			// Point class

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

	Circle& operator = (const Circle& circ);	// Assignment Operator
};

// Global function outside of class for OStream << opertor
ostream& operator << (ostream& os, const Circle& circ);

#endif
