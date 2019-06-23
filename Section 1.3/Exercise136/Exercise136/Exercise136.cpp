// Exercise 1.3.6: Shift operator
//
// by Scott Sidoli
//
// 3-18-19
//
// The goal of this exercise is to write a program that allows a user to input an integer,
// then the program performs a bit-wise right-shift twice. The program then prints the result.
// It also prints the type of shift that is performed.

// Preprocessor directives
#include <stdio.h>

// Main function
int main()
{
	int number;
	printf("Pick an integer: \n");        // User inputs integer. Value is assigned to variable
	scanf_s("%d", &number);               // number.

	int shifted_number = number>>2;       // User input is shifted right twice and then printed.
	printf("The shifted value is %d.\nIt has the same sign!\nThis is an arithmetic shift!", shifted_number);

	// We know that the shift is arithmetic because, for signed int's, the sign bit it preserved. 
    // In other words, the MSB is copied. It should be noted that if an unsigned int is used,
	// the logical shift and arithmetic shift are indistinguishable.
	return 0;
}