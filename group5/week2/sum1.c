#include <stdio.h>
#include <cs50.h>
#include <math.h>

int summ(long number);

int main()
{
    printf("enter nummber:\t");
    long number = get_long();
    printf("sum of digits in %li is %d\n", number, summ(labs(number)));
}

int summ(long number)
{
    int result = 0;
    while (number)
    {
        result += number % 10;
        number /= 10;
    }
    return result;
}