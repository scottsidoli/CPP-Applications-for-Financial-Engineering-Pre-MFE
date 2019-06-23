// Group D - Advanced Monte Carlo 
// 
// by Scott Sidoli
//
// 6-14-19
//
// TestMC.cpp
//
// We take CEV model with a choice of the elaticity parameter
// and the Euler method. We give option price and number of times
// S hits the origin.
//
// (C) Datasim Education BC 2008-2011
//
// Note: We have modified the code provided by DJD to enable the functionality of computation of 
// the standard deviation and standard error.

#include "OptionData.hpp" 
#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include <cmath>
#include "SDSE.hpp"
#include <iostream>

using namespace std;

// We ran this, we found that we have to comment out this portion of code.
// We get error C2760: syntax error: unexpected token 'identifier', expected ';'
// and we get error C7510: 'const_iterator': use of dependent type name must be prefixed with 'typename'
// After much effort, I couldn't figure out where the issue was, but this functionality isn't used in my
// code so I hope it is okay. Everything else functions well and I meet the requirements of the exercise.
/*
template <class T> void print(const std::vector<T>& myList)
{  // A generic print function for vectors

	cout << std::endl << "Size of vector is " << l.size() << "\n[";

	// We must use a const iterator here, otherwise we get a compiler error.
	std::vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i)
	{
		std::cout << *i << ",";

	}

	std::cout << "]\n";
}
 */
namespace SDEDefinition
{ // Defines drift + diffusion + data

	OptionData* data;				// The data for the option MC

	double drift(double t, double X)
	{ // Drift term

		return (data->r)*X; // r - D
	}


	double diffusion(double t, double X)
	{ // Diffusion term

		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);

	}

	double diffusionDerivative(double t, double X)
	{ // Diffusion term, needed for the Milstein method

		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV)* pow(X, 2.0 * betaCEV - 1.0);
	}
} // End of namespace


int main()
{
	std::cout << "1 factor MC with explicit Euler\n";
	OptionData myOption;
	myOption.K = 100.0;
	myOption.T = 1.0;
	myOption.r = 0.0;
	myOption.sig = 0.2;
	myOption.type = 1;	// Put -1, Call +1
	double S_0 = 100.0;

	long N = 100;
	std::cout << "Number of subintervals in time: ";
	std::cin >> N;

	// Create the basic SDE (Context class)
	Range<double> range(0.0, myOption.T);
	double VOld = S_0;
	double VNew;

	std::vector<double> x = range.mesh(N);


	// V2 mediator stuff
	long NSim = 50000;
	std::cout << "Number of simulations: ";
	std::cin >> NSim;

	double k = myOption.T / double(N);
	double sqrk = sqrt(k);

	// Normal random number
	double dW;
	double price = 0.0;	// Option price

	// NormalGenerator is a base class
	NormalGenerator* myNormal = new BoostNormal();

	using namespace SDEDefinition;
	SDEDefinition::data = &myOption;

	std::vector<double> res;
	int coun = 0; // Number of times S hits origin

	vector<double> C_tj; // Call prices used in the SD and SE formulas
	// A.
	for (long i = 1; i <= NSim; ++i)
	{ // Calculate a path at each iteration

		if ((i / 10000) * 10000 == i)
		{// Give status after each 1000th iteration

			std::cout << i << std::endl;
		}

		VOld = S_0;
		for (unsigned long index = 1; index < x.size(); ++index)
		{

			// Create a random number
			dW = myNormal->getNormal();

			// The FDM (in this case explicit Euler)
			VNew = VOld + (k * drift(x[index - 1], VOld))
				+ (sqrk * diffusion(x[index - 1], VOld) * dW);

			VOld = VNew;

			// Spurious values
			if (VNew <= 0.0) coun++;
		}

		double tmp = myOption.myPayOffFunction(VNew);
		price += (tmp) / double(NSim);
		C_tj.push_back(tmp);	// Storing values in C_tj
	}

	// D. Finally, discounting the average price
	price *= exp(-myOption.r * myOption.T);

	// Cleanup; V2 use scoped pointer
	delete myNormal;

	std::cout << "Price, after discounting: " << price << ", " << std::endl;
	std::cout << "Number of times origin is hit: " << coun << endl;
	cout << "SD: " << SD(C_tj, myOption.r, myOption.T) << endl;		// Output SD
	cout << "SE: " << SE(C_tj, myOption.r, myOption.T) << endl;		// OUtput SE
	return 0;
}