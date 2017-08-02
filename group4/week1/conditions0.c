#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("enter number greater than 10 or less than 0\n");
    int number = get_int();
    
    if (number > 10 || number < 0)
    {
        printf("number is correct\n");
    }
    else
    {
        printf("wrong number!\n");
        return 10;
    }
    
    return 0;
}