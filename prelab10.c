//cnhfg6
//Claire Hough
//CS1050 Prelab10

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* getPass(char*);
int checkPass(char*);

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		return 0;
	}

	char* filename = argv[1];
	char* password = getPass(filename);
	
	while(checkPass(password) != 1)
	{
		printf("Please re-enter a password 8-12 characters in length, with "
		"one capital, one capital, one lowercase, one number, and one special "			    "character.\n");
		scanf("%s", password);
	}

	printf("Password %s is valid.\n", password);
	printf("Freeing memory and exiting...\n");
	free(password);


	return 0;
}

char* getPass(char* filename)
{
	FILE* fp = fopen(filename, "r");
	
	if(fp == NULL)
	{
		return NULL;
	}

	char* password = (char*)malloc(sizeof(char) * 12);
	fscanf(fp, "%s", password); //read line from file

	fclose(fp);
	return password;
}

int checkPass(char* password)
{
	int length = strlen(password);
	int i=0, hasUpper=0, hasLower=0, hasNum=0, hasChar=0;
	
	if(length < 8 || length > 12)
	{
		return 0;
	}

	for(i=0; i < length; i++)
	{
		if(isupper( *(password + i)) != 0)
		{
			hasUpper++;
		}
		else if(islower( *(password + i)) != 0)
		{
			hasLower++;
		}
		else if(isdigit( *(password + i)) != 0)
		{
			hasNum++;
		}
		else if(ispunct( *(password + i)) != 0)
		{
			hasChar++;
		}
	}

	if(hasUpper>0 && hasLower>0 && hasNum>0 && hasChar>0)
	{
		return 1;
	}
	
	return 0;
}
