// Exercise 4.2b.4 - Stack Class (composition)
//
// by Scott Sidoli
//
// 5-24-19
//
// Shape.hpp
//
// Shape base class.

#ifndef Shape_HPP
#define Shape_HPP

#include <stdio.h>
#include <string>
using namespace std;

class Shape
{
private:
	int m_ID;

public:
	Shape();										// Default Shape constructor
	Shape(int id);									// Shape Copy Constructor
	virtual ~Shape();										// Shape Destructor
	Shape& operator = (const Shape& source);		// Assignment Operator

	int id() const;									// Retrieves the ID

	virtual string toString() const;				// Prints ID
	virtual void Draw() const = 0;					// Draw function. A pure, virtual, member function.
	void Print() const;								// Template Method Pattern
};

#endif


