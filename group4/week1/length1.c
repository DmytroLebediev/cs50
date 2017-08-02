#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("enter positive integer\n");
    int number = get_int();
    
    int counter;
    
    if (number == 0)
    {
        counter = 1;
    }
    else
    {
        for (counter = 0; number != 0; counter++)
        {
            number /= 10;
        }
    }
    
    printf("number length is %d\n", counter);
    
    return 0;
}