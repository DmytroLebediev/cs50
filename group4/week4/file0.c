#include <stdio.h>

int main()
{
    FILE* file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf("could not open file\n");
        return 1;
    }

    char c = fgetc(file);
    while (c != EOF)
    {
        if (c != '\n')
        {
            printf("%c ", c);
        }
        c = fgetc(file);
    }

    fclose(file);

    return 0;
}