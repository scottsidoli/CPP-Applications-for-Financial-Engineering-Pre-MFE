// Exercise 2.4.2 - Ostream << Operator
//
// by Scott Sidoli
//
// 5-5-19
//
// main.cpp
// 
// The goal of this file is to test the Ostream << Operator.
// We test this for the point, line, and circle class.


#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

int main()
{
	// Test Ostream << operator for point class
	Point A(-4, 10);
	cout << A.toString() << endl;   // Using toString to print
	cout << A << endl;              // Using Ostream << operator to print


	// Test Ostream << operator for class Line
	Point B(3, -2);
	Line line(A, B);
	cout << line.toString() << endl; // Using toString to print
	cout << line << endl;            // Use Ostream << operator to print


	// Test Ostream << operator for class Circle
	double rad = 4.0;
	Circle C_one(B, rad);
	cout << C_one.toString() << endl;    // Use toString to print
	cout << C_one << endl;               // Use Ostream << operator to print

	return 0;
}