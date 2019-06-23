// Exercise 4.2b.6 - Value Template Arguments
//
// by Scott Sidoli
//
// 5-25-19
//
// Stack.cpp
//
// Stack class.

#ifndef Stack_cpp
#define Stack_cpp

#include "Stack.hpp"
#include "DifferentSizeException.hpp"
#include "OutOfBoundsException.hpp"
#include "StackEmptyException.hpp"
#include "StackFullException.hpp"

namespace ssidoli
{
	namespace Containers
	{//========================Constructors and Destructors====================
		template <typename T, int size>
		Stack<T, size>::Stack() : m_current(0), m_array(size)
		{
			// cout << "Default Stack constructor" << endl;
		}

		template <typename T, int size>
		Stack<T, size>::Stack(Stack& source) : m_current(source.m_current), m_array(source.m_array)
		{
			// cout << "Stack Copy Constructor" << endl;
		}

		template <typename T, int size>
		Stack<T, size>::~Stack()
		{
			// cout << "Stack Destructor" << endl;
		}

		//==================Assignment Operator=========================
		template <typename T, int size>
		Stack<T, size>& Stack<T,size>::operator = (const Stack<T,size>& source)
		{
			if (this == &source)
				return *this;

			m_current = source.m_current;
			m_array = source.m_array;

			return *this;
		}

		//==============Functionality==================================
		template <typename T,int size>
		void Stack<T, size>::Push(T element)
		{
			try
			{
				m_array[m_current] = element;
				m_current++;
			}
			catch (OutOfBoundsException& ex)
			{
				throw StackFullException("full");
			}
		}
		template <typename T, int size>
		T Stack<T, size>::Pop()
		{
			try
			{
				--m_current;
				return m_array[m_current];
			}
			catch (OutOfBoundsException& ex)
			{
				m_current = 0;
				throw StackEmptyException("empty");
			}
		}

		template <typename T, int size>
		int Stack<T, size>::GetCurrentIndex()
		{
			return m_current;
		}

		template <typename T, int size>
		int Stack<T, size>::GetArraySize()
		{
			return m_array.Size();
		}

		template <typename T, int size>
		T Stack<T, size>::GetArrayElement(int index)
		{
			return m_array[index];
		}
	}
}

#endif

