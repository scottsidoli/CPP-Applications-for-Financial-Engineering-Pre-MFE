// Exercise 1.7.1 - Swap Function Using Pointers
//
// by Scott Sidoli
//
// 4-10-19
//
// The goal of this exercise is to write a program that swaps the values of two variables.
// We define the swap function to take float pointers as arguements. We first define the
// the swap function, then in main() we prompt the user for inputs for float variable i and
// j. Once the user chooses values, the Swap function is called and we print the values of 
// i and j after the swap function.

// Preprocessor Directives
#include <stdio.h>

// Variable "storage" is used to hold the value of the variable i.
float storage;

void Swap(float* a, float* b)
{
	storage = (*a);						// We assign the first value to the storage variable
	(*a) = (*b);						// via dereferencing. We then transfer the value of the
	(*b) = storage;						// second variable to the first variable. The stored value
}										// is then assigned to the second variable. Again, this is
										// done with dereferencing.
int main()
{
	float i, j;							// Variable declarations.

	printf("We are going swap i and j.\nTell me i!\ni = ");	// User prompts and inputs.
	scanf_s("%f", &i);
	printf("Tell me j!\nj = ");
	scanf_s("%f", &j);

	Swap(&i, &j);						// Calling the Swap function. The arguments are the addresses
										// of the floats i and j.
	printf("Now i = %f and j = %f! Ta-da!", i, j);			// Final print statement of result.

	return 0;
}