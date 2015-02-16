/*
 * =====================================================================
 * LEARNING OBJECTIVES:  This module lets you practice:
 *   -- Using ARRAYs allocated via the STACK
 *   -- Using ARRAYs allocated viat the HEAP, by using MALLOC to do so
 *        -- More precisely, using POINTERs that emulate arrays.
 *
 * Allocating via the HEAP is the fundamental approach for constructing
 * OBJECTs, as well as for allocating "dynamically-allocated arrays"
 * like LISTs.
 *
 * Authors: David Mutchler, Chandan Rupakheti, Matt Boutell, Curt Clifton,
 *          Delvin Defoe and their colleagues.  February, 2013.
 =======================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void stack_example();
void heap_example();
float* allocate_from_heap_and_use(int size);
void memory_leak(int n);
void misuse_of_stack();
float* failed_attempt_to_return_array();
void foo();

void store_sines(float numbers[], int size);
void print_array(float numbers[], int size);

int main() {
	stack_example();
	heap_example();

	// Open Task Manager and watch the memory use of this process
	// while it runs: without and with the memory leak.
	//memory_leak(300); // Try increasing to (say) 1000

	//misuse_of_stack();

	return EXIT_SUCCESS;
}

/***********************************************************************
 * stack_example():
 *   -- Allocates an array from the STACK, and then uses the array.
 **********************************************************************/
void stack_example() {
	printf("\nAllocating an array from the STACK.\n");

	float numbers[10000]; // Allocates from the STACK

	store_sines(numbers, 10000); // Put data into the array.
	print_array(numbers, 10); // Print 1st 10 data items in the array
}

/***********************************************************************
 * heap_example():
 *   -- Allocates an array from the HEAP, and then uses the array.
 *          More precisely, allocates space to which a POINTER points,
 *          but note that one can (and perhaps should) use ARRAY
 *          notation with that pointer.
 *   -- Returns a pointer to the space to which the array refers.
 *          Note: a real application would probably need to also return
 *          the size of that space.
 **********************************************************************/
void heap_example() {
	printf("\nAllocating an array from the HEAP.\n");

	// The function call below allocates space from the HEAP
	// and returns a pointer to that space.
	float* numbers;
	numbers = allocate_from_heap_and_use(10000);

	// So we can continue using that space here in the CALLER.
	// Note that you can (and should) use ARRAY notation from here on!
	numbers[3] = numbers[2] + numbers[1];
	print_array(numbers, 10); // Print 1st 10 data items in the array

	// Forgetting to FREE the space when you are done with the space
	// can create a "memory leak".
	free(numbers);
}

/***********************************************************************
 * allocate_from_heap_and_use(int size):
 *   -- Allocates an array from the HEAP, of the given size,
 *          and then uses the array.
 *          More precisely, allocates space to which a POINTER points,
 *          but note that one can (and perhaps should) use ARRAY
 *          notation with that pointer.
 *   -- Returns a pointer to the space to which the array refers.
 *          The caller can then safely use that space.
 *          But the caller has the responsibility for FREEing that space
 *          when the caller is done with it.
 **********************************************************************/
float* allocate_from_heap_and_use(int size) {
	// Allocates from the HEAP, using MALLOC.
	float* numbers;
	numbers = (float*) malloc (size * sizeof(float));

	// Now you use the space, just like it were an array.
	// It will be clear to you if you use ARRAY notation (square brackets)
	// instead of POINTER notation (asterisks).
	store_sines(numbers, 10000); // Put data into the array.
	print_array(numbers, 10); // Print 1st 10 data items in the array
	numbers[0] = 999;

	// Unlike an array, you CAN safely return a pointer to the space.
	return numbers;
}

/***********************************************************************
 * memory_leak_example(int n):
 *  Repeats n times:
 *    1. Allocates lots of space (100,000 floats).
 *    2. Uses the space.
 *    3. Frees up the space.
 *
 *  Deleting Step 3 demonstrates the effect of a memory leak.
 **********************************************************************/
void memory_leak(int n) {
	int k;
	float* numbers;
	int size = 1000000;

	printf("\nDemonstrates FREE and (without it) a MEMORY LEAK.\n");

	for (k = 0; k < n; k = k + 1) {
		numbers = (float*) malloc (size * sizeof(float));
		store_sines(numbers, size);

		// Try commenting out the following to see the effect
		// of the memory leak.
		free(numbers);
	}
}

/***********************************************************************
 * misuse_of_stack():
 *   -- The CALLER attempts to use memory allocated on the STACK
 *         by the CALLEE.  This is an ERROR!!!
 **********************************************************************/
void misuse_of_stack() {
	printf("\nDemonstrates a WRONG attempt to return memory allocated on the STACK.\n");

	float* numbers;
	numbers = failed_attempt_to_return_array();

	printf("Back in Caller: Memory from Callee may be ok so far:\n");
	print_array(numbers, 10); // Print 1st 10 data items in the array

	printf("Call just about ANY function (so use the STACK again):\n");
	foo();

	printf("Back in Caller: Memory from original Callee may be CORRUPT now:\n");
	print_array(numbers, 10); // Print 1st 10 data items in the array
}

float* failed_attempt_to_return_array() {
	printf("\nAllocating an array from the STACK.\n");

	float numbers[10000]; // Allocates from the STACK

	store_sines(numbers, 10000); // Put data into the array.
	print_array(numbers, 10); // Print 1st 10 data items in the array

	return numbers; // same as &(numbers[0]) -- returning this is an ERROR
}

void foo() {
	float blah[10000];
	int k;

	for (k = 0; k < 10000; k = k + 1) {
		blah[k] = k;
	}
	print_array(blah, 10); // Print 1st 10 data items in the array
}

/***********************************************************************
 * store_sines(float numbers[], int size):
 *   Stores the sines of 0, 1, 2, ... in the given array,
 *   up to the given size.
 *
 * Precondition: The array's capacity is at least the given size.
 **********************************************************************/
void store_sines(float numbers[], int size) {
	int k;

	for (k = 0; k < size; k = k + 1) {
		numbers[k] = sin(k);
	}
}

/***********************************************************************
 * print_array(float numbers[], int size):
 *   -- Prints the numbers in the given array of the given size,
 *         all on one (possibly long) line.
 *   -- Precondition: The array has at least the given size.
 **********************************************************************/
void print_array(float numbers[], int size) {
	int k;

	for (k = 0; k < size; k = k + 1) {
		printf("%7.2f", numbers[k]);
	}
	printf("\n");
}

