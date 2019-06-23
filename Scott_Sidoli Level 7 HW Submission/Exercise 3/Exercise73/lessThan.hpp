// Exercise 7.3 - STL Algorithms
//
// by Scott Sidoli
//
// 5-28-19
//
// lessThan.hpp
//
// lessThan class with global function and function object.

#ifndef lessThan_hpp
#define lessThan_hpp

extern double threshold;

class lessThan
{
private:
	double boundary;					// Threshold value

public:
	lessThan(double value);				// Constructor with a threshold value
	~lessThan();						// Destructor

	bool operator () (double value);	// Overloaded operator
};

// Global function template
template <typename T>
bool less_than(const T& value)
{
	return (value < threshold);
}

#endif 

