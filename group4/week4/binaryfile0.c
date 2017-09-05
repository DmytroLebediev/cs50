#include <stdio.h>

int main()
{
    char* filename = "binary0";
    FILE* file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("could not open file %s\n", filename);
        return 1;
    }

    int number[10] = { 0,1,2,3,4,5,6,7,8,9 };
    int count = fwrite(number, sizeof(int), 10, file);

    printf("items written %d\n", count);

    fclose(file);
}