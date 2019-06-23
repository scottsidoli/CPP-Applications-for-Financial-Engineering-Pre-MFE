// Exercise 4.2b.4 - Stack Class (composition)
//
// by Scott Sidoli
//
// 5-24-19
//
// Main.cpp
//
// In this exercise, we made a stack class. We use data storage from the array class, but we do not derive
// from the array class because there is functionality from the array class that we do not wish to include
// in the stack class. Instead we include an Array<T> as a data member in the stack class. This is called 
// composition. The function of data storage is delegated to the array class. We add source file and header
// file. We include additional functionality of Push() and Pop(). The Push() function stores the element at
// the current position of the embedded array, then increments the current position forward. Pop()
// decrements the current position and then returns the element at that position. In either case, the index
// is unchanged if Array throws and exception. We test the stack class in main.cpp.

#include "Point.hpp"
#include "Array.hpp"
#include "Stack.hpp"
#include <iostream>
#include <iomanip>
using namespace ssidoli::CAD;
using namespace ssidoli::Containers;

int main()
{
	// Create stack objects for tests
	Stack<int> intstack1;                    // Default constructor
	Stack<int> intstack2(6);                 // Stack of integers of size 5
	Stack<int> intstack3(7);                 // Stack of integers of size 6


	// Push elements into the stacks
	for (int i = 0; i < 6; i++)
		intstack2.Push(i);

	for (int i = 0; i < 7; i++)
		intstack3.Push(i);

	Stack<int> intstack4(intstack3);        // Copy constructor


	// Pop elements from the stacks
	cout << "intstack3  intstack4" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << setw(5) << intstack3.Pop() << setw(13) << intstack4.Pop() << endl;
	}
	cout << endl;
	
	// OutOfBound Exception with using Push()
	try
	{
		cout << "i  " << "m_current  " << "m_array[i]" << endl;
		for (int i = 0; i < 1000; i++)       
		{
			intstack1.Push(i);
			cout << i << setw(8) << intstack1.GetCurrentIndex()
				<< setw(10) << intstack1.GetArrayElement(i) << endl;
			
		}

		
	}
	catch (ArrayException& ex)               
	{
		cout << ex.GetMessage() << endl;      
	}
	catch (...)
	{
		cout << "An unhandled exception has occurred..." << endl;
	}
	cout << endl;

	// OutOfBoundsException using Pop()
	try
	{
		cout << "After Push(), m_current is "
			<< intstack1.GetCurrentIndex() << endl;
		cout << "i  " << "m_array[i]  " << "m_current" << endl;
		for (int i = 0; i < 100; i++)         
		{
			cout << i << setw(8) << intstack1.Pop()
				<< setw(10) << intstack1.GetCurrentIndex() << endl;
		}

	}
	catch (ArrayException& ex)                
	{
		cout << ex.GetMessage() << endl;     
	}
	catch (...)
	{
		cout << "An unhandled exception has occurred..." << endl;
	}
	cout << "m_current is set back to " << intstack1.GetCurrentIndex() << endl;

	return 0;
}