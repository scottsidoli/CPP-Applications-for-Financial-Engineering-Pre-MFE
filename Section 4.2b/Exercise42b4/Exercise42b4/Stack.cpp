// Exercise 4.2b.4 - Stack Class (composition)
//
// by Scott Sidoli
//
// 5-24-19
//
// Stack.cpp
//
// Stack class.

#ifndef Stack_cpp
#define Stack_cpp

#include "Stack.hpp"
#include "DifferentSizeException.hpp"

namespace ssidoli
{
	namespace Containers
	{//========================Constructors and Destructors====================
		template <typename T>
		Stack<T>::Stack() : m_current(0), m_array()
		{
			// cout << "Default Stack constructor" << endl;
		}

		template <typename T>
		Stack<T>::Stack(int size) : m_current(0), m_array(size)
		{
			// cout << "Stack Constructor with size" << endl;
		}

		template <typename T>
		Stack<T>::Stack(Stack& source) : m_current(source.m_current), m_array(source.m_array)
		{
			// cout << "Stack Copy Constructor" << endl;
		}

		template <typename T>
		Stack<T>::~Stack()
		{
			// cout << "Stack Destructor" << endl;
		}

	//==================Assignment Operator=========================
		template <typename T>
		Stack<T>& Stack<T>::operator = (const Stack<T>& source)
		{
			if (this == &source)
				return *this;

			m_current = source.m_current;
			m_array = source.m_array;

			return *this;
		}

	//==============Functionality==================================
		template <typename T>
		void Stack<T>::Push(T element)
		{
			m_array[m_current] = element;
			m_current++;
		}

		template <typename T>
		T Stack<T>::Pop()
		{
			T value = m_array[m_current - 1];
			--m_current;

			return value;
		}

		template <typename T>
		int Stack<T>::GetCurrentIndex()
		{
			return m_current;
		}

		template <typename T>
		int Stack<T>::GetArraySize()
		{
			return m_array.Size();
		}

		template <typename T>
		T Stack<T>::GetArrayElement(int index)
		{
			return m_array[index];
		}
	}
}

#endif

