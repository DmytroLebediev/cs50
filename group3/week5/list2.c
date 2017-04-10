#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

typedef struct _NODE
{
    int value;
    struct _NODE* next;
    struct _NODE* prev;
} NODE;

NODE* create_node(int value);

void add(NODE* root, int value);

void add_at(int index, NODE** root, int value);

int* get_at(int index, NODE* root);

void remove_value(int value, NODE** root);

void remove_at(int index, NODE** root);

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
    
    int* list_value = get_at(0, root);
    if (list_value != NULL)
    {
        printf("list[0]:\t%i\n", *list_value);
    }
    
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
            add_at(0, &root, value);
        }
    }
    fclose(file);
    
    printf("\ninitialized list:\n");
    print_list(root);
    
    list_value = get_at(0, root);
    if (list_value != NULL)
    {
        printf("\nlist[0]:\t%i\n", *list_value);
    }
    
    remove_at(0, &root);
    remove_value(9, &root);

    printf("\nmodified list:\n");
    print_list(root);
    
    list_value = get_at(0, root);
    if (list_value != NULL)
    {
        printf("\nlist[0]:\t%i\n", *list_value);
    }
    
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
    result->prev = NULL;
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
    item->prev = cur;
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

void add_at(int index, NODE** root, int value)
{
    // adds value to be at index position from the beginning
    // if list is shorter than index then item will be added at the end
    
    if (root == NULL)
    {
        return;
    }
    if (index < 0)
    {
        return;
    }
    NODE* item = create_node(value);
    
    if (index == 0)
    {
        item->next = *root;
        (*root)->prev = item;
        *root = item;
    }
    else
    {
        NODE* cur = *root;
        int count = 0;
        while (cur->next != NULL
            || count < index)
        {
            cur = cur->next;
            count++;
        }
        cur->next = item;
        item->prev = cur;
    }
}

int* get_at(int index, NODE* root)
{
    // returns pointer to value at index
    // if index is out of list range then NULL is returns
    
    NODE* cur = root;
    int i = 0;
    while (cur != NULL
        && i < index)
    {
        i++;
        cur = cur->next;
    }
    if (cur == NULL)
    {
        return NULL;
    }
    return &(cur->value);
}

void remove_value(int value, NODE** root)
{
    // finds node with specify value and removes it from list
    // does nothing if value is not present in the list
    
    NODE* cur = *root;
    while (cur != NULL
        && cur->value != value)
    {
        cur = cur->next;   
    }
    
    if (cur == NULL)
    {
        return;
    }
    else
    {
        // delete cur
        if (cur->prev == NULL) // delete root
        {
            *root = cur->next;
            (*root)->prev = NULL;
            free(cur);
        }
        else if (cur->next == NULL) //delete tail
        {
            cur->prev->next = NULL;
            cur->prev = NULL;
            free(cur);
        }
        else //somewhere in the middle
        {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur->prev = NULL;
            cur->next = NULL;
            free(cur);
        }
    }
}

void remove_at(int index, NODE** root)
{
    // removes node at specified position
    // does nothing if index is out of list range
    
    NODE* cur = *root;
    
    int i = 0;
    while (cur != NULL
        && i < index)
    {
        i++;
        cur = cur->next;
    }
    
    if (cur == NULL)
    {
        return;
    }
    else
    {
        // delete cur
        if (cur->prev == NULL) // delete root
        {
            *root = cur->next;
            (*root)->prev = NULL;
            free(cur);
        }
        else if (cur->next == NULL) //delete tail
        {
            cur->prev->next = NULL;
            cur->prev = NULL;
            free(cur);
        }
        else //somewhere in the middle
        {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur->prev = NULL;
            cur->next = NULL;
            free(cur);
        }
    }
}