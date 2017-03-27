#include <stdio.h>
#include <cs50.h>

typedef struct
{
    string name;
    string surname;
    unsigned int age;
} PERSON;

int main()
{
    int length = get_int();
    
    PERSON person;
    
    PERSON persons[length];
    
    person.age = 18;
    person.name = get_string();
    printf("Age: %u\n", person.age);
    
    for (int i = 0; i < length; i++)
    {
        persons[i].age = get_int();
        persons[i].name = get_string();
        persons[i].surname = get_string();
        
        printf("Age: %u\n", persons[i].age);
    }
}