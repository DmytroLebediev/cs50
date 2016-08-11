#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main()
{
    // get input from user and save it to variable
    printf("Enter some text\n");
    long long input = GetLongLong();
    
    // get length of users input
    unsigned long length = 0;
    
    do
    {
        length++;
    } while ((input = input/10) != 0);
    
    // validate card length
    if (length != 16
        && length != 15
        && length != 13)
    {
        printf("Wrong length\n");
    }
    
    // display result
    printf("Input lenght %lu\n", length);
    
    return 0;
}