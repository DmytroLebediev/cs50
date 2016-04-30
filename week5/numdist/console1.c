#define _XOPEN_SOURCE

#include "distribution.h"

int main (int argc, char **argv)
{
    int my_size = 201;
    if (argc == 2 && argv != NULL && argv[1] != NULL)
    {
        my_size = atoi(argv[1]);
    }
    int my_values[my_size];
    
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    printf ("columns %d\n", w.ws_col);
    
    srand48((long int) time(NULL));
    for (int i = 0; i < my_size; i++)
    {
        my_values[i] = (int)(drand48() * 10);
    }
    
    drawdistribution(my_values, my_size);
    
    return 0;
}