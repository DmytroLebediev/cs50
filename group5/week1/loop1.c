#include <stdio.h>
#include <cs50.h>

int main()
{
    int number = 0;
    do
    {
        printf("Enter number greater than 100 or less than -100:\t");
        number = get_int();
    } while(-100 <= number && number <= 100);

    printf("number is %d\n", number);

    return 0;
}