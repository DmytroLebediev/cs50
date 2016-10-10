#include <stdio.h>
#include <string.h>
#include <cs50.h>

string words[20000];

int getHash(const string word, int limit);

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        return 1;
    }
    
    for (int i=1; i<argc; i++)
    {
        words[getHash(argv[i], 20000)] = argv[i];
    }
    
    printf("Enter some word\n");
    string word = GetString();
    int index = getHash(word, 20000);
    if (words[index] != NULL
        && strcmp(words[index], word) == 0)
    {
        printf("Word was found!\n");
    }
}

int getHash(const string word, int limit)
{
    int result = 0;
    for (int i=0, length = strlen(word); i<length; i++)
    {
        result = result ^ (int)word[i];
        result = result << 2;
    }
    return result % limit;
}