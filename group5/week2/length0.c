#include <stdio.h>
#include <cs50.h>

int number_of_digits(long variable);

int main()
{
    printf("enter positive number:\t");
    long number = get_long();

    printf("%li contains %d digits\n",
        number,
        number_of_digits(number));
    printf("%li\n", number);
}

int number_of_digits(long variable)
{
    if (variable == 0)
    {
        return 1;
    }
    int counter = 0;
    while (variable != 0)
    {
        counter++;
        variable /= 10;
    }
    return counter;
}