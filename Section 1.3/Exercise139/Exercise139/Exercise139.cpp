// Exercise 1.3.9 - Conditional Expressions
//
// by Scott Sidoli
//
// 3-18-19
//
// The goal of this exercise is to predict the output of computations 
// involving conditional statements. We have to note that += operator 
// is evaluated from right to left. So after the initial declarations
// we have y = 2, and after the second operation, x = 3.


/* Conditional expressions */

#include <stdio.h> 

int main() 
{
	int x = 1;  
	int y = 1;  
	int z = 1;
	x += y += x;    // These are evaluated from right to left!
					// x += (y += x);  y = 2
					// x += 2;         x = 3 because x is incremented by y.
	printf( "%d\n\n", (x < y) ? y : x);        // 3
	printf( "%d\n", (x < y) ? x++ : y++);      // 2
	printf( "%d\n", x);                        // 3
	printf( "%d\n", y);                        // 3
	return 0;
}