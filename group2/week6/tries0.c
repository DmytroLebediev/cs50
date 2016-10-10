#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <cs50.h>

#define ALPHABET_LENGTH 26

typedef struct node
{
    bool* end;
    bool* abc;
    struct node** next;
} node;

node* createnode();
bool isnullorempty(const char* word);
void insertword(node* root, const char* word);
bool contains(node* root, const char* word);
void dispose(node* root);

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("./tries <word> [word] ...\n");
        return 1;
    }
    node* root = createnode();
    for (int i = 1; i < argc; i++)
    {
        insertword(root, argv[i]);
    }
    
    printf("Check the word\t");
    char* word = GetString();
    if (contains(root, word))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not found!\n");
    }
    
    dispose(root);
    root = NULL;
    
    return 0;
}

node* createnode()
{
    node* item = malloc(sizeof(node));
    item->abc = calloc(ALPHABET_LENGTH, sizeof(bool));
    item->end = calloc(ALPHABET_LENGTH, sizeof(bool));
    item->next = calloc(ALPHABET_LENGTH, sizeof(node));
    
    return item;
}


void insertword(node* root, const char* word)
{
    if (isnullorempty(word) || root == NULL)
    {
        return;
    }
    
    unsigned short c = word[0] - 'a';
    // check if current letter is already in tree
    root->abc[c] = true;
    
    // if it's the laast character in the word
    if (word[1] == '\0')
    {
        root->end[c] = true;
    }
    else
    {
        // check if the next node exists
        if (root->next[c] == NULL)
        {
            root->next[c] = createnode();
        }
        insertword(root->next[c], word + 1);
    }
}

bool contains(node* root, const char* word)
{
    if (isnullorempty(word) || root == NULL)
    {
        return false;
    }
    
    unsigned short c = word[0] - 'a';
    // check if the word ends with current character
    // of if next nodes contain the rest of the word
    return (word[1] == '\0' && root->abc[c] && root->end[c])
        || (root->abc[c] && contains(root->next[c], word + 1));
}

bool isnullorempty(const char* word)
{
    return word == NULL || word[0] == '\0';
}

void dispose(node* root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        dispose(root->next[i]);
    }
    free(root->next);
    free(root->end);
    free(root->abc);
    free(root);
}