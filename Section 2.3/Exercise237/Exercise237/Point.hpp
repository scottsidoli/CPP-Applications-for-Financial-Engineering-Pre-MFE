// Exercise 2.3.7 - Inline Functions
//
// by Scott Sidoli
//
// 4-28-19
//
// Point.hpp
// 
// Point Class with inline functions.

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

	inline double x() const
	{
		return m_x;
	}									// Getter functions **Normal Inline**
	inline double y() const
	{
		return m_y;
	}
	void x(double a)
	{
		m_x = a;
	}									// Setter functions **default inline**
	
	void y(double b)
	{
		m_y = b;
	}

	std::string toString() const;			// String description 

	double distance() const;				// Member functions. distance() computes the distance
	double distance(const Point& P) const;	// between the point and the origin while distance() computes the  
};											// the distance between two points.

#endif
