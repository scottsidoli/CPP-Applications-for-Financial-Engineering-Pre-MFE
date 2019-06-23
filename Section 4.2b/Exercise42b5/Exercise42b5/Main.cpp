// Exercise 4.2b.5 - Layering Exceptions
//
// by Scott Sidoli
//
// 5-25-19
//
// Main.cpp
//
// In this exercise, we try to layer exceptions. When the stack is either full
// or empty, we want to get an exception from the array class. Since we do not
// the client to know about array exceptions, we translate array exceptions into
// stack exceptions. To do this, we create a stack exception base class with
// 'stack full exception' and 'stack empty exception' derived classes. For the 
// Push() function we wish to throw a StackFullException and for the Pop() function
// we wish to throw a StackEmptyException. We place this code in a try...catch
// block. In main, we write a test program to catch the exceptions.

#include "Array.hpp"
#include "Stack.hpp"
#include <iostream>
#include <iomanip>

using namespace ssidoli::Containers;

int main()
{
	// Create a stack object
	Stack<int> intstack;				// Default size is 5.

	// Try to catch a stack full exception
	cout << "i   " << "m_current   " << "m_array[i]" << endl;
	
	try
	{
		for (int i = 0; i < 20; i++)
		{
			intstack.Push(i);
			cout << i << "   " << intstack.GetCurrentIndex()
				<< "           " << intstack.GetArrayElement(i) << endl;

		}
	}
	catch(StackException& ex)
	{
		cout << ex.GetMessage() << endl;
	}
	catch (...)
	{
		cout << "An unhandled exception has occurred." << endl;
	}

	cout << "The current index is " << intstack.GetCurrentIndex() << endl;
	// Try to catch a stack empty exception
	cout << "i   " << "m_array[i]   " << "m_current" << endl;
	try 
	{
		for (int i = 0; i < 20; i++)
		{
			cout << i << "   " << intstack.Pop() 
				<< "            " << intstack.GetCurrentIndex() << endl;
		}
	}
	catch (StackException& ex)
	{
		cout << ex.GetMessage() << endl;
	}
	catch (...)
	{
		cout << "An unhandled exception has occurred." << endl;
	}
	
	cout << "In the end, m_current is " << intstack.GetCurrentIndex() << endl;


	return 0;
}