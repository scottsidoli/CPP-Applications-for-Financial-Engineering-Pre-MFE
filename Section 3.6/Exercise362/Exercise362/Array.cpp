// Exercise 3.6.2 - Exception Objects
//
// by Scott Sidoli
//
// 5-18-19
//
// Array.cpp
// 
// Array Class.

#include "OutOfBoundsException.hpp"
#include "Array.hpp"
#include <iostream>

namespace ssidoli
{
	namespace Containers
	{
		// Constructors and Destructor
		Array::Array()
		{ // Default Constructor
			m_size = 10;
			m_data = new CAD::Point[m_size];

			//	cout << "Array default constructor" << endl;
		}

		Array::Array(int size)
		{ // Constructor with size
			m_size = size;
			m_data = new CAD::Point[m_size];

			//	cout << "Array constructor with size" << endl;
		}

		Array::Array(const Array& source)
		{ // Copy Constructor
			m_size = source.m_size;
			m_data = new CAD::Point[m_size];

			for (int i = 0; i < m_size; i++)
				m_data[i] = source.m_data[i];

			//	cout << "Array copy constructor" << endl;
		}

		Array::~Array()
		{ // Array Destructor
			delete[] m_data;
			//	cout << "Array Destructor" << endl;
		}

		// Assignment Operator

		Array& Array::operator = (const Array& source)
		{ // Assignment operator
			if (this == &source)
				return *this;

			delete[] m_data;
			m_size = source.m_size;
			m_data = new CAD::Point[m_size];

			for (int i = 0; i < m_size; i++)
				m_data[i] = source.m_data[i];

			return *this;
		}

		// Getter functions

		int Array::Size() const
		{
			return m_size;
		}

		CAD::Point& Array::GetElement(int index) const
		{
			if (index < 0 || index >= m_size)
				throw OutOfBoundsException(index);

			return m_data[index];
		}

		// Setter function
		void Array::SetElement(int index, const CAD::Point& p)
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
		CAD::Point& Array::operator [] (int index)
		{
			if (index < 0 || index >= m_size)
				throw OutOfBoundsException(index);

			return m_data[index];
		}

		const CAD::Point& Array::operator [] (int index) const
		{ // returns constanct reference to CAD::Point object
			if (index < 0 || index >= m_size)
				throw OutOfBoundsException(index);

			return m_data[index];
		}
	}
}