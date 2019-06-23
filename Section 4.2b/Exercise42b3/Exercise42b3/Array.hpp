// Exercise 4.2b.3 - Point Array (concrete inheritance)
//
// by Scott Sidoli
//
// 5-23-19
//
// Array.hpp
// 
// Array Class.

#ifndef Array_HPP
#define Array_HPP

using namespace std;

namespace ssidoli
{
	namespace Containers
	{
		template <typename T> class Array;
	}
}


template <typename T>
class ssidoli::Containers::Array
{
private:

	T * m_data;
	int m_size;
	static int d_size;										// Static Variable for default array size

public:

	Array();												// Default Constructor
	Array(int size);										// Constructo with size
	Array(const Array<T>& source);							// Copy Constructor
	virtual ~Array();										// Destructor
	Array<T>& operator = (const Array<T>& source);			// Assignment operator

	int Size() const;										// Gets the size of the array
	int DefaultSize() const;								// Gets the default size of the array
	T& GetElement(int index) const;							// Get the element at the index

	void SetElement(int index, const T& p);					// Set element at the index
	void DefaultSize(int size);								// Sets the default size of the array

	T& operator [] (int index);								// Operator overloading: Square brackets to access element
	const T& operator [] (int index) const;					// Returns a constant reference to a T
};

#ifndef Array_cpp      // Must be the same name as in source file #define 
#include "Array.cpp"
#endif 

#endif


