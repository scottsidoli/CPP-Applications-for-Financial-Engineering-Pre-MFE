// Exercise 3.6.2 - Exception Objects
//
// by Scott Sidoli
//
// 5-18-19
//
// Array.hpp
// 
// Array Class.

#ifndef Array_HPP
#define Array_HPP

#include "Point.hpp"

namespace ssidoli
{
	namespace Containers
	{
		class Array;
	}
}

class ssidoli::Containers::Array
{
private:
	CAD::Point * m_data;
	int m_size;

public:
	Array();											// Default Constructor
	Array(int size);									// Constructo with size
	Array(const Array& source);							// Copy Constructor
	~Array();											// Destructor
	Array& operator = (const Array& source);			// Assignment operator

	int Size() const;									// Gets the size of the array
	CAD::Point& GetElement(int index) const;					// Get the element at the index

	void SetElement(int index, const CAD::Point& p);			// Set element at the index

	CAD::Point& operator [] (int index);						// Operator overloading: Square brackets to access element
	const CAD::Point& operator [] (int index) const;			// Returns a constant reference to a CAD::Point
};

#endif
