//cnhfg6
//Claire Hough
//CS1050 prelab8


#include <stdio.h>
#define MAX 50

char* getInput(void);
char* changeString(char*);

int main(void)
{
	char *arrayptr;

	arrayptr = getInput();

	printf("The string \"%d\" is stored at memory address %p.\n", *arrayptr, arrayptr);	

	arrayptr = changeString(arrayptr);

	printf("The string \"%d\" is stored at memory address %p.\n", *arrayptr, arrayptr);
	return 0;
}

char* getInput(void)
{
	char array[MAX];
	char *arrayptr;

	printf("Please enter a character string.\n");
	scanf("%s", array);

	arrayptr = array;
	
	return arrayptr; 
}

char* changeString(char* arrayptr)
{
	char array2[MAX];

	printf("Please enter a new replacement string.\n");
	scanf("%s", array2);

	arrayptr = array2;

	return arrayptr;
}
