// Exercise 4.2b.6 - Value Template Arguments
//
// by Scott Sidoli
//
// 5-25-19
//
// DifferentSizeException.hpp
//
// DifferentSizeException Class.

#ifndef DifferentSizeException_hpp
#define DifferentSizeException_hpp

#include "ArrayException.hpp"
#include <sstream>



class DifferentSizeException : public ArrayException
{
private:
	string m_chars;

public:
	DifferentSizeException(string chars)
	{	// Constructor that stores chars to data member
		m_chars = chars;
	}

	string GetMessage()
	{	// Returns the error message
		stringstream error_message;
		error_message << "\nThe arrays are of " << m_chars << "." << endl;

		return error_message.str();
	}
};
#endif


