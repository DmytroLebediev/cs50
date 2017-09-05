#include <stdio.h>
#include <string.h>

typedef char* string;

int main()
{
    FILE* file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf("could not open file\n");
        return 1;
    }


    char *s;
    char buffer[256];
    s = fgets(buffer, 20, file);
    while (s != NULL)
    {
        if (buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }

        printf("\"%s\" of length %lu\n", buffer, strlen(buffer));


        s = fgets(buffer, 20, file);
    }

    fclose(file);

    return 0;
}