#include <stdio.h>
#include <cs50.h>
#include <math.h>

unsigned long sumDigits(long long number)
{
    unsigned long sum = 0;
    while (number != 0)
    {
        int digit = number % 10;
        sum += digit;
        number /= 10;
    }
    return sum;
}

int main()
{
    // get input from user and save it to variable
    printf("Enter some number\n");
    long long input = GetLongLong();
    
    unsigned long sum = sumDigits(input);
    
    // display result
    printf("Sum is %lu\n", sum);
    
    return 0;
}