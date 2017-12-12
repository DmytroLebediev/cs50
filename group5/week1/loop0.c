#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("Enter number greater than 100 or less than -100:\t");
    int number = get_int();

    while (-100 <= number && number <= 100)
    {
        int i = 0;
        printf("You've enteredd wrong value. Try again:\t");
        number = get_int();
    }
    printf("Number is %d\n", number);
    return 0;
}