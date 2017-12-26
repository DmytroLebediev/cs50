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
    fputs(text, file);
    fputc('\n', file);
    fputs(text, file);
    
    fclose(file);
}