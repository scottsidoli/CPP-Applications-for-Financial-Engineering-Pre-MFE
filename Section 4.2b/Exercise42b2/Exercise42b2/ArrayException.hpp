// Exercise 4.2b.2 - Numeric Array (generic inheritance)
//
// by Scott Sidoli
//
// 5-22-19
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


