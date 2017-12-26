#include <stdio.h>
#include <stdlib.h>

void print_array(const int* values, int length)
{
    for (int i = 0; i < length; i++)
        printf("%p ~ %p: %i\n", &values[i] , values + i, values[i]);
}

int main()
{
    int *pointer = NULL;

    pointer = malloc(10 * sizeof(int));
    if (pointer == NULL)
    {
        return 1;
    }
    for (int i = 0; i < 10; i++)
    {
        pointer[i] = i + 1;
    }
    print_array(pointer, 10);
}