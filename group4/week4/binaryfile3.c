#include <stdio.h>

typedef struct
{
    unsigned char red;
    unsigned char blue;
    unsigned char green;
} PIXEL;

int main()
{
    char* filename = "binary0";
    FILE* file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("could not open file %s\n", filename);
        return 1;
    }


    PIXEL image[4];

    int count = fwrite(image, sizeof(PIXEL), 4, file);

    fseek(file, -12, SEEK_CUR);

    int count = fwrite(image, sizeof(PIXEL), 4, file);

    printf("items written %d\n", count);

    fclose(file);
}