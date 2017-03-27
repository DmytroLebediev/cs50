#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void print_array(int length, const int numbers[]);

void sort(int length, int numbers[]);

bool search(int value, int lenght, int numbers[]);

bool binary_search(int left, int right, int value, int numbers[]);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("usage: ./params1 digit [digit] ... \n");
        return 1;
    }
    
    int numbers[argc - 1];
    
    // go through arv array
    for (int i = 1; i < argc; i++)
    {
        // convert each item in argv to number
        // store results in numbers array
        numbers[i - 1] = atoi(argv[i]);
    }
    print_array(argc - 1, numbers);
    
    printf("\nSorted array:\n");
    
    sort(argc - 1, numbers);
    print_array(argc - 1, numbers);
    
    printf("\nWhat number do you want to find?\n");
    int value = get_int();
    if (search(value, argc - 1, numbers))
    {
        printf("Found!\n");
    }
    else
    {
        printf("404. Not Found!\n");
    }
}

void print_array(int length, const int numbers[])
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", numbers[i]);  
    }
}

void sort(int length, int numbers[])
{
    bool swap = false;
    do
    {
        swap = false;
        for (int i = 1; i < length; i++)
        {
            if (numbers[i] < numbers[i-1])
            {
                int temp = numbers[i-1];
                numbers[i - 1] = numbers[i];
                numbers[i] = temp;
                
                swap = true;
            }
        }
    } while (swap);
}

bool search(int value, int lenght, int numbers[])
{
    return binary_search(0, lenght, value, numbers);
}

bool binary_search(int left, int right, int value, int numbers[])
{
    if (right - left == 1)
    {
        return numbers[left] == value;
    }
    
    int middle = (left + right) / 2;
    if (numbers[middle] == value)
    {
        return true;
    }
    
    if (value > numbers[middle])
    {
        return binary_search(middle, right, value, numbers);
    }
    return binary_search(left, middle, value, numbers);
}