// Group B - Perpetual American Options
//
// by Scott Sidoli
//
// 6-10-19
//
// OptionData.hpp
//
// Creates a struct that contains option parameters.

#ifndef OptionData_hpp
#define OptionData_hpp

#include "Types.hpp"

using namespace std;


struct OptionData
{	// Option Data
	Strike_Price K;
	Volatility sig;
	rate r;
	cost_of_carry b;
	curr_stock_price S;
};

#endif