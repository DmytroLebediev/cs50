#include <stdio.h>

int main()
{
    char* filename = "text2.txt";
    FILE* file = fopen(filename, "a");

    if (file == NULL)
    {
        printf("could not open file\n");
        return 1;
    }

    char* text = "Hello, world!";

    for (;text != NULL && (*text) != '\0'; text++)
    {
        if (fputc(*text, file) == EOF)
        {
            fclose(file);
            printf("some error occured\n");
            return 2;
        }
    }

    fclose(file);
}