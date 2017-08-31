#include <stdio.h>

typedef int* pint;

typedef char* string;// '\0'

void swap(int* a, int* b);

int main()
{
    int a = 10;
    int b = 20;

    printf("a: %p\n", &a);
    printf("b: %p\n", &b);

    swap(&a, &b);

    printf("\na: %p\n", &a);
    printf("b: %p\n", &b);
    printf("\na: %i\n", a);
    printf("b: %i\n", b);
}

void swap(int* a, int* b)
{
    if (a == NULL
        || b == NULL)
    {
       return;
    }
    int c = *a;
    *a = *b;
    *b = c;

    printf("\na: %p\n", a);
    printf("b: %p\n", b);
}