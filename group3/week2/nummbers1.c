#include <stdio.h>
#include <cs50.h>
#include <math.h>

unsigned long summ_digits(long long number);

int main()
{
    // get input from user and save it to variable
    printf("Enter some number\n");
    long long input = get_long_long();
    
    unsigned long sum = summ_digits(input);
    
    // display result
    printf("Original value is %lld\n", input);
    printf("Sum is %lu\n", sum);
}

unsigned long summ_digits(long long number)
{
    unsigned long result = 0;
    
    while (number != 0)
    {
        result += number % 10;
        number /= 10;
    }
    
    return result;
}