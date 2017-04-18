#include <stdio.h>
#include <string.h>

int hash(char c)
{
    return (255 ^ c) << 4
        | c;
}
int hash_str(const char* c)
{
    int result = 0;
    for (int i = 0; i<strlen(c); i++)
    {
        result ^= c[i];
        result *= 2;
    }
    return result;
}

int main()
{
    char hashtable[1023];
    
    char* str = "hello, world!";
    
    for (int i = 0; i< strlen(str); i++)
    {
        hashtable[hash(str[i]) % 1023] = str[i];
    }
    
    char c = 'h';
    if (hashtable[hash(c) % 1023] == c)
    {
        printf("found!\n");
    }
    
    for (int i = 0; i < 1023; i++)
    {
        printf("%c\n", hashtable[i]);
    }
}