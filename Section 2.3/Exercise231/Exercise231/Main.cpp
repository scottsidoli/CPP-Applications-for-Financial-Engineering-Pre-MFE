// Exercise 2.3.1 - Copy Constructors
//
// by Scott Sidoli
//
// 4-20-19
//
// Main.cpp
//
// The goal of this exercise is to add additional constructors to our Point class.
// For the first part of the exercise we simple add some print statements to our
// constructor and destructor. This allows us to count the number of times each has
// called. We notice that the destructor is called three times and constructor is
// called two times. They are not the same. However, when we add the copy constructor
// (with a print statement), we notice that it gets called as we call our distance
// function. The input point (point B) for our distance function is copied to the
// stack. This makes the number of constructor calls equal the number of destructor
// calls. It also demonstrates that copy constructors are called, even when they are
// not hard coded. We also note that, based on our print statements, we do not call 
// our default constructor.

#include "Exercise231.hpp"
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
	
	Point A(x_1, y_1);						// Constructor creates points
	Point B(x_2, y_2);						// without using set().	

	cout << "The distance between A and B is " << A.distance(B) << endl; // Input point B is copied
																		 // and the copy constructor is called.

	// The destructor deleted all three instances.
	return 0;
}