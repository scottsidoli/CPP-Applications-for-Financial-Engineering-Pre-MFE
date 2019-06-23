// Exercise 4.2b.5 - Layering Exceptions
//
// by Scott Sidoli
//
// 5-25-19
//
// StackEmptyException.hpp
//
// Stack Empty Exception class

#ifndef StackEmptyException_hpp
#define StackEmptyException_hpp

#include "StackException.hpp"
#include <sstream>

class StackEmptyException : public StackException
{
private:
	string m_chars;

public:
	StackEmptyException(string chars)
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
