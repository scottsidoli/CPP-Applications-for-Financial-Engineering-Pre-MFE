// Group D - Advanced Monte Carlo 
// 
// by Scott Sidoli
//
// 6-14-19
//
// TestMC.cpp
//
// Here we have the implementation of the formula to find estimates of the standard deviation
// and the standard error. The input is the vector of call prices. The size of the vector is 
// determined by the number of simulations.

#ifndef SDSE_hpp
#define SDSE_hpp

#include <cmath>
#include <vector>

double SD(const vector<double>& Opt_array, double r, double T)
{
	double c_TJ = 0.0;
	double c_TJsqr = 0.0;
	double NSim = Opt_array.size();
	for (unsigned long i = 0; i < Opt_array.size(); ++i)
	{
		c_TJ += Opt_array[i];
		c_TJsqr += (Opt_array[i] * Opt_array[i]);
	}

	return sqrt((c_TJsqr - (1 / NSim)*(c_TJ * c_TJ)) / (NSim - 1)) * exp(-r * T);
}

double SE(const vector<double>& Opt_array, double r, double T)
{
	return SD(Opt_array, r, T) / sqrt(Opt_array.size());
}

#endif