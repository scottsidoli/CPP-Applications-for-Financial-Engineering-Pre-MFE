// Exercise 4.2b.1 - Static Variable for Array Default Size
//
// by Scott Sidoli
//
// 5-22-19
//
// OutOfBoundsException.hpp
// 
// OutOfBoundsException class.

#ifndef OutOfBoundsException_hpp
#define OutOfBoundsException_hpp

#include "ArrayException.hpp"
#include <sstream>
#include <string>

class OutOfBoundsException : public ArrayException
{
private:
	int m_index;

public:
	OutOfBoundsException(int index)
	{ // Constructor with the out-of-bounds array index as input, and store to data member

		m_index = index;
	}

	string GetMessage()
	{ // Return the array index in the error message

		stringstream array_error;
		array_error << "The index " << m_index << " is out of bounds." << endl;

		return array_error.str();
	}
};

#endif


