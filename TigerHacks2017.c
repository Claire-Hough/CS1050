#include <stdio.h>
#define MAX 100

char write(char);
float wordCount(char, int);
int paperDone(int, float);
void reward(int,char);
void game(void);

int main(void)
{
	int min=0, done=0;
	char paper[MAX] = {'a'};
	float count;

	printf("This program will check to see if you have reached the word ");
	printf("count necessary for any paper that you are writing.\n");
	printf("When you reach the minimum you set, you will be rewarded with");
	printf(" a game.\n\n");

	printf("Please enter the minimum word count you must reach.\n");
	scanf("%d", &min);

	paper[] = write(paper);

	count = wordCount(paper, min);

	done = paperDone(min, count);

	reward(done, paper);
	return 0;
}

char write(char paper[])
{
	printf("You can write your paper here. Press 'enter' when you are finished");
	printf(" or you'd like to check your progress.\n");
	scanf("%s", paper);

	return paper;
}

float wordCount(char paper[], int min)
{
	int length, i, counter;

	length = paper[]+1;

	for(i=0; paper[i] <length; i++)
	{
		if(paper[i] == ' ')
		{
			counter++;
		}
	}
	
	return counter;
}

int paperDone(int min, float count)
{
	if(count >= min)
		return 1;
	else
		return 0;
}

void reward(int done, char paper[])
{
	int choice;

	if(done == 1)
	{
		printf("Congrats! You've met your word goal!\n");
		printf("If you'd like to keep writing, enter 1.\n");
		printf("If you'd like to take a study break, enter 2.\n");
		scanf("%d", &choice);
		
		if(choice == 1)
		{
			write(paper);
		}
		else if(choice == 2)
		{
			game();
		}
	}
}

/*void game(void)
{
	
}*/
