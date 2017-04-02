#include <stdio.h>
#include <stdlib.h>

void print_array(const int* values, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("value: %i\n", values[i]);
    }
}

int main()
{
    int *pointer = NULL;
    
    pointer = malloc(100 * sizeof(int));
    if (pointer == NULL)
    {
        return 1;
    }
    print_array(pointer, 100);
    free(pointer);
}