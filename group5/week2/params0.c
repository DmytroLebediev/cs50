#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%i]:\t\"%s\"\n", i, argv[i]);
    }
    
    return 0;
}