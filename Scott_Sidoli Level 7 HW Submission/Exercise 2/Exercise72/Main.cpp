// Exercise 7.2 - STL Iterators
//
// by Scott Sidoli
//
// 5-27-19
//
// Main.cpp
//
// In this exercise, we practice using the iterators for the STL containers. We
// create a template function Sum() the sums together the elements of a container
// of type T. We get an iterator to stop the addition. Finally it returns the sum.
// We also create a sum function that calculates the sum between two iterators.
// For our test, we sum all elements except for the first one and the last one.

#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <iterator>
#include <string>

using namespace std;

// Sum of all elements in a container
template <typename T>
double Sum(const T& source)
{
	double sum = 0.0;

	typename T::const_iterator it;
	typename T::const_iterator end = source.end();

	for (it = source.begin(); it != end; ++it)
		sum += *it;

	return sum;
}

// Sum function for the map container
template<>
double Sum(const map<const string, double>& source)
{
	double sum = 0.0;

	map<const string, double>::const_iterator it;
	map<const string, double>::const_iterator end = source.end();

	for (it = source.begin(); it != end; ++it)
		sum += it->second;

	return sum;
}

// Sum of all elements between two iterators of a container
template <typename T>
double Sum(const T& start, const T& end)
{
	double sum = 0.0;
	for (T it = start; it != end; ++it)
		sum += *it;

	return sum;
}


// Map specialization for the sum of all elements between two iterators
template <>
double Sum(const map<const string, double>::const_iterator& start, const map<const string, double>::const_iterator& end)
{
	double sum = 0.0;

	map<const string, double>::const_iterator it;

	for (it = start; it != end; ++it)
		sum += it->second;

	return sum;
}

int main()
{
	list<double> list1;
	vector<double> vec;
	map<const string, double> temperature;

	for (int i = 0; i < 10; ++i)
	{
		list1.push_front(i);
		vec.push_back(i + 1);
	}

	// Key for map
	temperature["New York"] = 72;
	temperature["Los Angeles"] = 62;
	temperature["Mumbai"] = 88;

	// Sum of the elements in each container
	cout << "The sum of the vector is: " << Sum(vec) << endl;

	cout << "The sum of the list is: " << Sum(list1) << endl;

	cout << "The sum of the map is " << Sum(temperature) << endl;

	cout << endl;

	// Sum of vector elements between two iterators
	vector<double>::const_iterator vec_start = vec.begin() + 1;
	vector<double>::const_iterator vec_end = vec.end() - 1;
	cout << "The sum of all elements in vector besides the first one and the last one is "
		<< Sum(vec_start, vec_end) << "." << endl;

	// Sum of list elements between two iterators
	list<double>::const_iterator list_start = ++list1.begin();
	list<double>::const_iterator list_end = --list1.end();
	cout << "The sum of all elements in list besides the first one and the last one is "
		<< Sum(list_start, list_end) << "." << endl;

	// Sum of the doubles in the map. Note that the order is alphabetical by the string.
	map<const string, double>::const_iterator map_start = ++temperature.begin();
	map<const string, double>::const_iterator map_end = --temperature.end();
	cout << "The sum of all double elements in map besides the first and last is "
		<< Sum(map_start, map_end) << "." << endl;	// Los Angeles--->Mumbai--->New York means that
													// Mumbai = 88 is what is left.

	return 0;
}