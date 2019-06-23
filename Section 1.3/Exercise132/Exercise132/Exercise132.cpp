// Exercise 1.3.2 - Area of a Triangle
//
// By Scott Sidoli
//
// 3-14-19
//
/* Our goal is to write a program that prints the area
of a triangle with base and height determined by user input.
*/


// Preprocessor Directives
#include <stdio.h>

// Our main function and body.
int main()
{
	float base;                    // Initializing variables 'base' 
	float height;			       // and 'height' as type float.
	
	
	printf("Enter the base: ");   // Prompts the user to input 'base' value.
	scanf_s("%f", &base);         // Takes input and assigns value to variable 'base'.
	printf("Enter the height: "); // Prompts the user to input 'height' value.
	scanf_s("%f", &height);       // Takes input and assigns value to variable 'height'.

										  // Initializing variable 'area' as type float.
	float area = (0.5f) * base * height;  // The 'f' allows the compiler to read 0.5 as 
										  // a float instead of a double. Removes warning.

	printf("The area of the triangle is ");  // Displays the string followed by result of 
	printf("%f", area);						 // arithmetic, i.e. the area of the triangle.
	
	return 0;
}