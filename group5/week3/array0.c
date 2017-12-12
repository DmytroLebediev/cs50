#include <stdio.h>
#include <cs50.h>

int main()
{
    int array2d[10][5];

    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            array2d[row][column] = row * 5 + column;
        }
    }

    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            printf("%d ", array2d[row][column]);
        }
        printf("\n");
    }
}