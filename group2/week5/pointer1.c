#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initArray(int* array, int* length);
void printArray(int* array, int length);

int main()
{
    int length = 0;
    
    malloc(10);
    calloc(length * sizeof(char));
    int length = 32;
    length *= 2;
    array = realloc(array, 20 * sizeof(int))
    
    int* array = NULL;
    
    printf("Before init:\n");
    printf("address length: %p\n", &length);
    printf("array: %p\n", array);
    printf("address array: %p\n", &array);
    printf("\n");
    
    initArray(array, &length);
    
    printf("After init:\n");
    printf("address length: %p\n", &length);
    printf("array: %p\n", array);
    printf("address array: %p\n", &array);
    printf("\n");
    
    printf("length\t%i\n", length);
    printArray(array, length);
}

void initArray(int* array, int* length)
{
    printf("In init:\n");
    printf("length: %p\n", length);
    printf("address length: %p\n", &length);
    printf("array: %p\n", array);
    printf("address array: %p\n", &array);
    printf("\n");
    
    array = malloc(10 * sizeof(int));
    *length = 10;
    for (int i=0; i<10; i++)
    {
        array[i] = i+1;
    }
    
    printf("In init:\n");
    printf("length: %p\n", length);
    printf("address length: %p\n", &length);
    printf("array: %p\n", array);
    printf("address array: %p\n", &array);
    printf("value in array: %i\n", *array);
    printf("\n");
    printArray(array, (*length));
}

void printArray(int* array, int length)
{
    for (int i=0; i<length; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}