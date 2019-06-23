// Exercise 1.4.6 - Number Counter
//
// by Scott Sidoli
//
// 4-2-19
//
// The goal of this exercise is to count the number of times the values
// 0-4 are typed by the user. We also want to count the characters. The 
// construction that we use is the switch-case construction. We also want 
// to count all other characters.

// Preprocessor directives
#include <stdio.h>

// main functions
int main()
{
	int count_0 = 0;				// Counter initializations
	int count_1 = 0;
	int count_2 = 0;
	int count_3 = 0;
	int count_4 = 0;
	int count_other = 0;
	
	int c;
	c = getchar();					// Assigns ascii code of user input to 
									// int variable c.
	while (c != EOF)				// ctrl+z = EOF
	{
		switch (c)					// Switch case for the ascii code values
		{							// ascii 48 = 0, 49 = 1, 50 = 2, 51 = 3, 52 = 4.
		case 48:					// We increase the corresponding counts.
			++count_0;
			break;
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
		case 9:						// We do not count spaces, tabs, or new lines. 
			break;
		case 10:
			break;
		case 32:
			break;
		default:
			++count_other;
			break;
		}
		c = getchar();				// capture the ascii code for the next character
	}
	printf("The number of 0's = %d\n", count_0);	// Prints the counts.
	printf("The number of 1's = %d\n", count_1);
	printf("The number of 2's = %d\n", count_2);
	printf("The number of 3's = %d\n", count_3);
	printf("The number of 4's = %d\n", count_4);
	printf("The number of other characters is %d\n", count_other);
	return 0;
}