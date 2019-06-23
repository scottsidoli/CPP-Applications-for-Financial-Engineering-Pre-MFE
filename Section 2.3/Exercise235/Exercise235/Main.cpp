// Exercise 2.3.5. - Line Class
//
// by Scott Sidoli
//
// 4-20-19
//
// Main.cpp
//
// The goal of this exercise is to create the line class. This file is to test this class.
// We take user input for the starting point and ending point of the line. There are print
// statements in the constructors, but since having constructors prints statements does not
// appear in the scope of the exercise, we comment them out.

#include <iostream>
#include "Line.hpp"

#include "Point.hpp"


int main()
{
	double x1, y1;
	double x2, y2;

	Point P1;
	Point P2;

	P1.x(0);
	P1.y(1);

	P2.x(4);
	P2.y(0);

	Line l1;							// User prompt for the starting point and ending point.
	Line l2(P1, P2);

	cout << "We need a starting point. Tell me the x- and y- coordinates!" << endl;
	cin >> x1 >> y1;

	cout << "We need an ending point. Tell me the x- and y- coordinates!" << endl;
	cin >> x2 >> y2;

	Point A(x1, y1);					// Starting point and ending point of the line
	Point B(x2, y2);

	l1.start(A);						// setter functions
	l1.end(B);

	Line l3 = l2;

	cout << "The starting point is " << (l1.start()).toString() << endl;			// getter functions
	cout << "The ending point is " << (l1.end()).toString() << endl;
	cout << "The description of the line:" << endl << l1.toString() << endl;		// toString()
	cout << "The length of the line is " << l1.length() << endl;					// Length()
	return 0;
}
