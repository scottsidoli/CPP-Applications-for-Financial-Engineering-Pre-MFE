// Exercise 2.3.1 - Extra Constructors
//
// by Scott Sidoli
//
// 4-19-19
//
// Exercise231.hpp
// 
// Point Class. We have added two constructors. One is a copy constructor
// and the other is a constructor that facilitates object creation and 
// allows the user to set the member data without calling the set function.
// For further exercise details see Main.cpp.

#ifndef Point_Class_with_Distance_HPP
#define Point_Class_with_Distance_HPP
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
	double distance(Point P);				// between the point and the origin while distance() computes the  
};											// the distance between two points.

#endif

