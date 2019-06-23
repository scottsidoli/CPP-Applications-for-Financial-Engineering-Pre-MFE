// Exercise 5.1.2 - Tuple
//
// by Scott Sidoli
//
// 5-29-19
//
// Main.cpp
//
// In this exercise, we experiment with tuples from boost. Tuples can store data of different
// types as a single entity. This allows us to circumvent the process of creating a new class.
// We create a typedef 'Person' that contains the name, age, and length. We create a function
// that prints the person tuple. We use get<T>() member function to access the data. We create
// a few instances of people and print them. We increment the age of one of the people.

#include <boost\tuple\tuple.hpp>
#include <boost\tuple\tuple_io.hpp>
#include <string>
#include <iostream>
using namespace std;
using boost::tuple;

void Print(const boost::tuple<string, int, int>& person)
{
	cout << "Name: " << person.get<0>() << endl;
	cout << "Age: " << person.get<1>() << endl;
	cout << "Length: " << person.get<2>() << endl;
}

int main()
{
	typedef boost::tuple<string, int, int> Person;

	// Create instances of 'Person'
	Person P1 = boost::make_tuple(string("James"), 26, 75);
	Person P2 = boost::make_tuple(string("Giancarlo"), 32, 72);
	Person P3 = boost::make_tuple(string("Scott"), 31, 73);

	// Print Persons
	Print(P1);
	Print(P2);
	Print(P3);

	// increment the age of the P2
	P2.get<1>() += 1;

	// Print again
	Print(P1);
	Print(P2);
	Print(P3);
	return 0;
}