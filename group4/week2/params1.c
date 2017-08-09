/**
 * Program finds the greatest number among provided positive integers.
 * Invalid input or lack of arguments at the start will stop program execution.
 **/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


/**
 * checks if provided string consists only of digits
 **/
bool is_correct_number(const string string_with_digits);


/**
 * returns max number among provided
 **/
unsigned int find_max(unsigned int length, const unsigned int numbers[]);



int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("usage: ./params1 number [number] ...\n");
        return 1;
    }
    
    int length = argc - 1;
    unsigned int numbers[length];
    
    for (int i = 1; i < argc; i++)
    {
        if (is_correct_number(argv[i]))
        {
            numbers[i - 1] = atoi(argv[i]);
        }
        else
        {
            printf("you've entered incorrect number [%d]: %s\n", i - 1, argv[i]);
            return 2;
        }
    }
    
    printf("%u\n", find_max(length, numbers));
    
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



unsigned int find_max(unsigned int length, const unsigned int numbers[])
{
    unsigned int max = 0;
	for (int i = 0; i < length; i++)
	{
	    if (numbers[i] > max)
	    {
	        max = numbers[i];
	    }
	}
	return max;
}