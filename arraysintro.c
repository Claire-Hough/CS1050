//cnhfg6
//Claire Hough
//CS1050 Lab6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInput(void);
int rngMax(void);
void initializeArray(int, int);
int arrayMin(int[], int);
int arrayMax(int[], int);
double arrayAvg(int[], int);
void sort(int[], int);

int main(void)
{
	int size = getInput();
	int max = rngMax();
	initializeArray(size, max);

	return 0;
}

int getInput(void)
{
	int size = 0;
	printf("Enter the size of the array to be generated.\n");
	scanf("%d", &size);

	while (size<=0 || size>=100)
	{
		printf("Invalid entry. Enter an integer between 0 and 100 to determine array size.\n");
		scanf("%d", &size);
	}
	
	return size;
}

int rngMax(void)
{
	int max = 0;

	printf("Enter the maximum random value to be inserted in the array.\n");
	scanf("%d", &max);

	while (max<=0 || max>=100)
	{
		printf("Invalid entry. Enter an integer between 0 and 100 to determine maximum value in array.\n");
		scanf("%d", &max);
	}
	
	return max;
}

void initializeArray(int size, int max)
{
	int i, Amin, Amax, array[size];
	double Aavg;

	srand(time(NULL));
	
	for(i = 0; i < size; i++)
	{
		array[i] = rand() % max + 1;
	}

	Amin = arrayMin(array, size);
	Amax = arrayMax(array, size);
	Aavg = arrayAvg(array, size);

	printf("The minimum value is %d and occurs at index %d.\n", array[Amin], Amin);
	printf("The maximum vaue is %d and occurs at index %d.\n", array[Amax], Amax);
	printf("The average of the data set is %lf.\n", Aavg);

	sort(array, size);  //bonus
}

int arrayMin(int array[], int size)
{
	int i, min, index=0;
	
	min = array[0];

	for(i = 1; i < size; i++)
	{
		if(array[i] < min)
		{
			index = i;
			min = array[i];
		}
	}

	return index;
}

int arrayMax(int array[], int size)
{
	int i, max, index=0;

	max = array[0];
	
	for(i = 1; i < size; i++)
	{
		if(array[i] > max)
		{
			index = i;
			max = array[i];
		}
	}

	return index;
}

double arrayAvg(int array[], int size)
{
	int i, sum=0; 
	double Aavg=0;
	
	for(i = 0; i < size; i++)
	{
		sum += array[i];
	}

	Aavg = sum/(double)size;

	return Aavg;
}

void sort(int array[], int size)
{
	int i, j, a=0;

	for(i = 0; i < size; i++)
	{
		for(j = i+1; j < size; j++)
		{
			if(array[i] > array[j]) //compares all other values to the first one, then second, and so on
			{
				a = array[i];	//saves number in index i to a
				array[i] = array[j];	//saves array j to array i, now smallest value is in lowest array index
				array[j] = a;	//saves number in a to index j, goes back to for loop and compares numbers to this smallest number
			}
		} 
	}

	printf("*****BONUS COMPLETE, ARRAY SORTED*****\n");
}
