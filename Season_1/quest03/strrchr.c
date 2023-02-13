#include <string.h>
char* my_strrchr(char* str, char ch)
{
    int i;
    for (i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] == ch)
        {
            return &(str[i]);
        }
    }
    return NULL;
}