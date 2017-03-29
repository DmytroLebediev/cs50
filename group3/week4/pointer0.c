#include <stdio.h>
#include <cs50.h>

void swap(int a, int b);
void swap2(int* a, int* b);

int main()
{
    int x = 10;
    int y = 20;
    
    printf("x: %p, y: %p\n", &x, &y);
    swap(x, y);
    swap2(&x, &y);
    
    int* x1;
    
    printf("x: %i, y: %i\n", x, y);
}

void swap(int a, int b)
{
    printf("a: %p, b: %p\n", &a, &b);
    int temp = a;
    a = b;
    b = temp;
    printf("a: %p, b: %p\n", &a, &b);
}

void swap2(int* a, int* b)
{
    if (a == NULL
        || b == NULL)
    {
        return;
    }
    
    int temp = *a;
    *a = *b;
    *b = temp;
}