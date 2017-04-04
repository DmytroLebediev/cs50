//fread
//fwrite

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int x;
    int y;
    POINT point;
} POINT;

int main()
{
    char* filename = "binary_file";
    FILE* file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("file error!\n");
        return 1;
    }
    
    POINT point;
    fread(&point, sizeof(POINT), 1, file);
    
    printf("x: %i, y: %i\n", point.x, point.y);
    
    fclose(file);
}