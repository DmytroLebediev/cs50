#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

long factor(int number);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./factor number\n");
        return 1;
    }
    
    int number = atoi(argv[1]);
    
    if (number < 0)
    {
        printf("can be calculated for positive integers\n");
        return 2;
    }
    
    printf("%li\n", factor(number));
    
    return 0;
}

long factor(int number)
{
    if (number < 2)
    {
        return 1;
    }
    
    return number * factor(number - 1);
}