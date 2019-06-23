// Exercise 1.4.1 - Word Counter (While Loop)
//
// by Scott Sidoli
//
// 3-21-19
//
// The goal of this exercise is to create a program that accepts the user input of a string
// and returns the count of characters, words, and lines. A variety of challenges occur in
// this exercise as a counter of this type needs a plethora of logical exceptions included in its code.
// We use a while loop and we use boolean operators to negotiate the variety of logical twists
// and turns.

// Preprocessor Directives
#include <stdio.h>

// Main Function
int main()
{
	int c;													// Variable Declarations. "c" is the current and previous user inputs.
	int character_number = 0;								// The statistics we are interested in computing are listed here.
	int word_number = 0;
	int line_number = 0;
	bool character = false;									// A boolean switch that is true if the user hits a character key.
	bool line = false;										// A boolean switch that is true if the user starts a new line.


	// User Prompt
	printf("Please enter a string. End your string with Ctrl+D and then press enter.\n" );
	c = getchar();											// 'c' takes the ascii code value of whatever was last typed. Note that
															// 4 = ctrl+d (i.e. end of file), 9 = "tab", 10 = "new line", and 32 = "space",


	while (c != 4)
	{
		if (character_number == 0 && (c == 9 || c == 10 || c == 32)) // Ignores spaces, tabs, and new lines as the first imputs
		{
			continue;
		}
		else if (character_number == 0 && c != 10 && c != 32 && c != 9) // As soon as a character is typed, it counts the line and character.
		{																// The character and line booleans are set to "true" and "false", respectively. 
			++line_number;
			++character_number;
			character = true;
			line = false;
		}
		else if (c != 10 && c != 32 && c != 9)				// Once past the situation of starting the string, we want to count characters.
		{													// Also, we want the program to set the character boolean to true.
			++character_number;
			character = true;
			if (line)										// If the line boolean is "true," i.e. the user started a new line, then typing a
			{												// character will cause the line to be counted and switch the boolean back to false.
				++line_number;
				line = false;
			}
		}
		else if (c == 10 || c == 9 || c == 32)				// If the user hits a new line, space, or tab key when the previous entry was a 
		{													// character (i.e. character = true), then we count a word. The boolean 'character'
			if (character)									// is then set to false. If the user specifically started a new line, then the
			{												// boolean 'line' is set to true.
				++word_number;
			}

			character = false;

			if (c == 10)
				line = true;

		}
		else if (line && (c != 9 || c != 10 || c != 32))	// If line is true and we type a character, then we count a line and
		{													// set line to false.
			++line_number;
			line = false;
		}
		c=getchar();
	}

	if (character)											// This recognizes the last word if we type a character and then hit 
		++word_number;										// ctrl+d.
	    
	
	printf("The number of characters is %d.\nThe number of words is %d.\nThe number of lines is %d", character_number, word_number, line_number);
	return 0;
}