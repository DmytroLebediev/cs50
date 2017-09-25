#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

#define ALPHABET_LENGTH 26

typedef struct node
{
    bool end[ALPHABET_LENGTH + 1];
    bool abc[ALPHABET_LENGTH + 1];
    struct node* next[ALPHABET_LENGTH + 1];
} node;

node* createnode();

bool isnullorempty(const char* word);

void insertword(node* root, const char* word);

bool contains(node* root, const char* word);

node* read_words(FILE* file);

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("usage: ./trie0 <valid file path>\n");
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

    node* trie = read_words(file);
    fclose(file);

    printf("enter word:\t");
    char* word = get_string();
    while (word != NULL)
    {
        printf(contains(trie, word) ? "Found!\n" : "Not found!\n");

        printf("enter word:\t");
        word = get_string();
    }

    return 0;
}

node* read_words(FILE* file)
{
    if (file == NULL)
    {
        return NULL;
    }

    node* trie = createnode();
    if (trie == NULL)
    {
        return NULL;
    }

    while (!feof(file))
    {
        char word[255];
        fscanf(file, "%s", word);
        insertword(trie, word);
    }

    return trie;
}

node* createnode()
{
    return calloc(1, sizeof(node));
}

bool isnullorempty(const char* word)
{
    return word == NULL || word[0] == '\0';
}

void insertword(node* root, const char* word)
{
    if (isnullorempty(word) || root == NULL)
        return;

    unsigned char index = word[0] - 'a';
    root->abc[index] = true;

    if (word[1] == '\0')
    {
        root->end[index] = true;
    }
    else
    {
        if (root->next[index] == NULL)
        {
            root->next[index] = createnode();
        }
        insertword(root->next[index], word + 1);
    }
}

bool contains(node* root, const char* word)
{
    if (isnullorempty(word) || root == NULL)
        return false;

    unsigned char index = word[0] - 'a';
    return (word[1] == '\0' && root->abc[index] && root->end[index])
        || (root->abc[index] && contains(root->next[index], word + 1));
}