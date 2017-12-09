//cnhfg6
//Claire Hough
//CS1050 LAB10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getPass(char*, char*);
int checkPass(char*);

int main(int argc, char** argv)
{
	if(argc != 3)
	{
		printf("Command line error. \n"
		"./a.out <input_filename> <output_filename>\n");
		return 0;
	}

	char* filename = argv[1];
	char* validpass = argv[2];
	int total = getPass(filename, validpass);

	if(total  == -1)
		exit(1);

	printf("There were %d valid passwords written to %s.\n", total, validpass);

	return 0;
}

int getPass(char* filename, char* validpass)
{
	int total=0;
	FILE* fp = fopen(filename, "r");
	FILE* fp2 = fopen(validpass, "w");
	if(fp == NULL)
	{
		printf("Error. Unable to open file.\n");
		return -1;
	}

	char* password = (char*)malloc(sizeof(char) * 20);
	
	while( fscanf(fp, "%s", password) != EOF)
	{
		if(checkPass(password) == 1)
		{
			total++;
			fprintf(fp2, "%s\n", password);
		}
	}

	fclose(fp);
	fclose(fp2);
	free(password);
	return total;
}

int checkPass(char* password)
{
	int i=0, hasUpper=0, hasLower=0, hasNum=0, hasChar=0;
	int length = strlen(password);

	if(length > 8 || length < 12)
	{
		return 0;
	}

	for(i=0; i < length; i++)
	{
		if(isupper( *(password + i) != 0))
		{
			hasUpper++;
		}
		if(islower( *(password + i) != 0))
		{
			hasLower++;
		}
		if(isdigit( *(password + i) != 0))
		{
			hasNum++;
		}
		if(ispunct( *(password + i) != 0))
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
