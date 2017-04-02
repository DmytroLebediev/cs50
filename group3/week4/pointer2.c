#include <stdio.h>
#include <stdlib.h>

void print_numbers(int a, int b, int * pointer_a, int * pointer_b);

int main()
{
    int * a = NULL;
    int b = 0;
    
    a = malloc(1 * sizeof(int));
    *a = 29;
    b = 33;
    
    print_numbers(
        *a,      // pass value of a
        b,      // pass b itself
        a,   // pass a itself
        &b    // pass address of b
    );
}

void print_numbers(int a, int b, int * pointer_a, int * pointer_b)
{
    // print a and b
    printf("a = %i, b = %i\n", a, b);
    // print address of a and address of b
    printf("&a = %p, &b = %p\n", &a, &b);
    // print pointer_a and pointer_b
    printf("pointer_a = %p, pointer_b = %p\n", pointer_a, pointer_b);
    // print value from pointer_a and value from pointer_b
    printf("*pointer_a = %i, *pointer_b = %i\n", *pointer_a, *pointer_b);
}