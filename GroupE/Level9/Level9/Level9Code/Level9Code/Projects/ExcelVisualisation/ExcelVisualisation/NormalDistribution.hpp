// Group E - Excel Visualization
//
// by Scott Sidoli
//
// 6-15-19
//
// NormalDistribution.cpp
//
// Normal distribution functionality.

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
