#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    if (true)
    {
        printf("true\n");
    }
    if ('\0')
    {
        printf("\\0\n");
    }
    if ('\n')
    {
        printf("\\n\n");
    }
    if ('0')
    {
        printf("0\n");
    }
    if ("true")
    {
        printf("\"true\"\n");
    }
}