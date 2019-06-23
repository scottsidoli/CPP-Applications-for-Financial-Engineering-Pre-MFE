// Exercise 2.3.2 - Call By Reference
//
// by Scott Sidoli
//
// 4-20-19
//
// Exercise232.hpp
// 
// Point Class. We want have our distance function use call by reference.
// We expect to see that our copy constructor is called a fewer number
// of times. For further exercise details see Main.cpp.

#ifndef Exercise232_HPP
#define Exercise232_HPP
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

	double get_x();							// Getter functions
	double get_y();

	void set_x(double a);					// Setter functions
	void set_y(double b);

	std::string toString();					// String description

	double distance_origin();				// Member functions. distance_origin() computes the distance
	double distance(const Point& P);		// between the point and the origin while distance() computes the  
};											// the distance between two points. distance() is now call by reference.

#endif

