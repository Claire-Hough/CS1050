//Claire Hough

#include <stdio.h>

int main (void)
{
	int num1, num2, sum, diff;

	printf("\nThis program will add and subtract two integers.\n");
	
	printf("Enter the first integer.\n");
	scanf("%d", &num1);

	printf("\nEnter the second integer.\n");
	scanf("%d", &num2);

	sum = num1 + num2;
	diff = num1 - num2;

	printf("\nThe sum of the two integers is: %d", sum);
	printf("\nThe difference of the two integers is: %d", diff);

	if (num1 == num2)
	{
		printf("\nThe two intergers are equal.\n");
	}
	if (num1 > num2)
	{
		printf("\nThe first integer is greater than the second.\n");
	}
	if (num1 < num2)
	{
		printf("\nThe first integer is less than the second.\n");
	}

	return 0;
}
