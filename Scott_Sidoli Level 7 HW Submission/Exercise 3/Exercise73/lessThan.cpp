// Exercise 7.3 - STL Algorithms
//
// by Scott Sidoli
//
// 5-28-19
//
// lessThan.cpp
//
// lessThan class with global function and function object.

#include <iostream>
#include "lessThan.hpp"

lessThan::lessThan(double value) : boundary(value)
{
	// Sets the boundary value in the constructor.
}

lessThan::~lessThan()
{
	// Destructor
}

bool lessThan::operator () (double value)
{
	return (value < threshold);				// function object implementation
}