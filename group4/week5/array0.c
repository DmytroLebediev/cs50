#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        return 3;
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

    int resized_length = 4;
    int *resizable_array = malloc(resized_length * sizeof(int));

    char buffer[256];
    while (fgets(buffer, 256, file) != NULL)
    {
        int number = atoi(buffer);

        if (numbers.length == resized_length)
        {
            resized_length *= 2;
            resizable_array = realloc(resizable_array,
                resized_length * sizeof(int));
            if (resizable_array == NULL)
            {
                exit(4);
            }
        }

        resizable_array[numbers.length] = number;
        numbers.length++;
    }

    numbers.array = malloc(numbers.length * sizeof(int));
    if (numbers.array == NULL)
    {
        exit(4);
    }
    memcpy(numbers.array, resizable_array, numbers.length * sizeof(int));

    free(resizable_array);

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