#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

bool search(int number, int length, int nummbers[]);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("usage: ./search number <number> ...\n");
        return 1;
    }

    int length = argc - 1;
    int numbers[length];

    for (int i = 1; i < argc; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }

    printf("what number are you looking for?\n");
    int number = get_int();

    if (search(number, length, numbers))
    {
        printf("found!\n");
    }
    else
    {
        printf("not found :(\n");
    }

    return 0;
}

// 1. loop over array of numbers
//  1.1. if number we are looking for equals to item in an array
//      1.1.1 found
//  1.2. go to the next item in an array

bool search(int number, int length, int numbers[])
{
    bool result = false;
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] == number)
        {
            result = true;
            break;
        }
    }
    return result;
}