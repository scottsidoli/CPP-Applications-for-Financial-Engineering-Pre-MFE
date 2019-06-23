// Exercise 1.5.4 - Number Printing and Digit Extraction
//
// By Scott Sidoli
//
// 4-7-19
//
// The goal of this exercise is to creat a function which takes
// an integer as an input and then prints the integer digit by
// digit. In order to do this, we take a user input. This input
// then becomes the input for the function 'printnumber()', which
// is defined below. This function takes integers as input and
// does not produce an output. It does, however, perform an action.
// More detail below.

// Preprocessor Directives
#include <stdio.h>

// The function printnumber
void printnumber(int i)				// Return type void, input type int
{
	if (i < 0)						// Negative integers become positive,
	{								// and we print a negative sign.
		i = -i;
		putchar('-');
	}								// After the first call, the function
	if (i / 10)						// takes input and divides it by 10.
	{								// Function calls itself and, in doing
		printnumber(i / 10);		// so cycles through each digit.
	}

	putchar('0' + i % 10);			// Takes the input and prints the 
}									// remainder mod 10, i.e. a digit.

int main()							// Main function.
{
	int i;							// Variable initialization
	printf("Type an integer: ");	// User prompt
	scanf_s("%d", &i);				// User input

	printnumber(i);					// Function call
	return 0;
}