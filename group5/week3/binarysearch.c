#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool is_valid_number(const string string_with_digits);

void print_array(int length, const int numbers[]);

void bubble_sort(int length, int numbers[]);

bool search(int number, int length, const int numbers[]);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("usage: ./sort0 number [number] ...\n");
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
            printf("wrong input: [%d] = %s\n", j, argv[j]);
            return 2;
        }
    }

    print_array(length, numbers);
    bubble_sort(length, numbers);
    print_array(length, numbers);

    printf("what number are you looking for?\n");
    int number = get_int();
    printf(search(number, length, numbers)
        ? "found\n" : "not found\n");

    return 0;
}

bool is_valid_number(const string number)
{
    for (int i = 0, len = strlen(number); i < len; i++)
        if (!isdigit(number[i]))
            return false;
    return true;
}

void print_array(int length, const int numbers[])
{
    for (int i = 0; i < length; i++)
        printf("%d ", numbers[i]);
    printf("\n");
}

void bubble_sort(int length, int numbers[])
{
    bool exchanges;
    do
    {
        exchanges = false;
        for (int i = 0; i < length - 1; i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                numbers[i] = numbers[i] ^ numbers[i + 1];
                numbers[i + 1] = numbers[i] ^ numbers[i + 1];
                numbers[i] = numbers[i] ^ numbers[i + 1];

                exchanges = true;
            }
        }
    } while (exchanges);
}

bool bin_search(int left, int right, int number, const int numbers[])
{
    if (right - left == 1)
        return numbers[left] == number;

    int middle = (left + right) / 2;
    if (number < numbers[middle])
        return bin_search(left, middle, number, numbers);
    else
        return bin_search(middle, right, number, numbers);
}

bool search(int number, int length, const int numbers[])
{
    return bin_search(0, length, number, numbers);
}