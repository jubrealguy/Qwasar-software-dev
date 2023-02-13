#include <string.h>
#include <stdio.h>
char* reverse_string(char* s)
{
    int i, tmp;
    int j = strlen(s) - 1;
    for (i = 0; s[i] && i < j; i++)
    {
        tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;

        j--;
    }
    return s;
}