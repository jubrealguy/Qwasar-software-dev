#include <stdlib.h>
#include <string.h>

char* my_strdup(char* str)
{
    char* words = malloc(sizeof(char) * strlen(str));
    int i;

    for (i = 0; str[i]; i++)
    {
        words[i] = str[i];
    }
    words[i] = '\0';
    return words;
}