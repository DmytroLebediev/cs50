#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

typedef unsigned int uint;

void print_array(uint length, int array[]);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("usage: ./array2 <number> [number] ...\n");
        return 1;
    }

    int length = argc - 1;
    int array[length];
    for (int i = 1; i < argc; i++)
    {
        array[i - 1] = atoi(argv[i]);
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