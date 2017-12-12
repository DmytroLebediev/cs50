#include <stdio.h>
#include <stdlib.h>

long long factor(int number);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    int number = atoi(argv[1]);
    if (number < 0)
    {
        return 2;
    }

    printf("%lli\n", factor(number));

    long long result = 1;
    while (number != 0)
    {
        result *= number;
        number--;
    }
    printf("%lli\n", result);
}

long long factor(int number)
{
    if (number <= 1)
    {
        return 1;
    }

    return number * factor(number - 1);
}