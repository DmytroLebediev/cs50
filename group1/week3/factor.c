#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int factor(int number)
{
    if (number <= 1)
    {
        return 1;
    }
    return number * factor (number-1);
}

int main ()
{
    int number = GetInt();
    number = factor (number);
    printf("%i\n", number);
}
