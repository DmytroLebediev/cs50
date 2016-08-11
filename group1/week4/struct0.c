#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string fname;
    string lname;
    int phone;
} PERSON;

int main()
{
    PERSON p1;
    p1.fname = GetString();
    p1.lname = GetString();
    printf("Person: %s %s, %i years old, tel.: %s\n", p1.fname, p1.lname, p1.age, p1.phone);
    return 0;
    
}