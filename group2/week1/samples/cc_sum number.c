#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    // get input from user and save it to variable
    printf("Enter some number\n");
    long long input = GetLongLong();
    
    unsigned long sum = 0;
    
    while (input != 0)
    {
        int digit = input % 10;
        sum += digit;
        input /= 10;
    }
    
    // display result
    printf("Sum is %lu\n", sum);
    
    return 0;
}