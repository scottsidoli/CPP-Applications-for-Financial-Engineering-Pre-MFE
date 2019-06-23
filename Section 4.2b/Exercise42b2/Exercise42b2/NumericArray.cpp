// Exercise 4.2b.2 - Numeric Array (generic inheritance)
//
// by Scott Sidoli
//
// 5-22-19
//
// NumericArray.cpp
//
// Derived class Numeric Array.

#ifndef NumericArray_cpp
#define NumericArray_cpp
#include "DifferentSizeException.hpp"
#include "NumericArray.hpp"
#include <iostream>
using namespace std;

namespace ssidoli
{
	namespace Containers
	{
		//=============== Constructors, Destructors, and Assignment Operator ===============
		template <typename T>
		NumericArray<T>::NumericArray() : Array<T>::Array()							// Call the default constructor of base class
		{
			// cout << "Numeric Array Default Constructor" << endl;
		}

		template <typename T>
		NumericArray<T>::NumericArray(int size) : Array<T>::Array(size)			// Call the size constructor of the base class
		{
			// cout << "Numeric Array Constructor with size" << endl;
		}

		template <typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& source) : Array<T>::Array(source)	// Copy constructor of the base class
		{
			// cout << "Numeric Array Copy Constructor" << endl;
		}

		template <typename T>
		NumericArray<T>::~NumericArray()											// Numeric array destructor
		{
			// cout << "Numeric Array Destructor" << endl;
		}

		template <typename T>														// Numeric array assignment operator
		NumericArray<T>& NumericArray<T>:: operator = (const NumericArray<T>& source)
		{
			if (this == &source)
				return *this;

			Array<T>:: operator = (source);											// 
			return *this;
		}


		//=============== Numeric Functionality ===============
		template <typename T>
		NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& arr) const
		{ // addition operator 
			typename NumericArray<T>::NumericArray new_arr(arr.Size());
			if (this->Size() == arr.Size())
			{
				for (int index = 0; index < arr.Size(); index++)
				{
					new_arr[index] = arr.GetElement(index) + this->GetElement(index);
				}

				return new_arr;
			}
			else
			{
				throw DifferentSizeException();
			}
		}

		template <typename T>
		double NumericArray<T>::Dot(const NumericArray<T>& arr) const
		{ // Dot Product Function
			
			if (this->Size() == arr.Size())
			{
				T dot_product(0);
				for (int index = 0; index < arr.Size(); index++)
					dot_product += (this->GetElement(index) * arr.GetElement(index));
				
				return dot_product;
			}
			else
				throw DifferentSizeException();
		}


		template<typename T>
		NumericArray<T> NumericArray<T>::operator * (double factor)  const							//Scale by factor
		{
			
			NumericArray<T> temp(this->Size());
			for (int i = 0; i < (*this).Size(); i++)
			{
				temp[i] = factor * (*this)[i];
			}
			return temp;
		}

	}
}

#endif