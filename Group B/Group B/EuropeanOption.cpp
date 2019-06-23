// Group B - Perpetual American Option
//
// by Scott Sidoli
//
// 6-10-19
//
// EuropeanOption.cpp
//
// Implementations of member functions of the EuropeanOption class.

#ifndef EuropeanOption_cpp
#define EuropeanOption_cpp
#include "OptionPricing.hpp"
#include "EuropeanOption.hpp"
#include <cmath>


using namespace std;



// Constructors and Destructor =====================================================================
EuropeanOption::EuropeanOption()
{	// Default call option
	// Initial values chosen arbitrarily
	data.T = 60.0;
	data.K = 50.0;
	data.sig = 0.50;
	data.r = 0.05;
	data.S = 50.0;
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{	// Copy Constructor
	data.T = o2.data.T;
	data.K = o2.data.K;
	data.sig = o2.data.sig;
	data.r = o2.data.r;
	data.S = o2.data.S;
}

EuropeanOption::~EuropeanOption()
{	// Destructor

}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{
	if (this == &option2)
		return *this;

	data.T = option2.data.T;
	data.K = option2.data.K;
	data.sig = option2.data.sig;
	data.r = option2.data.r;
	data.S = option2.data.S;

	return *this;
}

// Getter and Setter Functions ====================================================================
Time EuropeanOption::GetT() const
{	// Get expiry time
	return data.T;
}

Strike_Price EuropeanOption::GetK() const
{	// Get strike price
	return data.K;
}

Volatility EuropeanOption::GetSig() const
{	// Get the volatility
	return data.sig;
}

rate EuropeanOption::Getr() const
{	// Get the risk-free interest rate
	return data.r;
}

curr_stock_price EuropeanOption::GetS() const
{	// Get the current stock price
	return data.S;
}

cost_of_carry EuropeanOption::Getb() const
{	// Get the cost-of-carry
	return data.b;
}

OptionData EuropeanOption::GetData() const
{	// Get the option data
	return data;
}

void EuropeanOption::SetOption(Time newT, Strike_Price newK, Volatility newsig, rate newr, cost_of_carry newb, curr_stock_price newS)
{	// Set the data of a European Option
	SetOption(newT);
	SetOption(newK);
	SetOption(newsig);
	SetOption(newr);
	SetOption(newb);
	SetOption(newS);
}

// Option Sensitivities ============================================================================

double EuropeanOption::CallPutGammaEuro() const
{	// Gamma (exact)
	return CallPutGamma(data);
}

double EuropeanOption::CallPutGammaEuro(curr_stock_price h) const
{	// Gamma (divided difference)
	return CallPutGamma(data, h);
}

double EuropeanOption::CallDeltaEuro() const
{	// Delta for call (exact)
	return CallDelta(data);
}

double EuropeanOption::CallDeltaEuro(curr_stock_price h) const
{	// Delta for call (divided difference)
	return CallDelta(data, h);
}

double EuropeanOption::PutDeltaEuro() const
{	// Delta for put (exact)
	return PutDelta(data);
}

double EuropeanOption::PutDeltaEuro(curr_stock_price h) const
{	// Delta for put (divided difference)
	return PutDelta(data, h);

}

// Input a range of values for S, the current stock price, and output a vector of deltas for call/put
vector<double> EuropeanOption::CallDeltaEuro(const vector<curr_stock_price>& S_array)
{// Delta for call as a function of current stock price (Exact formula)
	vector<double> deltas;
	for (int i = 0; i < S_array.size(); ++i)
	{
		SetOption(S_array[i]);	// Changes the value of S
		deltas.push_back(CallDeltaEuro());
	}

	return deltas;
}

vector<double>  EuropeanOption::CallDeltaEuro(const vector<curr_stock_price>& S_array, curr_stock_price h)
{	// Delta for call as a function of current stock price (Difference approximation)
	vector<double> deltas;
	for (int i = 0; i < S_array.size(); ++i)
	{
		SetOption(S_array[i]);	// Changes the value of S
		deltas.push_back(CallDeltaEuro(h));
	}

	return deltas;
}

vector<double> EuropeanOption::PutDeltaEuro(const vector<curr_stock_price>& S_array)
{	// Delta for put as a function of current stock price (Exact formula)
	vector<double> deltas;
	for (int i = 0; i < S_array.size(); ++i)
	{
		SetOption(S_array[i]);	// Change the value of S
		deltas.push_back(PutDeltaEuro());
	}

	return deltas;
}

vector<double> EuropeanOption::PutDeltaEuro(const vector<curr_stock_price>& S_array, curr_stock_price h)
{	// Delta for put as a function of current stock price (Difference approx.)
	vector<double> deltas;
	for (int i = 0; i < S_array.size(); ++i)
	{
		SetOption(S_array[i]);	// Change the value of S
		deltas.push_back(PutDeltaEuro(h));
	}

	return deltas;
}

// Call/Put Pricing =================================================================================
double EuropeanOption::CallPriceEuro()
{
	return CallPrice(data);
}

double EuropeanOption::PutPriceEuro()
{
	return PutPrice(data);
}

double EuropeanOption::CalltoPutParity()
{
	return CallPriceEuro() - data.S + data.K * exp(-data.r * data.T);
}

bool EuropeanOption::ParityChecker()
{
	double tolerance = 0.000001;
	double putprice1, putprice2;

	putprice1 = CallPriceEuro() - data.S + data.K * exp(-data.r * data.T);
	putprice2 = PutPriceEuro();

	return(fabs(putprice1 - putprice2) < tolerance);
}

#endif

