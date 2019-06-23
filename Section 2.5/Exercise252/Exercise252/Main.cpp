// Exercise 2.5.2 - Creating an Array of Pointers
//
// by Scott Sidoli
//
// 5-10-19
//
// Main.cpp
// 
// Our goal is to create an array of point pointers. We will have three elements
// on the stack. We create for each element of the array, a point on the heap.

#include "Point.hpp"
#include <iostream>

using namespace std;

int main()
{
	int n = 3;
	Point* *array_of_pointers;									// Point to point pointers
	array_of_pointers = new Point*[n];							// Array of point pointers of size 3.

	array_of_pointers[0] = new Point();							// Pointer to a point created with the Default Constructor
	array_of_pointers[1] = new Point(1.0, 2.0);					// Pointer to a point created with the Coordinate Constructor
	array_of_pointers[2] = new Point(*array_of_pointers[1]);	// Pointer to a point created with Copy constructor
	
	for (int m = 0; m < n; m++)
		cout << *array_of_pointers[m];							// Prints point object that is pointed to

	for (int m = 0; m < n; m++)
		delete array_of_pointers[m];							// Deletes pointers.

	delete[] array_of_pointers;									// Deletes array
	
	/* Memory Layout:
	
	Each element of the pointer array holds a pointer that points to
	a point object. The array is created on the stack, as are the pointers
	that are stored in the array. Each point object, since it is created
	with the new keyword, is stored on the heap:
		
					
					
															
															 
												_____________________________________________________________________________________
												|							||							||							|
												|	     Point on heap    	||	      Point on heap    	||	      Point on heap    	|
												|							||							||							|
												=====================================================================================
															/\							  /\						  /\
															/\							  /\						  /\
	_________________________					_____________________________________________________________________________________
	|						|					|							||							||							|
	|	array_of_pointers	|	--------->>>>	|	array_of_pointers[0]	||	array_of_pointers[1]	||	array_of_pointers[2]	|
	|						|					|							||							||							|
	=========================					=====================================================================================
															 |							 |							  |
	\__________  ___________/								 V							 V							  V
			   \/										  On Stack					  On Stack					   On Stack
			On Stack							
	*/
	
	
	return 0;
}