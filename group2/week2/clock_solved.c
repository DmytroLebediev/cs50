#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (int count, string arg[])
{
    string time = arg[1];
    int hours = 0;
    /*
    example of what is stored in array time
         |2|3|:|5|5| - string argument passed to the program
         |0|1|2|3|4| - indeces of symbols (char) in the array
    */
    hours = time[0] - '0';
    hours = hours * 10 + (time[1] - '0');
    
    char daytime = 'A';
    if (hours % 12 > 0)
    {
        daytime = 'P';
    }
    hours = hours == 12 ? hours : hours % 12;
    /*
    if (hours != 12)
    {
        hours %= 12;
    }
    */
    printf("Hours %i:%c%c %cM\n", hours, time[3], time[4], daytime);

    return 0;
}