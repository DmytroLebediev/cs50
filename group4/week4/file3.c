#include <stdio.h>

int main()
{
    char *filename = "text2.txt";
    FILE* file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("could not open file %s\n", filename);
        return 1;
    }

    char* text = "Hello, world!";
    fputs(text, file);
    fputc('\n', file);
    fputs(text, file);

    fclose(file);
}