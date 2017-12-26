#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int a = 10;
    int b = 20;

    printf("main() a: %i\tb: %i\n", a, b);
    swap(&a, &b);
    printf("main() a: %i\tb: %i\n", a, b);
}

void swap(int *a, int *b)
{
    printf("swap() a: %i\tb: %i\n", *a, *b);

    int c = *a;
    *a = *b;
    *b = c;

    printf("swap() a: %i\tb: %i\n", *a, *b);
}