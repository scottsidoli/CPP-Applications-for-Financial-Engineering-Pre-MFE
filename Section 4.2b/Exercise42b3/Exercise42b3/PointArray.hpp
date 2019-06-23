// Exercise 4.2b.3 - Point Array (concrete inheritance)
//
// by Scott Sidoli
//
// 5-24-19
//
// NumericArray.hpp
//
// Derived class Point Array.

#ifndef PointArray_hpp
#define PointArray_hpp

#include "Point.hpp"
#include "Array.hpp"
#include <iostream>



namespace ssidoli
{
	namespace Containers
	{
		class PointArray;
	}
}

class ssidoli::Containers::PointArray : public Array<CAD::Point>
{
private:

public:
	PointArray();											// Default Constructor
	PointArray(int size);									// Constructor with size
	PointArray(const PointArray& source);					// Copy Constructor
	virtual ~PointArray();											// Destructor
	
	PointArray& operator = (const PointArray& source);		// Assignment Operator

	double Length() const;									// Total length between points in the array
};
#endif