// Exercise 3.5.1 - Polymorphic toString() Function
//
// by Scott Sidoli
//
// 5-15-19
//
// Shape.cpp
//
// Shape base class.

#include "Shape.hpp"
#include <iostream>
#include <sstream>
#include <stdlib.h>

Shape::Shape() : m_ID(rand())									// Shape Default Constructor
{
	// cout << "shape default constructor" << endl;
}

Shape::Shape(int id) : m_ID(id)									// Shape Copy Constructor
{
	// cout << "shape copy constructor" << endl;
}

Shape::~Shape()													// Shape Destructor
{
	// cout << "Shape destructor" << endl;
}

Shape& Shape::operator = (const Shape& source)					// Shape Assignment Operator
{
	if (this == &source)
		return *this;

	m_ID = source.m_ID;
	return *this;
}

int Shape::id() const
{
	return m_ID;
}

string Shape::toString() const
{
	std::stringstream shape_string;
	shape_string << "ID: " << m_ID << "\n" << endl;
	return shape_string.str();
}