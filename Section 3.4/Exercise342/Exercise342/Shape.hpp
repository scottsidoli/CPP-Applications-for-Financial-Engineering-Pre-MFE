// Exercise 3.4.2 - Creating a Shape Base Class
//
// by Scott Sidoli
//
// 5-15-19
//
// Shape.hpp
//
// Shape base class.

#ifndef Shape_HPP
#define Shape_HPP

#include <iostream>

using namespace std;

class Shape
{
private:
	int m_ID;

public:
	Shape();										// Default Shape constructor
	Shape(int id);									// Shape Copy Constructor
	~Shape();										// Shape Destructor
	Shape& operator = (const Shape& source);		// Assignment Operator

	int id() const;										// Retrieves the ID

	string toString() const;						// Prints ID
};

#endif
