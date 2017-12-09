#include <stdio.h>
int y=3;

int main(void)
{
	y=2;
	printf("%d", y);
	{
		y=1;
		printf("%d", y);
	}
	printf("%d", y);

	printf("%d", y);

return 0;
}
