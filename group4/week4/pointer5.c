#include <stdio.h>
#include <stdlib.h>

int main()
{
    int length = 10;
    int *a = malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        a[i] = 10 - i;
        *(a + i) = 10 - i;
    }

    for (int i = 0; i < length; i++)
    {
        printf("%p (%d): %d\n", a + i, i, a[i]);
    }

    free(a);
    return 0;
}