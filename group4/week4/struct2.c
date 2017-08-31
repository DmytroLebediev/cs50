#include <stdio.h>
#include <cs50.h>

typedef struct //Book
{
    int pages;
    string author;
    string genre;
} BOOK;

void sort(int length, BOOK books[]);

int main()
{
    printf("enter number of books:\t");
    int length = get_int();

    BOOK books[length];
    for (int i=0; i<length; i++)
    {
        printf("pages:\t");
        books[i].pages = get_int();
        printf("author:\t");
        books[i].author = get_string();
        printf("genre:\t");
        books[i].genre = get_string();
    }

    sort(length, books);
    printf("\nsorted books:\n");

    for (int i=0; i<length; i++)
    {
        printf("pages: %i\n", books[i].pages);
        printf("author: %s\n", books[i].author);
        printf("genre: %s\n", books[i].genre);
    }

    return 0;
}

void sort(int length, BOOK books[])
{
    bool changes;

    do
    {
        changes = false;
        for (int i = 0; i < length - 1; i++)
        {
            if (books[i].pages > books[i + 1].pages)
            {
                BOOK temp = books[i];
                books[i] = books[i + 1];
                books[i + 1] = temp;

                changes = true;
            }
        }
    } while(changes);
}