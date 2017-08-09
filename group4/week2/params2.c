#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2
        || strlen(argv[1]) != 5)
    {
        printf("usage: ./params2 23:45\n");
        return 1;
    }
    
    string arg = argv[1];
    short hours = (arg[0] - '0') * 10 + (arg[1] - '0');
    
    if (hours > 12)
    {
        hours = hours % 12;
    }
    printf("%02hi:%c%c\n", hours, arg[3], arg[4]);
    
    return 0;
}