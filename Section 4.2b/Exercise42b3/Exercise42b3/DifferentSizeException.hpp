// Exercise 4.2b.3 - Point Array (Concrete inheritance)
//
// by Scott Sidoli
//
// 5-24-19
//
// DifferentSizeException.hpp
//
// DifferentSizeException Class.

#ifndef DifferentSizeException_hpp
#define DifferentSizeException_hpp
#include <string>
#include "ArrayException.hpp"
#include <sstream>

using namespace std;

class DifferentSizeException : public ArrayException
{
private:
	string m_chars;

public:
	DifferentSizeException()
	{	// Constructor that stores chars to data member
		m_chars = "The arrays are of different sizes";
	}

	string GetMessage()
	{	// Returns the error message
		stringstream error_message;
		error_message << m_chars << endl;

		return error_message.str();
	}
};
#endif

