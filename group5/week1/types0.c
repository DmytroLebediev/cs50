#include <stdio.h>
#include <math.h>

int main()
{
    short small_number = 0;
    unsigned short u_small_number = 0;

    printf("short value:\t\t\t%hi\t\tof size:\t%lu B\n",
        small_number,
        sizeof(short));
    printf("unsigned short value:\t\t%hu\t\tof size:\t%lu B\n",
        u_small_number,
        sizeof(unsigned short));

    int number = 0;
    unsigned int u_nummber = 0;

    printf("int value:\t\t\t%d\t\tof size:\t%lu B\n",
        number,
        sizeof(int));
    printf("unsigned int value:\t\t%u\t\tof size:\t%lu B\n",
        u_nummber,
        sizeof(unsigned int));

    long big_number = 0;
    unsigned long u_big_number = 0;

    printf("long value:\t\t\t%li\t\tof size:\t%lu B\n",
        big_number,
        sizeof(long));
    printf("unsigned long value:\t\t%lu\t\tof size:\t%lu B\n",
        u_big_number,
        sizeof(unsigned long));

    long long very_big_number = 0;
    unsigned long long u_very_big_number = 0;

    printf("long long value:\t\t%lli\t\tof size:\t%lu B\n",
        very_big_number,
        sizeof(long long));
    printf("unsigned long long value:\t%llu\t\tof size:\t%lu B\n",
        u_very_big_number,
        sizeof(unsigned long long));

    float fraction = 0.0;
    printf("float value:\t\t\t%f\tof size:\t%lu B\n", fraction, sizeof(float));

    double big_fraction = 0.0;
    printf("double value:\t\t\t%f\tof size:\t%lu B\n",
        big_fraction,
        sizeof(double)); //%g, %f, %e

    long double very_big_fraction = 0.0;
    printf("long double value:\t\t%Lf\tof size:\t%lu B\n",
        very_big_fraction,
        sizeof(long double));

    char character = 'a';
    unsigned char byte = 'a';

    printf("char value:\t\t\t%c\t\tof size:\t%lu B\n",
        character,
        sizeof(char)); //%hhi
    printf("unsigned char value:\t\t%c\t\tof size:\t%lu B\n",
        byte,
        sizeof(unsigned char)); //%hhu

    return 0;
}