#define _XOPEN_SOURCE

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

static int min(const int a, const int b);

static int consolewidth();

static int consoleheight();

static int calcdistribution(const int* values, int val_size, int* distribution, int dis_size);

void drawdistribution(const int* array, int size)
{
    int width = min(consolewidth(), size);
    int distribution[width];
    int max = calcdistribution(array, size, distribution, width);
    int height = min(consoleheight(), max);
    double ratio = (double)height / (double)max;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i < ratio * distribution[j])
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int min(const int a, const int b)
{
    if (a < b)
        return a;
    return b;
}

int consolewidth()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

int consoleheight()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;
}

int calcdistribution(const int* values, int val_size, int* distribution, int dis_size)
{
    int max = -1;
    int dencity = val_size / dis_size + 1;
    for (int i = 0; i < dis_size; i++)
    {
        distribution[i] = -1; // min in rnage
        for (int examined = i * dencity, limit = min(examined + dencity, val_size), j = examined; j < limit; j++)
        {
            if (distribution[i] < values[j])
            {
                distribution[i] = values[j];
            }
        }
        if (max < distribution[i])
        {
            max = distribution[i];
        }
    }
    return max;
}