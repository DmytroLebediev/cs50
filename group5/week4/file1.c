#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file = fopen("text.txt", "r");

    if (file == NULL)
    {
        return 1;
    }

    char *s;
    char buffer[256];
    s = fgets(buffer, 255, file);
    while (s != NULL)
    {
        int len = strlen(buffer);
        if (buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }

        printf("%s: %lu~", buffer, strlen(buffer));
        s = fgets(buffer, 255, file);
    }

    fclose(file);
}