#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("Enter height\t");
    int height = GetInt();
    
    for (int i = 0; i < height; i++)
    {
        int spaces = (height + 1) - (i + 2);
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        int hashes = i + 2;
        for (int j = 0; j < hashes; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    
    prinf("%.6f", 5.);
    
    return 0;
}
