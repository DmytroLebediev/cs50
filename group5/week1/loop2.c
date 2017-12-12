#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("Enter number greater than 100 or less than -100:\t");
    int number = get_int();

    for (int i = 2; -100 <= number && number <= 100; i++)
    {
        printf("Retry #%d:\t", i);
        number = get_int();
    }

    printf("number is %d\n", number);

    return 0;
}