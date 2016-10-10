#include <stdio.h>
#include <cs50.h>

int* array = NULL;

int main(int arc, char** argv)
{
    if (argv == NULL)
    {
        return 1;
    }
    int length = 10;
    int* a = NULL;
    a = malloc(length*sizeof(int));
    if (a == NULL)
    {
        return 1;
    }
    a++;
    for (int i=0; i<length; i++)
    {
        *(a + i) = i + 1;
    }
    
    for(int i=0; i<length; i++)
    {
        printf("%p\n", (a + i));
        printf("%i\n", *(a + i));
    }
    
    free(a);
}