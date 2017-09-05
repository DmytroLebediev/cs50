#include <stdio.h>

int main()
{
    char* filename = "binary0";
    FILE* file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("could not open file %s\n", filename);
        return 1;
    }

    int number[10];
    int count = fread(number, sizeof(int), 10, file);

    printf("items written %d\n", count);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", number[i]);
    }
    printf("\n");

    fclose(file);
}