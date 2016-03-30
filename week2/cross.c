#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MIN_INT -1000000

int main(int argc, string argv[])
{
    int max = MIN_INT;
	// find max number among argument
    for (int i = 1; i < argc; i++)
    {
        int k = atoi(argv[i]);
        if (k > max)
        {
			max = k;
        }
    }
	
	// determine what items should be painted
    bool cross[max][argc - 1];
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < argc-1; j++)
        {
            int k = atoi(argv[j+1]);
            cross[i][j] = i < k;
        }
    }
	
	// print everything on the screen
    for (int i = 0; i < max; i++)
    {
        printf("|");
        for (int j = 0; j < argc - 1; j++)
        {
            if (cross[i][j])
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