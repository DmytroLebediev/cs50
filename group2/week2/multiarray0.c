#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#define MIN_INT -2147483648

int main()
{
    int rows = GetInt();
    int columns = GetInt();
    
    bool field[rows][columns];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            field[i][j] = (i + j) % 3;
        }
    }
    
    
    for (int i = 0; i < rows; i++)
    {
        printf("|");
        for (int j = 0; j < columns; j++)
        {
            if (field[i][j])
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("\n");
}