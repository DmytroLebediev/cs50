#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void print_array(int length, const int numbers[]);

void sort(int length, int numbers[]);

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
}

void print_array(int length, const int numbers[])
{
    // go through arv array
    for (int i = 0; i < length; i++)
    {
        // print each item on screen
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
                numbers[i] = numbers[i] ^ numbers[i-1];
                numbers[i - 1] = numbers[i] ^ numbers[i-1];
                numbers[i] = numbers[i] ^ numbers[i-1];
                
                swap = true;
            }
        }
    } while (swap);
}