#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main()
{
    // get input from user and save it to variable
    printf("Enter some text\n");
    string text = GetString();
    
    // get length of users input
    unsigned long length = strlen(text);
    
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