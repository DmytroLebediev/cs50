#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file = fopen("text2.txt", "r");

    if (file == NULL)
    {
        return 1;
    }

    int year = 0;
    char tmp1[50];
    char tmp2[50];
    char tmp3[50];

    fscanf(file,
        "%s %s %s %d",
        tmp1,
        tmp2,
        tmp3,
        &year);

    printf("year: %d\n", year);

    fclose(file);
}