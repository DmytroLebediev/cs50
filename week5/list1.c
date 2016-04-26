#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int value;
    struct _node* next;
    struct _node* prev;
} node;

/**
 * To create new node for each new line in file
 */
node* getnode(FILE* file);

/**
 * prints list on the scrren
 */
void printlist(node* root);

int main(int argc, char** argv)
{
    if (argc != 2 || argv == NULL || argv[1] == NULL)
    {
        printf("\ttry to run ./list0 <file path>\n");
        return 1;
    }
    
    char* filename = argv[1];
    FILE* fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("can't open the file specified: %s\n", filename);
        return 1;
    }
    
    node* root = NULL;
    node* current = NULL;
    
    root = getnode(fptr);
    current = root;
    
    while (current != NULL)
    {
        current->next = getnode(fptr);
        if (current->next != NULL)
        {
            current->next->prev = current;
        }
        current = current->next;
    }
    
    if (ferror(fptr))
    {
        printf("error while reading a file\n");
    }
    
    printlist(root);
    
    current = root;
    while (root != NULL)
    {
        root = root->next;
        free(current);
        current = root;
    }
    
    return 0;
}

node* getnode(FILE* file)
{
    node* item = NULL;
    
    char *line = NULL;
    size_t line_length = 0;
    ssize_t read_length;
    
    if (file != NULL && (read_length = getline(&line, &line_length, file)) != -1)
    {
        // allocate memory for new item in a list
        item = malloc(sizeof(node));
        item->next = NULL;
        item->prev = NULL;
        // set value read from file
        item->value = atoi(line);
    }
    
    return item;
}

void printlist(node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    for (node* i = root; i != NULL; i = i->next)
    {
        printf("%i ", i->value);
    }
    printf("\n");
}