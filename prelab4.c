//cnhfg6
//Claire Hough
//CS1050 prelab4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInput(void);
void rngLoop(int);

int num;

int main(void)
{
	srand(time(NULL));
	int num = getInput();
	rngLoop(num);
	return 0;
}

int getInput(void)
{
	int num= 0;
	printf("Enter an integer between 0 and 100.\n");
	scanf("%d", &num);
	while (num <=0 || num >= 100)
	{
		printf("Invaild input! Enter an integer between 0 and ");
		printf("100.\n");
		scanf("%d", &num);
	}
	return num;
}

void rngLoop(int num)
{
	int i = 0;
	for (i=0; i < num; i++)
	{
		int random = rand() % 101;
		printf("%d  ", random);
	}
	printf("\n");
	return;
}
