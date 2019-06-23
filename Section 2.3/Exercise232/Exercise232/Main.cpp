// Exercise 2.3.2 - Call By Reference
//
// by Scott Sidoli
//
// 4-20-19
//
// Main.cpp
//
// The goal of this exercise is to have the distance formula use call by reference.
// This will prevent a copy from being produced and we notice from our print statements
// that the copy constructor is not called. We use a const designation to make it 
// impossible to alter the point in the distanct function. We test this and find a 
// compiler error (C3490). We also notice that the destructor is called only two times.

#include "Exercise232.hpp"
#include <iostream>

using namespace std;

int main()
{
	double x_1, y_1;
	double x_2, y_2;

	cout << "Tell me the x- and y-coordinates of the point A(x, y)!" << endl;
	cin >> x_1 >> y_1;			// User prompt and input for point A

	cout << "Tell me the x and y coordinates of the point B(x, y)!" << endl;
	cin >> x_2 >> y_2;			// User prompt and input for point B

	Point A(x_1, y_1);			// Constructor creates points
	Point B(x_2, y_2);			// without using set().	

	cout << "The distance between " << A.toString() << "and " << B.toString() << "is " << A.distance(B) << endl;
								// We notice that the copy constructor
								// is not called.

								// The destructor deleted two instances.
	return 0;
}