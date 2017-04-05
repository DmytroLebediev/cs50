#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

typedef struct _NODE
{
    int value;
    struct _NODE* next;
} NODE;

NODE* create_node(int value);

void add(NODE* root, int value);

void print_list(const NODE* root);

void free_list(NODE* root);

int main()
{
    FILE* file = fopen("numbers.txt", "r");
    if (file == NULL)
    {
        return 1;
    }
    
    NODE* root = NULL;
    char buffer[256];
    while (fgets(buffer, 256, file) != NULL)
    {
        buffer[strlen(buffer) - 1] = '\0';
        int value = atoi(buffer);
        if (root == NULL)
        {
            root = create_node(value);
        }
        else
        {
            add(root, value);
        }
    }
    fclose(file);
    
    print_list(root);
    
    free_list(root);
    root = NULL;
}

NODE* create_node(int value)
{
    NODE* result = malloc(1 * sizeof(NODE));
    if (result == NULL)
    {
        return NULL;
    }
    result->value = value;
    result->next = NULL;
    return result;
}

void add(NODE* root, int value)
{
    if (root == NULL)
    {
        return;
    }
    
    NODE* item = create_node(value);
    NODE* cur = root;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = item;
}

void print_list(const NODE* root)
{
    for (const NODE* cur = root; cur != NULL; cur = cur->next)
    {
        printf("%i\n", cur->value);
    }
}

void free_list(NODE* root)
{
    if (root == NULL)
    {
        return;
    }
    free_list(root->next);
    free(root);
}