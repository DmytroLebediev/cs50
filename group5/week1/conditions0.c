#include <stdio.h>
#include <cs50.h>

int main()
{
    int number;
    printf("Enter number greater than 100 or less than -100:\t");
    number = get_int();

    if (number > 100 || number < -100)
    {
        printf("Number is %d\n", number);
    }
    else
    {
        printf("You've entered wrong number!\n");
    }

    return 0;
}

/*

&& T | F   || T | F   !        ^  T | F
--------   --------   -----    --------
T |T | F   T |T | T   T | F    T |F | T
F |F | F   F |T | F   F | T    F |T | F

*/