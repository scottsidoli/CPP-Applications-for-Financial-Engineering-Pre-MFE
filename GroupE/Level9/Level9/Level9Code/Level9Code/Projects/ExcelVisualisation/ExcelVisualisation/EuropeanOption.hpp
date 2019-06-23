// Group E - Excel Visualization
//
// by Scott Sidoli
//
// 6-15-19
//
// EuropeanOption.hpp
//
// European Option class.

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

#include "OptionData.hpp"
#include <vector>
using namespace std;

class EuropeanOption
{
private:
	OptionData data;

	Time T;
	Strike_Price K;
	Volatility sig;
	rate r;
	cost_of_carry b;
	curr_stock_price S;



public:
	EuropeanOption();											// Default Constructor
	EuropeanOption(const EuropeanOption& option);				// Copy Constructor
	virtual ~EuropeanOption();									// DEstructor

	EuropeanOption& operator = (const EuropeanOption& option);	// Assignment Operator

	// Getter and Setter Functions
	Time GetT() const;											// Get the expiry time
	Strike_Price GetK() const;									// Get the strike price
	Volatility GetSig() const;									// Get the volatility
	rate Getr()	const;											// Get the risk-free interest rate
	cost_of_carry Getb() const;									// Get the cost-of-carry
	curr_stock_price GetS() const;								// Get the current stock price

	OptionData GetData() const;									// Get the option data

	// Set the option
	void SetOption(Time newT, Strike_Price newK, Volatility newSig, rate newr, cost_of_carry newb, curr_stock_price newS);

	// Option Sensitivities
	double CallPutGammaEuro() const;							// Gamma (exact)
	double CallPutGammaEuro(curr_stock_price h) const;			// Gamma (divided difference)

	double CallDeltaEuro() const;								// Delta for call (exact)
	double CallDeltaEuro(curr_stock_price h) const;				// Delta for call (divided difference)

	double PutDeltaEuro() const;								// Delta for put (exact)
	double PutDeltaEuro(curr_stock_price h) const;				// Delta for put (divided difference)

	// Input a range of values for S, the current stock price, and output a vector of deltas for call/put
	vector<double> CallDeltaEuro(const vector<curr_stock_price>& S_array);			// Exact formula
	vector<double> CallDeltaEuro(const vector<curr_stock_price>& S_array, curr_stock_price h); // Difference approximation

	vector<double> PutDeltaEuro(const vector<curr_stock_price>& S_array);			// Exact formula
	vector<double> PutDeltaEuro(const vector<curr_stock_price>& S_array, curr_stock_price h);	// Difference approx.

	// Exact price functions for euro call/Put
	double CallPriceEuro();										// Call Price
	double PutPriceEuro();										// Put Price
	bool ParityChecker();										// Option type checker
	double CalltoPutParity();										// Put Price calculated from parity relationship

	// Implementation of call price array. Input is OptionData.
	template <typename T> vector<double> CallPriceEuro(const vector<T>& m_array)
	{
		vector<double> prices;
		for (int i = 0; i < m_array.size(); ++i)
		{
			SetOption(m_array[i]);
			prices.push_back(CallPriceEuro());
		}

		return prices;
	}

	// Implementation of put price array. Input is OptionData.
	template <typename T> vector<double> PutPriceEuro(const vector<T>& m_array)
	{
		vector<double> prices;
		for (int i = 0; i < m_array.size(); ++i)
		{
			SetOption(m_array[i]);
			prices.push_back(PutPriceEuro());
		}

		return prices;
	}

	// Taking input to set option data
	template <typename T> void SetOption(T var)
	{
		// Use the type to set member data
		if (is_same<T, curr_stock_price>::value)
		{
			data.S = var;
		}
		else if (is_same<T, Time>::value)
		{
			data.T = var;
		}
		else if (is_same<T, Strike_Price>::value)
		{
			data.K = var;
		}
		else if (is_same<T, Volatility>::value)
		{
			data.sig = var;
		}
		else if (is_same<T, rate>::value)
		{
			data.r = var;
		}
		else if (is_same<T, cost_of_carry>::value)
		{
			data.b = var;
		}
	}
};

#endif