#include <stdio.h>
#include <stdlib.h>


int main()
{
    int **pointer = NULL;
    
    pointer = calloc(10, sizeof(int*));
    if (pointer == NULL)
    {
        return 1;
    }
    
    for (int i = 0; i < 10; i++)
    {
        pointer[i] = calloc((i + 1), sizeof(int));
        for (int j = 0; j < i + 1; j++)
        {
            pointer[i][j] = j + i;
        }
    }
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("%i\t", pointer[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    for (int i = 0; i < 10; i++)
    {
        free(pointer[i]);
        pointer[i] = NULL;
    }
    free(pointer);
    pointer = NULL;
    
    return 0;
}