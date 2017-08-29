#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

void sort(int length, int numbers[]);
bool search(int number, int length, int numbers[]);
bool binary_search(int left, int right, int number, int numbers[]);

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

    sort(length, numbers);
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


bool search(int number, int length, int numbers[])
{
    return binary_search(0, length, number, numbers);
}

bool binary_search(int left, int right, int number, int numbers[])
{
    if (right - left == 1)
    {
        return numbers[left] == number;
    }

    //left + (right - left) / 2
    //(2 * left + right - left) / 2

    int middle = (left + right) / 2;
    if (numbers[middle] == number)
    {
        return true;
    }
    else if (number > numbers[middle])
    {
        return binary_search(middle, right, number, numbers);
    }
    else
    {
        return binary_search(left, middle, number, numbers);
    }
}

void sort(int length, int numbers[])
{
    bool changes;

    do
    {
        changes = false;
        for (int i = 0; i < length - 1; i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                int temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;

                changes = true;
            }
        }
    } while(changes);
}