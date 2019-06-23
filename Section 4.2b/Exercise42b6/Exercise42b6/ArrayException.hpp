// Exercise 4.2b.6 - Value Template Arguments
//
// by Scott Sidoli
//
// 5-25-19
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





