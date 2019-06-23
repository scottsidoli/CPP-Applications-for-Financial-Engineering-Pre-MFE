// Group A - Exact Pricing Methods
//
// by Scott Sidoli
//
// 6-9-19
//
// OptionData.hpp
//
// Contains the struct of option data. Bundles data together and allows for flexibility
// in getter and setter functions.

#ifndef OptionData_hpp
#define OptionData_hpp

#include "Types.hpp"

using namespace std;


struct OptionData
{	// Option Data
	Time T;
	Strike_Price K;
	Volatility sig;
	rate r;
	cost_of_carry b;
	curr_stock_price S;
};

#endif