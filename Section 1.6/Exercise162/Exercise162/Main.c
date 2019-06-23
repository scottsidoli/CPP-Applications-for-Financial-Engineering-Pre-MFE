// Exercise 1.6.2 - More Macros
//
// by Scott Sidoli
//
// 4-9-19
//
// The goal of this exercise was to create two more macros. The first, MAX2(x,y), find the maximum
// of two values. The second, MAX3(x,y,z), finds the maximum of three values. We define MAX3 in
// terms of MAX2. The user inputs the values. Once the first two values are entered, MAX2 is called.
// The user is then prompted to pick a third value, at which time MAX3 is called.

// Preprocessor Directives. We include a header file "Defs.h"
#include <stdio.h>
#include "Defs.h"

// Main function
int main()
{
	float x, y, z;														// Variable declations

	printf("Give me a number!\n");										// User prompts and input
	scanf_s("%f", &x);

	printf("Give me a second number!\n");
	scanf_s("%f", &y);

	printf("The max of those two numbers is %f!\n", MAX2(x, y));		// Prints statement and macro call.


	printf("Finally, give me a third number!\n");						// Final user prompt and input.
	scanf_s("%f", &z);

	printf("The max of those three number is %f!", MAX3(x, y, z));		// Prints statement and macro call.
	return 0;
}