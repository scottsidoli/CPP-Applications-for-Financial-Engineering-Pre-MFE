// Exercise 5.1.4 - Random Number Generation
//
// by Scott Sidoli
//
// 5-30-19
//
// Main.cpp
//
// In this exercise, we experiment with a random number generator. We create a discrete uniform
// distribution with values ranging from 1 to 6 inclusively. We keep track of the count and 
// use this to get the frequency. We ask the user to determine the number of trials and then
// run the simulation.

#include <boost\random.hpp>
#include <boost\random\detail\const_mod.hpp>
#include <ctime>
#include <map>
#include <iostream>

using namespace std;

int main()
{
	// Throwing dice. 
	// Mersenne Twister. 
	boost::random::mt19937 myRng;

	// Set the seed. 
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

	// Uniform in range [1,6] 
	boost::random::uniform_int_distribution<int> six(1, 6);
	
	map<int, long> statistics;				// Structure to hold outcome + frequency
	int outcome;							// Current outcome

	// Setting the number of trials
	cout << "How many trials? ";
	int n;
	cin >> n;
	
	// Initializing the count
	for (int i = 0; i < 6; ++i)
		statistics[i + 1] = 0;
	
	// Dice throw
	for (int i = 0; i < n; ++i)
	{
		outcome = six(myRng);
		statistics[outcome]++;
	}

	// Setting the precision of the output
	cout.precision(6);

	cout << endl;

	// Desired print statement
	for (int i = 0; i < 6; ++i)
		cout << "Trial " << i + 1 << " has " << 100.0 * double(statistics[i + 1]) / double(n) << "% outcomes" << endl;


	return 0;
}