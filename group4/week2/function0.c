#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool is_correct_number(const string string_with_digits);

int main()
{
    string number = get_string();
    if (!is_correct_number(number))
    {
        printf("You've entered incorrect number\n");
        return 1;
    }
    
    int length = strlen(number);
    printf("number length is %d\n", length);
    
    return 0;
}

bool is_correct_number(const string string_with_digits)
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