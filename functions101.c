//cnhfg6
//Claire Hough
//CS1050 Lab4 functions101.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInput(void);
int menu(void);
int checkPrime(int);
int addDigits(int);
int rngLoop(int);

int main(void)
{
	int input = getInput();
	int prime;
	int sum;
	int even;
	int odd = 0;

while (1)
{	
	int choice = menu();
	switch (choice)
	{
		case 1:
		prime = checkPrime(input);
		if (prime == 1)
		{
			printf("%d is a prime number.\n", input);
		}
		else
		{
			printf("%d is not a prime number.\n", input);
		}
		break;

		case 2:
		sum = addDigits(input);
		printf("The sum of the digits in %d is %d\n", input, sum);
		break;

		case 3:
		even = rngLoop(input);
		odd = input - even;

		printf("\n%d even values and %d odd values generated\n", even, odd);
		break;

		case 4:
		return 0;

		default:
		printf("Invalid entry! Redirecting to menu.");
		break;
	}
}
	return 0;
}

int getInput(void)
{
	int input = 0;

	printf("Enter an integer between 0 and 1000.\n");
	scanf("%d", &input);

	while(input <=0 || input >=1000)
	{
		printf("Invalid input! Enter an integer between 0 and 1000.\n");
		scanf("%d", &input);
	}
	return input;
}

int menu(void)
{
	int choice = 0;

	printf("***** MAIN MENU *****\n");
	printf("Enter the number cooresponding to your choice.\n\n");
	printf("(1) Check prime number\n");
	printf("(2) Add up individual digits\n");
	printf("(3) Generate random values\n");
	printf("(4) Exit\n");
	scanf("%d", &choice);

	return choice;
}

int checkPrime(int input)
{
	int j;

	if (input <= 1)
	{
		return 0;
	}

	for (j=2; j <= input/2; j++)
	{
		if ((input%j) == 0)
		{
			return 0;
		} 
	}
	return 1;
}

int addDigits(int input)
{
	return (input % 10 + addDigits(input/10));	
}

int rngLoop(int input)
{
	int i = 0, even = 0;

	for(i=0; i < input; i++)
	{
		int random = rand() % 101;
		printf("%d  ", random);
	
		if (random % 2 == 0)
		{
			even++;
		}
	}
	
	return even;
}



