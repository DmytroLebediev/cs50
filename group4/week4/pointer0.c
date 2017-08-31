#include <stdio.h>

void swap(int a, int b);

int main()
{
    int a = 10;
    int b = 20;

    printf("a: %i\n", a);
    printf("b: %i\n", b);

    swap(a, b);

    printf("\na: %i\n", a);
    printf("b: %i\n", b);
}

void swap(int a, int b)
{
    int c = a;
    a = b;
    b = c;

    printf("\na: %i\n", a);
    printf("b: %i\n", b);
}