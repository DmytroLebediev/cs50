#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define COIN25 25
#define COIN10 10
#define COIN5 5
#define COIN1 1

int main()
{
    printf("Enter change\n");
    float change = GetFloat();
    
    while (change <= 0)
    {
        printf("Enter correct change\n");
        change = GetFloat(); 
    }
    
    int rchange = roundf(change * 100.0);
    int count = 0;
    while (rchange != 0 )
    {
        if (rchange >= COIN25)
        {
            rchange = rchange - COIN25;
        }
        else if (rchange >= COIN10)
        {
            rchange = rchange - COIN10;
        }
        else if (rchange >= COIN5)
        {
            rchange = rchange - COIN5;
        }
        else
        {
            rchange = rchange - COIN1;
        }
        count++;
    }
    
    printf("%d\n", count);
    return 0;
}