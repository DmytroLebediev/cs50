#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <limits.h>

/*
0|1|1  1
3|7|0  7

#
#######

*/

int find_max(int length, const int numbers[]);

void print_sharps(int length);


int main(int argc, string argv[])
{
    if (argc != 3)
    {
        printf("usage: ./arrays0 rows columns\n");
        return 1;
    }
    
    int rows = atoi(argv[1]);
    int columns = atoi(argv[2]);
    
    int array2D[rows][columns];
    
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("enter [%i,%i]:\t", row, column);
            array2D[row][column] = get_int();
        }
    }
    
    for (int row = 0; row < rows; row++)
    {
        int max = find_max(columns, array2D[row]);
        print_sharps(max);
    }
}

int find_max(int length, const int numbers[])
{
    int max = INT_MIN;
	for (int i = 0; i < length; i++)
	{
	    if (numbers[i] > max)
	    {
	        max = numbers[i];
	    }
	}
	return max;
}

void print_sharps(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("#");
    }
    printf("\n");
}