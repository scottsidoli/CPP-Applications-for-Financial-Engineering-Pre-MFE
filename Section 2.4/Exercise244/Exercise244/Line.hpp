// Exercise 2.4.4 - Friends
//
// by Scott Sidoli
//
// 5-10-19
//
// Line.hpp
// 
// Line Class with Friends Ostream operator. 

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


	void start(const Point& P1);		// Setter function for the starting point (overloaded)
	void end(const Point& P1);			// Setter function for the ending point (overloaded)

	std::string toString() const;		// String description of the line.

	double length() const;				// Uses distance formula to determine the length of
										// the line.

	Line& operator = (const Line& source);		// Assignment Operator

	// Global function declared as friend can now access member data
	friend ostream& operator << (ostream& os, const Line& L);
};

#endif
