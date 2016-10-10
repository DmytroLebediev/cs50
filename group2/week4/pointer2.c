#include <stdio.h>

int main()
{
    int array[10][5];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            array[i][j] = i * 10 + j;
            
            printf("%p ", &array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("2D array\t\t%p address\n", array);
    printf("1D array\t\t%p address\n", *array); //&array[0][0]
    printf("sizeof 2D pointer\t%lu bytes\n", sizeof(array));
    printf("sizeof 1D pointer\t%lu bytes\n", sizeof(*array)); // array[0]
    
    printf("\n");
    // item ~ int*
    // array ~ int**
    
    for (int i = 0, *item = (int*)array; i < 10 * 5; i++)
    {
        printf("%p\t%i\n", (item + i), *(item + i));
    }
    
    int** array = NULL;
    array = malloc(5 * sizeof(int*));
    for (int i = 0; i < 5; i++)
    {
        array[i] = malloc((i + 1) * sizeof(int));
    }
}