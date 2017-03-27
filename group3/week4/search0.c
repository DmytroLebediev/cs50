#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void sort(int length, int numbers[]);
void print_array(int length, const int numbers[]);
bool search(int value, int length, const int numbers[]);
bool binary_search(int value, int left, int right, const int numbers[]);

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
    
    printf("What number do you want to find?\t");
    int number = get_int();
    if (search(number, count - 1, numbers))
    {
        printf("Found!\n");
    }
    else
    {
        printf("404. Not Found!\n");
    }
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
                int temp = numbers[i];
                numbers[i] = numbers[i - 1];
                numbers[i - 1] = temp;
                
                swap = true;
            }
        }
    } while (swap);
}


bool search(int value, int length, const int numbers[])
{
    return binary_search(value, 0, length, numbers);
}

bool binary_search(int value, int left, int right, const int numbers[])
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
        return binary_search(value, middle, right, numbers);
    }
    else
    {
        return binary_search(value, left, middle, numbers);
    }
}