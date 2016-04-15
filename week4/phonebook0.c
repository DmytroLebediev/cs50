#include <cs50.h>
#include <stdio.h>

typedef struct
{
    char* fname;
    char* lname;
    int phone;
} PERSON;



void sort(PERSON values[], int size);

int search(int value, PERSON values[], int size);

int binarysearch(int bleft, int bright, int bcount, PERSON barray[], int bnumber);

void printperson(PERSON person);

void getpersons(PERSON persons[], int size);



int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Run the program again specifying size of the phonebook\n\t./phonebook0 <size>");
		return 1;
	}
	if (argv == NULL || argv[1] == NULL)
	{
		printf("Oops! Can't get size of the phonebook\n");
		return 1;
	}
	
	int size = atoi(argv[1]);
    PERSON persons[size];
	
	getpersons(persons, size);
    sort(persons, size);
	
    printf("\nPlease enter phone number to find: ");
    int to_find_phone = GetInt();
	
    int index = search(to_find_phone, persons, size);
    if (index > -1)
    {
		printperson(persons[index]);
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
    
    return;
}

int search(int value, PERSON values[], int size)
{
    return binarysearch(0, size, size, values, value);
}

int binarysearch(int bleft, int bright, int size, PERSON values[], int bnumber)
{
    if ((bright - bleft) == 1)
    {
        if (values[bleft].phone == bnumber)
        {
            return bleft;
        }
        else
        {
            return -1;
        }
    }
    int mid = (bright + bleft) / 2;
    if (values[mid].phone == bnumber)
    {
        return mid;
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

void getpersons(PERSON persons[], int size)
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

void printperson()
{
	// TODO: display person
}