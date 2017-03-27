#include <stdio.h>
#include <cs50.h>
#include <math.h>

unsigned long summ_digits(long long number)
{
    unsigned long result = 0;
    return result;
}

int main()
{
    // get input from user and save it to variable
    printf("Enter some number\n");
    long long input = get_long_long();
    
    unsigned long sum = 0;
    
    while (input != 0)
    {
        sum += input % 10;
        input /= 10;
    }
    
    // display result
    printf("Sum is %lu\n", sum);
}