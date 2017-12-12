#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool validate_number(string number);
long to_long(string number);

int main()
{
    string number = get_string();
    if (validate_number(number))
    {
        long var = to_long(number);
        printf("%s -> %li \n", number, var);
    }
    else
    {
        printf("invalid number was entered!\n");
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

long to_long(string number)
{
    long result = 0;
    for (int i = 0, len = strlen(number);
        i < len;
        i++)
    {
        unsigned char digit = number[i] - '0';
        result = result * 10 + digit;
    }
    return result;
}