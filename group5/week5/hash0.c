#include <stdio.h>
#include <cs50.h>

#define HASHTABLE_SIZE 10231023

unsigned int hash(const char *str)
{
    unsigned int hash = 0;
    for (const char *c = str; *c != '\0'; c++)
    {
        hash &= 0x0fffffff;
        hash = (hash << 2) ^ *c;
    }
    return hash % HASHTABLE_SIZE;
}

int main()
{
    char **table = calloc(HASHTABLE_SIZE, sizeof(char*));
    for (int i = 0; i < 10; i++)
    {
        char *word = get_string();
        int index = hash(word);
        table[index] = word;
    }
    char *word = "cat";
    int index = hash(word);
    if (table[index] != NULL)
    {
        printf("\"cat\" was found\n");
    }
    else
    {
        printf("404\n");
    }

    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        free(table[i]);
    }
    free(table);
}