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
    int symbols = fprintf(file, "%s\n%s", text, text);
    
    printf("prosecced symbols: %i\n", symbols);
    
    symbols = fprintf(file, "\nprosecced symbols: %i\n", symbols);
    
    fclose(file);
}