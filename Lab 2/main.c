#include <stdio.h>

// Requirement:
// For the Fibonacci sequence whose values do not exceed a given number, find the sum of the even-valued terms

int main() {
	int firstFibonacciTerm = 0, secondFibonacciTerm = 1, thirdFibonacciTerm = 1;
	// 'thirdFibonacciTerm' will represent the current term
	// 'firstFibonacciTerm' and 'secondFibonacciTerm' will be its predecessors
	int upperLimit; // the terms should not become larger than this limit
	int evenTermsSum = 0; // sum of all the even fibo numbers <= upperLimit

	// read the number (the upper limit) from the keyboard, and ensure the process went well
	// <=> it did not return NULL
	if (scanf("%d", &upperLimit) == NULL)
		return 0;

	// while the next fibonacci term is lower than the limit, we calculate it and move on
	while (secondFibonacciTerm + thirdFibonacciTerm <= upperLimit) {
		// we 'shift' the fibonacci terms to the right (the first term takes the value of the second, 
		// the second takes the value of the third, and the third becomes the sum of the new second and third
		// (first, second, third) -> (second, third, second + third)
		firstFibonacciTerm = secondFibonacciTerm;
		secondFibonacciTerm = thirdFibonacciTerm;
		thirdFibonacciTerm = firstFibonacciTerm + secondFibonacciTerm; // the current term is the sum of the 2 previous ones
		if (thirdFibonacciTerm % 2 == 0) {
			evenTermsSum += thirdFibonacciTerm;
		}
	}

	printf("%d", evenTermsSum);
	
	return 0;
}