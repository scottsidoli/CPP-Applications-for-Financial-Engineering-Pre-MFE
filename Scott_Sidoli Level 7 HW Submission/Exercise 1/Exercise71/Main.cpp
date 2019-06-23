// Exercise 7.1 - STL Containers
//
// by Scott Sidoli
//
// 5-26-19
//
// Main.cpp
//
// In this exercise, we practice using the STL containers. We create a list of 
// doubles, a vector, and a map. We fill the list and print the first element
// using the function front(), and the last element using the function back().
// Next, we fill our vector with data. We check the size of the vector before 
// we add data and then again after we add data. We print the elements of the
// vector by accessing the elements using []. We create a map that sends strings
// to doubles and access the elements using [] and add a print statement.

#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

int main()
{	// Create a list of doubles
	list<double> list_of_dubs;

	// Add some data
	list_of_dubs.push_back(1.0);
	list_of_dubs.push_back(2.0);
	list_of_dubs.push_back(3.0);
	list_of_dubs.push_back(4.0);

	// Access the first and last elememt
	cout << "The first element of the list: " << list_of_dubs.front() << endl;
	cout << "The last element of the list: " << list_of_dubs.back() << endl;

	cout << endl;
	// Create a vector of doubles
	vector<double> vector_of_dubs;

	// reserve space in the vector
	vector_of_dubs.reserve(15);

	// Check the size of the vector
	cout << "The size of vector_of_dubs is " << vector_of_dubs.size() << endl;

	// Add Data to the vector
	vector_of_dubs.push_back(1.1);
	vector_of_dubs.push_back(4.1);
	vector_of_dubs.push_back(7.1);
	vector_of_dubs.push_back(10.1);
	vector_of_dubs.push_back(13.1);

	// Recheck the size
	cout << "After adding data the size is now " << vector_of_dubs.size() << endl;

	cout << endl;

	// Access the elements
	for (int i = 0; i < vector_of_dubs.size(); i++)
	{		
		cout << "Element " << i+1 << ": " << vector_of_dubs[i] << endl;
	}
	
	vector_of_dubs.clear();

	// Create a map that maps strings to doubles
	map<const char*, double> string_2_doubles;

	// Filling the map
	string_2_doubles["age"] = 30;
	string_2_doubles["checking account balance"] = 1234.56;
	string_2_doubles["current temperature"] = 61.2;

	cout << endl;
	// Access elements
	cout << "Age: " << string_2_doubles["age"] << endl;
	cout << "Checking Account Balance: " << string_2_doubles["checking account balance"] << endl;
	cout << "Current Temperature: " << string_2_doubles["current temperature"] << endl;

	return 0;
}