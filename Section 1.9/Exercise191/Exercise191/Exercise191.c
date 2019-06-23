// Exercise 1.9.1 - Input and Output
//
// by Scott Sidoli
//
// 4-12-19
//
// The goal of this exercise it to create a program that reads characters and then
// prints what has been read upon pressing enter. We use a while loop. The input ends
// upon pressing ctrl + shift + a, as opposed to just ctrl + a. It was determined that
// on my machine, ctrl + a selects all and does not produce ^A.

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>

// Main function
int main()
{	// User Prompt
	printf("Enter some characters!\nWhen you press enter, you will see them again! End with Ctrl + Shift + a\n");

	int c = getchar();			// Reads input and stores ascii code in variable c.

	while (c != 1)				// While loop that reads and writes characters.
	{							// When typing a new line, a second new line is 
		putchar(c);				// printed. I was not sure if this was necessary,
		c = getchar();			// but I thought to include it just in case.
		if (c == 10)			// putchar() writes characters while getchar()
		{						// reads characters.
			printf("\n");
		}
		
	}

	if (c == 1)					// Print statement to indicate the correct termination.
	{
		printf("\nCtrl + shift + A is a correct ending.\n");
	}

	return 0;
}