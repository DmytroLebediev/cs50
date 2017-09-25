#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

typedef struct strnode
{
    char* word;
    struct strnode *next;
} strnode;

typedef struct
{
    strnode *root;
    int length;
} hashnode;

typedef struct
{
    hashnode *array;
    int size;
} hashtable;

int hash(const char *word);

strnode* create_node(const char *word);

void add_to_list(const char *word, hashnode* node);

bool contains_in_list(const char *word, const hashnode* node);

void add_to_table(const char *word, hashtable* table);

bool contains(const char *word, const hashtable* table);

hashtable* read_words(FILE* file);

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("usage: ./hash1 <valid file path>\n");
        return 1;
    }
    if (argv[1] == NULL)
    {
        printf("can not process empty file name\n");
        return 2;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("can not open file %s\n", argv[1]);
        return 3;
    }

    hashtable* table = read_words(file);
    fclose(file);

    printf("enter word:\t");
    char* word = get_string();
    while (word != NULL)
    {
        printf(contains(word, table) ? "Found!\n" : "Not found!\n");

        printf("enter word:\t");
        word = get_string();
    }

    return 0;
}

int hash(const char *word)
{
    int result = 0;
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        result += word[i];
    }
    return result;
}

strnode* create_node(const char *word)
{
    strnode* node = calloc(1, sizeof(strnode));
    if (node)
    {
        node->word = malloc((strlen(word) + 1) * sizeof(char));
        strcpy(node->word, word);
    }
    return node;
}

void add_to_list(const char *word, hashnode* node)
{
    strnode* list_node = create_node(word);
    if (list_node)
    {
        if (!node->root)
        {
            node->root = list_node;
        }
        else
        {
            strnode* last = node->root;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = list_node;
        }
        node->length++;
    }
}

bool contains_in_list(const char *word, const hashnode* node)
{
    strnode* current = node->root;
    while (current != NULL)
    {
        if (!strcmp(current->word, word))
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void add_to_table(const char *word, hashtable* table)
{
    if (!table)
    {
        return;
    }

    int index = hash(word) % table->size;
    add_to_list(word, table->array + index);
}

bool contains(const char *word, const hashtable* table)
{
    if (!table)
    {
        return false;
    }

    int index = hash(word) % table->size;
    return contains_in_list(word, table->array + index);
}

hashtable* read_words(FILE* file)
{
    if (!file)
    {
        return NULL;
    }

    hashtable* table = calloc(1, sizeof(hashtable));
    if (!table)
    {
        return NULL;
    }
    table->size = 1023;
    table->array = calloc(1023, sizeof(hashnode));

    while (!feof(file))
    {
        char word[255];
        fscanf(file, "%s", word);
        add_to_table(word, table);
    }

    return table;
}