#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <cs50.h>

typedef struct _node
{
    int val;
    struct _node* left;
    struct _node* right;
} node;


node* createnode(int value);
void addintree(int value, node* root);
bool find(int value, node* root);
void dispose(node* root);

node* tree = NULL;

int main(int argc, char** argv)
{
    if (argc != 2 || argv == NULL || argv[1] == NULL)
    {
        return 1;
    }
    
    char *line = NULL;
    size_t line_length = 0;
    ssize_t read_length;
    
    FILE* file = fopen(argv[1], "r");
    while (file != NULL && (read_length = getline(&line, &line_length, file)) != -1)
    {
        if (line[read_length - 1] == '\n')
            line[read_length - 1] = '\0';
        if (tree == NULL)
            tree = createnode(atoi(line));
        else
            addintree(atoi(line), tree);
        line = NULL;
    }
    fclose(file);
    
    printf("Enter number to search:\t");
    int number = GetInt();
    if (find(number, tree))
    {
        printf("Found!\n");
    }
    else 
    {
        printf("404\n");
    }
    dispose(tree);
    return 0;
}

node* createnode(int value)
{
    node* item = calloc(1, sizeof(node));
    item->val = value;
    return item;
}

void addintree(int value, node* root)
{
    if (root->val == value)
    {
        return;
    }
    if (value < root->val)
    {
        if (root->left == NULL)
        {
            root->left = createnode(value);
        }
        else
        {
            addintree(value, root->left);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = createnode(value);
        }
        else
        {
            addintree(value, root->right);
        }
    }
}

bool find(int value, node* root)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->val == value)
    {
        return true;
    }
    if (value < root->val)
    {
        return find(value, root->left);
    }
    return find(value, root->right);
}

void dispose(node* root)
{
    if (root == NULL)
        return;
    dispose(root->left);
    dispose(root->right);
    free(root);
}