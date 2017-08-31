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
    struct Book book;

    printf("size of book: %lu B\n", sizeof(book));
    book.pages = 10;
    book.author = "John Doe";
    book.genre = "fiction";

    printf("size of book: %lu B\n", sizeof(book));

    printf("pages: %i\n", book.pages);
    printf("author: %s\n", book.author);
    printf("genre: %s\n", book.genre);

    return 0;
}