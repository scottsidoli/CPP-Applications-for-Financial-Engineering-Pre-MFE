// Group B - Perpetual American Options
//
// by Scott Sidoli
//
// 6-10-19
//
// NormalDistribution.hpp
//
// Implementation of cdf and pdf for black-scholes. Utililizes boost libraries.

#ifndef NormalDistribution_hpp
#define NormalDistribution_hpp

#include <iostream>

using namespace std;
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp> 
using namespace boost::math;


double N(double x)
{

	normal_distribution<> myNormal(0.0, 1.0);

	return cdf(myNormal, x);

}

double n(double x)
{

	normal_distribution<> myNormal(0.0, 1.0);

	return pdf(myNormal, x);

}

#endif
