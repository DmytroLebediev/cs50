#include <stdio.h>
#include <cs50.h>

struct Book
{
    int pages;
    string author;
    string genre;
};

int main()
{
    printf("enter number of books:\t");
    int length = get_int();

    struct Book books[length];
    for (int i=0; i<length; i++)
    {
        printf("pages:\t");
        books[i].pages = get_int();
        printf("author:\t");
        books[i].author = get_string();
        printf("genre:\t");
        books[i].genre = get_string();
    }

    for (int i=0; i<length; i++)
    {
        printf("pages: %i\n", books[i].pages);
        printf("author: %s\n", books[i].author);
        printf("genre: %s\n", books[i].genre);
    }

    return 0;
}