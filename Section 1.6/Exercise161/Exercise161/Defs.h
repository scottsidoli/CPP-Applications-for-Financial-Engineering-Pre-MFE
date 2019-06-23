// Exercise 1.6.1 - Macros (header)
//
// by Scott Sidoli
//
// 4-9-19
//
// See source file Macro.c for exercise description. He we define macros
// implement a mechanism to avoid multiple inclusions. 

// Preprocessor Directives. Conditional compilations.
#ifndef DEFS_H				// Mechanism to avoid multiple inclusions.
#define DEFS_H


// Macro definitions. PRINT1 takes one argument and prints a statement.
// Print 2 takes two arguements and prints a statement. Because macros aren't type
// specific, the input type can be declared in the main function. We do have to make 
// sure we use the appropriate format specifier. Here, we use %d type int.
#define PRINT1(a)  (printf("The macro is printing the value of a, which is %d\n", a))
#define PRINT2(a,b) (printf("The macro is printing the values of a and b, which are %d and %d\n", a, b))

#endif