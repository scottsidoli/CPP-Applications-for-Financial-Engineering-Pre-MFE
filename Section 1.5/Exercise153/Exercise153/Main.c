// Exercise 1.5.3 - Two Source Files
//
// by Scott Sidoli
//
// 4-7-19
//
// The goal of this exercise is to create two source files,
// one called Main.c, which contains the main function, and
// the other called Print.c, which contains the function body
// of the 'print()' function called in main(). Print takes a
// float input, and returns void.

// Preprocessor Directives
#include <stdio.h>

// Forwarded function and variable declarations
void print(float i);						// These tell the compiler to look
float i;									// For these functions. The compiler
											// will look through source files to find the body

// Main function
int main()
{
	printf("Give me a number!\n");			// User prompt
	scanf_s("%f", &i);						// User input, type is float, value assigned to
	print(i);								// variable i, function call.
	return 0;
}