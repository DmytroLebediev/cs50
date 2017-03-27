#include <stdio.h>
#include <cs50.h>

int main()
{
    float value = get_float();
    int value2 = value * 100;
    
    printf("float size: %lu\n", sizeof(float));
    printf("double size: %lu\n", sizeof(double));
    printf("float value: %.9f\n", value);
    printf("int size: %lu\n", sizeof(int));
    printf("int value: %d\n", value2);
}