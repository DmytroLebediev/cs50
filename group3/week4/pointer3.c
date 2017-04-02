#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *pointer = NULL;
    
    pointer = malloc(10 * sizeof(int)); // *pointer == 0
    int array[10];
    if (pointer == NULL)
    {
        return 1;
    }
    
    for (int i = 0; i < 10; i++)
    {
        array[i] = i + 1;
    }
    for (int i = 0, *pint = pointer; i < 10; i++, pint++)
    {
        pointer[i] = i + 1;
        *pint = i + 1;
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("array[%i] = %i\n", i, array[i]);
        printf("pointer[%i] = %i\n", i, pointer[i]);
    }
    free(pointer);
    
    return 0;
}