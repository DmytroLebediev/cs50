#include <stdio.h>
#include <stdlib.h>

void print_numbers(int a, int b, int * pointer_a, int * pointer_b);

int main()
{
    int * a = NULL, b = 0;

    a = malloc(1 * sizeof(int));
    *a = 29;
    b = 33;

    print_numbers(
        *a,      // pass value of a
        b,      // pass b itself
        a,   // pass a itself
        &b    // pass address of b
    );

    free(a);
}

void print_numbers(int a, int b, int * pointer_a, int * pointer_b)
{
    // print a and b
    printf("a:\t%d\n", a);
    printf("b:\t%d\n", b);
    // print address of a and address of b
    printf("&a:\t%p\n", &a);
    printf("&b:\t%p\n", &b);
    // print pointer_a and pointer_b
    printf("pointer_a:\t%p\n", pointer_a);
    printf("pointer_b:\t%p\n", pointer_b);
    // print value from pointer_a and value from pointer_b
    printf("*pointer_a:\t%d\n", *pointer_a);
    printf("*pointer_b:\t%d\n", *pointer_b);
}