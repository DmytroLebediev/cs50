#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char* fname;
    char* lname;
    char* phone;
} PERSON;

typedef struct
{
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
PERSON* search(char* lastname, PERSON* values, int size);

/**
 * binary search to speed things up
 */
PERSON* binarysearch(int left, int right, int bcount, PERSON* persons, char* lastname);

/**
 * prints person t o a string
 */
void printperson(PERSON* person);

/**
 * reads array of PERSON structs
 */
void getpersons(PHONEBOOK* phonebook, char* filename);

/**
 * compares two persons by last name then by first name
 * if they are equal then return 0
 * else if first one is greater then returns positive integer
 * otherwise returns negetive integer
 */
int comparepersons(PERSON a, PERSON b);

/**
 * buffer to read from file
 */
char buffer[256];



int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Run the program again specifying file with the phonebook\n\t./phonebook3 <filename>\n");
		return 1;
	}
	if (argv == NULL || argv[1] == NULL)
	{
		printf("Oops! Can't get file with the phonebook\n");
		return 1;
	}
	
	char *filename = argv[1];
    PHONEBOOK phonebook;
	getpersons(&phonebook, filename);
    sort(phonebook.persons, phonebook.size);
        
    printf("\nPlease enter surname to find: ");
    char* surname = GetString();
    PERSON* person = search(surname, phonebook.persons, phonebook.size);
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
            if (comparepersons(values[i], values[i + 1]) > 0)
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
PERSON* search(char* lastname, PERSON* persons, int size)
{
    return binarysearch(0, size, size, persons, lastname);
}

/**
 * binary search to speed things up
 */
PERSON* binarysearch(int left, int right, int size, PERSON* persons, char* lastname)
{
    if ((right - left) == 1)
    {
        if (strcmp(persons[left].lname, lastname) == 0)
        {
            return (persons + left);
        }
        else
        {
            return NULL;
        }
    }
    int mid = (right + left) / 2;
    int compare_middle = strcmp(lastname, persons[mid].lname);
    if (compare_middle == 0)
    {
        return (persons + mid);
    }
    else
    {
        if (compare_middle < 0)
        {
            return binarysearch(left, mid, size, persons, lastname);
        }
        else
        {
            return binarysearch(mid, right, size, persons, lastname);
        }
    }
}

/**
 * reads array of PERSON structs
 */
void getpersons(PHONEBOOK* phonebook, char* filename)
{
    if (phonebook == NULL || filename == NULL)
    {
        return;
    }
    
    FILE* fp = fopen(filename, "r");
    if (fp != NULL)
    {
        if (fgets(buffer, 256, fp) != NULL)
        {
            phonebook->size = atoi(buffer);
        }
        phonebook->persons = malloc(phonebook->size * sizeof(PERSON));
        for (int i = 0; i < phonebook->size; i++)
        {
            // read surname
            if (fgets(buffer, 256, fp) != NULL)
            {
                int length = strlen(buffer);
                if (buffer[length - 1] == '\n')
                {
                    buffer[length - 1] = '\0';
                }
                phonebook->persons[i].lname = malloc(sizeof(char) * length);
                strcpy(phonebook->persons[i].lname, buffer);
            }
            // read name
            if (fgets(buffer, 256, fp) != NULL)
            {
                int length = strlen(buffer);
                if (buffer[length - 1] == '\n')
                {
                    buffer[length - 1] = '\0';
                }
                phonebook->persons[i].fname = malloc(sizeof(char) * length);
                strcpy(phonebook->persons[i].fname, buffer);
            }
            // read phone
            if (fgets(buffer, 256, fp) != NULL)
            {
                int length = strlen(buffer);
                if (buffer[length - 1] == '\n')
                {
                    buffer[length - 1] = '\0';
                }
                phonebook->persons[i].phone = malloc(sizeof(char) * length);
                strcpy(phonebook->persons[i].phone, buffer);
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
	    printf ("%s %s %s \n", person->fname, person->lname, person->phone);
    }
}

/**
 * compares two persons by last name then by first name
 * if they are equal then return 0
 * else if first one is greater then returns positive integer
 * otherwise returns negetive integer
 */
int comparepersons(PERSON a, PERSON b)
{
    int comparelnames = strcmp(a.lname, b.lname);
    int comparefnames = strcmp(a.fname, b.fname);
    if (comparelnames != 0)
    {
        return comparelnames;
    }
    return comparefnames;
}