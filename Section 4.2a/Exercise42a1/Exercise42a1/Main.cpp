// Exercise 4.2a.1 - Templated Array Class 
//
// by Scott Sidoli
//
// 5-21-19
//
// Main.cpp
// 
// In this exercise, we were required to transform the array class into a template class.
// We adopt the appropriate syntax and implementation and test the array template in main.
// We include the following code:
//		#ifndef Array_cpp
//		#include "Array.cpp"
//		#endif
// This works because this code allows the compiler to instantiate the template and create
// a .o file for linking. Implementation of a templated class must be known at compile-time,
// while for ordinary classes, implementation can be known at linking-time.

#include "Array.hpp"
#include "Array.cpp"
#include "line.hpp"
#include "Circle.hpp"
using namespace ssidoli::CAD;
using namespace ssidoli::Containers;

int main()
{
	int size(5);

	Array<Point> points(size);
	
	Point p(2.0, 3.0);

	points[0].x(6);
	points[0].y(88);
	cout << points[0] << endl;
	points[3] = p;	
	points[4] = 4.2 * points[3];
	points[3] *= 5.0;
	points[1].Draw();

	for (int i = 0; i < points.Size(); i++)
	{
		cout << i << ": " << points[i] << endl;
	}

	try
	{
		cout << points[7] << endl;
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage();
	}
	catch (...)
	{
		cout << "An unhandled exception has occurred..." << endl;
	}
	
	return 0;
}