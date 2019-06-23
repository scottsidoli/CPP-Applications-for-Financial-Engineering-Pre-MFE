// Group B - Perpetual American Option
//
// by Scott Sidoli
//
// 6-10-19
//
// PerpetualAmericanOption.cpp
//
// Constructors and destructors, getter and setter functions, Call and Put pricing functions.

#include "PerpetualAmericanOption.hpp"
#include "OptionPricing.hpp"
#include <vector>
#include <cmath>
using namespace std;

PerpetualAmericanOption::PerpetualAmericanOption()
{
	data.K = 50;
	data.sig = 0.50;
	data.r = 0.05;
	data.b = r;
	data.S = 50.0;
}

PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption& option)				// Copy Constructor
{
	data.K = option.data.K;
	data.sig = option.data.sig;
	data.r = option.data.r;
	data.b = option.data.b;
	data.S = option.data.S;
}

PerpetualAmericanOption::~PerpetualAmericanOption()													// Destructor
{

}

PerpetualAmericanOption& PerpetualAmericanOption::operator = (const PerpetualAmericanOption& option2)
{
	if (this == &option2)
		return *this;

	data.K = option2.data.K;
	data.sig = option2.data.sig;
	data.r = option2.data.r;
	data.b = option2.data.b;
	data.S = option2.data.S;

	return *this;
}

// Pricing functions
double PerpetualAmericanOption::CallPriceAmer()
{
	return CallPrice(data.K, data.sig, data.r, data.b, data.S);
}
double PerpetualAmericanOption::PutPriceAmer()
{
	return PutPrice(data.K, data.sig, data.r, data.b, data.S);
}

// Getter and Setter functions
Strike_Price PerpetualAmericanOption::GetK() const													// gets the srike price
{
	return data.K;
}
Volatility PerpetualAmericanOption::GetSig() const													// gets the volatility
{
	return data.sig;
}
rate PerpetualAmericanOption::Getr() const															// gets the risk-free interest rate
{
	return data.r;
}
cost_of_carry PerpetualAmericanOption::Getb() const													// gets the cost-of-carry
{
	return data.b;
}
curr_stock_price PerpetualAmericanOption::GetS() const												// gets the current stock price
{
	return data.S;
}
void PerpetualAmericanOption::SetOption(Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S)	// Sets the option
{
	SetOption(K);
	SetOption(sig);
	SetOption(r);
	SetOption(b);
	SetOption(S);
}