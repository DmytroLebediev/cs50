#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_STRUCT {
    char* word;
    struct NODE_STRUCT* next;
} node;

node* createNode(char* word);
void addNode(node* root, node* _node);
void addNodeAtPosition(node* root, int position, node* _node);
void printList(const node* root);

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        return 1;
    }
    
    node* root = createNode(argv[1]);
    if (root == NULL)
    {
        return 2;
    }
    /*for (int i = 2; i < 6 && i < argc; i++)
    {
        node* newNode = createNode(argv[i]);
        if (newNode == NULL)
        {
            return 2;
        }
        addNode(root, newNode);
    }*/
    for (int i = 2; i < argc; i++)
    {
        node* newNode = createNode(argv[i]);
        if (newNode == NULL)
        {
            return 2;
        }
        addNodeAtPosition(root, 1, newNode); // 0xffffeedada
    }
    
    printList(root);
    
    while (root != NULL)
    {
        node* current = root;
        root = root->next;
        free(current);
    }
    root = NULL;
}

node* createNode(char* word)
{
    // allocate memmory for a new node
    // write word into a new node
    // initialize next pointer with NULL
    // return pointer to created node
    node* item = malloc(sizeof(node));
    if (item == NULL)
    {
        return NULL;
    }
    item->next = NULL; // (*root).next
    item->word = word;
    return item;
}

void addNode(node* root, node* _node)
{
    // check if root is initialized
    // find pointer to the last item in a list
    // set it equal to newly added node
    if (root == NULL)
        return;
        
    node* item = root;
    while (item->next != NULL)
    {
        item = item->next;
    }
    item->next = _node;
}

void printList(const node* root)
{
    // check if root is initialized
    // go through the list
    // print each new item from a new line
    if (root == NULL)
        return;
    
    for (const node* i = root; i != NULL; i = i->next)
    {
        printf("%s\n", i->word);
    }
}

void addNodeAtPosition(node* root, int position, node* _node) // 0xffffeedada
{
    // check if root is iniialized
    // go through list and find
    // last element if list lenght is less than position
    // else find [position-1] element
    // add new node after found item
    
    // NOTE: position starts from 0 like in arrays
    
    if (root == NULL || position < 1)
    {
        return;
    }
    
    int i = 0;
    node* item = root;
    while (item->next != NULL && i < position - 1)
    {
        item = item->next;
        i++;
    }
    
    _node->next = item->next;
    item->next = _node;
}