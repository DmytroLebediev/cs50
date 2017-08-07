#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool is_correct_number(string string_with_digits);
unsigned int summ_digits(const string number);

int main()
{
    string number = get_string();
    if (!is_correct_number(number))
    {
        printf("You've entered incorrect number\n");
        return 1;
    }
    
    unsigned int summ = summ_digits(number);
    printf("summ is %u\n", summ);
    
    return 0;
}

bool is_correct_number(string string_with_digits)
{
    bool is_correct = true;
    int len = strlen(string_with_digits);
    for (int i = 0; i < len; i++)
    {
        if (isdigit(string_with_digits[i]) == 0)
        {
            is_correct = false;
            break;
        }
    }
    return is_correct;
}

unsigned int summ_digits(const string number)
{
    unsigned int result = 0;
    
    int len = strlen(number);
    for (int i = 0; i < len; i++)
    {
        result += number[i] - '0';
    }
    return result;
}