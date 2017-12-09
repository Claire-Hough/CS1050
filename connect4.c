//cnhfg6
//Claire Hough
//CS1050 HW2

#include <stdio.h>

char getCounter(void);
char game(char, char);
void printBoard(void);
int turn(char, int);
int victory(char, int);

char board[6][7] = 	{{'-', '-', '-', '-', '-', '-', '-'},
			 {'-', '-', '-', '-', '-', '-', '-'},
			 {'-', '-', '-', '-', '-', '-', '-'},
			 {'-', '-', '-', '-', '-', '-', '-'},
			 {'-', '-', '-', '-', '-', '-', '-'},
			 {'-', '-', '-', '-', '-', '-', '-'}};

int main(void)
{
	char p1 = ' ', p2 = ' ', winner = ' ';
	
	printf("Player 1, ");
	p1 = getCounter();
	printf("Player 2, ");
	p2 = getCounter();

	while(p2 == p1)
	{
		printf("Same letter as Player 1! Enter a different letter.\n");
		printf("Player 2, ");
		p2 = getCounter();
	}
		
	winner = game(p1, p2);
	printf("Player %c won!\n", winner);

	return 0;
}

char getCounter(void)
{
	char counter='A';

	printf("enter your letter (A-Z)\n");
	scanf("%c", &counter);
	getchar();

	while(counter < 'A' || counter > 'Z')
	{
		printf("Invaild entry. Enter an uppercase letter A-Z.\n");
		scanf("%c", &counter);
	}

	return counter;
}

char game(char p1, char p2)
{
	int column, win, numberOfSpaces = 42;

	while(1)
	{
		printf("Player %c, enter a column to drop into.\n", p1);
		scanf("%d", &column);
	
		if(column > 6 || column < 0)
		{
			printf("Invalid column! Enter a column between 0-6\n");
			scanf("%d", &column);
		}
		if(board[0][column] != '-')
		{
			printf("Column full! Enter a new column.\n");
			scanf("%d", &column);
		}
		win = turn(p1, column);
		numberOfSpaces--;
		printBoard();
		if(win == 1 || numberOfSpaces == 0)
		{
			return p1;
		}

		printf("Player %c, enter a column to drop into.\n", p2);
		scanf("%d", &column);

		if(column > 6 || column < 0)
		{
			printf("Invalid column! Enter a column between 0-6\n");
			scanf("%d", &column);
		}
		if(board[0][column] != '-')
		{
			printf("Column full! Enter a new column.\n");
			scanf("%d", &column);
		}
		win = turn(p2, column);
		numberOfSpaces--;
		printBoard();
		if(win == 1 || numberOfSpaces == 0)
		{
			return p2;
		}
	}
}

void printBoard(void)
{
	int i, j;

	for(i=0; i < 6; i++)
	{
		for(j=0; j < 7; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

int turn(char p, int column)
{
	int i;

	for(i=5; i>=0; i--)			
	{
		if(board[i][column] == '-')
		{
			board[i][column] = p;
			break;	
		}
	}

	return victory(p, column);
}

int victory(char p, int column)
{
	int i, j, counter=0;

	for(i=5;i>=0; i--)			//horizontal
	{
		for(j=0; j < 7; j++)
		{
			if(board[i][j] == p)
			{
				counter++;
				if(counter==4)
				{
					return 1;
				}
			}
			else
			{
				counter=0;
			}
		}
	}

	counter=0;
	for(i=5; i>=0; i--)			//veritcal
	{
		if(board[i][column] == p)
		{
			counter++;
			if(counter==4)
			{
				return 1;
			}
		}
		else
		{
			counter=0;
		}
	}

	return 0;
}
