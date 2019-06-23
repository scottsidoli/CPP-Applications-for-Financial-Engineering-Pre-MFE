// Exercise 1.6.2 - More Macros
//
// by Scott Sidoli
//
// 4-9-19
//
// See Main.c for more details. Here we define two additional macros. MAX2(x, y) finds
// the maximum of two values x and y. MAX3(x, y, z) finds the maximum of three values
// x, y, and z. To define MAX2 we use the ?: operator. To define MAX3, we use MAX2.

// Conditional compilation statements are include to prevent multiple inclusions.
#ifndef DEFS_H
#define DEFS_H

// Macros from exercise 1.6.1.
#define PRINT1(a)  (printf("The macro is printing the value of a, which is %d\n", a))
#define PRINT2(a,b) (printf("The macro is printing the values of a and b, which are %d and %d\n", a, b))

// Macros MAX2 and MAX3.
#define MAX2(x,y) (x > y ? x : y )
#define MAX3(x,y,z) (MAX2( MAX2(x, y) , z ))

#endif
