// Exercise 2.3.5 - Line Class
//
// by Scott Sidoli
//
// 4-20-19
//
// Line.hpp
// 
// Line Class. Member data includes a starting point and an ending point. We include 
// a default constructor, a copy constructor, and a constructor that sets the starting
// point and ending point. We have a destructor. We have overloaded getter and setter
// functions. We have a toString() function which prints a description of the line
// and we have a length function which uses the distance formula from the point class
// to determine the length of the line.

#ifndef Line_HPP
#define Line_HPP
#include "Point.hpp"

using namespace std;

class Line
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
};

#endif
