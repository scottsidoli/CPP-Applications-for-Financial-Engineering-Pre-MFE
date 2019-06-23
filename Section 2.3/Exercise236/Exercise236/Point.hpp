// Exercise 2.3.6 - Circle Class
//
// by Scott Sidoli
//
// 4-26-19
//
// Point.hpp
// 
// Point Class.

#ifndef Point_HPP
#define Point_HPP
#include <string>

using namespace std;

class Point
{
private:
	double m_x;								// Member data
	double m_y;

public:
	Point();								// Constructor
	Point(const Point& pt);					// Copy constructor
	Point(double xval, double yval);		// User input constructor
	~Point();								// Destructor

	double x() const;						// Getter functions
	double y() const;

	void x(double a);						// Setter functions
	void y(double b);

	std::string toString() const;			// String description 

	double distance() const;				// Member functions. distance() computes the distance
	double distance(const Point& P) const;	// between the point and the origin while distance() computes the  
};											// the distance between two points.

#endif