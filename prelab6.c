//cnhfg6
//Claire Hough
//CS1050 prelab6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInput(void);
int rngMax(void);
double initializeArray(int[], int, int);

int main(void)
{
	double sum;

	int num = getInput();
	int max = rngMax();

	srand(time(NULL));

	int array[num];

	sum = initializeArray(array,max,num);
	printf("The sum of all the values is %lf\n", sum);
	return 0;
}

int getInput(void)
{
	int num = 0;

	printf("Enter an integer between 0 and 100 to determine array size.\n");
	scanf("%d", &num);
	
	while (num <=0 || num>=100)
	{
		printf("Invalid entry. Enter an integer between 0 and 100.\n");
		scanf("\n%d", &num);
	}

	return num;
}

int rngMax(void)
{
	int max= 0;

	printf("Enter an integer between 0 and 100 to set maximum number ");
	printf("inserted into array.\n");
	scanf("%d", &max);

	while (max<=0 || max >=100)
	{
		printf("Invaild entry. Enter a number between 0 and 100.\n");
		scanf("%d", &max);
	}

	return max;
}

double initializeArray(int array[],int max, int num)
{
	double sum=0;
	int x;

	for(x=0;x < num;x++)
	{
		array[x] = rand()%max+1;
		sum += array[x];
	}
	
	return sum;
}
