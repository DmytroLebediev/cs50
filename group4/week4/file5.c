#include <stdio.h>

int main()
{
    char* filename = "text2.txt";
    FILE* file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("could not open file %s\n", filename);
        return 1;
    }

    int year = 0;
    char tmp1[256];
    char tmp2[256];
    fscanf(file, "%s %s %d", tmp1, tmp2, &year);

    printf("year: %d\n", year);

    fclose(file);
}