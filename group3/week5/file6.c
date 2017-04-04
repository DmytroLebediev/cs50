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
    
    for (int i = 1; i < 11; i++)
    {
        if (fseek(file, 0, SEEK_SET) != 0)
        {
            return 1;
        }
        fprintf(file, "%i\n", i);
        printf("cursor position: %lu\n", ftell(file));
    }
    
    fclose(file);
}