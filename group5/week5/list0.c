#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>


typedef unsigned int uint;

typedef struct int_node
{
    int value;
    struct int_node* next;
} int_node;

typedef struct
{
    uint length;
    struct int_node* root;
} int_list;


/**
 * Reads all numbers from file with each number written from a new line
 * Returns list root and its length
 */
int_list* read_numbers(FILE* file, int_list* list);

/**
 * Returns new list node with a specified number
 * Node is out of list
 */
int_node* create_node(int number);

/**
 * Adds number to the end of the list
 */
void add_item(int_list* list, int number);

/**
 * Returns 0-based index of number in a list
 * If number is not found -1 is returned
 */
int index_of(const int_list* list, int number);

/**
 * Prints all list items on the screen separated with space
 */
void print_list(const int_list* list);

/**
 * Frees memory occupied by the list
 */
void remove_list(int_list* list);


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: ./list0 <valid file path>\n");
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

    int_list* list = read_numbers(file, NULL);
    fclose(file);

    print_list(list);

    printf("what number are you looking for?\n");
    int number = get_int();

    if (index_of(list, number) == -1)
    {
        printf("404 Not Found!\n");
    }
    else
    {
        printf("List contains %d\n", number);
    }

    remove_list(list);

    return 0;
}

/**
 * Prints all list items on the screen separated with space
 */
void print_list(const int_list* list)
{
    if (list == NULL)
    {
        return;
    }

    const int_node *item = list->root;
    while (item != NULL)
    {
        printf("%d ", item->value);
        item = item->next;
    }
    printf("\n");
}

/**
 * Reads all numbers from file with each number written from a new line
 * Returns list root and its length
 */
int_list* read_numbers(FILE* file, int_list* list)
{
    if (file == NULL)
    {
        return NULL;
    }

    if (list == NULL)
    {
        list = calloc(1, sizeof(int_list));
    }

    while (!feof(file))
    {
        int number = 0;
        fscanf(file, "%d", &number);
        add_item(list, number);
    }

    return list;
}

/**
 * Returns new list node with a specified number
 * Node is out of list
 */
int_node* create_node(int number)
{
    int_node *node = calloc(1, sizeof(int_node));
    if (node != NULL)
    {
        node->value = number;
    }
    return node;
}

/**
 * Adds number to the end of the list
 */
void add_item(int_list* list, int number)
{
    int_node *node = create_node(number);
    if (list->root == NULL)
    {
        list->root = node;
    }
    else
    {
        int_node *item = list->root;
        while (item->next != NULL)
        {
            item = item->next;
        }
        item->next = node;
    }
    list->length++;
}

/**
 * Returns 0-based index of number in a list
 * If number is not found -1 is returned
 */
int index_of(const int_list* list, int number)
{
    if (list == NULL)
    {
        return -1;
    }

    int index = 0;
    const int_node* item = list->root;
    while (item != NULL)
    {
        if (item->value == number)
        {
            return index;
        }
        index++;
        item = item->next;
    }
    return -1;
}

/**
 * Frees memory occupied by the list
 */
void remove_list(int_list* list)
{
    list->length = 0;
    int_node *item = list->root;
    while (list->root != NULL)
    {
        list->root = list->root->next;
        free(item);
        item = list->root;
    }
}