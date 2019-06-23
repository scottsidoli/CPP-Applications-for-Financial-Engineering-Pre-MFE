// Exercise 2.4.1 - Operator Overloading
//
// by Scott Sidoli
//
// 5-5-19
//
// Main.cpp
//
// Testing operator functionality. We start with "-", "+", and "=". 
// Next we test "*" and " *= ". Then the boolean operator ==. We check
// The assignment operators in the circle and line classes and finally,
// we check that we can chain *, and *=.

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace std;

int main()
{
	// Test -, +, and assignment
	Point A(2, 3);
	cout << "A is " << A.toString() << endl;
	Point B(-4, 2);
	cout << "B is " << B.toString() << endl;
	B = A + (-B);
	cout << "Now B = A + (-B) = " << B.toString() << endl;


	// Test * and *=
	double factor = 2;
	A = A * factor;
	cout << "2 * A = " << A.toString() << endl;
	A *= 2;
	cout << "And 2 * (2 * A) = " << A.toString() << endl;

	// Test ==
	cout << ((A == B) ? "A equals B" : "A does not equal B") << endl;

	// Assignment operators for the line and circle classes
	Line L1 = Line(A, B);
	cout << "Line L1 is " << L1.toString() << endl;
	Line L2 = L1;
	cout << "line L2 is " << L2.toString() << endl;
	cout << endl;

	Circle circle_one = Circle(A, factor);
	cout << "circle_one is " << circle_one.toString() << endl;
	Circle circle_two = circle_one;
	cout << "Setting circle_two = circle_one, we have circle_two is " << circle_two.toString() << endl;

	// Chained Operators
	Point C;
	C = A *= 3;
	cout << "Point C = A *= 3 yields " << C.toString() << endl;
	
	return 0;
}