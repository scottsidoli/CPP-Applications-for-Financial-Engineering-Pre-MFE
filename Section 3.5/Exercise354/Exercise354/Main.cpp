// Exercise 3.5.4 - Abstract Functions
//
// by Scott Sidoli
//
// 5-17-19
//
// Main.cpp
//
// In this exercise, we create a member function, Draw(), in the base class shape
// and override it in the Point, Line, and Circle classes. We created a pure virtual
// member function by giving Draw() an empty implementation. This turned the base class
// Shape into an abstract base class. We can no longer create instances of shape.

#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace ssidoli::CAD;

int main()
{
	// Shape s;															// Doesn't compile. Shape is now an ABC.

	Shape * shapes[10];

	shapes[0] = new Line;												// Default line constructor
	shapes[1] = new Point;												// Default point constructor
	shapes[2] = new Point(2.0);											// matching coordinate point constructor
	shapes[3] = new Point(1.5, 2.5);									// coordinate point constructor
	shapes[4] = new Point(Point());										// copy point constructor
	shapes[5] = new Line(Point(1.0, 2.0), Point(3.0, 4.0));				// coordinate line constructor
	shapes[6] = new Line(Line());										// line copy constructor
	shapes[7] = new Circle;												// Default circle constructor
	shapes[8] = new Circle(Point(), 1.0);								// circle constructor
	shapes[9] = new Circle(Circle());									// circle copy constructor
	
	for (int i = 0; i != 10; i++) 
		shapes[i]->Draw();												// Overridden PVMF
	
	for (int i = 0; i != 10; i++) 
		delete shapes[i];
	
	return 0;
}