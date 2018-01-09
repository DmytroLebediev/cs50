#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

typedef int* intptr;

struct intarray
{
    int length;
    intptr pointer;
};

typedef struct person // typedef int* intptr;
{                     // 1) int* ~ person
    char *fname;      // 2) int* ~ struct person
    char *lname;      // 3) int* ~ PERSON
    char *address;    // 4) intptr ~ person
    int age;          // 5) intptr ~ struct person
    struct person *mom;// 6) intptr ~ PERSON
    struct person *dad;
} PERSON;

typedef struct
{
    struct person bio;
    char* group;
    struct intarray grades;
} STUDENT;

int main()
{
    struct intarray array = { .length = 0, .pointer = NULL };
    printf("enter array length\t");
    array.length = get_int();
    array.pointer = malloc(array.length * sizeof(int));

    // fill array with numbers from 1 to length
    for (int i = 0; i < array.length; i++)
    {
        array.pointer[i] = i + 1;
    }
    for (int i = 0; i < array.length; i++)
    {
        printf("array[%d]: %d\n", i, array.pointer[i]);
    }
    array.length = 0;
    free(array.pointer);
    array.pointer = NULL;

    PERSON mom, dad; //p1
    PERSON children[4];

    mom.lname = get_string();
    dad.lname = mom.lname;
    mom.fname = get_string();
    dad.fname = get_string();
    mom.address = get_string();
    dad.address = mom.address;
    mom.age = get_int();
    dad.age = get_int();
    mom.mom = NULL;
    mom.dad = NULL;
    dad.mom = NULL;
    dad.dad = NULL;

    for (int i = 0; i < 4; i++)
    {
        children[i].lname = dad.lname;
        children[i].address = dad.address;
        children[i].mom = &mom;
        children[i].dad = &dad;

        children[i].lname = children[i].dad->lname;

        children[i].fname = get_string();
        children[i].age = get_int();
    }

    STUDENT student;
    student.group = "1-A";
    student.bio = children[1];
    student.grades.length = 35;
    student.grades.pointer = malloc(35 * sizeof(int));
}