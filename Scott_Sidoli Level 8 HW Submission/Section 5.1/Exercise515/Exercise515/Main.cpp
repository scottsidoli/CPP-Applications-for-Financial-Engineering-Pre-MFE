// Exercise 5.1.5 - Statistical Functions
//
// by Scott Sidoli
//
// 5-30-19
//
// Main.cpp
//
// In this exercise, we modify the code in TestNormalDistribution.cpp to work with the exponential distribution instead of the 
// normal distribution and the poisson distribution instead of the gamma distribution.

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions
#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>

#include <vector>
#include <iostream>
using namespace std;


int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;

	//=============================== Normal Distribution ===============================

	normal_distribution<> myNormal(1.0, 10.0); // Default type is 'double'
	cout << "Mean: " << mean(myNormal) << ", standard deviation: " << standard_deviation(myNormal) << endl;

	// Distributional properties
	double x = 10.25;

	cout << "pdf: " << pdf(myNormal, x) << endl;
	cout << "cdf: " << cdf(myNormal, x) << endl;

	// Choose another data type and now a N(0,1) variate
	normal_distribution<float> myNormal2;
	cout << "Mean: " << mean(myNormal2) << ", standard deviation: " << standard_deviation(myNormal2) << endl;

	cout << "pdf: " << pdf(myNormal2, x) << endl;
	cout << "cdf: " << cdf(myNormal2, x) << endl;

	// Choose precision
	cout.precision(10); // Number of values behind the comma

	// Other properties
	cout << "\n***normal distribution: \n";
	cout << "mean: " << mean(myNormal) << endl;
	cout << "variance: " << variance(myNormal) << endl;
	cout << "median: " << median(myNormal) << endl;
	cout << "mode: " << mode(myNormal) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myNormal) << endl;
	cout << "kurtosis: " << kurtosis(myNormal) << endl;
	cout << "characteristic function: " << chf(myNormal, x) << endl;
	cout << "hazard: " << hazard(myNormal, x) << endl;

	//=============================== Exponential Distribution ===============================

	double scaleParameter = 0.5;

	// Default type is 'double'
	exponential_distribution<> myExponential(scaleParameter);

	cout << "Mean: " << mean(myExponential) << ", standard deviation: " << standard_deviation(myExponential) << endl;

	// PDF and CDF
	cout << "pdf: " << pdf(myExponential, x) << endl;
	cout << "cdf: " << cdf(myExponential, x) << endl;

	// Using another data type and a N(0,1) variate
	exponential_distribution<float> myExponential2(1.0);
	cout << "Mean: " << mean(myExponential2) << ", standard deviation: " << standard_deviation(myExponential2) << endl;

	// PDF and CDF
	cout << "pdf: " << pdf(myExponential2, x) << endl;
	cout << "cdf: " << cdf(myExponential2, x) << endl;

	// Other properties
	cout << "\n***exponential distribution: \n";
	cout << "mean: " << mean(myExponential) << endl;
	cout << "variance: " << variance(myExponential) << endl;
	cout << "median: " << median(myExponential) << endl;
	cout << "mode: " << mode(myExponential) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
	cout << "kurtosis: " << kurtosis(myExponential) << endl;
	cout << "characteristic function: " << chf(myExponential, x) << endl;
	cout << "hazard: " << hazard(myExponential, x) << endl;

	//=============================== Gamma Distribution ===============================
	double alpha = 3.0; // Shape parameter, k
	double beta = 0.5;	// Scale parameter, theta
	gamma_distribution<double> myGamma(alpha, beta);
	cout << "everything that follows is for the gamma distribution" << endl;
	double val = 13.0;
	cout << endl << "pdf: " << pdf(myGamma, val) << endl;
	cout << "cdf: " << cdf(myGamma, val) << endl;

	vector<double> pdfList;
	vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myGamma, val));
		cdfList.push_back(cdf(myGamma, val));

		val += h;
	}

	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", " << endl;

	}

	cout << "***" << endl;

	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", " << endl;

	}

	//=============================== Poisson Distribution ===============================
	cout << "everything that follows is for the Poisson distribution" << endl;
	double mean = 3.0;
	poisson_distribution<double> myPoisson(mean);

	val = 3.5;
	cout << "pdf: " << pdf(myPoisson, val) << endl;
	cout << "cdf: " << cdf(myPoisson, val) << endl;

	vector<double> pdfList2;
	vector<double> cdfList2;

	double start2 = 0.0;
	double end2 = 6.0;
	long N2 = 30;		// Number of subdivisions

	val = 0.0;
	double h2 = (end2 - start2) / double(N2);

	for (long j = 1; j <= N2; ++j)
	{
		pdfList2.push_back(pdf(myPoisson, val));
		cdfList2.push_back(cdf(myPoisson, val));

		val += h2;
	}

	for (long j = 0; j < pdfList2.size(); ++j)
	{
		cout << pdfList2[j] << ", "<< endl;

	}

	cout << "***" << endl;

	for (long j = 0; j < cdfList2.size(); ++j)
	{
		cout << cdfList[j] << ", " << endl;

	}
	return 0;
}