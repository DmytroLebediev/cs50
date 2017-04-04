//fread
//fwrite

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int x;
    int y;
} POINT;

int main()
{
    char* filename = "binary_file";
    FILE* file = fopen(filename, "w+");

    if (file == NULL)
    {
        printf("file error!\n");
        return 1;
    }
    
    POINT point = { .x = 0, .y = 10 };
    fwrite(&point, sizeof(POINT), 1, file);
    
    fclose(file);
}