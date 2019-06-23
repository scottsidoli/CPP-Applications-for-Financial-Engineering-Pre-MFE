// Exercise 1.8.1 - Structures
//
// by Scott Sidoli
//
// 4-12-19
//
// The goal of this exercise is to create a structure called "Article" and write a program that
// prints the associated data contained in the structure. The structure is defined in the header
// file "Exercise181.h." It contains the information "Article Number (an int)," "Quantity (also
// an int)," and "Description (a string)." We write a program whose main() initializes the struct
// and its data. In the header, we also define a function, print_article(), which prints the 
// initialized data by taking the address of the struct as input.

// Preprocessor Directives. We include our header.
#include <stdio.h>
#include "Exercise181.h"

int main()			// Main Function.
{
	struct Article article = { 1, 1, "The first article" };			// Struct initialization.	
																	// See header for more details.
	print_article(&article);										// Function call.

	return 0;
}