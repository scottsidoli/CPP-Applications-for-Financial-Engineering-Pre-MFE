// Exercise 1.4.4 Fahrenheit to Celsius with While-Loop
//
// by Scott Sidoli
//
// 4-1-19
//
// The goal of this exercise is to write a program that prints two columns of temperatures.
// The left column is Fahrenheit temperatures while the right column is Celsius Temperatures.
// We must have the range of Fahrenheit temperatures go from 0 to 300. Other requirements include
// a single decimal value in the Celsius temperature and it must be easy to adjust the starting
// temperature, ending temperature, and step size. 

// Preprocessor Directives
#include <stdio.h>

// Main Function
int main()
{
	float max_temp = 300.0;								// Max temp, min temp, and step size								
	float min_temp = 0.0;								// are set here.
	float step_size = 20;								// We calculate the number of steps
	float step_num = (max_temp - min_temp) / step_size; // using these parameters.
	int x = 0;											// x counts each step.
	float fahrenheit = min_temp + step_size * x;		// Fahrenheit temp computation based on parameters.
	float celsius = (5.0 / 9)*(fahrenheit - 32);		// Celsius computation based on Fahrenheit value.

	printf("Farenheit			Celsius\n");			// Header to print.
	while (x <= step_num)								// While contruction prints a line of temperatures
	{													// for each step. The number of lines depends on the 
		printf("%.01f				%.01f\n", fahrenheit, celsius); // parameters min_temp, max_temp, and step_size.
		++x;														
		fahrenheit = min_temp + step_size * x;			// Recalculates the next Fahrenheit and Celsius temperatures.
		celsius = (5.0 / 9)*(fahrenheit - 32);
	}
	return 0;
}