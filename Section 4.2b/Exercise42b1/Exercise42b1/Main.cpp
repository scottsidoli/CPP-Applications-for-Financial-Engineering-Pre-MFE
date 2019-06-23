// Exercise 4.2b.1 - Static Variable for Array Default Size
//
// by Scott Sidoli
//
// 5-22-19
//
// Main.cpp
// 
// In this exercise, we add a static template member variable to the array class and
// study its behavior. The following is test code with outputs and an answer to the
// question.

#include "Array.hpp"
#include "Array.cpp"
#include "line.hpp"
#include "Circle.hpp"
using namespace ssidoli::CAD;
using namespace ssidoli::Containers;

int main()
{   // Default size is set to 5.

	Array<int> intArray1; 
	Array<int> intArray2; 
	Array<double> doubleArray; 
	
	cout << intArray1.DefaultSize() << endl;	// 5 
	cout << intArray2.DefaultSize() << endl;	// 5
	cout << doubleArray.DefaultSize() << endl;	// 5
	
	intArray1.DefaultSize(15); 
	
	cout << intArray1.DefaultSize() << endl;	// 15
	cout << intArray2.DefaultSize() << endl;	// 15
	cout << doubleArray.DefaultSize() << endl;	// 5

	/* The values produced are as expected. The first three outputs are in accordance
	with the static template member variable. When we change the default array size for
	intArray1, it changes the default size for all future instances of Array<int>. Hence
	the default size of intArray2 is changed to 15. The default size of doubleArray is
	unaffected by the change in default size to Array<int>.*/
	
	return 0;
}