#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int min(int a, int b);
int max(int a, int b);

int main()
{
    int *a = NULL, *b = NULL, c = 0;

    a = malloc(1 * sizeof(int));
    b = malloc(1 * sizeof(int));
    if (a == NULL
        || b == NULL)
    {
        return 1;
    }

    *a = 10;
    *b = get_int();
    c = get_int();

    printf("max(%i, %i) = %i\n", *a, *b, max(*a, *b));
    printf("min(%i, %i) = %i\n", *b, c, min(*b, c));

    free(a);
    free(b);

    return 0;
}

int min(int a, int b)
{
    return a > b ? b : a;
}

int max(int a, int b)
{
    return a > b ? a : b;
}