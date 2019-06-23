// Exercise 2.2.2 - Add Distance
//
// by Scott Sidoli
//
// 4-15-19
//
// Point_Class_with_Distance.hpp
// The goal of this exercise is to extend the class "Point" whose objects are 2-dimensional
// points in the (x,y)-plane to have functions the give the distance from the origin to the
// point and the distance between two points. We remove comments that were seen in the previous
// exercise for clarification.

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
	Point();								// Constructor and Destructor
	~Point();

	double get_x();							// Getter functions
	double get_y();							

	void set_x(double a);					// Setter functions
	void set_y(double b);					

	std::string toString();					// String description

	double distance_origin();				// New member functions. distance_origin() computes the distance
	double distance(Point P);				// between the point and the origin while distance computes the  
};											// the distance between two points.

#endif
