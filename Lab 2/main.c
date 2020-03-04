#include <stdio.h>

// Requirement:
// For the Fibonacci sequence whose values do not exceed a given number, find the sum of the even-valued terms

int main() {
	int first = 0, second = 1, third = 1; 
	// the first three fibonacci terms (in the order first <= second <= third)
	// 'third' will represent the current term, 'first' and 'second' will be its predecessors
	int upperLimit; // the terms should not become larger than this limit
	int sum = 0; // sum of all the even fibo numbers <= upperLimit

	// read the number (the upper limit) from the keyboard, and ensure the process went well
	// (it did not return NULL)
	if (scanf("%d", &upperLimit) == NULL)
		return 0;

	// while the next fibonacci term is lower than the limit, we calculate it and move on
	while (second + third <= upperLimit) { 
		// we 'shift' the fibonacci terms to the right (the first term takes the value of the second, 
		// the second takes the value of the third, and the third becomes the sum of the new second and third
		// (first, second, third) -> (second, third, second + third)
		first = second;
		second = third;
		third = first + second; // the current term is the sum of the 2 previous ones
		if (third % 2 == 0) { // if the number is even, we add it to the sum
			sum += third;
		}
	}

	printf("%d", sum); // print the number to the screen
	
	return 0;
}