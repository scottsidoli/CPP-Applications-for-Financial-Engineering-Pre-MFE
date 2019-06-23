#ifndef TotalLengthException_hpp
#define TotalLengthException_hpp

#include "ArrayException.hpp"
#include <sstream>

class TotalLengthException : public ArrayException
{
private:
	int m_index;

public:
	TotalLengthException(int index)
	{
		m_index = index;
	}

	string GetMessage()
	{
		stringstream length_error_message;
		length_error_message << "This point array has size " << m_index << " and is too small!" << endl;

		return length_error_message.str();
	}
};
#endif
