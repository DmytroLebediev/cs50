#include <stdio.h>

int main()
{
    char* filename = "text2.txt";
    FILE* file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("could not open file %s\n", filename);
        return 1;
    }

    unsigned short year = 2018;
    int result = fprintf(file, "Happy New %hu Year!", year);

    printf("processed symbols: %d\n", result);

    fclose(file);
}