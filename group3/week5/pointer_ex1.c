#include <stdio.h>
#include <stdlib.h>

void init_pointer(int** root);

int main()
{
    int* root = NULL;
    init_pointer(&root);
    
    if (root != NULL)
    {
        printf("value[0]=%i\n", *root);
    }
    else
    {
        printf("nothing\n");
    }
}

void init_pointer(int** root)
{
    *root = malloc(1 * sizeof(int));
    if (*root != NULL)
    {
        root[0][0] = 10;
    }
}