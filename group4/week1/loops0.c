#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("enter number greater than 10 or less than 0\n");
    
    int number;
    
    do
    {
        number = get_int();
    } while (number <= 10 && number >= 0);
    
    printf("correct number\n");
    
    return 0;
}