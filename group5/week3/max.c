/**
 * Program finds the greatest number among provided positive integers.
 * Invalid input or lack of arguments at the start will stop program execution.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>


/**
 * checks if provided string consists only of digits
 **/
bool is_valid_number(const string string_with_digits);


/**
 * returns max number among provided
 **/
int find_max(unsigned int length, const int numbers[]);



int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("usage: ./max number [number] ...\n");
        return 1;
    }

    int length = argc - 1;
    int numbers[length];

    for (int i = 0, j = 1; i < length; i++, j++)
    {
        if (is_valid_number(argv[j]))
        {
            int number = atoi(argv[j]);
            numbers[i] = number;
        }
        else
        {
            printf("wrong input: [%d] = %s\n",
                j,
                argv[j]);
            return 2;
        }
    }
    printf("%d\n", find_max(length, numbers));

    return 0;
}

bool is_valid_number(const string number)
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

int find_max(unsigned int length, const int numbers[])
{
    int max = -1;
    for (int i = 0; i < length; i++)
    {
        if (max < numbers[i])
        {
            max = numbers[i];
        }
    }
    return max;
}