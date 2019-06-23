// Group A - Exact Pricing Methods
//
// by Scott Sidoli
//
// 6-9-19
//
// Main.cpp
//
// In this work we create pricing methods for European options
// Questions for Group A are answered in the comments here in Main.cpp. We give an
// outline of file contents here:
// 
// This is done by creating the EuropeanOption class in EuropeanOption.hpp. We outline
// array pricing. We organize the option data in a struct. This is contained in
// OptionData.hpp. 


#include "EuropeanOption.hpp"
#include "MeshArray.hpp"
#include <boost/tuple/tuple_io.hpp>
#include <iomanip>


int main()
{
	// Group A =Exact Solutions of One-Factor Plain Options==================================================
	// 1 part a) Implement the above formula for call and put option pricing using data sets
	// Batch 1 to Batch 4. Check your answers.

	// Batch 1
	Time T1 = (Time) 0.25;
	Strike_Price K1 = (Strike_Price)65;
	Volatility sig1 = (Volatility) 0.30;
	rate r1 = (rate) 0.08;
	cost_of_carry b1 = (cost_of_carry) 0.08;
	curr_stock_price S1 = (curr_stock_price) 60.0;

	// Create option and set parameters
	EuropeanOption option1;
	option1.SetOption(T1, K1, sig1, r1, b1, S1);

	cout << "Batch 1 Call price: " << option1.CallPriceEuro() << endl;
	cout << "Batch 1 Put price: " << option1.PutPriceEuro() << endl;

	// Batch 2
	Time T2 = (Time) 1.0;
	Strike_Price K2 = (Strike_Price) 100.0;
	Volatility sig2 = (Volatility) 0.2;
	rate r2 = (rate) 0.00;
	cost_of_carry b2 = (cost_of_carry) 0.00;
	curr_stock_price S2 = (curr_stock_price) 100.0;

	// Create option and set parameters
	EuropeanOption option2;
	option2.SetOption(T2, K2, sig2, r2, b2, S2);

	cout << "Batch 2 Call price: " << option2.CallPriceEuro() << endl;
	cout << "Batch 2 Put price: " << option2.PutPriceEuro() << endl;

	// Batch 3
	Time T3 = (Time) 1.0;
	Strike_Price K3 = (Strike_Price) 10.0;
	Volatility sig3 = (Volatility) 0.50;
	rate r3 = (rate) 0.12;
	cost_of_carry b3 = (cost_of_carry) 0.12;
	curr_stock_price S3 = (curr_stock_price) 5.0;

	// Create option and set parameters
	EuropeanOption option3;
	option3.SetOption(T3, K3, sig3, r3, b3, S3);

	cout << "Batch 3 Call price: " << option3.CallPriceEuro() << endl;
	cout << "Batch 3 Put price: " << option3.PutPriceEuro() << endl;

	// Batch 4
	Time T4 = (Time) 30.0;
	Strike_Price K4 = (Strike_Price) 100.0;
	Volatility sig4 = (Volatility) 0.30;
	rate r4 = (rate) 0.08;
	cost_of_carry b4 = (cost_of_carry) 0.08;
	curr_stock_price S4 = (curr_stock_price) 100.0;

	// Create option and set parameters
	EuropeanOption option4;
	option4.SetOption(T4, K4, sig4, r4, b4, S4);

	cout << "Batch 4 Call price: " << option4.CallPriceEuro() << endl;
	cout << "Batch 4 Put price: " << option4.PutPriceEuro() << endl;

	cout << endl;
	//================================================================================================================================================================================
		// 1 b) Apply the put-call parity relationship lto compute the put prices given the call prices
		// We use our CalltoPutParity function.

	cout << "Using Parity: " << endl;
	cout << "Batch 1 Put Price: " << option1.CalltoPutParity() << endl;
	cout << "Batch 2 Put Price: " << option2.CalltoPutParity() << endl;
	cout << "Batch 3 Put Price: " << option3.CalltoPutParity() << endl;
	cout << "Batch 4 Put Price: " << option4.CalltoPutParity() << endl;

	cout << endl;

	// Now we check if the batches satisfy put-call parity.
	cout << "Batch 1 satisfies parity: " << (option1.ParityChecker() ? "True." : "False.") << endl;
	cout << "Batch 2 satisfies parity: " << (option2.ParityChecker() ? "True." : "False.") << endl;
	cout << "Batch 3 satisfies parity: " << (option3.ParityChecker() ? "True." : "False.") << endl;
	cout << "Batch 4 satisfies parity: " << (option4.ParityChecker() ? "True." : "False.") << endl;
	//================================================================================================================================================================================	
		// 1 c) We compute the option prices for a monotonically increasing ranges of values for S, the current stock price.
		// Let S = 10, 11, 12, ... 50. We use our MeshArray.
	curr_stock_price S_start = (curr_stock_price) 10.0;
	curr_stock_price S_end = (curr_stock_price) 50.0;
	curr_stock_price S_interval = (curr_stock_price) 1.0;

	// Compute the Call prices and Put prices
	vector<curr_stock_price> S_array = MeshArray(S_start, S_end, S_interval);
	vector<double> S_CallPrices = option1.CallPriceEuro(S_array);
	vector<double> S_PutPrices = option1.PutPriceEuro(S_array);

	cout << endl;
	cout << "S - Value, Call Price, Put Price" << endl;
	PrintArray(S_array, S_CallPrices, S_PutPrices);

	cout << endl;

	// reset the option
	option1.SetOption(T1, K1, sig1, r1, b1, S1);
	//================================================================================================================================================================================
		// 1 d) We create a matrix pricer to determine prices as we vary two parameters. We use expiry time and volatility.

		// Create Vector of T-values. This is where we change our option parameter.
	Time T_start = (Time) 0.25;
	Time T_end = (Time) 5.0;
	Time T_interval = (Time) 0.25;
	vector<Time> T_array = MeshArray(T_start, T_end, T_interval);

	// Create Vector of sig-values. This is where we change our second option parameter.

	Volatility sig_start = (Volatility) 0.05;
	Volatility sig_end = (Volatility) 1.00;
	Volatility sig_interval = (Volatility) 0.05;
	vector<Volatility> sig_array = MeshArray(sig_start, sig_end, sig_interval);

	// Create two-dimensional array to store call prices and put prices
	typedef boost::tuple<double, double> CallPrice_PutPrice;
	const int num_rows = 50;
	const int num_columns = 50;
	CallPrice_PutPrice PriceMatrix[num_rows][num_columns]; // Price matrix stores call and put price when parameter I takes value x and parameter J takes value y.
														   // In this example we use expiry time and volatility. 

	cout << "(Time, Volatility, (Call Price Put Price))" << endl;

	for (int i = 0; i < T_array.size(); ++i)
	{
		option1.SetOption(T_array[i]);

		for (int j = 0; j < sig_array.size(); ++j)
		{
			option1.SetOption(sig_array[j]);
			PriceMatrix[i][j] = CallPrice_PutPrice(option1.CallPriceEuro(), option1.PutPriceEuro());

			cout << "(" << T_array[i] << ", " << sig_array[j] << ", " << PriceMatrix[i][j] << ")" << endl;
		}
	}
	cout << endl;

	// reset the option
	option1.SetOption(T1, K1, sig1, r1, b1, S1);
	//==============================================================================================================================================================================
		// Group A =Option Sensitivities, aka the Greeks ==================================================
		// 2 a) We implement formula for gamma for call and put future option pricing. We also compute
		// Delta for call and Delta for put.
	EuropeanOption greek_option;
	Time T_greek = (Time) 0.5;
	Strike_Price K_greek = (Strike_Price)100;
	Volatility sig_greek = (Volatility) 0.36;
	rate r_greek = (rate) 0.1;
	cost_of_carry b_greek = (cost_of_carry)0;
	curr_stock_price S_greek = (curr_stock_price)105;

	greek_option.SetOption(T_greek, K_greek, sig_greek, r_greek, b_greek, S_greek);

	cout << "Call Gamma: " << greek_option.CallPutGammaEuro() << endl;
	cout << "Call Delta: " << greek_option.CallDeltaEuro() << endl;
	cout << "Put Delta: " << greek_option.PutDeltaEuro() << endl;
	//================================================================================================================================================================================
		// 2 b) In the same spirit as the first part, we use our previous code to compute the call delta 
		// price for a monotonically increasing range of underlying values of S. We take S to range from 
		// 10 up to 50. We use S_array from the previous question.

	vector<double> delta_call_array = greek_option.CallDeltaEuro(S_array);

	cout << "S - Value, Call Delta" << endl;
	PrintArray(S_array, delta_call_array);

	cout << endl;

	// reset the option
	greek_option.SetOption(T_greek, K_greek, sig_greek, r_greek, b_greek, S_greek);
	//================================================================================================================================================================================
		// 2 c) We create a new matrix that holds gamma's as we input a matrix of parameters. As before,
		// we use expiry time and volatility.

	cout << "(Time, Volatility, Gamma)" << endl;
	double Gamma_Matrix[num_rows][num_columns];

	for (int i = 0; i < T_array.size(); ++i)
	{
		greek_option.SetOption(T_array[i]);			// Set the ith row by using the expiry time. Setting the row means we set the option parameter.

		for (int j = 0; j < sig_array.size(); ++j)
		{
			greek_option.SetOption(sig_array[j]);	// Set the column by using the volatility. Here, we set the option parameter with column value.
			Gamma_Matrix[i][j] = greek_option.CallPutGammaEuro();

			cout << "(" << T_array[i] << ", " << sig_array[j] << ", " << Gamma_Matrix[i][j] << ")" << endl;
		}
	}
	cout << endl;
	// reset the option
	greek_option.SetOption(T_greek, K_greek, sig_greek, r_greek, b_greek, S_greek);
	//================================================================================================================================================================================
		// 2 d) We repeat parts a) and b) but now we use the formulas for the appoximations.


	curr_stock_price h = (curr_stock_price) 0.05;

	cout << "Gamma and Delta from the exact formula: " << endl;
	cout << "Gamma: " << greek_option.CallPutGammaEuro() << endl;
	cout << "Delta for call: " << greek_option.CallDeltaEuro() << endl;
	cout << "Delta for put: " << greek_option.PutDeltaEuro() << endl;

	cout << endl;

	cout << "Gamma and Delta from divided difference approximation: " << endl;
	cout << "Gamma: " << greek_option.CallPutGammaEuro(h) << endl;
	cout << "Delta for call: " << greek_option.CallDeltaEuro(h) << endl;
	cout << "Delta for put: " << greek_option.PutDeltaEuro(h) << endl;


	return 0;
}