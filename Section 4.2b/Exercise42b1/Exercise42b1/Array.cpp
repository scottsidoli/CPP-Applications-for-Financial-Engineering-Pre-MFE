// Exercise 4.2b.1 - Static Variable for Array Default Size 
//
// by Scott Sidoli
//
// 5-22-19
//
// Array.cpp
// 
// Array Class.

#ifndef Array_CPP
#define Array_CPP

#include "OutOfBoundsException.hpp"
#include "Array.hpp"
#include <iostream>

namespace ssidoli
{
	namespace Containers
	{	// Default Array Size
		template <typename T>
		int Array<T>::d_size = 5;

		// Constructors and Destructor
		template <typename T>
		Array<T>::Array() : m_size(d_size), m_data(new T[d_size])
		{
			//	cout << "Array default constructor" << endl;
		}

		template <typename T>
		Array<T>::Array(int size) : m_size(size), m_data(new T[size])
		{
			//	cout << "Array constructor with size" << endl;
		}

		template <typename T>
		Array<T>::Array(const Array<T>& source) : m_size(source.m_size), m_data(new T[source.m_size])
		{ // Copy Constructor
			for (int i = 0; i < m_size; i++)
				m_data[i] = source.m_data[i];

			// cout << "Array copy constructor" << endl;
		}

		template <typename T>
		Array<T>::~Array()
		{ // Array Destructor
			delete[] m_data;
			//	cout << "Array Destructor" << endl;
		}

		// Assignment Operator
		template <typename T>
		Array<T>& Array<T>::operator = (const Array<T>& source)
		{ // Assignment operator
			if (this == &source)
				return *this;

			delete[] m_data;
			m_size = source.m_size;
			m_data = new T[m_size];

			for (int i = 0; i < m_size; i++)
				m_data[i] = source.m_data[i];

			return *this;
		}

		// Getter functions
		template <typename T>
		int Array<T>::DefaultSize() const
		{
			return d_size;
		}

		template <typename T>
		int Array<T>::Size() const
		{
			return m_size;
		}

		template <typename T>
		T& Array<T>::GetElement(int index) const
		{
			if (index < 0 || index >= m_size)
				throw OutOfBoundsException(index);

			return m_data[index];
		}

		// Setter function
		template <typename T>
		void Array<T>::DefaultSize(int size)
		{
			d_size = size;
		}

		template <typename T>
		void Array<T>::SetElement(int index, const T& p)
		{
			if (index < 0 || index >= m_size)
			{
				throw OutOfBoundsException(index);
			}

			else
			{
				m_data[index] = p;
			}
		}

		// Bracket operators
		template <typename T>
		T& Array<T>::operator [] (int index)
		{
			if (index < 0 || index >= m_size)
				throw OutOfBoundsException(index);

			return m_data[index];
		}

		template <typename T>
		const T& Array<T>::operator [] (int index) const
		{ // returns constanct reference to object T
			if (index < 0 || index >= m_size)
				throw OutOfBoundsException(index);

			return m_data[index];
		}
	}
}

#endif