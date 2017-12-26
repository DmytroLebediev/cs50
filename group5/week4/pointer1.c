#include <stdlib.h>
#include <stdio.h>

void print_pointers(const int *p);

int main()
{
    int *a = NULL;
    int b = 10;

    //printf("a: %i\tb: %i\n", *a, b); <- bad idea

    a = &b;

    printf("a: %i\tb: %i\n", *a, b);

    b *= 5;

    printf("a: %i\tb: %i\n", *a, b);

    *a *= 5;

    printf("a: %i\tb: %i\n", *a, b);

    int array[10];
    array[0] = 100;

    print_pointers(a);
    print_pointers(&b);
    print_pointers(array);
    printf("array[0]: %i\n", array[0]);

    int *c = NULL;
    c = malloc(10 * sizeof(int));
    if (c == NULL) return 1;
    c[0] = 20;
    c[5] = 40;
    *(c + 6) = 50;
    c[9] = 200;
    print_pointers(c + 5);

    for (int *i = c, step = 0;
        step < 10;
        i++, step++)
    {
        print_pointers(i);
    }

    int *i = c + 1;
    free(i);
    free(c);
    c = NULL;
}

typedef char* string;

void print_pointers(const int *p)
{
    if (p == NULL)
    {
        return;
    }

    printf("pint: %p\n", p);
    printf("int: %i\n", *p);
}