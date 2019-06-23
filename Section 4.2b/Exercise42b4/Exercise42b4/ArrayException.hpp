// Exercise 4.2b.4 - Stack Class (composition)
//
// by Scott Sidoli
//
// 5-24-19
//
// ArrayException.hpp
// 
// ArrayException class

#ifndef ArrayException_hpp
#define ArrayException_hpp

#include <string>
using namespace std;

class ArrayException
{
public:
	virtual string GetMessage() = 0;						// PVMF
};

#endif




