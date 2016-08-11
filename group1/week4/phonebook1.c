#include <cs50.h>
#include <stdio.h>

typedef struct
{
    char* fname;
    char* lname;
    int phone;
} PERSON;



/**
 * sorts array of PERSON structs by phone number
 */
void sort(PERSON* values, int size);

/**
 * searches for a specified phone in array of PERSON structs
 */
PERSON* search(int value, PERSON* values, int size);

/**
 * binary search to speed things up
 */
PERSON* binarysearch(int bleft, int bright, int bcount, PERSON* barray, int bnumber);

/**
 * prints person t o a string
 */
void printperson(PERSON* person);

/**
 * fills array of PERSON structs
 */
void getpersons(PERSON* persons, int size);



int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Run the program again specifying size of the phonebook\n\t./phonebook1 <size>");
		return 1;
	}
	if (argv == NULL || argv[1] == NULL)
	{
		printf("Oops! Can't get size of the phonebook\n");
		return 1;
	}
	
	int size = atoi(argv[1]);
	// 1. how 57th line differs from
	// PERSON persons;
	// PERSON persons[10];?
    PERSON* persons = NULL;
	// 2. how many bytes are allocated in 60th line?
	// 3. what will be stored in 'persons'?
    persons = malloc(size * sizeof(PERSON));
	
	// 4. what arguments does getpersons() accept?
	// 5. what is passed to the getpersons() in 'persons' variable and in 'size' variable?
	getpersons(persons, size);
	// 6. what arguments does getpersons() accepts?
	// 7. what is passed in 'persons' variable and in 'size' variable?
    sort(persons, size);
	
    printf("\nPlease enter phone number to find: ");
    int to_find_phone = GetInt();
	
    PERSON* index = search(to_find_phone, persons, size);
    if (index != NULL)
    {
		// 8. what is passed in 'index' variable?
		printperson(index);
    }
    else
    {
        printf("\nNot found :(\n");
    }
}

void sort(PERSON values[], int size)
{
    PERSON tmp;
    int count = 0;
    do
    {
        count = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (values[i].phone > values[i + 1].phone)
            {
                tmp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = tmp;
                count++;
            }
        }
    }
    while (count != 0);
}

PERSON* search(int value, PERSON* values, int size)
{
    return binarysearch(0, size, size, values, value);
}

PERSON* binarysearch(int bleft, int bright, int size, PERSON* values, int bnumber)
{
    if ((bright - bleft) == 1)
    {
        if (values[bleft].phone == bnumber)
        {
            return (values + bleft);
        }
        else
        {
            return NULL;
        }
    }
    int mid = (bright + bleft) / 2;
    if (values[mid].phone == bnumber)
    {
        return (values + mid);
    }
    else
    {
        if (bnumber < values[mid].phone)
        {
            return binarysearch(bleft, mid, size, values, bnumber);
        }
        else
        {
            return binarysearch(mid, bright, size, values, bnumber);
        }
    }
}

void getpersons(PERSON* persons, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\nPlease enter person's %i last name:\n", i+1);
        persons[i].lname = GetString();
        printf("Please enter person's %i first name:\n", i+1);
        persons[i].fname = GetString();
        printf("\nPlease enter person's %i phone:\n", i+1);
        persons[i].phone = GetInt();
    }
}

void printperson(PERSON* person)
{
	printf ("%s %s %i \n", (*person).fname, (*person).lname, (*person).phone);
}