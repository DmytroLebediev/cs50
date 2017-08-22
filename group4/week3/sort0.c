#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

void sort(int length, int numbers[]);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("usage: ./sort0 number [number] ...\n");
        return 1;
    }
    
    int length = argc - 1;
    int numbers[length];
    
    for (int i = 1; i < argc; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }
    
    sort(length, numbers);
    
    for (int i = 0; i < length; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

// bubble sort
void sort(int length, int numbers[])
{
    bool changes;
    
    do
    {
        changes = false;
        for (int i = 0; i < length - 1; i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                int temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
                
                changes = true;
            }
        }
    } while(changes);
}