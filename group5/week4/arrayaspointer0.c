#include <stdio.h>
#include <stdlib.h>

void array_func1(int array[]);
void array_func2(int *array);

int main()
{
    int array[10] = { 0,1,2,3,4,5,6,7,8,9 };

    array_func1(array);
    array_func2(array);

    printf("array as-is:\t\t%p\n", array);
    printf("its size:\t\t%lu\n", sizeof(array));
    printf("next item:\t\t%p\n", array + 1);
    printf("\n");

    return 0;
}

void array_func1(int array[])
{
    printf("array as-is:\t\t%p\n", array);
    printf("its size:\t\t%lu\n", sizeof(array));
    printf("next item:\t\t%p\n", array + 1);
    printf("\n");
}

void array_func2(int *array)
{
    printf("pointer to array:\t%p\n", array);
    printf("its size:\t\t%lu\n", sizeof(array));
    printf("next item:\t\t%p\n", array + 1);
    printf("\n");
}