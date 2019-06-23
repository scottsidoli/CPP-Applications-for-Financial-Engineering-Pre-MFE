// Exercise 2.4.4 - Friends
//
// by Scott Sidoli
//
// 5-10-19
//
// Main.cpp
// 
// Testing the friends functionality with global function Ostream operator.

#include "Point.hpp"
#include "Line.hpp"
#include <iostream>

int main()
{
	Point P1(1.0, -1.0);
	Point P2(4.0, 5.0);
	cout << P1.toString() << endl;
	cout << P1 << endl;

	Line l(P1, P2);
	cout << l.toString() << endl;
	cout << l << endl;
	return 0;
}