// Exercise 1.7.2 - Arrays and the Length Function
//
// by Scott Sidoli
//
// 4-10-19
//
// The goal of this exercise is to create a function that counts the length of a string which
// contains at most 30 characters. Our length function takes an array as an argument. Much of
// the code is supplied in the statement of the exercise. We merely define the function.

/* Calculate the length of a string */ 
#include <stdio.h> 
#define MAXLINE 30 

// String length declaration int Length(char str[]); 
int main() 
{
	char string[MAXLINE + 1]; // Line of maxium 30 chars + \0  
	int c;    // The input character  
	int i=0;    // The counter 

	// Print intro text  
	printf("Type up to %d chars. Exit with Enter followed by ^Z\n", MAXLINE);	// To make this work, we had to 
																				// prompt the user to hit enter
	// Get the characters														// before ^Z.
	while ((c=getchar())!=EOF && i<MAXLINE)  
	{   
		// Append entered character to string  
		string[i++]=(char)c;  
	}  
	string[i]='\0';  // String must be closed with \0  
	printf("String length is %d\n", Length(string));  
	return 0; 
} 

int Length(char str[])						// Length function implementation.
{
	int n;									// The variable n counts the entries of the string.
	for (n = 0; *str != '\0'; str++)		// If an address contains '\0', then the loop exits.
	{										// If not, then we increase the count and move to the
		n++;								// next entry in the array. The functions returns the count.
	}										// It should be noted that spaces, new lines, and tabs
	return n;								// increase the count.
}
  