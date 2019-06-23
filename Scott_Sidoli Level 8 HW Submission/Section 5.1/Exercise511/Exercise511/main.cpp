// Exercise 5.1.1 - Smart Pointers
//
// by Scott Sidoli
//
// Main.cpp
//
// In this exercise, we store different types of shapes in the array template class
// that we created earlier. We store pointers to shapes in the array, Shapes1. The
// boost::shared_ptr<T> class stores a pointer an will delete the object automatically
// when no one is referencing the object. So to exploit this feature we create an array
// with boost::shared_ptr<Shape>. The deletion is done automatically. We mark in the 
// code when destructors are called.

#include <boost\smart_ptr.hpp>
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"

using namespace ssidoli::Containers;
using namespace ssidoli::CAD;

// Typedefs to simplify code
typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

int main()
{
	// Create an array of shared pointers for shapes
	int size = 3;

	ShapeArray Shapes1(size);

	// Fill the array with shape pointers
	ShapePtr p(new Point(1.0, 2.0));
	ShapePtr l(new Line(Point(), Point(1.0, 2.0)));			// Destructors are called for point objects and shape objects
	ShapePtr c(new Circle(Point(), 4.0));					// Destructors are called for point object and shape object

	Shapes1[0] = p;
	Shapes1[1] = l;
	Shapes1[2] = c;

	// Print the shapes
	cout << "Shapes in the array: " << endl;
	cout << "Point: " << (*Shapes1[0]).toString() << endl;
	cout << "Line: " << (*Shapes1[1]).toString() << endl;
	cout << "Circle: " << (*Shapes1[2]).toString() << endl;

	/* Destructor calls after printing:
	Circle Destructor
	A point is destroyed!
	Shape destructor
	Shape destructor
	A line is destroyed!
	A point is destroyed!
	Shape destructor
	A point is destroyed!
	Shape destructor
	Shape destructor
	A point is destroyed!
	Shape destructor
	*/
	return 0;
	}