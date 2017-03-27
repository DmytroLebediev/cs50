#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

unsigned long factorial(unsigned int value);

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
    unsigned long result = factorial(value);
    printf("Result: %lu\n", result);
}

unsigned long factorial(unsigned int value)
{
    unsigned long result = 1;
    while(value > 1)
    {
        result *= value;
        value--;
    }
    return result;
}