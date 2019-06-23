// Exercise 1.4.3 - Word Counter (Switch-Case Loop)
//
// by Scott Sidoli
//
// 3-29-19
//
// The goal of this exercise is to create a program that accepts the user input of a string
// and returns the count of characters, words, and lines using a switch-case loop.

// Preprocessor Directives
#include <stdio.h>

// Main Function
int main()
{
	int c;													// Variable Declarations. "c" is ascii code of the most recent keystroke.
	int character_number = 0;								// The statistics we are interested in computing are listed here.
	int word_number = 0;
	int line_number = 0;
	int character = 0;										// A int switch that is "1" if the user hits a character key. We think of it as a Boolean.
	int line = 0;											// A int switch that is "1" if the user starts a new line. We think of it as a Boolean.

	// User Prompt
	printf("Please enter a string. End your string with Ctrl+D and then press enter.\n");
	c = getchar();											// 'c' takes the ascii code value of whatever was last typed. Note that
															// 4 = ctrl+d (i.e. end of file), 9 = "tab", 10 = "new line", and 32 = "space",
	while (c != 4)
	{
		switch (character_number)
		{
		case 0:												// This is the case when we first start, i.e. there are no characters.
			switch (c)
			{
			case 9:											// Tab should do nothing.
				break;
			case 10:										// New lines make int line = 1, but nothing counted.
				line = 1;
				break;
			case 32:										// Spaces should do nothing.
				break;
			default:										 
				++line_number;								
				++character_number;
				character = 1;
				break;
			}
			c = getchar();
			break;
		default:											// This is the case after we have counted at least one character.
			switch (c)
			{
			case 9:											// This is for a tab after a character.									
				character = 0;
				break;

			case 10:										// If we hit enter, nothing should happen.
				line = 1;									// We should keep track of the fact that we are on a new line, in case we hit a character. 
				character = 0;								// We can also keep track of the fact that we did not just hit a character.
				c = getchar();
				break;

			case 32:										// If we hit space, then we log that it is not a character.
				character = 0;
				c = getchar();
				break;

			default:										// If we hit a character, then we first look at if we are on a new line.
				switch (line)								// If we are on a new line (i.e. line = 1) then we increase the line count
				{											// and the word count. We increase the character count by 1 for each character. 
				case 0:										// We set line = 0 to prepare for the next new line.
					switch (character)
					{
					case 0:
						++word_number;
						++character_number;
						break;
					default:								// If we just typed a character, then we do not want to increase the word count.
						++character_number;					// We only increase the character number.
						break;
					}								
					break;
				default:									// Here is code for when we are at the start of a new line, i.e. line = 1, and
					++character_number;						// type a character.
					++line_number;
					line = 0;
					switch (character)
					{
					case 0:
						++word_number;
						break;
					default:
						break;
					}
					break;
				}
				character = 1;								// Here we want to make sure that we log the previous entry as a character.
				c = getchar();
				break;
			}
		}
	} 
	switch (character)										// We want to now handle the case when we are at the end of the file.
	{
	case 0:													// What follows ensure the we count the last word.
		switch (line)
		{
		case 0:
			break;
		default:
			++word_number;
			break;
		}
		break;
	default:
		++word_number;
		break;
	}
											// Finally, we print the result.
			printf("The number of characters is %d.\nThe number of words is %d.\nThe number of lines is %d", character_number, word_number, line_number);
			return 0;
}
	