#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    printf("Enter number\t");
    float a = GetFloat();
    printf("Enter power\t");
    float b = GetFloat();
    
    printf("%f", pow(a, b));
    
    return 0;
}