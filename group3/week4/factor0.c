#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ulong;
typedef unsigned int uint;
typedef char* string;

ulong factor(uint value);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./factor0 number\n");
        return 1;
    }
    int argument = atoi(argv[1]);
    if (argument < 0)
    {
        printf("enter positive numbers only\n");
        return 2;
    }
    
    ulong result = factor(argument);
    printf("result:\t%lu\n", result);
}

ulong factor(uint value)
{
    ulong result = 1;
    
    while (value > 0)
    {
        result *= value;
        value--;
    }
    return result;
}