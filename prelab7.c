//cnhfg6
//Claire Hough
//CS1050 Prelab 7

#include <stdio.h>

int getInput(void);
int getLength(char[]);

int main(void)
{
	int size, length;

	size = getInput();
	char array[size];

	printf("Enter a string.\n");
	scanf("%c", &array);

	length = getLength(array);
	printf("The length of %c is %d.\n", array[], length);
	return 0;
}

int getInput(void)
{
	int input;

	printf("Enter a length for the character array.\n");
	scanf("%d", &input);

	return input;
}

int getLength(char array[])
{
	int i, counter;
	for(i = 0; array[i] != '\0'; i++)
	{
		counter++;
	}

	return counter;
}
