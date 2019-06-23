// Group B - Perpetual American Option
//
// by Scott Sidoli
//
// 6-10-19
//
// Main.cpp
//
// We program the formula for pricing perptual American Options (part a). We test the data.
// Again, we take the input of an array to compute prices for a varying parameter. We then 
// code a matrix pricer that allows us to vary two parameters. The structure of this project
// mirrors the structure of group A. We have defined types for the option parameters in
// Types.hpp. We have the struct in OptionData.hpp and we have our pricing functions in
// OptionPricing.hpp. The perpetual American Option Class is in PerpetualAmericanOption.hpp
// We have MeshArray.hpp to use the method for creating an array of parameter values.

#include "PerpetualAmericanOption.hpp"
#include "MeshArray.hpp"
#include <boost/tuple/tuple_io.hpp>

int main()
{	// 2 b)
	// We test our perpetual American option class. First we create the option and set the data.
	PerpetualAmericanOption Amer_Option;
	Strike_Price K = (Strike_Price)100.0;
	Volatility sig = (Volatility) 0.1;
	rate r = (rate)0.1;
	cost_of_carry b = (cost_of_carry)0.02;
	curr_stock_price S = (curr_stock_price)110;
	Amer_Option.SetOption(K,sig,r,b,S);

	// Now we print the call and put prices.
	cout << "Perpetual American Option Call Price: " << Amer_Option.CallPriceAmer() << endl;
	cout << "Perpetual American Option Put Price: " <<Amer_Option.PutPriceAmer() << endl;
	
	cout << endl;
	//============================================================================================== =
	// 2 c) We create a mesh array of current stock prices and determine the option prices.
	curr_stock_price start = (curr_stock_price) 10.0;
	curr_stock_price end = (curr_stock_price) 50.0;
	curr_stock_price interval = (curr_stock_price) 1.0;

	vector<curr_stock_price> S_array = MeshArray(start, end, interval);

	// Create vector of Calls and puts
	vector<double> CallPrices = Amer_Option.CallPriceAmer(S_array);
	vector<double> PutPrices = Amer_Option.PutPriceAmer(S_array);

	
	// Print the result
	cout << "S - value, Call, Put " << endl;
	PrintArray(S_array, CallPrices, PutPrices);

	// Reset the Option
	Amer_Option.SetOption(K, sig, r, b, S);
	cout << endl;
	//============================================================================================== =
	// 2 d) We create a matrix of option parameters and output a matrix of option prices.
	// For the parameters, we use K and sig. We create two vectors.
	Strike_Price K_start = (Strike_Price)80.0;
	Strike_Price K_end = (Strike_Price)120.0;
	Strike_Price K_interval = (Strike_Price)1.0;
	vector<Strike_Price> K_array = MeshArray(K_start, K_end, K_interval);

	Volatility sig_start = (Volatility) 0.01;
	Volatility sig_end = (Volatility) 0.20;
	Volatility sig_interval = (Volatility)0.01;
	vector<Volatility> sig_array = MeshArray(sig_start, sig_end, sig_interval);

	// Create a Matrix to store the call prices and put prices.
	typedef boost::tuple<double, double> CallPrice_PutPrice;
	const int num_rows = 50;
	const int num_cols = 50;
	CallPrice_PutPrice PriceMatrix[num_rows][num_cols]; // Price matrix stores call and put price when parameter I takes value x and parameter J takes value y.
														   // In this example we use expiry time and volatility. 

	cout << "(Strike Price, Volatility, (Call Price Put Price))" << endl;

	for (int i = 0; i < K_array.size(); ++i)
	{
		Amer_Option.SetOption(K_array[i]);

		for (int j = 0; j < sig_array.size(); ++j)
		{
			Amer_Option.SetOption(sig_array[j]);
			PriceMatrix[i][j] = CallPrice_PutPrice(Amer_Option.CallPriceAmer(), Amer_Option.PutPriceAmer());

			cout << "(" << K_array[i] << ", " << sig_array[j] << ", " << PriceMatrix[i][j] << ")" << endl;
		}
	}
	cout << endl;

	// reset the option
	Amer_Option.SetOption(K, sig, r, b, S);
	return 0;
}