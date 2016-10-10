#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node;

node* createnode(int value);
bool addnode(node* root, int value);
bool contains(const node* root, int value);
void dispose(node* root);
void printtree(const node* root);

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("usage: ./btree <number> [number]...\n");
        return 1;
    }
    
    node* btree = NULL;
    
    for (int i=1; i<argc; i++)
    {
        if (btree == NULL)
        {
            btree = createnode(atoi(argv[i]));
        }
        else
        {
            addnode(btree, atoi(argv[i]));
        }
    }
    printtree(btree);
    
    printf("\nEnter number to check:\t");
    int number = GetInt();
    if (contains(btree, number))
    {
        printf ("Found!\n");
    }
    else
    {
        printf ("404 Not found!\n");
    }
    
    dispose(btree);
}

node* createnode(int value)
{
    node* newnode = calloc(sizeof(node), 1);
    newnode->value = value;
    return newnode;
}

bool addnode(node* root, int value)
{
    if (root == NULL
        || value == root->value)
    {
        return false;
    }
    node* subtree = NULL;
    if (value < root->value)
    {
        if (root->left != NULL)
        {
            subtree = root->left;
        }
        else
        {
            root->left = createnode(value);
            return true;
        }
    }
    else
    {
        if (root->right != NULL)
        {
            subtree = root->right;
        }
        else
        {
            root->right = createnode(value);
            return true;
        }
    }
    return addnode(subtree, value);
}

bool contains(const node* root, int value)
{
    return root != NULL
        && (
            root->value == value
            || (value < root->value && contains(root->left, value))
            || (value > root->value && contains(root->right, value))
        );
}

void dispose(node* root)
{
    if (root == NULL)
    {
        return;
    }
    dispose(root->left);
    dispose(root->right);
    free(root);
}

void printtree(const node* root)
{
    // 1. check if root exists
    if (root == NULL)
    {
        return;
    }
    // 2. print left subtree
    printtree(root->left);
    // 3. print node value
    printf("%i ", root->value);
    // 4. print right subtree
    printtree(root->right);
}