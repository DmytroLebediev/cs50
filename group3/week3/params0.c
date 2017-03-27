#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void sort(int length, int numbers[]);
void print_array(int length, const int numbers[]);

int main(int count, string params[])
{
    if (count == 1)
    {
        printf("usage: ./params0 digit [digit] ...\n");
        return 1;
    }
    
    int numbers[count - 1];
    for (int i = 1; i < count; i++)
    {
        numbers[i - 1] = atoi(params[i]);
    }
    print_array(count - 1, numbers);
    
    printf("\n");
    sort(count - 1, numbers);
    print_array(count - 1, numbers);
}

void print_array(int len, const int numbers[])
{
    for (int i = 0; i < len; i++)
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
            if (numbers[i] < numbers[i - 1])
            {
                numbers[i] = numbers[i] ^ numbers[i - 1];
                numbers[i - i] = numbers[i] ^ numbers[i - 1];
                numbers[i] = numbers[i] ^ numbers[i - 1];
                
                swap = true;
            }
        }
    } while (swap);
}