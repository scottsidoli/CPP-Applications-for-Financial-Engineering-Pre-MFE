// Group E - Excel Visualization
//
// by Scott Sidoli
//
// 6-15-19
//
// OptionData.hpp
//
// Struct containing the option data.

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