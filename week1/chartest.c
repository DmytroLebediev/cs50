#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    printf("Enter symbol\t");
    char c1 = GetChar();
    
    printf("Enter another symbol\t");
    char c2 = GetChar();
    
    printf("%c, %d\n", c1 + c2, c1 + c2);
    
    return 0;
}