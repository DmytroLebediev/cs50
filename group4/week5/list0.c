#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
int_list* read_numbers(FILE* file);

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

/**
 * Removes number from list
 * Returns true if number was actually in list
 */
bool delete_item(int_list* list, int number);


void test_search(const int_list* list);

void test_delete(int_list* list);


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: ./array0 <valid file path>\n");
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

    int_list* list = read_numbers(file);
    fclose(file);

    print_list(list);

    test_search(list);
    printf("\n");
    test_delete(list);

    remove_list(list);

    return 0;
}

void print_list(const int_list* list)
{
    if (!list || !list->root)
    {
        return;
    }

    for (int_node* curr = list->root; curr != NULL; curr = curr->next)
    {
        printf("%d ", curr->value);
    }
    printf("\n");
}

int_list* read_numbers(FILE* file)
{
    if (!file)
    {
        return NULL;
    }

    int_list* list = calloc(1, sizeof(int_list));
    if (!list)
    {
        return NULL;
    }

    while (!feof(file))
    {
        int number = 0;
        fscanf(file, "%d", &number);
        add_item(list, number);
    }

    return list;
}

int_node* create_node(int number)
{
    int_node* node = malloc(1 * sizeof(int_node));
    if (!node)
    {
        return NULL;
    }
    node->value = number;
    node->next = NULL;
    return node;
}

int_node* get_last_node(const int_list* list)
{
    if (!list || !list->root)
    {
        return NULL;
    }

    int_node* last = list->root;
    while (last->next != NULL)
    {
        last = last->next;
    }
    return last;
}

void add_item(int_list* list, int number)
{
    int_node* node = create_node(number);
    if (!node)
    {
        return;
    }

    if (list->root == NULL)
    {
        list->root = node;
    }
    else
    {
        int_node* last = get_last_node(list);
        last->next = node;
    }
    list->length++;
}

int index_of(const int_list* list, int number)
{
    int i = 0;
    for (int_node* curr = list->root; curr != NULL; curr = curr->next, i++)
    {
        if (curr->value == number)
        {
            return i;
        }
    }
    return -1;
}

void remove_node(int_node* node)
{
    if (!node)
    {
        return;
    }
    remove_node(node->next);
    free(node);
}

void remove_list(int_list* list)
{
    if (!list || !list->root)
    {
        return;
    }
    remove_node(list->root);
    list->root = NULL;
    list->length = 0;
}

void delete_root(int_list* list)
{
    int_node* to_delete = list->root;
    list->root = to_delete->next;
    free(to_delete);
    list->length--;
}

void delete_node_after(int_node* node)
{
    int_node* to_delete = node->next;
    node->next = to_delete->next;
    free(to_delete);
}

int_node* find_item_before(int number, int_list* list)
{
    int_node* curr = list->root;
    while (curr->next != NULL
        && curr->next->value != number)
    {
        curr = curr->next;
    }
    return curr->next ? curr : NULL;
}

bool delete_item(int_list* list, int number)
{
    if (!list || !list->root)
    {
        return false;
    }

    if (list->root->value == number)
    {
        delete_root(list);
        return true;
    }
    else
    {
        int_node* node = find_item_before(number, list);
        if (node)
        {
            delete_node_after(node);
            list->length--;
            return true;
        }
    }

    return false;
}

void test_search(const int_list* list)
{
    printf("number to search: ");
    int number_to_search = get_int();
    while (number_to_search != INT_MAX)
    {
        printf("index: %d\n\n", index_of(list, number_to_search));

        printf("number to search: ");
        number_to_search = get_int();
    }
}

void test_delete(int_list* list)
{
    printf("number to delete: ");
    int number_to_delete = get_int();
    while (number_to_delete != INT_MAX)
    {
        printf("%d was %s\n\n", number_to_delete, delete_item(list, number_to_delete) ? "deleted" : "not found");
        print_list(list);
        printf("\n");

        printf("number to delete: ");
        number_to_delete = get_int();
    }
}