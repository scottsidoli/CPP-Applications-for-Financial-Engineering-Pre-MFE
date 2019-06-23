// Exercise 1.5.2 - Recursion and the Factorial
//
// by Scott Sidoli
//
// 4-6-19
//
// The goal of this exercise is to define a function
// that uses recursion to find the value of a factorial.
// We set up a base case and then have the function
// call itself to compute the factorial. The input type is an
// int and the return type is a long long int. Note that the 
// largest int we can input to this function is 20.

// Preprocessor Directives
#include <stdio.h>

// Variable declarations
int n;

// Function body
long long int factorial(int n)
{
	if (n == 0)								// Base case: 0! = 1
		return 1;
	
	return (n * factorial(n - 1));			// Functions calls itself using the 
}											// identity n! = n * (n-1)!

// Main Function
int main()
{
	printf("Enter a non-negative integer: ");	// User prompt
	scanf_s("%d", &n);							// User input

	long long int factorial_n = factorial(n);	// The value returned by factorial() function
												// is stored in variable factorial_n.
	
	printf("%d! = %lld", n, factorial_n);		// Prints the (user input)! = (function output)
	return 0;
}