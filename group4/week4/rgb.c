#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef unsigned char byte;

byte getRed(int color);
byte getGreen(int color);
byte getBlue(int color);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./rgb number\n");
        return 1;
    }
    int color = atoi(argv[1]);

    byte red = getRed(color);
    byte green = getGreen(color);
    byte blue = getBlue(color);

    // print each component
    printf("red:\t%#x\n", red);
    printf("green:\t%#x\n", green);
    printf("blue:\t%#x\n", blue);

    return 0;
}

byte getRed(int color)
{
    return (byte)(color >> 16);
}

byte getGreen(int color)
{
    return (byte)(color >> 8);
}

byte getBlue(int color)
{
    return (byte)color;
}