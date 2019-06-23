// Exercise 2.6.1 - Namespaces
//
// by Scott Sidoli
//
// 5-12-19
//
// Point.hpp
// 
// Point Class.

#ifndef Point_HPP
#define Point_HPP

#include <string>

using namespace std;

namespace ssidoli
{
	namespace CAD
	{
		class Point;
	}
}

class ssidoli::CAD::Point
{
private:
	double m_x;								// Member data
	double m_y;

public:
	Point();								// Constructor
	Point(const Point& pt);					// Copy constructor
	explicit Point(const double value);		// "One double" constructor
	Point(double xval, double yval);		// User input constructor
	~Point();								// Destructor

	double x() const;						// Getter functions
	double y() const;

	void x(double a);						// Setter functions
	void y(double b);

	std::string toString() const;			// String description 

	double distance() const;				// Member functions. distance() computes the distance
	double distance(const Point& P) const;	// between the point and the origin while distance() computes the  
											// the distance between two points.

	Point& operator = (const Point& source);// Assignment operator
	Point operator * (double factor) const;	// Scale the coordinates
	Point operator - () const;				// Negates coordinates
	Point operator + (const Point& P) const;// Add coordinates
	bool operator == (const Point& p) const;// Compares point coordinates
	Point& operator *= (double factor);		// Scale the coordinates and make assignment

	// Global function declared as friend to now access member data
	friend ostream& operator << (ostream& os, const Point& P);
};

#endif