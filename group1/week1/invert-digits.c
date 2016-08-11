#include <stdio.h>
#include<cs50.h>

int main()
{
    printf("Enter number\n");
    long long number = GetLongLong();
    
    while (number <= 0)
    {
        printf("Enter positive number\n");
        number = GetLongLong();
    }
    
    while (number != 0)
    {
        printf("%lld", number%10);
        number = number/10;
    }
    printf("\n");
    
}