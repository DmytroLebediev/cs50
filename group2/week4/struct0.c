#include <stdio.h>
#include <cs50.h>

typedef unsigned int uint;
typedef char* string;

typedef struct
{
    uint age;
    string fname;
    string lname;
    float avgmark;
} Person;

int main(int argc, string argv[])
{
    Persons* students = malloc(10 * sizeof(Persons));
    if (argc != 2)
    {
        return 1;
    }
    int length = atoi(argv[1]);
    
    Person students[length];
    for (int i=0; i<length; i++)
    {
        printf("Name:\t");
        students[i].fname = GetString();
        
        printf("Surname:\t");
        students[i].lname = GetString();
        
        printf("Age:\t");
        students[i].age = GetInt();
        
        printf("Score:\t");
        students[i].avgmark = GetFloat();
    }
    
    for (int i=0; i<length; i++)
    {
        printf("Student:\n\tname: %s\n", students[i].fname);
        printf("\tsurname: %s\n", students[i].lname);
        printf("\tage: %iu\n", students[i].age);
        printf("\tscore: %f\n", students[i].avgmark);
    }
    
    return 0;
}