// Exercise 1.9.2 - Output to File
//
// by Scott Sidoli
//
// 4-13-19
//
// The goal of this exercise is to write a program that reads text from a user input
// and prints it to a file. Our text is printed to a file titled "test.txt". We create the 
// file when we open it using the fopen() function. We open the file to write to it directly.
// When the input is completed, the user enters ctrl + shift + a to terminate. We print a 
// statement to the console and to test.txt. This was not expressed in the exercise, but I
// thought it was in the spirit of what was asked.

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>

// Main function
int main()
{
	FILE *output_file;							// File declaration using pointer.
	output_file = fopen("test.txt", "w");		// File title is test.txt and we write to it.

	// User prompt and input
	printf("Enter some characters!\nThey will write to the file test.txt! End with Ctrl+shift+A\n");

	int c = getchar();							// Captures the ascii code of input as int variable c.

	while (c != 1)
	{
		fputc(c, output_file);					// Instead of putchar() which writes to console, we use
		c = getchar();							// fputc() which writes to file. We declare the file using
	}											// a pointer.

	if (c == 1)
	{	// Here, we print to the console and to the file.
		printf("\nCtrl+shift+A is a correct ending.");
		fprintf(output_file, "\nCtrl+shift+A is a correct ending.\n");
	}

	fclose(output_file);						// When done, we close the file.

	return 0;
}
