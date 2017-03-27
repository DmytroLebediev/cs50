#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("Enter length of array:\t");
    int length = get_int();
    
    int iarray[length];
    char carray[length];
    double darray[length];
    
    for (int i = 0; i < length; i++)
    {
        printf(
            "%d)\tint:\t%d\n\tchar:\t%d/%c\n\tdouble:\t%f\n\tsum:\t%f\n",
            i + 1,      // 1st %d
            iarray[i],  // 2d %d
            carray[i],  // 3d %d
            carray[i],  // 4th %c
            darray[i],  // 5th %f
            iarray[i] + darray[i] + carray[i] // 6th %f
        );
    }
}