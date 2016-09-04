#include <stdio.h>

int main()
{
    int a = 1; //  ... 0000 0001
    int b = 8; //  ... 0000 1000
    
    //int c1 = a | b; // 0001 1001
    //int c2 = a ^ b; // 0000 1001
    
    /*printf("%i\n", c1);
    printf("%i\n", c2);*/
    
    printf("a = %i\n", a);
    printf("b = %i\n", b);
    
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    
    printf("a = %i\n", a);
    printf("b = %i\n", b);
    
    b = b << 2;
    a = a >> 2;
    a = a >> 4;
    
    printf("a = %i\n", a);
    printf("b = %i\n", b);
}