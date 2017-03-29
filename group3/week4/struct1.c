#include <stdio.h>
#include <cs50.h>

// struct Book
//  - author
//  - genre
//  - title
//  - number pages

// create one book
// ask use to fill its fields
// print book on screen

struct PERSON
{
    unsigned int id;
    char* name;
    string surname;
};

typedef struct PERSON PERSON1;
typedef unsigned int uint;

typedef struct
{
    string author;
    string title;
    string genre;
    unsigned int pages;
} BOOK;

int main()
{
    BOOK book;
    printf("Enter book author:\t");
    book.author = get_string();
    printf("Enter book title:\t");
    book.title = get_string();
    printf("Enter book genre:\t");
    book.genre = get_string();
    printf("Enter number of pages:\t");
    book.pages = get_int();
    
    printf("Enter book's author, title, genre and pages\n");
    BOOK book1 = {
        .author = get_string(),
        .title = get_string(),
        .genre = get_string(),
        .pages = get_int() };
        
    printf("Book \"%s\" by %s [%s], %i pages\n",
        book.title,
        book.author,
        book.genre,
        book.pages);
    
    printf("Book \"%s\" by %s [%s], %i pages\n",
        book1.title,
        book1.author,
        book1.genre,
        book1.pages);
}