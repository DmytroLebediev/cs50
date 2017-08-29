#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

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
    
    long factor = 1;
    while (number > 0)
    {
        factor *= number;
        number--;
    }
    
    printf("%li\n", factor);
    return 0;
}