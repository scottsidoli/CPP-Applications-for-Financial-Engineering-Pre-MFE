// Exercise 1.7.3 - Macro and Array Output Prediction
//
// by Scott Sidoli
//
// 4-10-19
//
// The goal of this exercise is to predict the output for several lines of code.
// Macros are defined and an array is initialized. Our predictions are commented
// following the for loops. We do not predict new lines, because it is clear when they
// occur.

#include <stdio.h> 
#define PRD(a) printf("%d", (a) )  // Print decimal 
#define NL  printf("\n");  // Print new line 
// Create and initialse array 
int a[]={0, 1, 2, 3, 4}; 

int main() {
	int i;  int* p;
	for (i = 0; i <= 4; i++) PRD(a[i]);    // 01234  
	NL; 
	for (p = &a[0]; p <= &a[4]; p++) PRD(*p);   // 01234
	NL;  
	NL; 
	for (p = &a[0], i = 0; i <= 4; i++) PRD(p[i]);  // 01234 
	NL; 
	for (p = a, i = 0; p + i <= a + 4; p++, i++) PRD(*(p + i)); // 024
	NL;  
	NL; 
	for (p = a + 4; p >= a; p--) PRD(*p);    // 43210 
	NL; 
	for (p = a + 4, i = 0; i <= 4; i++) PRD(p[-i]);   // 43210 
	NL; 
	for (p = a + 4; p >= a; p--) PRD(a[p - a]);   // 43210
	NL; 
	return 0;
}