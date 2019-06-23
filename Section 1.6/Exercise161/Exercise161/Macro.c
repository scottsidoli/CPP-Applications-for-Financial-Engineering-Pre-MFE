// Exercise 1.6.1 - Macros
//
// by Scott Sidoli
//
// 4-9-19
//
// The goal of this exercise is to write a program with a header file and a source file.
// The header file, Defs.h, contains the definitions of two macros. The first, PRINT1,
// prints the value of the variable a. The second macro, PRINT2, prints the values of the
// variables a and b. The values of a and b are declared in main() in the source code file, 
// Macro.c. We call the macros in main().

// Preprocessor Directives. The standard I/O and our header, Defs.h.
#include <stdio.h>
#include "Defs.h"

int main()
{
	int a = 6;						// Initializing the variables a and b. 
	int b = 88;						
	
	PRINT1(a);						// Calling the macros.
	PRINT2(a, b);
	
	return 0;
}