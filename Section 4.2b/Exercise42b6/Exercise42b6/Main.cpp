// Exercise 4.2b.6 - Value Template Arguments
//
// by Scott Sidoli
//
// 5-25-19
//
// Main.cpp
// 
// In this exercise, we adjust the stack class to take a value as an argument.
// In particular, we make the stack class take an int as an argument. We remove
// the size constructor and use the input for the size of the stack. We are now
// unable to assign or copy stacks of different sizes. We test the new class in
// main.cpp.

#include "Array.hpp"
#include "Stack.hpp"
#include <iostream>
#include <iomanip>

using namespace ssidoli::Containers;

int main()
{
	// Create Stack objects for testing
	Stack<int, 10> intstack1;
	Stack<int, 10> intstack2;
	Stack<int, 15> intstack3;

	//Stack<int, 25> intstack4(intstack1); //Not possible!
	for (int i = 0; i < 10; i++)
		intstack1.Push(i);

	try
	{
		intstack2 = intstack1;
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}
	catch (...)
	{
		cout << "An unhandled exception has occurred." << endl;
	}
	return 0;
}