#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    int number[argc-1];
    for(int i=1; i<argc; i++)
    {
        number[i-1]=atoi(argv[i]);
    }
    int count = 0;
    do
    {
        count = 0;
        for (int i = 1; i<argc-1; i++)
        {
            if (number[i]<number[i-1])
            {
                int var=number[i];
                number[i]=number[i-1];
                number[i-1]=var;
                count++;
            }
        }
        for (int i=0; i<argc-1; i++)
        {
            printf("%i ",number[i]);
        }
        printf("    %i\n", count);
    }
    while (count != 0);
}
