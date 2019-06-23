#ifndef Visitor_hpp
#define Visitor_hpp

#include <boost\variant\static_visitor.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
using namespace ssidoli::CAD;

class Visitor : public boost::static_visitor<void>
{
private:
	double m_dx;					// offset of the x-coordinate
	double m_dy;					// offset of the y-coordinate
public:
	Visitor();						// Default constructor
	Visitor(const Visitor& source);	// Copy Constructor
	Visitor(double xval, double yval);	// Constructor that sets the offsets
	~Visitor();						// Destructor

	// Member functions
	Visitor& operator = (const Visitor& source);		// Assignment operator
	void operator () (Point& p) const;					// () operator for point
	void operator () (Line& l) const;					// () operator for line
	void operator () (Circle& c) const;					// () operator for circle
};

#endif