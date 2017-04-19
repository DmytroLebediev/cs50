#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/**
 * Prints histogramm on a screen with ASCII-art
 * Each array's index is treated as X-axis while value by that index is treated as Y-axis
 * If size of desired chart is greater then the screen than Y-axis will be scaled
 */
void drawdistribution(const int* array, int size);