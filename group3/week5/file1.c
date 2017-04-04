#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

int main()
{
    char* filename = "text_file.txt";
    FILE* file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("file error!\n");
        return 1;
    }
    
    char* c;
    char buffer[256];
    c = fgets(buffer, 20, file);
    while(c != NULL)
    {
        printf("%s, length: %lu\n", buffer, strlen(buffer));
        c = fgets(buffer, 20, file);
    }
    printf("\n");
    
    fclose(file);
}