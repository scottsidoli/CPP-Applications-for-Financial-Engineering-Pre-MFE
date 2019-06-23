// Exercise 2.3.3 - Function Overloading
//
// by Scott Sidoli
//
// 4-20-19
//
// Exercise233.hpp
// 
// Point Class. We adjust the names of getter, setter, and distance functions 
// to facilitate function overloading. For further exercise details see Main.cpp.

#ifndef Exercise233_HPP
#define Exercise233_HPP
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

	double x();								// Getter functions
	double y();								// We use function overloading.

	void x(double a);						// Setter functions
	void y(double b);						// We use function overloading.

	std::string toString();					// String description

	double distance();						// Member functions. distance() computes the distance
	double distance(const Point& P);		// between the point and the origin while distance() computes the  
};											// the distance between two points. distance() is call by reference.
											// We use function overloading.
#endif


