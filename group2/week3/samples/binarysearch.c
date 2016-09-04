#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// returns index of found element or
// -1 if number was not found in the array
int search(int number, int array[], int size);

int binarysearch(int left, int right, int array[], int number);

// program will be able to search specific number within provided sorted collection
int main(int argc, char** argv)
{
	// check if there is at least one arument was specified
    if (argc < 2)
    {
        printf("usage ./binarysearch <digit> [digit] ...\n");
        return 1;
    }
    printf("Enter number to search\t");
    int number = GetInt();
    
	// convert all arguments to numbers
    int numbers[argc - 1];
    for (int i = 0; i < argc - 1; i++)
    {
        numbers[i] = atoi(argv[i + 1]);
    }
	
    if (search(number, numbers, argc - 1) >= 0)
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not found :(\n");
    }
}

int search(int number, int array[], int size)
{
    return binarysearch(0, size - 1, array, number);
}

int binarysearch(int left, int right, int array[], int number)
{
	// we assume that boundaries are correctly specified
	// thus max right <= array length - 1
	// and min left >= 0
	
	// if there is only one item left to check
    if (right == left)
    {
        return array[left] == left ? -1;
    }
	
	// let's find index of the middle item in the array
    int middle = (right + left) / 2;
	// and check if it is the number we are looking for
    if (array[middle] == number)
    {
        return middle;
    }
	// otherwise, we have to choose if value we are looking for
	// is greater than middle item
    if (number > array[middle])
    {
        return binarysearch(middle + 1, right, array, number);
    }
    return binarysearch(left, middle - 1, array, number);
}