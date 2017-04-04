#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

int main()
{
    char* filename = "text_file.txt";
    FILE* file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("file error!\n");
        return 1;
    }
    
    char* text = "hello, world!";
    for (; text != NULL && (*text) != '\0'; text++)
    {
        if (fputc(*text, file) == EOF)
        {
            fclose(file);
            return 1;
        }
    }
    
    fclose(file);
}