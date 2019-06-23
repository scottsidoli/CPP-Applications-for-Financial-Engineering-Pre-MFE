// Exercise 1.3.8 - Assignment Operators
//
// by Scott Sidoli
//
// 3-18-19
//
// The goal of this exercise is to predict the output of line in the following code given in the statement
// of the exercise. This required an understanding of operator precedence. For the first line, *= has lower
// precedence than +, so the addition happens first. 
//
// For the second line, x = 10 from the previous code. Again we consider the operator precendence to realize
// that y is assigned the same value as z (which is 4), after which, *= operator takes effect. We then 
// assign to x the value 10 * 4 = 40.
//
// For the last line, the operator used on the right hand side is ==. This takes the value 1 if the
// expression on the left is the same as the expression on the right. Since y = z from earlier assignment,
// we have y == z returns the value of 1 which is then assigned to x.

#include <stdio.h>

int main()
{
	int x = 2;  
	int y;  
	int z;
	
	x *= 3 + 2;						// x = 10
	printf("x=%d\n", x);
	
	x *= y = z = 4;					// x = 40
	printf("x=%d\n", x);
	
	x = y == z;						// x = 1
	printf("x=%d\n", x);

	return 0;
}