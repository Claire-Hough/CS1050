//Claire Hough
//cnhfg6
//CS1050 Lab3

#include <stdio.h>

int main(void)
{
	int input;
	int choice;
	int i;
	int prime = 0;
	int j;

//user input
	printf("Ener a number between 0 and 100.\n");
	scanf("%d", &input);

//checking input is within range
	while (input <=0 || input >=100)
	{
		printf("The number entered is outside the acceptable range.\n");
		printf("Enter a number between 0 and 100.\n");
		scanf("%d", &input);
	}

//menu print-out
	printf("Please enter the number beside your choice.\n");
	printf("1) List all prime numbers.\n");
	printf("2) Factorize the integer.\n");
	printf("0) Exit\n");
	scanf("%d", &choice);	

//checking choice entered is valid
	while (choice != 1 && choice != 2 && choice != 0)
	{
		printf("Invalid option. Redirecting to menu.\n");
		printf("Please enter the number beside your choice.\n");
		printf("1) List all prime numbers.\n");
		printf("2) Factorize the integer.\n");
		printf("0) Exit\n");
		scanf("%d", &choice);
	}

//while to loop so user can revisit the menu and do other things with the same entered number
	while (choice >= 0  && choice <= 2)
	{
//switch to execute choices
		switch (choice)
		{
			case 1:
			for (i = 2; i <= input; i++)
			{
				prime = 1;
				for (j = 2; j <= i/2; j++)
				{
					if (i % j == 0)
					{
						prime = 0;
						break;
					}
				}			
				if (prime == 1)
				{
					printf("%d\t", i); 
				}
			}
			printf("\n");
			break;

			case 2:
			for (i = 1; i <= input; i++)
			{
				if (input%i == 0)
				{
					printf(" %d\t", i);
				}
			}
			printf("\n");
			break;

			case 0:
			break;

			default:
			break;
		}

//menu print-out for loop
		printf("Rediecting to menu.\n");
		printf("Please enter the number beside your choice.\n");
		printf("1) List all prime numbers.\n");
		printf("2) Factorize the integer.\n");
		printf("0) Exit\n");
		scanf("%d", &choice);		

//checking new choice is valid for loop
		while (choice != 1 && choice != 2 && choice != 0)
		{
		printf("Invaild option. Redirecting to menu.\n");
		printf("Please enter the number beside your choice.\n");
		printf("1) List all prime numbers.\n");
		printf("2) Factorize the integer.\n");
		printf("0) Exit\n");
		scanf("%d", &choice);
		}
	}
return 0;
}
