// Exercise 1.3.4 - ?: Operator
//
// By Scott Sidoli
//
// 3-14-19
//
// Our goal in this exercise is to have a user input their marital status as an int
// and then print the marital status using the ?: operator. 

// Preprocessor directives
#include <stdio.h>

int main()
{
	/* We define the variable married to be of type int and have it take a value determined by
	the user.*/
	int married;
	printf("Think of a person. Enter 0 if they are not married, non-zero integer if they are married: ");
	scanf_s("%d", &married);

	/* We use is the ?: operator. If the Boolean is TRUE (i.e. the user input is 0), the 
	statement "The person is not married" is printed. If the Boolean is FALSE (i.e. the user 
	input is nonzero), the statement "The person is married" is printed.*/
	printf((married == 0) ? "The person is not married" : "The person is married");
	return 0;
}