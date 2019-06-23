// Exercise 3.5.4 - Abstract Functions
//
// by Scott Sidoli
//
// 5-17-19
//
// line.hpp
//
// Line Class.

#ifndef line_HPP
#define line_HPP

#include "Point.hpp"

namespace ssidoli
{
	namespace CAD
	{
		class Line;

		// Global function outside of class for OStream << opertor
		ostream& operator << (ostream& os, const Line& L);
	}
}

class ssidoli::CAD::Line : public Shape
{
private:
	Point starting_point;				// Member data consists of the starting point
	Point ending_point;					// and ending point of the line.

public:
	Line();												// Constructor
	Line(const Line& l);								// Copy Constructor
	Line(const Point& A, const Point& B);				// Constructor for line that goes from A to B
	~Line();											// Destructor

	Point start() const;				// Getter function for the starting point (overloaded)
	Point end() const;					// Getter functions for the ending point (overloaded)


	void start(const Point& P1);				// Setter function for the starting point (overloaded)
	void end(const Point& P1);					// Setter function for the ending point (overloaded)

	std::string toString() const;		// String description of the line.

	double length() const;				// Uses distance formula to determine the length of
										// the line.

	Line& operator = (const Line& source);		// Assignment Operator

	void Draw() const;					// Pure, virtual, member function
};

#endif
