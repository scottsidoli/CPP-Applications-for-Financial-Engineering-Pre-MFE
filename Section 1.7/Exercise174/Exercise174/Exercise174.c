// Exercise 1.7.4 - Days of the Week
//
// by Scott Sidoli
//
// 4-10-19
//
// The goal of this exercise is to write a program that takes a user input of a number from
// 1 up to 7 and print the corresponding day of the week in a specific format. We write the
// function DayName() which takes an int as an argument. We want for instance to see something
// like "Day 2 is Monday!" when we enter the value 2. We initialize and array of strings, which
// are the days of the week and write a function which prints the entry from the array. Since
// array entries start at "0," we must introduce a shift to make sure we print the correct day.

// Preprocessor Directives
#include <stdio.h>

int i;

void DayName(int a)
{	// Array initialization and print statement.
	char *days_array[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	printf("Day %d is %s!", i, days_array[i - 1]);		// Notice the shift in index. 
}

int main()
{	// User prompt and input.
	printf("Pick a whole number from 1 up to 7!\n");
	scanf_s("%d", &i);

	DayName(i);					// Function call

	return 0;
}