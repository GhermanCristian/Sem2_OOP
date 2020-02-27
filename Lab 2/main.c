#include <stdio.h>

int main() {
	int a = 0, b = 1, c = 1; // the first three fibonacci terms (in the order a, b, c)
	int upperLimit;
	int sum = 0;

	if (scanf("%d", &upperLimit) == NULL)
		return 0;

	// while the next fibonacci term is lower than the limit
	while (b + c <= upperLimit) {
		a = b;
		b = c;
		c = a + b;
		sum += !(c % 2) * c;
	}

	printf("%d", sum);
	
	return 0;
}