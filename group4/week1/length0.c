#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("enter positive integer\n");
    int number = get_int();
    
    int counter = 0;
    if (number == 0)
    {
        counter = 1;
    }
    while (number != 0)
    {
        number /= 10;// number = number / 10;
        counter++;
    }
    
    printf("number length is %d\n", counter);
    
    return 0;
}