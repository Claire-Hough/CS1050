//cnhfg6
//Claire Hough
//CS1050 Lab8

#include <stdio.h>
#include <math.h>

float* addValues(float*, int);
float* sort(float*, int);
void calculations(float*, int);

int main (void)
{
	int size, i=0;
	float *arrayptr;

	printf("Please enter the number of values you wish to input.\n");
	scanf("%d", &size);

	while(size < 1)
	{
		printf("Invalid entry! Must be a positive integer. Enter the number of values you wish to input.\n");
		scanf("%d", &size);
	}

	float array[size];
	arrayptr = array;

	arrayptr = addValues(arrayptr, size);

	arrayptr = sort(arrayptr, size);
	printf("Sorted values in descending order:\n");
	for(i=0; i < size; i++)
	{
		printf("%f\t", *(arrayptr+i));
	}
	printf("\n");

	calculations(arrayptr, size);

	return 0;
}

float* addValues(float* arrayptr, int size)
{
	int i=0;
	float value=0;

	for(i=0; i < size; i++)
	{
		printf("Enter a value.\n");
		scanf("%f", &value);

		*(arrayptr + i) = value; 
	}

	return arrayptr;
}

float* sort(float* arrayptr, int size)
{
	int i=0, j=0;
	float a=0.0;

	for(i=0; i < size; i++)
	{
		for(j= i+1; j < size; j++)
		{
			if( *(arrayptr+i) < *(arrayptr+j) )
			{
				a = *(arrayptr+i);
				*(arrayptr+i) = *(arrayptr+j);
				*(arrayptr+j) = a;
			}
		}
	}

	return arrayptr;
}

void calculations(float* arrayptr, int size)
{
	float median=0.0, mean=0.0, range=0.0, total=0.0, variance=0.0, sd=0.0;
	int i=0;

	if((size%2) == 0)
	{
		median = ( *(arrayptr+((size-1)/2)) + *(arrayptr+(((size-1)/2)+1)) ) /2;
	}
	else
	{
		median = *(arrayptr+(size/2));
	}

	for(i=0; i < size; i++)
	{
		total = total + *(arrayptr+i);
	}
	mean = total/(float)size;
	printf("Mean: %f\n", mean);
	printf("Median: %f\n", median);
	
	range = *(arrayptr+0) - *(arrayptr+(size-1));
	printf("Range: %f\n", range);


	//Bonus
	for(i=0; i < size; i++)		//individual deviations
	{
		*(arrayptr+i) = mean - *(arrayptr+i);
	}
	for(i=0; i < size; i++)		//squares of individual deviations
	{
		*(arrayptr+i) = pow( *(arrayptr+i), 2);
	}

	total=0;
	for(i=0; i < size; i++)		//sum of squares
	{
		total = total + *(arrayptr+i);
	}
	variance = total / (size-1);	//variance

	sd = sqrt(variance);		//standard deviation

	printf("***BONUS: Standard deviation of the data set: %f\n", sd);
}
