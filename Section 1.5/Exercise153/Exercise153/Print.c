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

// Variable declarations
float i;

// Function declaration and body.
void print(float i)
{												// Takes a float, from the code in main.
	float double_up = 2 * i;					// It prints the input in a line of text.
	printf("Main.c told me i was %f.\n", i);	// The function then doubles the input and
	printf("I'm gonna double it!\n");			// prints the result.
	printf("The result is %f", double_up);
}
