// Exercise 3.5.4 - Abstract Functions
//
// by Scott Sidoli
//
// 5-17-19
//
// Line.cpp
//
// Line Class.

#include <iostream>
#include <sstream>
#include "line.hpp"
#include <cmath>								

using namespace std;

namespace ssidoli
{
	namespace CAD
	{
		//===============================================================================================================

		Line::Line() : Shape(), starting_point(), ending_point()
		{
			//cout << "Default Constructor!" << endl;			// We initialize a line to have the starting point
		}														// and ending point both be the origin.

		Line::Line(const Line& l) : Shape(), starting_point(l.starting_point), ending_point(l.ending_point)	// Copy constructor with print statement
		{
			//cout << "Makin' copies!" << endl;
		}

		Line::Line(const Point& A, const Point& B) : Shape(), starting_point(A), ending_point(B)			// Constructor creates a line from initialized input.
		{
			//	cout << "I am a line constructor!" << endl;
		}

		Line::~Line()											// Destructor.
		{
			//	cout << "A line is destroyed!" << endl;
		}

		//===============================================================================================================

		Point Line::start() const								// Getter function for the starting point.
		{
			return starting_point;
		}

		Point Line::end() const									// Getter function for the ending point.
		{
			return ending_point;
		}

		//===============================================================================================================

		void Line::start(const Point& P1)							// Setter function for the starting point.
		{
			starting_point = P1;
		}

		void Line::end(const Point& P2)								// Setter function for the ending point.
		{
			ending_point = P2;
		}

		//===============================================================================================================

		std::string Line::toString() const							// String discription of the line using toString()
		{															// from point class.
			std::stringstream line_string;
			line_string << "Start: " << starting_point.toString() << "\n" << "End: " << ending_point.toString() << Shape::toString() << endl;
			return line_string.str();
		}

		//===============================================================================================================

		double Line::length() const									// Length of the line using the distance function from
		{															// the point class.
			return starting_point.distance(ending_point);
		}

		//===============================================================================================================

		Line& Line::operator = (const Line& l)						// Assignment Operator
		{
			if (this == &l)
				return *this;

			Shape::operator = (l);
			starting_point = l.starting_point;
			ending_point = l.ending_point;

			return *this;
		}

		//===============================================================================================================

		ostream& operator << (ostream& os, const Line& L)			// Ostream << Operator
		{
			// Returns toString output from line class directly to cout
			return os << L.toString() << "\n";
		}

		//===============================================================================================================

		void Line::Draw() const											// Pure virtual member function
		{
			cout << "Drawing a line" << endl;
		}
	}
}