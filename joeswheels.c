//Claire Hough
//cnhfg6
//CS1050 HW3

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void getCars(int*, float*, int*, char*);
float reserve(int*, float*, int, int);
void printInventory(int*, float*, int*, int);
void writeToFile(int*, float*, int*, char*, int);
void selectionSort(int*, float*, int*, int);
void swap(int*, float*, int*, int, int);

int main(int argc, char** argv)
{
	if(argc != 5)
	{	
		printf("Command line error! Correct usage:\n./a.out <master_input_filename> <number_of_vehicles> <reservation_input_filename> <output_filename>\n");
		return 0;
	}

	char* cars = *(argv + 1);
	int length = atoi( *(argv + 2) );
	char* reservations = *(argv + 3);
	char* inventory = *(argv + 4);

	float* prices = (float*)malloc(sizeof(float) * length);
	int* miles = (int*)malloc(sizeof(int) * length);
	int* carIDs = (int*)malloc(sizeof(int) * length);	

	getCars(carIDs, prices, miles, cars);
	printInventory(carIDs, prices, miles, length);
	
	FILE* fp = fopen(reservations, "r");
	
	if(fp == NULL)
	{
		printf("Can't open file!\n");
		return 0;
	}

	float totalprofit=0;
	int choice=0;
	
	printf("\nProcessing reservations...\n");

	while( fscanf(fp, "%d", &choice) != EOF)
	{
		totalprofit += reserve(carIDs, prices, choice, length);
	}
	fclose(fp);

	printInventory(carIDs, prices, miles, length);
	
	float profit =0;
	while(1)
	{
		printf("\nEnter vehicle ID. Enter 0 to exit.\n");
		scanf("%d", &choice);

		if(choice == 0)
			break;

		profit = reserve(carIDs, prices, choice, length);
		if( profit == -1)
			printf("Invalid input\n");
		else
		{
			totalprofit += profit;
			printInventory(carIDs, prices, miles, length);
		}
	}

	printf("\nTotal Profit: $%.2f\n", totalprofit);
	printf("Writing remaining inventory to inventory.txt\n");
	printf("Freeing memory and exiting.\n");
	printf("\n***BONUS COMPLETED***\n\n");
	writeToFile(carIDs, prices, miles, inventory, length);

	free(prices);
	free(miles);
	free(carIDs);
	return 0;
}

void getCars(int* carIDs, float* prices, int* miles, char* cars)
{
	int i=0;
	FILE* fp = fopen(cars, "r");
	if(fp == NULL)
	{
		printf("Can't open file!\n");
		return;
	}

	while( fscanf(fp, "%d %f %d", (carIDs + i), (prices + i), (miles + i)) != EOF )
	{
		i++;
	}

	fclose(fp);
}

float reserve(int* carIDs, float* prices, int choice, int length)
{
	int i=0;

	for(i=0; i < length; i++)
	{
		if( *(carIDs + i) == choice)
		{
			*(carIDs + i) =0;
			return *(prices + i);
		}
	}
	
	return -1.0;
}

void printInventory(int* carIDs, float* prices, int* miles, int length)
{
	int i=0;
	
	selectionSort(carIDs, prices, miles, length);

	printf("\n*** Current Inventory ***\n");
	for(i=0; i < length; i++)
	{
		if( *(carIDs + i) != 0)
		{
		printf("%-15d$%-15.2f%-15d\n",*(carIDs + i),*(prices + i),*(miles + i));
		}
	}
}

void selectionSort(int* carIDs, float* prices, int* miles, int length)
{
	int i=0, j=0, max=0;
	
	for(i=0; i < length-1; i++)
	{
		max = i;
		for(j=i+1; j < length; j++)
		{
			if( *(prices + j) > *(prices + max) )
				max = j;
		}
		
		swap(carIDs, prices, miles, i, max);
	}	
}

void swap(int* carIDs, float* prices, int* miles, int i, int max)
{
	int holdID = *(carIDs + max);
	float holdPrices = *(prices + max);
	int holdMiles = *(miles + max);

	*(carIDs + max) = *(carIDs + i);
	*(prices + max) = *(prices + i);
	*(miles + max) = *(miles + i);

	*(carIDs + i) = holdID;
	*(prices + i) = holdPrices;
	*(miles + i) = holdMiles;
}

void writeToFile(int* carIDs, float* prices, int* miles, char* inventory, int length)
{
	FILE* fp = fopen(inventory, "w");
	
	if(fp == NULL)
	{
		printf("File can't open!\n");
		return;
	}

	int i=0;
        for(i=0; i < length; i++)
        {
                if( *(carIDs + i) != 0)
                {
                fprintf(fp,"%-8d%-8f%-8d\n",*(carIDs + i),*(prices + i),*(miles + i));
                }
        }

	fclose(fp);
}
