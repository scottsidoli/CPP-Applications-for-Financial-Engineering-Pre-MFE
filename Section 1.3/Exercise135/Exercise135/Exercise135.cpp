// Exercise 1.3.5 - Prefix and Postfix Operators
//
// by Scott Sidoli
//
// 3-18-19
//
// The goal of this exercise is to write a program that clearly demonstrates the difference between
// prefix and postfix operators, --i and i--. 

// Preprocessor directives
#include <stdio.h>

// Main function: 
int main()
{
	// We define the variable b to take the value of 10. With the prefix operator,
	// b is decremented by one unit, making b take the value of 9, then c is
	// assigned that value.

	int b = 10;
	int c = --b;
	printf("c=%d\n", c);
	printf("b=%d\n", b);

	// Here, we define the variable n to take the value of 10. With the postfix operator,
	// d is assigned the value of n (i.e. d = 10) and then n is decremented by one unit. 
	// This makes n take the value 9.

	int n = 10;
	int d = n--;
	printf("d=%d\n", d);
	printf("n=%d", n);

	return 0;
}