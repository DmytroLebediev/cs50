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
        *a,  // pass value of a
        b,   // pass b itself
        a,   // pass a itself
        &b   // pass address of b
    );
}

void print_numbers(int a, int b, int * pointer_a, int * pointer_b)
{
    printf("a: %i\tb: %i\n", a, b);
    printf("&a: %p\t&b: %p\n", &a, &b);
    printf("p_a: %p\tp_b: %p\n", pointer_a, pointer_b);
    printf("*p_a: %i\t*p_b: %i\n", *pointer_a, *pointer_b);
    printf("&p_a: %p\t&p_b: %p\n", &pointer_a, &pointer_b);
}