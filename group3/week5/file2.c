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
    
    int read_items = 0;
    //13 sometext 12.5
    int int_number;
    char text[200];
    float float_number;
    
    read_items = fscanf(file, "%i %s %f", &int_number, text, &float_number);
    
    printf("Items read: %i\n", read_items);
    printf("integer: %i\n", int_number);
    printf("text: %s\n", text);
    printf("float: %f\n", float_number);
    
    fclose(file);
}