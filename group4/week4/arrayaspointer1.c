#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 10

int* array_func1(int start);
int* array_func2(int start);
void print(const int* array);

int main()
{
    int *array1 = NULL;
    int *array2 = NULL;
    int start1 = 1;
    int start2 = 5;

    array1 = array_func1(start1);
    array2 = array_func1(start2);
    print(array1);
    print(array2);

    array1 = array_func2(start1);
    array2 = array_func2(start2);
    print(array1);
    print(array2);

    free(array1);
    free(array2);

    return 0;
}

int* array_func1(int start)
{
    int array[DEFAULT_SIZE];
    for (int i = 0; i < DEFAULT_SIZE; i++)
    {
        array[i] = start + i;
    }
    return array;
}

int* array_func2(int start)
{
    int *array = malloc(DEFAULT_SIZE * sizeof(int));
    for (int i = 0; i < DEFAULT_SIZE; i++)
    {
        array[i] = start + i;
    }
    return array;
}

void print(const int* array)
{
    printf("array:\t%p\n", array);

    if (array == NULL)
        return;

    for (int i = 0; i < DEFAULT_SIZE; i++, array++)
    {
        printf("%d ", *array);
    }
    printf("\n");
    printf("\n");
}