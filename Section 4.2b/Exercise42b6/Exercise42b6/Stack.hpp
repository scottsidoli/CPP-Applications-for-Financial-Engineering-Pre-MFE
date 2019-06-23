// Exercise 4.2b.6 - Stack Template Arguments
//
// by Scott Sidoli
//
// 5-25-19
//
// Stack.hpp
//
// Stack class.

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
#include "Array.hpp"
using namespace ssidoli::Containers;

namespace ssidoli
{
	namespace Containers
	{
		template <typename T, int size> class Stack;
	}
}

template <typename T, int size>
class ssidoli::Containers::Stack
{
private:
	int m_current;
	Array<T> m_array;

public:
	Stack();									// Default Constructor
	Stack(Stack& source);					// Copy Constructor
	virtual ~Stack();							// Destructor

	Stack& operator = (const Stack& source);	// Assignment Operator

	void Push(T element);						// Add an element to the top of the stack
	T Pop();									// Remove and return the top element from the stack

	// Additional Functions
	int GetCurrentIndex();						// Gets m_current
	int GetArraySize();							// Gets size of m_array
	T GetArrayElement(int index);				// Gets indexed element from m_array
};

#ifndef Stack_cpp
#include "Stack.cpp"
#endif
#endif

