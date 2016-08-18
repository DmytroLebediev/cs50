#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("---------------------------------------\n");
    printf("\tSize of different types\n");
    printf("---------------------------------------\n");
    printf("\tsize of short\t\t%luB\n",     sizeof(short));
    printf("\tsize of ushort\t\t%luB\n",    sizeof(unsigned short));
    printf("\tsize of int\t\t%luB\n",       sizeof(int));
    printf("\tsize of long\t\t%luB\n",      sizeof(long));
    printf("\tsize of long long\t%luB\n",   sizeof(long long));
    printf("\tsize of float\t\t%luB\n",     sizeof(float));
    printf("\tsize of double\t\t%luB\n",    sizeof(double));
    printf("\tsize of long double\t%luB\n", sizeof(long double));
    printf("\tsize of char\t\t%luB\n",      sizeof(char));
    printf("\tsize of char*\t\t%luB\n",     sizeof(char*));
    printf("\tsize of void\t\t%luB\n",      sizeof(void));
    printf("\tsize of void*\t\t%luB\n",     sizeof(void*));
    printf("\tsize of int*\t\t%luB\n",      sizeof(int*));
    printf("\tsize of string\t\t%luB\n",    sizeof(string));
    
    return 0;
}