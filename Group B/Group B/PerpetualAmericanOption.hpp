// Group B - Perpetual American Option
//
// by Scott Sidoli
//
// 6-10-19
//
// PerptualAmericanOption.hpp
//
// Perpetual American Option class.

#ifndef PerpetualAmericanOption_hpp
#define PerpetualAmericanOption_hpp

#include "OptionPricing.hpp"
#include <vector>

using namespace std;

struct AmerOptionData
{
	Strike_Price K;																// Expiry time is no longer a data member because
	Volatility sig;																// the perpetual American Option takes the expiry
	rate r;																		// time toward infinity.	
	cost_of_carry b;
	curr_stock_price S;
};

class PerpetualAmericanOption
{
private:
	AmerOptionData data;

	Strike_Price K;
	Volatility sig;
	rate r;
	cost_of_carry b;
	curr_stock_price S;

public:
	PerpetualAmericanOption();													// Default Constructor
	PerpetualAmericanOption(const PerpetualAmericanOption& option);				// Copy Constructor
	virtual ~PerpetualAmericanOption();											// Destructor

	PerpetualAmericanOption& operator = (const PerpetualAmericanOption& source);// Assignment Operator

	// Pricing functions
	double CallPriceAmer();														// Call Price
	double PutPriceAmer();														// Put Price

	// Getter and Setter functions
	Strike_Price GetK() const;													// gets the srike price
	Volatility GetSig() const;													// gets the volatility
	rate Getr() const;															// gets the risk-free interest rate
	cost_of_carry Getb() const;													// gets the cost-of-carry
	curr_stock_price GetS() const;												// gets the current stock price

	void SetOption(Strike_Price K, Volatility sig, rate r, cost_of_carry b, curr_stock_price S);	// Sets the option

	// Taking input values to set the option
	template <typename T> void SetOption(T var)
	{
		// Use the type to set member data
		if (is_same<T, curr_stock_price>::value)
		{
			data.S = var;
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

	// Array Pricing
	// Implementation of call price array. Input is OptionData.
	template <typename T> vector<double> CallPriceAmer(const vector<T>& m_array)
	{
		vector<double> prices;
		for (int i = 0; i < m_array.size(); ++i)
		{
			SetOption(m_array[i]);
			prices.push_back(CallPriceAmer());
		}

		return prices;
	}

	// Implementation of put price array. Input is OptionData.
	template <typename T> vector<double> PutPriceAmer(const vector<T>& m_array)
	{
		vector<double> prices;
		for (int i = 0; i < m_array.size(); ++i)
		{
			SetOption(m_array[i]);
			prices.push_back(PutPriceAmer());
		}

		return prices;
	}

};

#endif