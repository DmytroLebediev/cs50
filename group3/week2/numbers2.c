#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("Enter number:\t");
    int number = get_int();
    
    int length = 0;
    int copy_number = number;
    if (number == 0)
    {
        length = 1;
    }
    else
    {
        while (copy_number != 0)
        {
            length++;
            copy_number /= 10;
        }
    }
    
    int digits[length];
    copy_number = number;
    for (int i = length - 1; i > -1; i--)
    {
        digits[i] = copy_number % 10;
        copy_number /= 10;
    }
    
    for (int i = 0; i < length; i++)
    {
        printf("%d", digits[i]);
    }
    printf("\n");
}