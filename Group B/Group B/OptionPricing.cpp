// Group B - Perpetual American Options
//
// by Scott Sidoli
//
// 6-10-19
//
// OptionPricing.cpp
//
// Implementations of option price formulas and Greeks

#include "OptionPricing.hpp"
#include <cmath>




// Exact Pricing of C and P options =============================================================================

// Call option price (Black-Scholes)
double CallPrice(Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S)
{
	double y1 = 0.5 - b / (sig*sig) + sqrt((b / (sig*sig) - 0.5)*(b / (sig*sig) - 0.5) + 2 * r / (sig*sig));

	return K / (y1 - 1.0) * pow(((y1 - 1.0) / y1 * S / K), y1);
}

// Put option price (Black-Scholes)

double PutPrice(Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S)
{
	double y2 = 0.5 - b / (sig*sig) - sqrt((b / (sig*sig) - 0.5)*(b / (sig*sig) - 0.5) + 2 * r / (sig*sig));

	return K / (1.0 - y2) * pow(((y2 - 1.0) / y2 * S / K), y2);
}