//Claire Hough
//cnhfg6
//CS1050 Lab9

#include <stdio.h>
#include <stdlib.h>

void createAccounts(int*, float*, int);
int deposit(int*, float*, int);
int withdraw(int*, float*, int);
void summary(int*, float*, int);

int main(void)
{
	int accounts=0, choice=0;
	int* ptr1;
	float* ptr2;
	
	printf("How many accounts are to be created?\n");
	scanf("%d", &accounts);

	ptr1 = malloc(sizeof(int) * accounts);
	ptr2 = malloc(sizeof(float) * accounts);
        
	if (ptr1 == NULL)
        {
                printf("Out of memory\n");
                return 0;
        }

        if(ptr2 == NULL)
        {
                printf("Out of memory\n");
                return 0;
        }

	createAccounts(ptr1, ptr2, accounts);

	while(1)
	{
		int Deposit=0, Withdraw=0;

		printf("\n\n*** MENU ***\n");
		printf("1) Deposit funds\n");
		printf("2) Withdraw funds\n");
		printf("3) Print active account summary\n");
		printf("4) Exit\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
			Deposit = deposit(ptr1, ptr2, accounts);
			if(Deposit == 1)
				printf("Deposit successful.\n");
			else
				printf("Invalid PIN. Redirecting to menu.");
			break;
			
			case 2:
			Withdraw = withdraw(ptr1, ptr2, accounts);
			if(Withdraw == 1)
				printf("Withdraw successful.\n");
			else
				printf("Invalid PIN or insufficient funds. Redirecting to menu.\n");
			break;

			case 3:
			summary(ptr1, ptr2, accounts);
			break;

			case 4:
			summary(ptr1, ptr2, accounts);
			free(ptr1);
			free(ptr2);
			return 0;
			break;

			default:
			printf("Invalid option.\n");
			continue;
		}
	}
}

void createAccounts(int* ptr1, float* ptr2, int accounts)
{
	int i=0;

	for(i=0; i < accounts; i++)
	{
		printf("Account #%d PIN: ", (i+1));
		scanf("%d", (ptr1+i));
	
		while( *(ptr1 + i) <1000 || *(ptr1 + i) >9999)
		{
			printf("Invalid PIN. Please reenter.\n");
			scanf("%d", (ptr1+i));
		}
	
		printf("Account #%d initial balance: ", (i+1));
		scanf("%f", (ptr2+i));

		while( *(ptr2 + i) <1)
		{
			printf("Invalid initial balance. Please reenter.\n");
			scanf("%f", (ptr2+i));
		}
	}
}

int deposit(int* ptr1, float* ptr2, int accounts)
{
	int PIN=0, i=0;
	float deposit=0;

	printf("Account PIN: ");
	scanf("%d", &PIN);

	printf("Deposit amount: $");
	scanf("%f", &deposit);

	while(deposit < 1)
	{
		printf("Invalid deposit. Please reenter.\n");
		scanf("%f", &deposit);
	}

	for(i=0; i < accounts; i++)
	{
		if( *(ptr1 + i) == PIN)
		{
			*(ptr2 + i) += deposit;
			return 1;
		}
	}
	return 0;
}

int withdraw(int* ptr1, float* ptr2, int accounts)
{
	int PIN=0, i=0;
	float withdraw=0;

	printf("Account PIN: ");
	scanf("%d", &PIN); 
	
	printf("Withdraw amount: $");
	scanf("%f", &withdraw);

	while(withdraw < 1)
	{
		printf("Invalid withdraw. Please reenter.\n");
		scanf("%f", &withdraw);
	}

	for(i=0; i < accounts; i++)
	{
		if( *(ptr1 + i) == PIN)
		{
			if( *(ptr2 + i) - withdraw >= 0)
			{
				*(ptr2 + i) -= withdraw;
				return 1;
			}
		}
	}
	return 0;
}

void summary(int* ptr1, float* ptr2, int accounts)
{
	int i=0;

	printf("***********************\n\n");
	printf("Acitve account summary:\n\n");
	printf("***********************\n\n");
	printf("PIN	Balance\n");
	
	for(i=0; i < accounts; i++)
	{
		printf("%d\t$%.2f\n", *(ptr1 +i), *(ptr2 + i) );
	}
}
