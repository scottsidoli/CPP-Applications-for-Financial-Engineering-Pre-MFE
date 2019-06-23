// Exercise 1.8.1 - Structures
//
// by Scott Sidoli
//
// 4-12-19
//
// Header file that contains the struct "Article" definition and function "print_article"
// definition.

// Preprocessor Directives for Conditional Compilation
#ifndef Exercise181_h
#define Exercise181_h

#include <stdio.h>

// Struct definition
struct Article
{
	int Article_Number;			// Struct contains three pieces of data.
	int Quantity;
	char Description[21];		// Max characters is 20 plus one for '\0'.
};

void print_article(struct Article* article)		// print_article function.
{												// Uses pointers to print initialized data.
	printf("Article Number: %d\n", article->Article_Number);
	printf("Quantity: %d\n", article->Quantity);
	printf("Description: %s", article->Description);
}

#endif