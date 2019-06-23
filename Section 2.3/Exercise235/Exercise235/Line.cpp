// Exercise 2.3.5 - Line Class
//
// by Scott Sidoli
//
// 4-20-19
//
// Line.cpp
// 
// The goal of the file is to define the functions declared in line.hpp.
// We define the constructors, destructor, getter functions, setter functions,
// toString(), and the length function. Constructors and destructor have
// print statements that have been commented out.

#include <iostream>
#include <sstream>
#include "Point.hpp"
#include "Line.hpp"
#include <cmath>								

using namespace std;

#ifndef Line_CPP
#define Line_CPP

Line::Line() : starting_point(0, 0), ending_point(0, 0)
{
	//cout << "Default Constructor!" << endl;					// We initialize a line to have the starting point
}														// and ending point both be the origin.

Line::Line(const Line& l): starting_point(l.starting_point), ending_point(l.ending_point)							// Copy constructor with print statement
{
		cout << "Makin' copies!" << endl;
}

Line::Line(const Point& A, const Point& B)				// Constructor creates a line from initialized input.
{
	starting_point = A;
	ending_point = B;
//	cout << "I am a line constructor!" << endl;
}

Line::~Line()											// Destructor.
{
//	cout << "A line is destroyed!" << endl;
}

Point Line::start() const								// Getter function for the starting point.
{
	return starting_point;
}

Point Line::end() const									// Getter function for the ending point.
{
	return ending_point;
}

void Line::start(const Point& P1)							// Setter function for the starting point.
{
	starting_point = P1;
}

void Line::end(const Point& P2)								// Setter function for the ending point.
{
	ending_point = P2;
}

std::string Line::toString() const							// String discription of the line using toString()
{															// from point class.
	std::stringstream line_string;
	line_string << "Start: " << starting_point.toString() << "\n" << "End: " << ending_point.toString() << endl;
	return line_string.str();
}

double Line::length() const									// Length of the line using the distance function from
{															// the point class.
	return starting_point.distance(ending_point);
}
#endif