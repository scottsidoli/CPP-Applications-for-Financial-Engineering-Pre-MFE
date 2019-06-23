// Exercise 5.1.3 - Variant
//
// by Scott Sidoli
//
// 5-29-19
//
// Main.cpp
//
// In this exercise, we experiment with boost::variant. This is similar to tuple, but can only store one value.
// We create a function that asks the user for a kind of shape to create and then returns that shape. Instead of
// returning a Shape*, we return a boost::variant. We create a typedef 'ShapeType' that can contain a Point, Line,
// or Circle. In the main function we call the function and print the result. Next, we try to assign the variant 
// to a Line variable by using the global boost::get<T>() function. We expect an exception to get thrown. Finally,
// we experiment with 'visitors'. We create a variant visitor that moves shapes, apply it, and print the shape
// afterwords to see if the shape's coordinates actually changed.

#include <boost\variant.hpp>
#include <iostream>
#include "Line.hpp"
#include "Circle.hpp"
#include "Visitor.hpp"
#include "Point.hpp"
#include <string>

using namespace std;
using namespace ssidoli::CAD;

typedef boost::variant<Point, Line, Circle> ShapeType;

ShapeType Create_Shape()
{
	ShapeType shape;

	cout << "Please choose a shape: " << endl << "a) Point" << endl << "b) Line" << endl << "c) Circle" << endl;
	char choice;
	cin >> choice;

	switch (choice)
	{
	case 'a':
		shape = Point();
		break;

	case 'b':
		shape = Line();
		break;

	case 'c':
		shape = Circle();
		break;

	default:
		break;
	}

	return shape;
}

int main()
{
	using boost::variant;

	// Creating a shape
	ShapeType user_Shape = Create_Shape();
	cout << "before visiting: " << user_Shape << endl;

	// Trying to catch an exception
	try
	{
		Line l = boost::get<Line>(user_Shape);
	}

	catch (boost::bad_get& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	// Using Visitor
	Visitor visitor(5.0, 7.0);
	boost::apply_visitor(visitor, user_Shape);

	cout << "After visiting: " << user_Shape << endl;
	return 0;
}


