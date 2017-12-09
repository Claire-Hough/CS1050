//cnhfg6
//Claire Hough
//CS1050 LAB7

#include <stdio.h>
#define MAX 25

int length(char[]);
int replace(char[], int);
void concatenate(char[], char[]);
void sort(char[]);

int main(void)
{
	char array1[MAX], array2[MAX];
	int Length, position, Replace;

	printf("Enter the first string.\n");
	scanf("%s", array1);

	Length = length(array1);
	printf("Length of the first string is %d.\n", Length);
	
	printf("Enter a position for the replacement operation between 1-%d.\n", Length);
	scanf("%d", &position);

	Replace = replace(array1, position);
	while(Replace != 1)
	{
		printf("Invaild entry. Enter an integer between 1-%d.\n", Length);
		scanf("%d", &position);

		Replace = replace(array1, position);
	}
	printf("The first string after the replacement operator is: %s.\n", array1);

	printf("Enter the second string.\n");
	scanf("%s", array2);

	concatenate(array1, array2);
	printf("The strings after concatenation is %s.\n", array1);

	sort(array1);
	printf("The string after sorting is %s.\n", array1);	
	return 0;
}

int length(char array1[])
{
	int i, counter=0;
	
	for(i=0; array1[i] != '\0'; i++)
	{
		counter++;
	}

	return counter;
}

int replace(char array1[], int position)
{
	int Length=0;
	Length = length(array1);
	
	if (position < 1 || position > Length)
	{
		return 0;
	}
	else
	{
		array1[position-1] = '#';
		return 1;
	}
}

void concatenate(char array1[], char array2[])
{
	int Length, j;
	
	Length = length(array1);
	for(j=0; array2[j] != '\0'; ++j, ++Length)
	{
		array1[Length]= array2[j];
	}
		
	array1[Length] = '\0';
}

void sort(char array1[])
{
	int i, j, Length, a=0;
	Length = length(array1);

	for(i=0; i < Length; i++)			//bubble sorting
	{
		for(j = 0; j < Length-1; j++)
		{
			if(array1[j] > array1[j+1])	//compares other chars to first one, then second, and so on
			{
				a = array1[j];		//saves char in index i to a
				array1[j] = array1[j+1];	//saves lowest value to array in index i 
				array1[j+1] = a;		//replaces low value with higher value to put it in order
			}
		}
	}
}
