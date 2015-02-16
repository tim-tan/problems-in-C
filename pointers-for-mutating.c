/*
 * =====================================================================
 * LEARNING OBJECTIVES:  This module lets you practice:
 *   -- Using POINTERS to MUTATE arguments.
 *
 * This is one of the TWO main reasons to have pointers:
 *
 *   Use 1. To allow mutating parameters (per functions below).
 *
 *   Use 2. To allow sending lots of information to a function
 *          without the expense of copying it
 *          (per functions in a forthcoming exercise).
 *
 * Authors: David Mutchler, Chandan Rupakheti, Matt Boutell, Curt Clifton
 *          and their colleagues and Eric Tan (CM 2991).  February, 2013.
 * =====================================================================
 *   
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void test_swap();
void failed_attempt_to_swap(int x, int y);
void swap(int c, int d, int* cee, int* dee) ;

void test_sine_and_cosine();
void sine_and_cosine(float x, float* sin, float* cos);  // YOU DECIDE WHAT ** else ** GOES IN THE PARENTHESES

int main() {
	test_swap();
	test_sine_and_cosine();

	return EXIT_SUCCESS;
}

/***********************************************************************
 * 
 * The next set of functions are for you to implement a SWAP function
 * that swaps the values of two variables in the caller.
 *
 *   a. Read   failed_attempt_to_swap   (below).  Run this program.
 *        -- Make SURE that you COMPLETELY UNDERSTAND WHY the failed
 *           attempt to swap does indeed fail.
 *
 *   b. Implement   swap   (below)   and put an appropriate statement
 *      in     test_swap    to TEST that swap really DOES swap
 *      the values of the variables in the CALLER (i.e., in test_swap).
 *
 *      ** You will need to modify the function header of   swap
 *                AND the prototype of   swap. **
 *
 *      TEST to be sure your swap REALLY WORKS!
 *
 *         -- Be SURE you UNDERSTAND WHY your swap works!
 *         -- Make sure that you understand how you can SWAP the values
 *               of variables in the caller by using POINTERS.
 **********************************************************************/
void test_swap() {
	int a, b, c, d;

	a = 10;
	b = 99;
	c = 300;
	d = 888;

	printf("Before the FAILED swap: %4i %4i.\n", a, b);
	failed_attempt_to_swap(a, b);
	printf("After the FAILED swap:  %4i %4i.\n\n", a, b);

	printf("Before the SUCCESSFUL swap: %4i %4i.\n", c, d);
	swap(c, d, &c, &d); //  YOU DECIDE WHAT GOES IN THE PARENTHESES.
	printf("After the SUCCESSFUL swap:  %4i %4i.\n\n", c, d);
}

void failed_attempt_to_swap(int x, int y) {
	// This does NOT succeed in swapping the values of the
	// actual arguments.  Make sure you understand WHY!
	int temp;

	printf("Before the swap INSIDE the FAILED attempt: %4i %4i.\n", x, y);

	temp = x;
	x = y;
	y = temp;

	printf("After the swap INSIDE the FAILED attempt:  %4i %4i.\n", x, y);
}

void swap(int c, int d, int* cee, int* dee) { // YOU DECIDE WHAT GOES IN THE PARENTHESES

	*cee = d;
	*dee = c;

}

/***********************************************************************

 * The next set of functions are for you to implement a sine_and_cosine
 * function that "sends" back to the caller TWO values:
 *   -- the SINE of the first argument of the function, and
 *   -- the COSINE of the first argument of the function.
 *
 * Implement   sine_and_cosine   (below)   and add appropriate statements
 *      to     test_sine_and_cosine    below to TEST that the latter
 *      really does "receive" the sine and cosine of the number sent
 *      to the   sine_and_cosine    function.
 *
 *      ** You will need to modify the function header of   sine_and_cosine
 *                AND the prototype of   sine_and_cosine. **
 *
 * TEST to be sure your   sine_and_cosine   REALLY WORKS!
 **********************************************************************/
void test_sine_and_cosine() {
	// YOU DECLARE  ** additional **  VARIABLES AS NEEDED.
	float PI, x, y, z;
	float sinx, cosx, siny, cosy, sinz, cosz;

	PI = 3.14159;

	x = PI / 2;
	y = PI / 3;
	z = PI / 4;

	sine_and_cosine(x, &sinx, &cosx); // YOU DECIDE WHAT  ** else **  GOES IN THE PARENTHESES.
	printf("The sine and cosine of %6.3f are %6.3f and %6.3f, respectively.\n",
			x, sinx, cosx); // YOU  ** replace **  SOME OF THE VARIABLES ON THIS LINE
	                  // WITH YOUR OWN CHOICES.

	sine_and_cosine(y, &siny, &cosy); // YOU DECIDE WHAT  ** else **  GOES IN THE PARENTHESES.
	printf("The sine and cosine of %6.3f are %6.3f and %6.3f, respectively.\n",
			y, siny, cosy); // YOU  ** replace **  SOME OF THE VARIABLES ON THIS LINE
	                  // WITH YOUR OWN CHOICES.

	sine_and_cosine(z, &sinz, &cosz); // YOU DECIDE WHAT  ** else **  GOES IN THE PARENTHESES.
	printf("The sine and cosine of %6.3f are %6.3f and %6.3f, respectively.\n",
			z, sinz, cosz); // YOU  ** replace **  SOME OF THE VARIABLES ON THIS LINE
                      // WITH YOUR OWN CHOICES.
}

/***********************************************************************
 * sine_and_cosine(float x, [more parameters as needed]):
 *   -- This function takes a floating point parameter, x,
 *         plus ADDITIONAL parameters as needed to accomplish the following.
 *   -- This function sets (mutates) two variables in the CALLER to:
 *        -- the sine of x
 *        -- the cosine of x
 *       respectively.
 *
 *       It does so by using the ADDITIONAL parameters (that you add).
 *       It must NOT return anything.  It must NOT print anything.
 *
 *       Note that you must change the PROTOTYPE near the beginning of
 *       this file as part of your solution to this problem.
 **********************************************************************/
void sine_and_cosine(float x, float* s, float* c) { // YOU DECIDE WHAT  ** else **  GOES IN THE PARENTHESES.
	*s = sin(x);
	*c = cos(x);
}
