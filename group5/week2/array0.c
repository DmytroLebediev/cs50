#include <stdio.h>
#include <cs50.h>

typedef unsigned int uint;

void print_array(uint length, int array[]);

int main()
{
    printf("enter array length:\t");
    int length = get_int();
    int array[length];
    for (int i = 0; i < length; i++)
    {
        array[i] = get_int();
    }
    print_array(length, array);
}

void print_array(uint length, int array[])
{
    for (uint i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}