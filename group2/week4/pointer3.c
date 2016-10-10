#include <stdio.h>
#include <stdlib.h>

typedef char* string;

typedef struct {
    string species; 8
    string name;    8
    int age;        4
    double weight;  8
} animal;

void readAnimals(animal** animals, int* length);

int main()
{
    animal* animals = NULL;
    int length = 0;
    
    printf("main:\n\tanimals:\t%p\n", animals);
    printf("\t&animals:\t%p\n", &animals);
    
    readAnimals(&animals, &length);
    
    printf("main:\n\tanimals:\t%p\n", animals);
    printf("\t&animals:\t%p\n", &animals);
    
    animal* cat = malloc(sizeof(animal));
    cat -> species = "mamals";
    cat[0].
    (*cat).species
    
    free(animals);
}

void readAnimals(animal** animals, int* length)
{
    if (animals == NULL)
    {
        printf("Some error!\n");
        return;
    }
    *animals = malloc(10 * sizeof(animal));
    *length = 10;
    
    printf("readAnimals:\n\tanimals:\t%p\n", animals);
    printf("\t&animals:\t%p\n", &animals);
    
    printf("\tlength:\t\t%p\n", length);
    printf("\t&length:\t%p\n", &length);
}