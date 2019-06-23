// Group B - Perpetual American Options
//
// by Scott Sidoli
//
// 6-10-19
//
// OptionPricing.hpp
//
// Global option pricing functions and greek functions.

#ifndef OptionPricing_hpp
#define OptionPricing_hpp

#include "OptionData.hpp"

// pricing functions
double CallPrice(Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S);
double PutPrice(Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S);

#endif