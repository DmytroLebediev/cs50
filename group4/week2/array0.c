#include <cs50.h>
#include <stdio.h>
#include <limits.h>

int find_min(int length, const int numbers[]);

int main()
{
	int numbers[10] = {5, 7, 0, -1, 5, -1, -10, 100, 8, 34};
	printf("minimum is %d\n", find_min(10, numbers));
	
	return 0;
}

int find_min(int length, const int numbers[])
{
	int min = INT_MAX;
	for (int i = 0; i < length; i++)
	{
	    if (numbers[i] < min)
	    {
	        min = numbers[i];
	    }
	}
	return min;
}