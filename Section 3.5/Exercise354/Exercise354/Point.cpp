// Exercise 3.5.4 - Abstract Functions
//
// by Scott Sidoli
//
// 5-17-19
//
// Point.cpp
// 
// Point Class.

#include <iostream>
#include <sstream>
#include "Point.hpp"
#include <cmath>								


namespace ssidoli
{
	namespace CAD
	{
		//=============================================================================================================
		// Constructors and Destructors
		Point::Point() : Shape(), m_x(0), m_y(0)
		{
			//cout << "Default Point Constructor" << endl;
		}

		Point::Point(const Point& pt) : Shape(pt), m_x(pt.m_x), m_y(pt.m_y)
		{
			//	cout << "Point Copy Constructor" << endl;
		}

		Point::Point(const double value) : Shape(), m_x(value), m_y(value)
		{
			// cout << "\"One double\" Constructor" << endl;
		}

		Point::Point(double xval, double yval) : Shape(), m_x(xval), m_y(yval)
		{
			//	cout << "Point Constructor That Sets Coordinates" << endl;
		}

		Point::~Point()						// Destructor. Prints statement when called.
		{
			//	cout << "A point is destroyed!" << endl;
		}

		//============================================================================================================


		double Point::x() const			// Overloaded getter functions.
		{
			return m_x;
		}

		double Point::y() const
		{
			return m_y;
		}

		void Point::x(double newX)		// Overloaded setter functions.
		{
			m_x = newX;
		}

		void Point::y(double newY)
		{
			m_y = newY;
		}

		//==============================================================================================================
		// String Description

		std::string Point::toString() const		// String description function.
		{
			std::stringstream point_string;
			point_string << "Point(" << m_x << ", " << m_y << ") " << Shape::toString() << endl;

			//cout << "toString of Point" << endl;

			return point_string.str();		// Retrieves string.
		}

		//==============================================================================================================
		// Distance Functions

		double Point::distance() const		// Finds distance from the point to the origin using Pythagorean Theorem (overloaded)
		{
			return std::sqrt(m_x*m_x + m_y * m_y);
		}

		double Point::distance(const Point& p) const		// Finds distance from the point to the point p using Pythagorean Theorem (overloaded)
		{
			return std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
		}

		//=================================================================================================================
		// Operator Overloading

		Point Point::operator - () const				// Negation operator
		{
			return Point(-m_x, -m_y);
		}

		Point Point::operator * (double factor) const	// Coordinate Scaling
		{
			return Point(factor * m_x, factor * m_y);
		}

		Point Point::operator + (const Point& P) const	// Adding coordinates
		{
			return Point(m_x + P.m_x, m_y + P.m_y);
		}

		bool Point::operator == (const Point& P) const  // Comparing coordinates
		{
			return m_x == P.m_x && m_y == P.m_y;
		}

		Point& Point::operator = (const Point& source)	// Assignment Operator
		{
			if (this == &source)
				return *this;

			Shape::operator = (source);					// Calls base class assignment operator

			m_x = source.m_x;
			m_y = source.m_y;

			return *this;
		}

		Point& Point::operator *= (double factor)
		{
			m_x *= factor;
			m_y *= factor;

			return *this;
		}

		//=================================================================================================================
		// Ostream << Operator

		ostream& operator << (ostream& os, const Point& P)
		{
			// Returns the toString output from the point class directly to cout.
			return os << P.toString() << "\n";
		}

		//=================================================================================================================
		// Pure, virtual, member function

		void Point::Draw() const
		{
			cout << "Drawing a point" << endl;
		}
	}
}