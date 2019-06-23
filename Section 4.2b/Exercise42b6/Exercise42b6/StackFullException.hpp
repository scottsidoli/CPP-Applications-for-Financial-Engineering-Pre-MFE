// Exercise 4.2b.6 - Value Template Exceptions
//
// by Scott Sidoli
//
// 5-25-19
//
// StackFullException.hpp
//
// Stack Full Exception class

#ifndef StackFullException_hpp
#define StackFullException_hpp

#include "StackException.hpp"
#include <sstream>

class StackFullException : public StackException
{
private:
	string m_chars;

public:
	StackFullException(string chars)
	{
		m_chars = chars;
	}

	string GetMessage()
	{
		stringstream error_message;
		error_message << "The stack is " << m_chars << endl;

		return error_message.str();
	}
};

#endif

