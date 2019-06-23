// Exercise 2.2.1 - The Point Class
//
// by Scott Sidoli
//
// 4-15-19
//
// Point.hpp
// The goal of this exercise is to create the class "Point" whose objects are 2-dimensional
// points in the (x,y)-plane. 

// Preprocessor directives to prevent multiple inclusions.
#ifndef Point_HPP
#define Point_HPP
#include <string>

using namespace std;

// Class initialization
class Point
{
private:
	double m_x;								// Data members, the x- and y- coordinates of the point.
	double m_y;

public:
	Point();								// Constructor and Destructor.
	~Point();

// Member functions
	double get_x();							// Gets the x-coordinate.
	double get_y();							// Gets the y-coordinate.

	void set_x(double a);					// Sets the x-coordinate as a.
	void set_y(double b);					// Sets the y-coordinate as b.
	
	std::string toString();					// Gives a description of the point as a string.
};

#endif