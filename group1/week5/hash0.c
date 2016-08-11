#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

typedef struct _node
{
    const char* word;
    struct _node* next;
} node;

typedef struct
{
    int capacity;
    int size;
    node** list;
} hashtable;

typedef unsigned int uint;

uint gethash(const char* word, const uint limit);

node* createnode(const char* word);

void addtable(const char* word, hashtable* table);

void addlist(const char* word, node* list);

bool intable(const char* word, hashtable* table);

void freetable(hashtable* table);

void freelist(node* list);

int main()
{
    hashtable dictionary;
    dictionary.capacity = 1023;
    dictionary.size = 0;
    dictionary.list = calloc(dictionary.capacity, sizeof(void*));
    
    char *line = NULL;
    size_t line_length = 0;
    ssize_t read_length;
    
    FILE* file = fopen("large", "r"); //file.txt
    
    while (file != NULL && (read_length = getline(&line, &line_length, file)) != -1)
    {
        if (line[read_length - 1] == '\n')
            line[read_length - 1] = '\0';
        addtable(line, &dictionary);
        line = NULL;
    }
    fclose(file);
    
    printf("What woard are you looking for?\n");
    char* check = GetString();
    if (intable(check, &dictionary))
    {
        printf("Found!\n");
    }
    else
    {
        printf("404\n");
    }
    freetable(&dictionary);
    
    return 0;
}

bool intable(const char* word, hashtable* table)
{
    uint hash = gethash(word, table->capacity);
    node* root = table->list[hash];
    if (root == NULL)
    {
        return false;
    }
    do
    {
        if (strcmp(root->word, word) == 0)
        {
            return true;
        }
        root = root->next;
    }
    while (root != NULL);
    return false;
}

uint gethash(const char* word, const uint limit)
{
    uint hash = limit;
    for(const char* i = word; *i != '\0'; i++)
    {
        hash += *i;
        hash *= 2;
    }
    return hash % limit;
}

node* createnode(const char* word)
{
    node* newnode = malloc(sizeof(node));
    newnode->word = word;
    newnode->next = NULL;
    return newnode;
}


void addtable(const char* word, hashtable* table)
{
    uint hash = gethash(word, table->capacity);
    if (table->list[hash] == NULL)
    {
        table->list[hash] = createnode(word);
    }
    else
    {
        addlist(word, table->list[hash]);
    }
    table->size++;
}

void addlist(const char* word, node* list)
{
    node* newnode = createnode(word);
    node* current = list;
    while (current->next != NULL
        && strcmp(word, current->word) < 0)
    {
        current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
}

void freetable(hashtable* table)
{
    for (int i = 0; i < table->capacity; i++)
    {
        if (table->list[i] != NULL)
        {
            freelist(table->list[i]);
        }
    }
    table->size = 0;
    table->capacity = 0;
}

void freelist(node* list)
{
    node* current = list;
    while (list != NULL)
    {
        list = list->next;
        free(current);
        current = list;
    }
}