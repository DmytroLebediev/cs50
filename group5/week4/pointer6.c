#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

void print_array(int row, const int columns[], int **array2D);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./pointer6 number\n");
        return 1;
    }

    int rows = atoi(argv[1]);

    int **array2D = calloc(rows, sizeof(int*));
    if (array2D == NULL)
    {
        return 2;
    }

    int columns[rows];
    for (int row = 0; row < rows; row++)
    {
        printf("how many columns are there?\t");
        columns[row] = get_int();
        array2D[row] = malloc(columns[row] * sizeof(int));
        for (int column = 0; column < columns[row]; column++)
        {
            array2D[row][column] = get_int();
        }
    }

    print_array(rows, columns, array2D);

    for (int row = 0; row < rows; row++)
    {
        free(array2D[row]);
    }

    free(array2D);
}


void print_array(int rows, const int columns[], int **array2D)
{
    if (array2D == NULL)
    {
        return;
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns[row]; column++)
        {
            printf("%i ", array2D[row][column]);
        }
        printf("\n");
    }
}