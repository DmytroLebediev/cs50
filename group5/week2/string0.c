#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool validate_number(string number);

int main()
{
    string number = get_string();
    if (validate_number(number))
    {
        printf("valid number\n");
    }
    else
    {
        printf("invalid number\n");
    }
    return 0;
}

bool validate_number(string number)
{
    for (int i = 0, len = strlen(number);
        i < len;
        i++)
    {
        char symbol = number[i];
        if (!('0' <= symbol && symbol <= '9'))
        {
            return false;
        }
    }
    return true;
}