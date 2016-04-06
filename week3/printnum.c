#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool isnumber(string number);
void printnum(int current, int max);

int main(int argc, string argv[]) 
{
    if (argc !=2)
    {
        return 1;
    }
    if (!isnumber(argv[1]))
    {
        return 1;
    }
    
    int k = atoi(argv[1]);
    printnum(0,k);
    printf("\n");
    return 0;
}

bool isnumber(string number)
{
    if (number==NULL)
    {
        return false;
    }
    for (int i=0; i<strlen(number); i++)
    {
        if (!isdigit(number[i]))
        {
            return false;
        }
    }
    return true;
}

void printnum(int current, int max)
{
    if (current == max)
    {
        return;
    }
    printf("%d ",current);
    printnum (current+1, max);
}