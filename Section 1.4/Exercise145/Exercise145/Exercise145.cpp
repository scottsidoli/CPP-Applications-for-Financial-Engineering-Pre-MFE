// Exercise 1.4.5 - Celsius to Fahrenheit (For-Loop)
//
// by Scott Sidoli
//
// 4-2-19
//
// The goal of this exercise is to print two columns of 
// temperatures. The left column should print Celsius
// temperatures ranging from 0 to 19. The right column
// should have the corresponding Fahrenheit temperatures.
// We use a for-loop for this construction.

// Preprocessor Directives
#include <stdio.h>

// Main Function
int main()
{
	float celsius;								// Variable declaration
	float fahrenheit;
	
	printf("Celsius			Fahrenheit\n");		// Printing header

	for (celsius = 0; celsius < 20; celsius++)	// Initializing the for-loop and cycles through Celsius values
	{											// that are less than 20.
		float fahrenheit = (9.0 / 5) * celsius + 32;	// Calculates the Fahrenheit temperature for a given Celsius.
		printf("%0.1f			%0.1f\n", celsius, fahrenheit);	// Prints the temps with one decimal point of accuracy.
	}
	return 0;
}