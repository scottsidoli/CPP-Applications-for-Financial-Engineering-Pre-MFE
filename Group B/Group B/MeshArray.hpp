// Group B - Perpetual American Option
//
// by Scott Sidoli
//
// 6-10-19
//
// MeshArray.hpp
//
// Used to create array for varying parameters in option price calculations.

#ifndef MeshArray_hpp
#define MeshArray_hpp

#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

template <typename T>
vector<T> MeshArray(T start, T end, T interval)
{
	// Generate a mesh array of elements of type T with mesh size 'interval'
	vector<T> arr;

	T step = start;
	while (step <= end)
	{
		arr.push_back(step);
		step = step + interval;
	}

	return arr;
}

template <typename T>
void PrintArray(const vector<T>& arr)
{
	// Prints the array
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;
}

template <typename T, typename S>
void PrintArray(const vector<T>& arr_1, const vector<S>& arr_2)
{
	// Prints two one dimensional arrays side-by-side
	for (int i = 0; i < arr_1.size(); i++)
	{
		cout << right << setw(4) << arr_1[i] << ", " << left << setw(12) << arr_2[i] << endl;
	}
}

template <typename T, typename S, typename I>
void PrintArray(const vector<T>& arr_1, const vector<S>& arr_2, const vector<I>& arr_3)
{
	// Prints the result of the array printing for three one-dimensional arrays
	for (int i = 0; i < arr_1.size(); i++)
	{
		cout << right << setw(4) << arr_1[i] << ", "
			<< setw(12) << arr_2[i] << ", " << left << setw(20) << arr_3[i] << endl;
	}
}

#endif