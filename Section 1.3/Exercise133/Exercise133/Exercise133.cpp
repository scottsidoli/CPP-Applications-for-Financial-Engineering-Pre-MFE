// Exercise 1.3.3 - Operators
//
// By Scott Sidoli
//
// 3-14-19
//
// Our goal is to predict the output of each assignment
// of the variable x. The following code is provided from
// the homework and copied here. Predictions are left as comments.

/* Operators */

#include <stdio.h> 

int main() 
{
	int x;    
	
	x = -3 + 4 * 5 - 6;   // x = 11
	printf("x=%d\n", x);

	x = 3 + 4 % 5 - 6;    // x = 1
	printf("x=%d\n", x);
	
	x = -3 * 4 % -6 / 5;  // x = 0
	printf("x=%d\n", x);
	
	x = (7 + 6) % 5 / 2;  // x = 1
	printf("x=%d\n", x);
	
	return 0;
}