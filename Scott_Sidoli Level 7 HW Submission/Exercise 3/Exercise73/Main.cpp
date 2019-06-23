// Exercise 7.3 - STL Algorithms
//
// by Scott Sidoli
//
// 5-28-19
//
// Main.cpp
//
// In this exercise, we work with the STL algorithm, count_if. Algorithms such as 
// this work with containers. We initialize a container (a vector) and use the
// count_if algorithm to determine the number of elements less than a certain value.
// We do this in two way. In the first way, we pass count_if a global function
// defined in our header. In the second way, we pass it a function object which is
// defined in the class in our header and implemented in our source code.

#include "lessThan.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double threshold = 50.0;				// Defining our extern double.

int main()
{
	// Create a vector and give it values
	int size = 10;
	vector<double> vec(size);
	for (int i = 0; i < vec.size(); ++i)
	{
		vec[i] = i * i;				// 0, 1, 4, 9, 16, 25, 36, 49, 64, 81
	}

	cout << "Using the global function, the number of elements smaller than " << threshold << ":" << endl;
	cout << count_if(vec.begin(), vec.end(), less_than<double>) << endl;

	cout << endl;

	cout << "Using the lessThan class's function object, the number of elements smaller than " << threshold << ":" << endl;
	cout << count_if(vec.begin(), vec.end(), lessThan(threshold)) << endl;

	// We should get 8.


	return 0;
}