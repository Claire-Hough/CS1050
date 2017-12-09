//Claire Hough
//cnhfg6
//CS1050 Prelab3

#include <stdio.h>

int main(void)
{
	int num; //user entered number
	int eoo; //even or odd
	int counter; //counter for for loop

//user input
	printf("Enter an integer between 0 and 100.\n");
	scanf("%d", &num);

//checking valid input
	while (num <= 0 || num >= 100)
	{
		printf("\nInvaild entry. Enter an integer between ");
		printf("0 and 100.\n");
		scanf("%d", &num);
	}

//for loop printing numbers up to entered number
	for (counter = 1; counter <= num; counter++)
	{
		printf("\n%d ", counter);
	}

//checking even or odd
	eoo = num % 2;

//switch to print out even or odd
	switch (eoo)
	{
		case 0:
		printf("\nThe integer is even.\n");
		break;

		default:
		printf("\nThe integer is odd.\n");
		break;
	}
return 0;
}
