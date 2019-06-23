// Exercise 4.2b.6 - Value Template Arguments
//
// by Scott Sidoli
//
// 5-25-19
//
// StackException.hpp
//
// Stack Exception class

#ifndef StackException_hpp
#define StackException_hpp

#include <string>
using namespace std;

class StackException
{
public:
	virtual string GetMessage() = 0;
};

#endif