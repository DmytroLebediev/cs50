#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE
{
    int value;
    struct _NODE* left;
    struct _NODE* right;
} NODE;

NODE* create_node(int value);
void add(int value, NODE* root);
void print_tree(const NODE* root);
void delete_tree(NODE* root);
bool find(int value, NODE* root);

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
            add(value, root);
        }
    }
    fclose(file);
    
    print_tree(root);
    printf("\n");
    
    if (find(10, root))
    {
        printf("10 found in tree\n");
    }
    if (find(33, root))
    {
        printf("33 found in tree\n");
    }
    
    delete_tree(root);
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
    result->left = NULL;
    result->right = NULL;
    return result;
}

void add(int value, NODE* root)
{
    if (root == NULL
        || root->value == value)
    {
        return;
    }
    if (value < root->value)
    {
        if (root->left == NULL)
        {
            root->left = create_node(value);
        }
        else
        {
            add(value, root->left);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = create_node(value);
        }
        else
        {
            add(value, root->right);
        }
    }
}

void print_tree(const NODE* root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%i ", root->value);
    print_tree(root->right);
}

void delete_tree(NODE* root)
{
    if (root == NULL)
    {
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

bool find(int value, NODE* root)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->value == value)
    {
        return true;
    }
    else if (value < root->value)
    {
        return find(value, root->left);
    }
    return find(value, root->right);
    /*
    return (root->value == value)
        || (value < root->value && find(value, root->left))
        || find(value, root->right);*/
}