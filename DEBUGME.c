// Jacob Zimmer
// jlz6w7
// 29 October 2017

#define Length 1 

#include <stdio.h>
#include <stdlib.h>

char* copyString(char*, int*);

int main(void)
{
    int *length = malloc(sizeof(int));    
    printf("Enter a size to allocate memory for the string: ");
    scanf("%d", length);

    char *data = malloc(sizeof(char) * (*length));
    printf("Enter a string: ");
    scanf("%s", data);

    char *copy = copyString(data, length);

    printf("Copy of original string: %s\n", copy);
    printf("Original string: %s\n\n", data);
   
    free(data);
    free(length);
    return 0;
}

char* copyString(char *data, int *length)
{
    char *copy = malloc(sizeof(char) * (*length));
    int i;
    for (i = 0; i < *length; i++)
    {
        *(copy + i) = *(data + i);
    }
    *(copy + i) = '\0';

    return copy;
}
