#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned short ushort;

/**
 * Checks if string contains time in \d\d:\d\d format
 **/
bool is_valid_timestring(string timestring);

/**
 * Converts digit character to number.
 * Characters other than [0;9] are interpreted as 0.
 **/
byte to_digit(char character);

/**
 * Returns hours part of time string
 **/
ushort get_hours(string time);

/**
 * Ensures that hours are presented in 12-hour format
 **/
ushort to_12_format(ushort hours);



int main(int argc, string argv[])
{
    if (argc != 2
        || !is_valid_timestring(argv[1]))
    {
        printf("usage: ./params2 23:45\n");
        return 1;
    }
    
    ushort hours = get_hours(argv[1]);
    hours = to_12_format(hours);
    
    printf("%02hi:%c%c\n", hours, argv[1][3], argv[1][4]);
    
    return 0;
}

bool is_valid_timestring(string timestring)
{
    return strlen(timestring) == 5
        && timestring[2] == ':'
        && isdigit(timestring[0])
        && isdigit(timestring[1])
        && isdigit(timestring[3])
        && isdigit(timestring[4]);
}

ushort get_hours(string time)
{
    return to_digit(time[0]) * 10 + to_digit(time[1]);
}

byte to_digit(char character)
{
    return isdigit(character) ? character - '0' : 0;
}

ushort to_12_format(ushort hours)
{
    return hours % 12;
}