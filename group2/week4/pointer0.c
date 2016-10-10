#include <stdio.h>

void swap(int* a, int* b);

int main(int argc, char** argv)
{
    int a = 10;
    int b = 20;
    swap(&a, &b);
    
    printf("main:\ta=%i\nb=%i\n", a, b);
    
    printf("sizeof int\t%lu\n", sizeof(int));
    printf("sizeof int*\t%lu\n", sizeof(int*));
    printf("sizeof char\t%lu\n", sizeof(char));
    printf("sizeof char*\t%lu\n", sizeof(char*));
    printf("sizeof double\t%lu\n", sizeof(double));
    printf("sizeof double*\t%lu\n", sizeof(double*));
    printf("sizeof void*\t%lu\n", sizeof(void*));
}

void swap(int* a, int* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
    printf("swap:\ta=%i\nb=%i\n", *a, *b);
}