#include <stdio.h>
#include <stdlib.h>

typedef int* intptr;

int main()
{
    intptr a = NULL, b = NULL;
    int *a1 = NULL, *b1 = NULL;
    
    printf("a:\t%p\nb:\t%p\n", a, b);
    printf("a1:\t%p\nb1:\t%p\n", a1, b1);
}