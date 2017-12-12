#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <cs50.h>
#include <string.h>

bool is_valid_number(const string string_with_digits);

int find_max(unsigned int length, const int numbers[]);

void print_sharps(int amount);

int main(int argc, string argv[])
{
    if (argc != 3)
    {
        printf("usage: ./arrays1 number number\n");
        return 1;
    }
    if (!is_valid_number(argv[1])
        || !is_valid_number(argv[2]))
    {
        printf("parameters should be positive integers\n");
        return 2;
    }

    int rows = atoi(argv[1]);
    int columns = atoi(argv[2]);

    int array2D[rows][columns];

    /*
    0|1|1  1
    3|7|0  7

    #
    #######

    */

    // 3. ask user to enter each number in the array
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            array2D[row][column] = get_int();
        }
    }

    for (int row = 0; row < rows; row++)
        print_sharps(find_max(columns, array2D[row]));
    // 4. find max value for each row
    // 5. print number of '#' in a row equal to max value found in p.4


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
    int max = length > 0 ? numbers[0] : INT_MIN;
    for (int i = 1; i < length; i++)
    {
        if (max < numbers[i])
        {
            max = numbers[i];
        }
    }
    return max;
}

void print_sharps(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        printf("#");
    }
    printf("\n");
}