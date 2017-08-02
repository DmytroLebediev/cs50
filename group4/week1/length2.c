#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{
    string number = get_string();
    
    int length = strlen(number);
    printf("number length is %d\n", length);
    
    return 0;
}