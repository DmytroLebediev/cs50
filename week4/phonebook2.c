#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char* fname;
    char* lname;
    long long phone;
} PERSON;

typedef struct
{
	// 9. what can 'persons' store?
    PERSON* persons;
    int size;
} PHONEBOOK;


/**
 * sorts array of PERSON structs by phone number
 */
void sort(PERSON* values, int size);

/**
 * searches for a specified phone in array of PERSON structs
 */
PERSON* search(long long phonenumber, PERSON* values, int size);

/**
 * binary search to speed things up
 */
PERSON* binarysearch(int left, int right, int bcount, PERSON* persons, long long phonenumber);

/**
 * prints person t o a string
 */
void printperson(PERSON* person);

/**
 * reads array of PERSON structs
 */
void getpersons(PHONEBOOK* phonebook, char* filename);

/**
 * buffer to read from file
 */
char buffer[256];



int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Run the program again specifying file with the phonebook\n\t./phonebook2 <filename>\n");
		return 1;
	}
	if (argv == NULL || argv[1] == NULL)
	{
		printf("Oops! Can't get file with the phonebook\n");
		return 1;
	}
	
	char *filename = argv[1];
    PHONEBOOK phonebook;
	
	// 10. what will be passed to the function if one writes
	// 11. getpersons(phonebook, filename)?
	// 12. getpersons(&phonebook, filename)?
	// 13. getpersons(phonebook, *filename)?
	getpersons(&phonebook, filename);
	// 14. will it be correct to write sort(&phonebook.persons, &phonebook.size)?
    sort(phonebook.persons, phonebook.size);
	
    printf("\nPlease enter phone number to find: ");
    long long to_find_phone = GetLongLong();
    PERSON* person = search(to_find_phone, phonebook.persons, phonebook.size);
    if (person != NULL)
    {
		printperson(person);
    }
    else
    {
        printf("\nNot found :(\n");
    }
    
    free(phonebook.persons);
    
    return 0;
}

/**
 * sorts array of PERSON structs by phone number
 */
void sort(PERSON* values, int size)
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

/**
 * searches for a specified phone in array of PERSON structs
 */
PERSON* search(long long phonenumber, PERSON* persons, int size)
{
    return binarysearch(0, size, size, persons, phonenumber);
}

/**
 * binary search to speed things up
 */
PERSON* binarysearch(int left, int right, int size, PERSON* persons, long long phonenumber)
{
    if ((right - left) == 1)
    {
        if (persons[left].phone == phonenumber)
        {
            return (persons + left);
        }
        else
        {
            return NULL;
        }
    }
    int mid = (right + left) / 2;
    if (persons[mid].phone == phonenumber)
    {
        return (persons + mid);
    }
    else
    {
        if (phonenumber < persons[mid].phone)
        {
            return binarysearch(left, mid, size, persons, phonenumber);
        }
        else
        {
            return binarysearch(mid, right, size, persons, phonenumber);
        }
    }
}

/**
 * reads array of PERSON structs
 */
void getpersons(PHONEBOOK* phonebook, char* filename)
{
	// 15. what does it mean if phonebook is NULL or filename is NULL?
    if (phonebook == NULL || filename == NULL)
    {
        return;
    }
    
	// 16. what does "r" mean?
    FILE* fp = fopen(filename, "r");
    if (fp != NULL)
    {
		// 17. what can fgets return?
		// 18. what does it mean if fgets return NULL?
		// 19. what fgets is used for?
		// 20. how will 'buffer' change after fgets?
        if (fgets(buffer, 256, fp) != NULL)
        {
			// 21. what is stored in phonebook variable?
			// 22. what is '->' operator used for?
			// 23. what does (*phonebook) mean?
			// 24. what is correct (*phonebook).size or (*phonebook)->size?
            phonebook->size = atoi(buffer);
            printf("%s\n", buffer);
        }
        phonebook->persons = malloc(phonebook->size * sizeof(PERSON));
        for (int i = 0; i < phonebook->size; i++)
        {
            // read surname
            if (fgets(buffer, 256, fp) != NULL)
            {
				// 25. why phonebook->persons[i].lname equals to (*phonebook).persons[i].lname and to (phonebook->persons + i)->lname?
                phonebook->persons[i].lname = buffer;
            }
            // read name
            if (fgets(buffer, 256, fp) != NULL)
            {
                phonebook->persons[i].fname = buffer;
            }
            // read phone
            if (fgets(buffer, 256, fp) != NULL)
            {
                phonebook->persons[i].phone = atoll(buffer);
            }
        }
    }
    fclose (fp);
}

/**
 * prints person t o a string
 */
void printperson(PERSON* person)
{
    if (person != NULL)
    {
	    printf ("%s %s %lld \n", person->fname, person->lname, person->phone);
    }
}