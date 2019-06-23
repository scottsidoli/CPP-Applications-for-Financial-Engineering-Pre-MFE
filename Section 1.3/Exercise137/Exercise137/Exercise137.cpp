// Exercise 1.3.7 - The Left Shift Operator
//
// by Scott Sidoli
//
// 3-18-19
//
// The goal of this exercise is to write a C program that efficiently
// takes an integer and multiplies it by two raised to some power. The number
// and power of two are both user inputs.

// Preprocessor Directives
#include <stdio.h>

// Main Function
int main()
{
	int number;								// Variables
	int exponent;
	
	printf("Pick a number: \n");			// User prompted for input. Input stored in
	scanf_s("%d", &number);                 // variable "number"

	printf("We are going to multiply it by two to a power!\n");
	printf("What power would you like to use?\n");                 // User prompted for integer input.
	scanf_s("%d", &exponent);									   // Input stored in "exponent"

	number = number << exponent;			// Variable "exponent" is used as the number of times the user
	printf("Your result is %d!", number);   // input of number is bit-wise shifted to the left. The result
											// is multiplication by 2^(exponent).
	return 0;
}