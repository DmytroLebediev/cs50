#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef unsigned long ulong;
typedef char* string;

ulong factorial(uint value);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./factor2 number\n");
        return 1;
    }
    int value = atoi(argv[1]);
    if (value < 0)
    {
        printf("enter positive numbers only!\n");
        return 2;
    }
    ulong result = factorial(value);
    printf("Result: %lu\n", result);
}

ulong factorial(uint value)
{
    if (value < 2)
    {
        return 1;
    }
    return value * factorial(value - 1);
}