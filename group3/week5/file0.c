#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* filename = "text_file.txt";
    FILE* file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("file error!\n");
        return 1;
    }
    
    char c;
    c = fgetc(file);
    while(c != EOF)
    {
        printf("%c", c);
        c = fgetc(file);
    }
    printf("\n");
    
    fclose(file);
}