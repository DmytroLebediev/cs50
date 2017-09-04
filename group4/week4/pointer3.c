#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int min(int a, int b);
int max(int a, int b);

int main()
{
    int *a = NULL, *b = NULL, c = 0;

    a = malloc(1 * sizeof(int)); // calloc
    b = malloc(1 * sizeof(int));
    if (a == NULL
        || b == NULL)
    {
        return 1;
    }

    // 1. set a = 10
    *a = 10;
    // 2. ask user to enter b
    *b = get_int();
    // 3. ask user to enter c
    c = get_int();

    // print max of a and b
    printf("max(a, b) = %d\n", max(*a, *b));
    // print min of b and c
    printf("min(c, b) = %d\n", min(c, *b));

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