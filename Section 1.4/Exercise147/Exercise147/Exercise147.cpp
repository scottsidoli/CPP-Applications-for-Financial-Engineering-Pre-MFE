// Exercise 1.4.7 - Number Counter with a Twist
//
// by Scott Sidoli
//
// 4-3-19
//
// The goal of this exercise is to count the number of times the values
// 0-4 are typed by the user. We also want to count the characters. The 
// difference between this exercise and the previous exercise is that in 
// this exercise, for the value three, we want to print the number of
// three's using words and if 3 occurs more than three times, we want to 
// print a default statement. We use a combination of two switch-case 
// constructions.

// Preprocessor directives
#include <stdio.h>

// Main Function
int main()
{
	int count_0 = 0;					// Variables to count the values
	int count_1 = 0;
	int count_2 = 0;
	int count_3 = 0;
	int count_4 = 0;
	int count_other = 0;				// Variable to count other characters

	int c;								// c takes the value of the ascii code
	c = getchar();						// of the user input

	while (c != EOF)					// Ctrl+z = EOF. When read, this terminates
	{									// the user input.
		switch (c)
		{
		case 48:						// ascii code for 0 = 48, 1 = 49, 2 = 50, 3 = 51
			++count_0;					// and 4 = 52. We increase the count for each
			break;						// occurrance.
		case 49:
			++count_1;
			break;
		case 50:
			++count_2;
			break;
		case 51:
			++count_3;
			break;
		case 52:
			++count_4;
			break;
		case 9:							// No increase for space, tab, or new lines
			break;
		case 10:
			break;
		case 32:
			break;
		default:						// Increase for all other characters.
			++count_other;
			break;
		}
		c = getchar();					// Captures the ascii code for the next character.
	}

	printf("The number of 0's = %d\n", count_0);	// Prints the counts
	printf("The number of 1's = %d\n", count_1);
	printf("The number of 2's = %d\n", count_2);
	
	switch (count_3)					// Switch-case that gives different print statements for 
	{									// the value 3.
	case 0:
		printf("The number of 3's is zero\n");
		break;
	case 1:
		printf("The number of 3's is one\n");
		break;
	case 2:
		printf("The number of 3's is two\n");
		break;
	case 3:
		printf("The number of 3's is three\n");
		break;
	default:
		printf("The number of 3's is more than three\n");
		break;
	}

	printf("The number of 4's = %d\n", count_4);			// Prints the count for four and
	printf("The number of other characters is %d\n", count_other);// other characters.
	return 0;
}