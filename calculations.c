//Claire Hough
//cnhfg6
//CS1050 Lab 2

#include <stdio.h>

int main (void)
{
	int int1, int2, sum, diff, prod;

	printf("\nEnter an integer that's greater than 0 and less than 10.\n");
	scanf("%d", &int1);

	printf("\nEnter a second integer that's also greater than 0");
	printf(" and less than 10.\n");
	scanf("%d", &int2);

	if (int1 < 0 || int1 > 10)
	{
		printf("\nFirst integer is less than 0 or greater than 10!");
		printf("\nRe-enter a new integer.\n");
		scanf("%d", &int1);
		printf("\n");
	}
	
	if (int2 < 0 || int2 > 10)
	{
		printf("\nSecond integer is less than 0 or greater than 10!");
		printf("\nRe-enter a new integer.\n");
		scanf("%d", &int2);
		printf("\n");
	}

	sum = int1 + int2;
	diff = int1 - int2;
	prod = int1 * int2;

	printf("\nThe sum is: %d", sum);
	printf("\nThe difference is: %d", diff);
	printf("\nThe product is: %d", prod);

	if (prod % 2 == 0)
	{
		printf("\nThe product of the two integers is even.\n");
	}
	else
	{
		printf("\nThe product of the two numbers in odd.\n");
	}

	if (int1 == int2)
	{
		printf("The two integers are equal.\n");
	}
	else if (int1 > int2)
	{
		printf("The first integer is greater than the second.\n");
	}
	else
	{
		printf("The first integer is less than the second.\n");
	}
return 0;
}
