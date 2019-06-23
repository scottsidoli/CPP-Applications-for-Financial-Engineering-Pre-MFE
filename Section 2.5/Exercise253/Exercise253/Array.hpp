// Exercise 2.5.3 - Array Class
//
// by Scott Sidoli
//
// 5-10-19
//
// Array.hpp
// 
// Array class

#ifndef Array_HPP
#define Array_HPP

#include "Point.hpp"

class Array
{
private:
	Point * m_data;
	int m_size;

public:
	Array();											// Default Constructor
	Array(int size);									// Constructo with size
	Array(const Array& source);							// Copy Constructor
	~Array();											// Destructor
	Array& operator = (const Array& source);			// Assignment operator

	int Size() const;									// Gets the size of the array
	Point& GetElement(int index) const;					// Get the element at the index

	void SetElement(int index, const Point& p);			// Set element at the index

	Point& operator [] (int index);						// Operator overloading: Square brackets to access element
	const Point& operator [] (int index) const;			// Returns a constant reference to a Point
};

#endif
