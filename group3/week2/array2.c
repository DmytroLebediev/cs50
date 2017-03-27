#include <stdio.h>
#include <cs50.h>

void print_array(int length, const int numbers[]);
int sum(int length, const int numbers[]);

int main()
{
    printf("Enter length of array:\t");
    int length = get_int();
    
    int numbers[length];
    
    for (int i = 0; i < length; i++)
    {
        printf("add %dth element\t", i + 1);
        numbers[i] = get_int();
    }
    
    int summ = sum(length, numbers);
    printf("Sum: %d\n", summ);
    
    print_array(length, numbers);
}

void print_array(int len, const int numbers[])
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", numbers[i]);  
    }
}

int sum(int length, const int numbers[])
{
    int result = 0;
    for (int i = 0; i < length; i++)
    {
        result = result + numbers[i];
    }
    return result;
}