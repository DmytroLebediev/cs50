#define _XOPEN_SOURCE 700

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "distribution.h"

#define HASHSIZE 1023

// node of list of words
// used to resolve collisions in hash table
typedef struct _LISTNODE
{
    char* word;
    struct _LISTNODE* prev;
    struct _LISTNODE* next;
} LISTNODE;

// node of hash table
// stores number of words added to this node
// and list of added words
typedef struct _HASHNODE
{
    int count;
    LISTNODE* root;
} HASHNODE;

// hash table itself
HASHNODE hash_table[HASHSIZE];

// calculates hash for any word
unsigned int hash(const char* word);

// sets default values for each node of hash table
void init();

// creates new list node with specified word
LISTNODE* create_node(const char* word);

// adds new word to the hash table
void add(const char* word);

// adds word to the end of the list specified with root
void add_list(LISTNODE* root, const char* word);

// tries to find word in a hash table
// returns true on success
bool check(const char* word);

// frees memory occupied with hash table
void clear();

// frees memory occupied with list of words
void free_list(LISTNODE* root);

int main()
{
    FILE* file = fopen("large.txt", "r");
    if (file == NULL)
    {
        return 1;
    }
    
    char buffer[256];
    while (fgets(buffer, 256, file) != NULL)
    {
        int length = strlen(buffer);
		// skip any read enter at the end of the word
		if (buffer[length - 1] == '\n')
		{
		    buffer[length - 1] = '\0';
		}
		// add word to the hash table
        add(buffer);
    }
    fclose(file);
    
    printf("enter word to check:\t");
    char* word = get_string();
    if (check(word))
    {
        printf("word is correct\n");
    }
    else
    {
        printf("word is unknown\n");
    }
    printf("\n");
    
	// collect counts from each node of the hash table
    int sizes[HASHSIZE];
    for (int i = 0; i < HASHSIZE; i++)
    {
        sizes[i] = hash_table[i].count;
    }
	// draw distribution of words in hash table
    drawdistribution(sizes, HASHSIZE);
    
    clear();
}

unsigned int hash(const char* word)
{
    unsigned int result = 0;
    for (int i = 0, length = strlen(word); i<length; i++)
    {
        result = (unsigned int)word[i]
            + (result << 6)
            + (result << 16)
            - result;
    }
    return result;
}

void init()
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        // default values for hash table nodes
        hash_table[i].count = 0;
        hash_table[i].root = NULL;
    }
}

LISTNODE* create_node(const char* word)
{
    LISTNODE* result = malloc(1 * sizeof(LISTNODE));
    if (result == NULL)
    {
        return NULL;
    }
    
	// copy received word into the hash table
	// need to free this memory also
    int length = strlen(word);
    result->word = malloc(length + 1);
	strcpy(result->word, word);
	
    result->next = NULL;
    result->prev = NULL;
    return result;
}

void add(const char* word)
{
	// calculate hash for new word
    int hash_word = hash(word) % HASHSIZE;
	// create new list in hash table node
	// or add word to already existing list
    if (hash_table[hash_word].root == NULL)
    {
        hash_table[hash_word].root = create_node(word);
    }
    else
    {
        add_list(hash_table[hash_word].root, word);
    }
	// keep track of added words
    hash_table[hash_word].count++;
}

void add_list(LISTNODE* root, const char* word)
{
    if (root == NULL)
    {
        return;
    }
    
    LISTNODE* item = create_node(word);
    LISTNODE* cur = root;
	// find the last item in a list
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
	// add new word to the end of the list
    cur->next = item;
    item->prev = cur;
}

bool check(const char* word)
{
	// calculate hash for new word
    int hash_word = hash(word) % HASHSIZE;
    if (hash_table[hash_word].root == NULL)
    {
        return false;
    }
    LISTNODE* cur = hash_table[hash_word].root;
    while (cur != NULL
        && strcmp(cur->word, word) != 0)
    {
        cur = cur->next;   
    }
    return cur != NULL;
}

void clear()
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        // for each item remove list of words
        hash_table[i].count = 0;
        free_list(hash_table[i].root);
    }
}

void free_list(LISTNODE* root)
{
    if (root == NULL)
    {
        return;
    }
    free_list(root->next);
    free(root->word);
    free(root);
}