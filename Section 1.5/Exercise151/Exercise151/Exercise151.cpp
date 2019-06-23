// Exercise 1.5.1 - Basic Functions
//
// by Scott Sidoli
//
// 4-5-19
//
// The goal of this exercise is to define a function that takes two numbers
// and finds their difference.

// Preprocessor Directives
#include <stdio.h>

// Variable declarations - type is float
float a;
float b;

// Function body
float minus(float a, float b)
{
	return(a - b);
}


int main()
{
	printf("Please enter a number!\n");					// User Prompt.
	scanf_s("%f", &a);									// User input.
	printf("Please enter a second number!\n");			// User prompt for 2nd value.
	scanf_s("%f", &b);									// User input for 2nd value.

	float difference = minus(a, b);						// Value returned by function
														// stored in variable difference.
	printf("The %f minus %f is %f\n", a, b, difference);// Prints the inputs and the result.
	return 0;
}


