// Group E - Excel Visualization
//
// by Scott Sidoli
//
// 6-15-19
//
// Main.cpp
//
// In this work we use the excel visualization functionality to produce spreadsheet output for the 
// four batches. It should be noted that some of the includes need to have the path adjusted to work
// other machines. We describe the four batches, create row labels for the S value and column labels
// are the call/put prices for a given batch. We use an if-else loop inside a for-loop to produce the
// matrix output and then send the output to an excel spreadsheet. We include all our option class 
// functionality.

#include "C:\Users\ssido\OneDrive\Desktop\Level9\Level9\Level9Code\Level9Code\UtilitiesDJD\ExcelDriver\ExcelDriverLite.hpp"
#include "C:\Users\ssido\OneDrive\Desktop\Level9\Level9\Level9Code\Level9Code\UtilitiesDJD\ExcelDriver\Utilities.hpp"
#include "C:\Users\ssido\OneDrive\Desktop\Level9\Level9\Level9Code\Level9Code\UtilitiesDJD\VectorsAndMatrices\Vector.hpp"
#include "C:\Users\ssido\OneDrive\Desktop\Level9\Level9\Level9Code\Level9Code\UtilitiesDJD\ExceptionClasses\DatasimException.hpp"
#include <iostream>
#include "EuropeanOption.hpp"
#include "MeshArray.hpp"
#include <boost/tuple/tuple_io.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <cmath>
#include <boost/numeric/ublas/matrix.hpp>
#include "C:\Users\ssido\OneDrive\Desktop\Level9\Level9\Level9Code\Level9Code\UtilitiesDJD\VectorsAndMatrices\NestedMatrix.hpp" 


using NumericMatrix = boost::numeric::ublas::matrix<double>; // using NumericMatrix = NestedMatrix<double>; 
 
using namespace std;

int main()
{
	curr_stock_price S_start = (curr_stock_price) 10.0;
	curr_stock_price S_end = (curr_stock_price) 50.0;
	curr_stock_price S_interval = (curr_stock_price) 1.0;

	vector<curr_stock_price> S_array = MeshArray(S_start, S_end, S_interval);

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

	// Now we create Row and column labels Rows labeled by S-value, column by Batch num call/put
	stringstream ss;
	string str;
	list<string> rowLabels;
	for (unsigned int i = 0; i < S_array.size(); ++i)
	{
		ss << i + 10;
		ss >> str;
		rowLabels.push_back(str);
		ss.clear();
	}

	list<string> colLabels{ "Batch 1 Call", "Batch 1 Put", "Batch 2 Call", "Batch 2 Put", "Batch 3 Call", "Batch 3 Put",
	"Batch 4 Call", "Batch 4 Put"};

	// Now we write the sheet name
	string sheetName("Option Prices");

	
	NumericMatrix PriceMatrix(rowLabels.size(), colLabels.size());
	for (unsigned int i = 0; i < PriceMatrix.size1(); i++)
	{
		for (unsigned int j = 0; j < PriceMatrix.size2(); j++)
		{
			if (j == 0)
			{
				option1.SetOption(S_array[i]);
				PriceMatrix(i, j) = option1.CallPriceEuro();
			}
			else if ( j == 1)
			{
				option1.SetOption(S_array[i]);
				PriceMatrix(i, j) = option1.PutPriceEuro();
			}
			else if (j == 2)
			{
				option2.SetOption(S_array[i]);
				PriceMatrix(i, j) = option2.CallPriceEuro();
			}
			else if (j == 3)
			{
				option2.SetOption(S_array[i]);
				PriceMatrix(i, j) = option2.PutPriceEuro();
			}
			else if (j == 4)
			{
				option3.SetOption(S_array[i]);
				PriceMatrix(i, j) = option3.CallPriceEuro();
			}
			else if (j == 5)
			{
				option3.SetOption(S_array[i]);
				PriceMatrix(i, j) = option3.PutPriceEuro();
			}
			else if (j == 6)
			{
				option4.SetOption(S_array[i]);
				PriceMatrix(i, j) = option4.CallPriceEuro();
			}
			else if (j == 7)
			{
				option4.SetOption(S_array[i]);
				PriceMatrix(i, j) = option4.PutPriceEuro();
			}
		}
	}

	ExcelDriver& excel = ExcelDriver::Instance();
	excel.MakeVisible(true);

	long row = 1;
	long col = 1;
	excel.AddMatrix<NumericMatrix>(PriceMatrix, sheetName, rowLabels, colLabels, row, col);
	return 0;
}