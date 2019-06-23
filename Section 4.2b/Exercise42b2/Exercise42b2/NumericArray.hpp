// Exercise 4.2b.2 - Numeric Array (generic inheritance)
//
// by Scott Sidoli
//
// 5-22-19
//
// NumericArray.hpp
//
// Derived class Numeric Array.

#ifndef NumericArray_hpp
#define NumericArray_hpp

#include "Array.hpp"
#include <iostream>


using namespace std;

namespace ssidoli
{
	namespace Containers
	{
		template <typename T> class NumericArray;
	}
}

template <typename T>
class ssidoli::Containers::NumericArray : public Array<T>
{
private:


public:
	NumericArray();													// Default Constructor
	NumericArray(int size);											// Constructor with size
	NumericArray(const NumericArray<T>& source);					// Copy Constructor
	virtual ~NumericArray();										// Destructor
	NumericArray<T>& operator = (const NumericArray<T>& source);	// Assignment Operator

	NumericArray<T> operator + (const NumericArray<T>& arr) const;  // Adds array elements
	double Dot(const NumericArray<T>& arr) const;						// Dot product

	NumericArray<T> operator * (double factor) const;
	

	
};

#ifndef NumericArray_cpp							// Must be the same name as source file #define
#include "NumericArray.cpp"
#endif

#endif
