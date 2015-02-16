/*
 =======================================================================
 * LEARNING OBJECTIVES:  This module lets you practice:
 *   -- Using STRUCTURES:
 *        -- Defining a structure TYPE
 *        -- Declaring a structure INSTANCE
 *        -- Putting values into the fields of a structure instance
 *        -- Referencing the fields of a structure instance
 *        -- Printing a structure instance
 *        -- Assignment (a = b) with structure instances
 *        -- Structure instances as arguments and returned values
 *        -- Arrays of structure instances
 *        -- Inputting a structure instance

 * Authors: David Mutchler, Claude Anderson, their colleagues and
 *          Eric Tan (CM 2991).  May, 2013.
 * =====================================================================
 *   
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Each field of a Color should be a number between 0 and 1.
typedef struct {
	float red;
	float green;
	float blue;
} Color;

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	Point p;
	Color color;
} ColoredPoint;

void print_color(Color color);
Color input_color();
void print_point(ColoredPoint point);
ColoredPoint input_point();
int count_points(ColoredPoint points[], int size);
ColoredPoint biggest_point(ColoredPoint points[], int size);
void swap_x_y(ColoredPoint points[], int size);

void test_print_color();
void test_input_color();
void test_print_point();
void test_input_point();
void test_count_points();
void test_biggest_point();
void test_swap_x_y();

/***********************************************************************
 * main():
 *   Calls the   TEST   functions in this module.
 **********************************************************************/
int main() {
	test_print_color();
	test_input_color();
	test_print_point();
	test_input_point();
	test_count_points();
	test_biggest_point();
	test_swap_x_y();

	return EXIT_SUCCESS;
}

/***********************************************************************
 * test_print_color():
 *   Tests the   print_color   function.
 **********************************************************************/
void test_print_color() {
	Color color1 = {0.45, 0.13, 0.00};
	Color color2 = {1, 0, 1};

	printf("\nTesting print_color:\n");

	print_color(color1);
	print_color(color2);
}

/***********************************************************************
 * print_color(Color color):
 *   -- PRINTs the data stored in the given Color,
 *      as in this example:
 *         (0.45, 0.13, 0.00)
 **********************************************************************/
void print_color(Color color) {
	printf("(%0.2f, %0.2f, %0.2f)\n", color.red, color.green, color.blue);

}

/***********************************************************************
 * test_input_color():
 *   Tests the   input_color   function.
 **********************************************************************/
void test_input_color() {
	Color color;

	printf("\nTesting input_color:\n");

	color = input_color();
	print_color(color);
}

/***********************************************************************
 * input_color():
 *   -- RETURNs a Color whose red, green and blue fields are obtained
 *      by prompting the user for 3 numbers and inputting those numbers.
 **********************************************************************/
Color input_color() {

	Color c;
	printf("Give us three numbers between 0 to 1, separated by spaces: ");
	fflush(stdout);
	scanf("%f %f %f", &(c.red), &(c.green), &(c.blue));
	return c;
}

/***********************************************************************
 * test_print_point():
 *   Tests the   print_point   function.
 **********************************************************************/
void test_print_point() {

	Color color1 = {0.45, 0.13, 0.88};
	Point point = {34, -44};
	ColoredPoint cpoint = {point, color1};

	printf("\nTesting print_point:\n");
	print_point(cpoint);
}

/***********************************************************************
 * print_point(ColoredPoint point):
 *   -- PRINTs the data stored in the given ColoredPoint,
 *      as in this example:
 *         Point: (45, -22)
 *         Color: (0.45, 0.13, 0.00)
 **********************************************************************/
void print_point(ColoredPoint point) {

	printf("Point: (%i, %i)\n", point.p.x, point.p.y);
	printf("Color: (%0.2f, %0.2f, %0.2f)\n", point.color.red, point.color.green, point.color.blue);
}

/***********************************************************************
 * test_input_point():
 *   Tests the   input_point   function.
 **********************************************************************/
void test_input_point() {
.
	ColoredPoint coloredpoint;

	printf("\nTesting input_point:\n");

	coloredpoint = input_point();
	print_point(coloredpoint);
}

/***********************************************************************
 * input_point():
 *   -- RETURNs a ColoredPoint whose point's x and y, and whose
 *      Color's red, green and blue fields are obtained
 *      by prompting the user for 5 numbers and inputting those numbers.
 **********************************************************************/
ColoredPoint input_point() {

	Color c;
	printf("For the color, input three numbers between 0 to 1, separated by spaces: ");
	fflush(stdout);
	scanf("%f %f %f", &c.red, &c.green, &c.blue);
	print_color(c);
	Point p;
	printf("For the location, input two integers, separated by spaces: ");
	fflush(stdout);
	scanf("%i %i", &p.x, &p.y);

	ColoredPoint cp;
	cp.p = p;
	cp.color = c;

	return cp;
}

/***********************************************************************
 * test_count_points():
 *   Tests the   count_points   function.
 **********************************************************************/
void test_count_points() {
	int answer1, answer2;
	ColoredPoint points1[] = {
			{{10, 14}, {0.55, 0.30, 0.60}}, // points[0]
			{{30, 5}, {0.45, 0.67, 0.60}}, // points[1]
			{{0, 0}, {1, 0, 1}}, // points[2]
			{{0, 0}, {1, 1, 1}}, // points[3]
			{{0, 0}, {0, 1, 0}} // points[4]
	};
	ColoredPoint points2[] = {
				{{2, 9}, {0.35, 0.30, 0.50}}, // points[0]
				{{20, 10}, {0.34, 0.27, 0.60}}, // points[1]
				{{80, -55}, {0.55, 0, 1}} // points[2]
		};

	printf("\nTesting count_points:\n");

	answer1 = count_points(points1, 5);
	answer2 = count_points(points2, 3);
	printf("Should be 2: %i\n", answer1); // Should be 2
	printf("Should be 3: %i\n", answer2);// Should be 3
}

/***********************************************************************
 * count_points(ColoredPoint points[], int size):
 *   -- RETURNs the number of ColoredPoint objects in the
 *      given array of ColoredPoint objects whose GREEN component
 *      is less than its BLUE component.
 *
 * Precondition: The array has at least the given size.
 **********************************************************************/
int count_points(ColoredPoint points[], int size) {
	
	int i, numberofpoints;
	numberofpoints = 0;
	for (i = 0; i < size; i++) {
		if (points[i].color.green < points[i].color.blue) {
			numberofpoints++;
		}
	}

	return numberofpoints; // REPLACE this stub by working code.
}

/***********************************************************************
 * test_biggest_point():
 *   Tests the   biggest_point   function.
 **********************************************************************/
void test_biggest_point() {

	ColoredPoint points1[] = {
				{{10, 14}, {0.55, 0.30, 0.60}}, // points[0]
				{{30, 5}, {0.45, 0.67, 0.60}}, // points[1]
				{{0, 0}, {1, 0, 1}}, // points[2]
				{{0, 0}, {1, 1, 1}}, // points[3]
				{{0, 0}, {0, 1, 0}} // points[4]
	};
	ColoredPoint answer;
	printf("\nTesting biggest_point:\n");
	answer = biggest_point(points1, 5);
	int a = answer.p.x;
	int b = answer.p.y;
	float rednumber = answer.color.red;
	float greennumber = answer.color.green;
	float bluenumber = answer.color.blue;
	printf("{{%i, %i}, {%0.2f, %0.2f, %0.2f}}\n", a, b, rednumber, greennumber, bluenumber);
}

/***********************************************************************
 * biggest_point(ColoredPoint points[], int size):
 *   -- RETURNs the ColoredPoint in the array which is farthest
 *      from the origin.  That is, its   (x squared + y squared)
 *      is bigger than that of any of the other ColoredPoints.
 *
 * Precondition: The array has at least the given size.
 **********************************************************************/
ColoredPoint biggest_point(ColoredPoint points[], int size) {
	// TODO: 7b. Implement and test this function.
	int i;
	double dist, largestdist;
	ColoredPoint cpoint;
	for (i = 0; i < size; i++) {
		dist = ((points[i].p.x)*(points[i].p.x)) + ((points[i].p.y)*(points[i].p.y));
		if (dist > largestdist) {
			largestdist = dist;
			cpoint = points[i];
		}
	}
	return cpoint;
}

/***********************************************************************
 * test_swap_x_y():
 *   Tests the   swap_x_y   function.
 **********************************************************************/
void test_swap_x_y() {

	ColoredPoint points1[] = {
					{{10, 14}, {0.55, 0.30, 0.60}}, // points[0]
					{{30, 5}, {0.45, 0.67, 0.60}}, // points[1]
	};
	swap_x_y(points1, 2);
	printf("\nTesting swap_x_y:\n");
	int i;
	for (i=0;i<2;i++){
		print_point(points1[i]);
	}
}

/***********************************************************************
 * swap_x_y(ColoredPoint points[], int size):
 *   -- MUTATES the given array as follows:
 *      For each ColoredPoint object in the given array of ColoredPoint
 *      objects, swap its x and y coordinates.  For example, if one
 *      of the points is at (50, 7), after this function returns
 *      that point should be at (7, 50).
 *
 * Precondition: The array has at least the given size.
 **********************************************************************/
void swap_x_y(ColoredPoint points[], int size) {

	int i;
	for (i=0;i<size;i++){
		int a = points[i].p.x;
		int b = points[i].p.y;
		points[i].p.x = b;
		points[i].p.y = a;
	}
}
