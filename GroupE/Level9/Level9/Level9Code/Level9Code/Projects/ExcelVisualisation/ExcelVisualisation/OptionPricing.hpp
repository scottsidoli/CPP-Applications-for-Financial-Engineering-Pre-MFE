// Group E - Excel Visualization
//
// by Scott Sidoli
//
// 6-15-19
//
// OptionPricing.hpp
//
// Option Pricing functions. Option Sensitivities.

#ifndef OptionPricing_hpp
#define OptionPricing_hpp

#include "OptionData.hpp"

// Overloaded pricing functions
double CallPrice(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S);
double CallPrice(const OptionData& data);

double PutPrice(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S);
double PutPrice(const OptionData& data);

// Overloaded Greeks functions
// Gamma (exact)
double CallPutGamma(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S);
double CallPutGamma(const OptionData& data);

// Gamma (divided difference approximation)
double CallPutGamma(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S, curr_stock_price h);
double CallPutGamma(const OptionData& data, curr_stock_price h);

// Delta for call (exact)
double CallDelta(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S);
double CallDelta(const OptionData& data);

// Delta for call (divided difference approximation)
double CallDelta(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S, curr_stock_price h);
double CallDelta(const OptionData& data, curr_stock_price h);

// Delta for put (exact)
double PutDelta(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S);
double PutDelta(const OptionData& data);

// Delta for put (divided difference approximation)
double PutDelta(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S, curr_stock_price h);
double PutDelta(const OptionData& data, curr_stock_price h);

#endif