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

    printf("r: %hhu\ng: %hhu\nb: %hhu\n", red, green, blue);
    return 0;
}

byte getBlue(int color)
{
    int mask = 255;
    byte blue = mask & color;
    return blue;
}

byte getGreen(int color)
{
    int mask = 255 << 8; // 0xff00
    byte green = (mask & color) >> 8;
    return green;
}

byte getRed(int color)
{
    int mask = 255 << 16; // 0xff0000
    byte red = (mask & color) >> 16;
    return red;
    // RGB
    // mask
    // 0000 0000 1011 0011 0100 0000 1100 1100 <- some value
    // 0000 0000 1111 0000 0000 0000 0000 0000 <- mask
    // &
    // 0000 0000 1011 0000 0000 0000 0000 0000
    // >> 16
    // 0000 0000 0000 0000 0000 0000 0000 1011
}