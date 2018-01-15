#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cs50.h>

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

typedef struct intnode
{
    int value;
    int left_height;
    int right_height;
    struct intnode* parent;
    struct intnode* left;
    struct intnode* right;
} intnode;

typedef struct
{
    unsigned int count;
    intnode* root;
} binarytree;


binarytree* read_numbers(FILE* file);

intnode* create_node(int number);

void add_item(int number, binarytree* tree);

void remove_tree(binarytree* tree);

bool contains(int number, const binarytree* tree);

void print_tree(const binarytree* tree);


void test_search(const binarytree* tree);


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: ./btree0 <valid file path>\n");
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

    binarytree* tree = read_numbers(file);
    fclose(file);

    print_tree(tree);

    test_search(tree);
    printf("\n");

    remove_tree(tree);

    return 0;
}

/**
 * Reads numbers froms file and adds each number to the binary tree
 * Return balanced binary tree
 */
binarytree* read_numbers(FILE* file)
{
    if (!file)
    {
        return NULL;
    }

    binarytree* tree = calloc(1, sizeof(binarytree));
    if (!tree)
    {
        return NULL;
    }

    while (!feof(file))
    {
        int number = 0;
        fscanf(file, "%d", &number);
        add_item(number, tree);
    }

    return tree;
}

/**
 * Returns new node of the binary tree
 * Node is not yet bound to the tree
 */
intnode* create_node(int number)
{
    intnode *node = calloc(1, sizeof(intnode));
    if (node != NULL)
    {
        node->value = number;
    }
    return node;
}

/**
 * Chenges the current root of the subtree
 * Reflects chenges in the binary tree if root is chenged and in parent node if any
 */
void swap_root(intnode* previous, intnode* current, binarytree* tree)
{
    intnode* parent = previous->parent;
    if (previous == tree->root)
    {
        tree->root = current;
    }
    else
    {
        if (parent->left == previous)
            parent->left = current;
        else
            parent->right = current;
    }
}

void minor_rotate_left(intnode* root, binarytree* tree)
{
    // Have a look at the https://ru.wikipedia.org/wiki/%D0%90%D0%92%D0%9B-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE
    // all the names are taken from the article except root ~ a

    intnode *b = root->right;
    intnode *C = b->left;

    swap_root(root, b, tree);

    root->right = C;
    if (C)
        C->parent = root;

    b->left = root;
    root->parent = b;
}

void major_rotate_left(intnode* root, binarytree* tree)
{
    // Have a look at the https://ru.wikipedia.org/wiki/%D0%90%D0%92%D0%9B-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE
    // all the names are taken from the article except root ~ a

    intnode *b = root->right;
    intnode *c = b->left;
    intnode *M = c->left;
    intnode *N = c->right;

    swap_root(root, c, tree);

    root->right = M;
    if (M)
        M->parent = root;

    b->left = N;
    if (N)
        N->parent = b;

    c->left = root;
    root->parent = c;

    c->right = b;
    b->parent = c;
}

void minor_rotate_right(intnode* root, binarytree* tree)
{
    // Have a look at the https://ru.wikipedia.org/wiki/%D0%90%D0%92%D0%9B-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE
    // all the names are taken from the article except root ~ a

    intnode *b = root->left;
    intnode *C = b->right;

    swap_root(root, b, tree);

    root->left = C;
    if (C)
        C->parent = root;

    b->right = root;
    root->parent = b;
}

void major_rotate_right(intnode* root, binarytree* tree)
{
    // Have a look at the https://ru.wikipedia.org/wiki/%D0%90%D0%92%D0%9B-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE
    // all the names are taken from the article except root ~ a

    intnode *b = root->left;
    intnode *c = b->right;
    intnode *M = c->left;
    intnode *N = c->right;

    swap_root(root, c, tree);

    root->left = N;
    if (N)
        N->parent = root;

    b->right = M;
    if (M)
        M->parent = b;

    c->left = b;
    b->parent = c;

    c->right = root;
    root->parent = c;
}

void balance(intnode* root, binarytree* tree)
{
    if (root->right_height - root->left_height == 2)
    {
        if (root->right->left_height <= root->right->right_height)
        {
            minor_rotate_left(root, tree);
        }
        else
        {
            major_rotate_left(root, tree);
        }
    }
    else if (root->left_height - root->right_height == 2)
    {
        if (root->left->right_height <= root->left->left_height)
        {
            minor_rotate_right(root, tree);
        }
        else
        {
            major_rotate_right(root, tree);
        }
    }
}

int height(intnode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    root->left_height = height(root->left);
    root->right_height = height(root->right);
    return max(root->left_height, root->right_height) + 1;
}

void add_node(intnode* node, intnode* root, binarytree* tree)
{
    if (node->value == root->value)
    {
        return;
    }

    if (node->value < root->value)
    {
        if (root->left == NULL)
        {
            root->left = node;
            node->parent = root;
        }
        else
        {
            add_node(node, root->left, tree);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = node;
            node->parent = root;
        }
        else
        {
            add_node(node, root->right, tree);
        }
    }
    tree->count++;
    height(root);
    balance(root, tree);
}

void add_item(int number, binarytree* tree)
{
    if (tree == NULL)
    {
        return;
    }

    intnode *node = create_node(number);
    if (tree->root == NULL)
    {
        tree->root = node;
        tree->count++;
    }
    else
    {
        add_node(node, tree->root, tree);
    }
}

void remove_node(intnode* root)
{
    if (root == NULL)
    {
        return;
    }
    remove_node(root->left);
    remove_node(root->right);
    free(root);
}

void remove_tree(binarytree* tree)
{
    if (tree == NULL)
    {
        return;
    }

    remove_node(tree->root);
    free(tree);
}

bool contains_item(int number, const intnode* root)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->value == number)
        return true;
    if (root->value > number)
        return contains_item(number, root->left);
    else
        return contains_item(number, root->right);
}

bool contains(int number, const binarytree* tree)
{
    return tree != NULL
        && contains_item(number, tree->root);
}

void print_node(const intnode* root)
{
    if (root == NULL)
    {
        return;
    }
    print_node(root->left);
    printf("%d ", root->value);
    print_node(root->right);
}

void print_tree(const binarytree* tree)
{
    if (tree)
    {
        print_node(tree->root);
        printf("\n");
    }
}

void test_search(const binarytree* tree)
{
    printf("number to search: ");
    int number_to_search = get_int();
    while (number_to_search != INT_MAX)
    {
        printf("%d %s\n\n", number_to_search, contains(number_to_search, tree) ? "was found" : "was not found");

        printf("number to search: ");
        number_to_search = get_int();
    }
}