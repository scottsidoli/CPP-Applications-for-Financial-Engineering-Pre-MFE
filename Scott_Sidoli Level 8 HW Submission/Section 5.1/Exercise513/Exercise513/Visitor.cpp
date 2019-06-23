#include "Visitor.hpp"
using namespace ssidoli::CAD;

Visitor::Visitor() : boost::static_visitor<void>()
{	// Default Constructor
	m_dx = 0.0;
	m_dy = 0.0;
}

Visitor::Visitor(const Visitor& source) : boost::static_visitor<void>(source)
{	// Copy Constructor
	m_dx = source.m_dx;
	m_dy = source.m_dy;
}

Visitor::Visitor(double xval, double yval) : boost::static_visitor<void>()
{	// Constructor with x and y offsets
	m_dx = xval;
	m_dy = yval;
}

Visitor::~Visitor()
{	//Destructor

}

Visitor& Visitor::operator = (const Visitor& source)
{	// Assignment Operator
	if (this == &source)
	{
		return *this;
	}

	Visitor::operator = (source);

	m_dx = source.m_dx;
	m_dy = source.m_dy;

	return *this;
}

void Visitor::operator () (Point& p) const
{	// () operator for point
	p.x(p.x() + m_dx);
	p.y(p.y() + m_dy);
}

void Visitor::operator () (Line& l) const
{	// () operator for line
	Point p1 = l.start();
	Point p2 = l.end();

	p1.x(p1.x() + m_dx);
	p1.y(p1.y() + m_dy);
	p2.x(p2.x() + m_dx);
	p2.y(p2.y() + m_dy);

	l.start(p1);
	l.start(p2);
}

void Visitor::operator () (Circle& c) const
{	// () operator for circle
	Point center = c.center();
	center.x(center.x() + m_dx);
	center.y(center.y() + m_dy);

	c.center(center);
}