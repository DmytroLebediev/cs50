#include <stdio.h>
#include <cs50.h>

unsigned int number_of_digits(int number);
void print_array(const int array[], unsigned int length, const string separator);

int main()
{
    printf("Enter number:\t");
    int number = get_int();
    
    unsigned int length = number_of_digits(number);
    
    int digits[length];
    int copy_number = number;
    for (int i = length - 1; i > -1; i--)
    {
        digits[i] = copy_number % 10;
        copy_number /= 10;
    }
    
    print_array(digits, length, " ");
    print_array(digits, length, " ");
}

unsigned int number_of_digits(int number)
{
    unsigned int result = 0;
    if (number == 0)
    {
        result = 1;
    }
    else
    {
        while (number != 0)
        {
            result++;
            number /= 10;
        }
    }
    return result;
}

void print_array(const int array[],
    unsigned int length,
    const string separator)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d%s", array[i], separator);
    }
    printf("\n");
}