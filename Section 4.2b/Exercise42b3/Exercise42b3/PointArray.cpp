// Exercise 4.2b.3- Point Array (concrete inheritance)
//
// by Scott Sidoli
//
// 5-23-19
//
// PointArray.cpp
// 
// PointArray Class.

#include "PointArray.hpp"
#include "DifferentSizeException.hpp"
#include "TotalLengthException.hpp"

namespace ssidoli
{
	namespace Containers
	{
		// ============= Constructors and Destructors =========================
		PointArray::PointArray() : Array<CAD::Point>()
		{
			// cout << "Point Array Default Constructor" << endl;
		}

		PointArray::PointArray(int size) : Array<CAD::Point>(size)
		{
			// cout << "Point Array Constructor with Size" << endl;
		}
		PointArray::PointArray(const PointArray& source) : Array<CAD::Point>(source)
		{
			// cout << "Point Array Copy Constructor" << endl;
		}
		
		PointArray::~PointArray()
		{
			// cout << "Point Array Destructor" << endl;
		}

		// ============== Assignment Operator ============================
		PointArray& PointArray::operator = (const PointArray& source)
		{
			if (this == &source)
				return *this;

			Array<CAD::Point>::operator = (source);
			return *this;
		}

		// ================ Total Length Between Points in the Array ======================
		double PointArray::Length() const
		{
			if (this->Size() < 2)
				throw TotalLengthException(this->Size()); // Arrays of size 1 have no length.

			double length = 0.0;
			for (int i = 1; i != this->Size(); i++)
			{
				length += ((this->GetElement(i - 1)).distance(this->GetElement(i)));
			}

			return length;
		}
	}
}