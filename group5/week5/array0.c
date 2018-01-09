#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

typedef struct
{
    uint length;
    int* array;
} int_array;

void print_array(int_array numbers);

int_array read_numbers(FILE* file);

void remove_array(int_array* numbers);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: ./array0 <valid file path>\n");
        return 1;
    }
    if (argv[1] == NULL)
    {
        printf("can not process empty file name\n");
        return 2;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("can not open file %s\n", argv[1]);
        return 2;
    }

    int_array numbers = read_numbers(file);
    print_array(numbers);

    remove_array(&numbers);
    fclose(file);

    return 0;
}

void print_array(int_array numbers)
{
    for (int i = 0; i < numbers.length; i++)
    {
        printf("%d ", numbers.array[i]);
    }
    printf("\n");
}

int_array read_numbers(FILE* file)
{
    int_array numbers = { .length = 0, .array = NULL };
    if (file == NULL)
    {
        return numbers;
    }

    fscanf(file, "%d", &numbers.length);

    numbers.array = malloc(numbers.length * sizeof(int));
    if (numbers.array == NULL)
    {
        return numbers;
    }

    int *i = numbers.array;
    while (!feof(file))
    {
        fscanf(file, "%d", i);
        i++;
    }

    return numbers;
}

void remove_array(int_array* numbers)
{
    if (numbers == NULL)
    {
        return;
    }

    free(numbers->array);
    numbers->array = NULL;
    numbers->length = 0;
}