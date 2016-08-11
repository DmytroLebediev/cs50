#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    int minimum = 1000000000;
    for (int i = 1; i < argc; i++)
    {
		// convert each argument to integer
		int chislo = atoi(argv[i]);
		if (chislo < minimum)
		{
			minimum = chislo;
		}
         
    }
    printf ("%i\n", minimum);
    return 0;
    
}