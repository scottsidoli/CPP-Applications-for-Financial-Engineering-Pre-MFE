// Group A - Exact Pricing Methods
//
// by Scott Sidoli
//
// 6-9-19
//
// OptionPricing.cpp
//
// Contains base function declarations for pricing functions and greeks. Overloaded to allow
// for the input of a struct. We also have the declarations of the pricing functions using 
// the divided difference appoximation. Formulas for BS, divided difference functions and 
// greeks are here.

#include "OptionPricing.hpp"
#include "EuropeanOption.hpp"
#include "NormalDistribution.hpp"
#include <cmath>




// Exact Pricing of C and P options =============================================================================

// Call option price (Black-Scholes)
double CallPrice(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S)
{
	double d1 = (log(S / K) + (b + (sig*sig)*0.5) * T) / (sig * sqrt(T));
	double d2 = d1 - sig * sqrt(T);

	return S * exp((b - r)*T) * N(d1) - K * exp(-r * T) * N(d2);
}

double CallPrice(const OptionData& data)
{
	return CallPrice(data.T, data.K, data.sig, data.r, data.b, data.S);
}

// Put option price (Black-Scholes)

double PutPrice(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S)
{
	double d1 = (log(S / K) + (b + (sig*sig)*0.5) * T) / (sig * sqrt(T));
	double d2 = d1 - sig * sqrt(T);

	return K * exp(-r * T) * N(-d2) - S * exp((b - r) * T) * N(-d1);
}

double PutPrice(const OptionData& data)
{
	return PutPrice(data.T, data.K, data.sig, data.r, data.b, data.S);
}

// Option sensitivities aka the Greeks===============================================================================

// Gamma (Exact formula)
double CallPutGamma(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S)
{
	double d1 = (log(S / K) + (b + (sig*sig)*0.5) * T) / (sig * sqrt(T));

	return (n(d1) * exp((b - r)*T)) / (S*sig*sqrt(T));
}

double CallPutGamma(const OptionData& data)
{
	return CallPutGamma(data.T, data.K, data.sig, data.r, data.b, data.S);
}

// Gamma (divided difference approximation)
double CallPutGamma(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S, curr_stock_price h)
{
	curr_stock_price S1, S2;
	S1 = S - h;
	S2 = S + h;

	return (CallPrice(T, K, sig, r, b, S2) - 2 * CallPrice(T, K, sig, r, b, S) + CallPrice(T, K, sig, r, b, S1)) / (h*h);
}

double CallPutGamma(const OptionData& data, curr_stock_price h)
{
	return CallPutGamma(data.T, data.K, data.sig, data.r, data.b, data.S, h);
}

// Delta for Call (Exact formula)
double CallDelta(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S)
{
	double d1 = (log(S / K) + (b + (sig*sig)*0.5) * T) / (sig * sqrt(T));

	return exp((b - r) * T) * N(d1);
}

double CallDelta(const OptionData& data)
{
	return CallDelta(data.T, data.K, data.sig, data.r, data.b, data.S);
}

// Delta for Call (divided difference approximation)
double CallDelta(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S, curr_stock_price h)
{
	curr_stock_price S1, S2;
	S1 = S - h;
	S2 = S + h;

	return (CallPrice(T, K, sig, r, b, S2) - CallPrice(T, K, sig, r, b, S1)) / (2 * h);
}

double CallDelta(const OptionData& data, curr_stock_price h)
{
	return CallDelta(data.T, data.K, data.sig, data.r, data.b, data.S, h);
}

// Delta for Put (Exact Formula)
double PutDelta(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S)
{
	double d1 = (log(S / K) + (b + (sig*sig)*0.5) * T) / (sig * sqrt(T));

	return -exp((b - r)*T) * N(-d1);
}

double PutDelta(const OptionData& data)
{
	return PutDelta(data.T, data.K, data.sig, data.r, data.b, data.S);
}

// Delta for put (divided difference approximation)
double PutDelta(Time T, Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S, curr_stock_price h)
{
	curr_stock_price S1, S2;
	S1 = S - h;
	S2 = S + h;

	return (PutPrice(T, K, sig, r, b, S2) - PutPrice(T, K, sig, r, b, S1)) / (2 * h);
}

double PutDelta(const OptionData& data, curr_stock_price h)
{
	return PutDelta(data.T, data.K, data.sig, data.r, data.b, data.S, h);
}
