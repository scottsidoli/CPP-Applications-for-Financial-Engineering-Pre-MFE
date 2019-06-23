// Exercise 2.2.2 - Distance Test
//
// by Scott Sidoli
//
// 4-15-19
//
// Main.cpp
// The goal here is to write a test program to test our distance functions in out point class. We
// take user inputs for the x and y coordinates of the point. We create a point A and set the coordinates
// the set_x() and set_y() functions. We then create a point B, again taking user input. We then use the 
// toString() function to print a verbal description of the point. We print the x and y coordinates using
// the get_x() and get_y() functions. Finally we determine the distance from the point pt to the origin and
// we determine the distance from pt to pt2.

// Preprocessor Directives
#include <iostream>
#include "Point_Class_with_Distance.hpp"

using namespace std;

int main()
{
	double m_x1, m_y1;				// Declare the x and y coordinate variables for the point A
	double m_x2, m_y2;				// Declare the x and y coordinate variables for the point B
	
	cout << "Tell me the x- and y-coordinates of the point A(x, y)!" << endl;
	cin >> m_x1 >> m_y1;			// User prompt and input for point A

	cout << "Tell me the x and y coordinates of the point B(x, y)!" << endl;
	cin >> m_x2 >> m_y2;			// User prompt and input for point B

	Point A;						// Constructor creates point
	Point B;

	A.set_x(m_x1);					// We set the coordinates of A to the user inputs.
	A.set_y(m_y1);

	B.set_x(m_x2);					// We set the coordinates of B to the user inputs.
	B.set_y(m_y2);

	cout << A.toString() << endl;	// Print the description of point A using toString().

	cout << "The x-coordinate of A is " << A.get_x() << endl;	// Print coordinates of A usin
	cout << "The y-coordinate of A is " << A.get_y() << endl;	// get_x() and get_y().

	cout << "Distance from A to the origin: " << A.distance_origin() << endl;	// Prints the distance from A to
	cout << "Distance from A to B: " << A.distance(B) << endl;					// the origin and from A to B.

	return 0;
}