// Group E - Excel Visualization
//
// by Scott Sidoli
//
// 6-15-19
//
// Types.hpp
//
// New type definitions for option parameters.

#ifndef Types_hpp
#define Types_hpp

#include <boost/serialization/strong_typedef.hpp>

BOOST_STRONG_TYPEDEF(double, Time);
BOOST_STRONG_TYPEDEF(double, Strike_Price);
BOOST_STRONG_TYPEDEF(double, Volatility);
BOOST_STRONG_TYPEDEF(double, rate);
BOOST_STRONG_TYPEDEF(double, cost_of_carry);
BOOST_STRONG_TYPEDEF(double, curr_stock_price);


#endif