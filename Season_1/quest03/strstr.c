#include <stddef.h>
#include <string.h>

char* my_strstr(char* str1, char* str2)
{
    int i, j;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len2 > len1)
    {
        return NULL;
    }
    if (len2 == 0)
    {
        return str1;
    }
    for (i = 0; str1[i]; i++)
    {
        for (j = 0; str2[j]; j++)
        {
            if (str1[i] != str2[j])
            {
                break;
            }
            else if ((str1[i] == str2[j]) && (str1[i + len2 - 1] == str2[j + len2 - 1]))
            {
                return &(str1[i]);
            }
        }
    }
    return NULL;
}