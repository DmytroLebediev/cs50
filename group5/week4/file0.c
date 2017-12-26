#include <stdio.h>

int main()
{
    FILE *file = fopen("text.txt", "r");

    if (file == NULL)
    {
        return 1;
    }

    char c = fgetc(file);
    while (c != EOF)
    {
        printf("%c~", c);
        c = fgetc(file);
    }

    fclose(file);
}