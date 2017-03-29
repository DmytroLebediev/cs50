#include <stdio.h>
#include <cs50.h>

typedef struct
{
    string author;
    string title;
    string genre;
    unsigned int pages;
} BOOK;

void print_book(BOOK book);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./struct2 number\n");
        return 1;
    }
    int length = atoi(argv[1]);
    BOOK books[length];
    // initialize each book in books array
    for (int i = 0; i < length; i++)
    {
        printf("Enter book author:\t");
        books[i].author = get_string();
        printf("Enter book title:\t");
        books[i].title = get_string();
        printf("Enter book genre:\t");
        books[i].genre = get_string();
        printf("Enter number of pages:\t");
        books[i].pages = get_int();
    }
    // print each book in books array with print_book
    for (int i = 0; i < length; i++)
    {
        print_book(books[i]);
    }
}

void print_book(BOOK book)
{
    printf("Book \"%s\" by %s [%s], %i pages\n",
        book.title,
        book.author,
        book.genre,
        book.pages);
}