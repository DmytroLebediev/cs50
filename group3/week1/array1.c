#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("Enter length of array:\t");
    int length = get_int();
    
    int numbers[length];
    
    for (int i = 0; i < length; i++)
    {
        printf("add %dth element\t", i + 1);
        numbers[i] = get_int();
    }
    
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum = sum + numbers[i];
    }
    
    printf("Sum: %d\n", sum);
    
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", numbers[i]);  
    }
}