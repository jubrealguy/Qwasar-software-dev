#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif
#include <string.h>
#include <stdio.h>


char* my_join(string_array* str, char* sep)
{
    int i;
    char* new_str;

    if (str->array == NULL)
    {
        return NULL;
    }
    strcat(str->array[0], sep);
    for (i = 1; i < str->size; i++)
    {
        if (i == str->size - 1)
        {
            new_str = str->array[i];
        }
        else
        {
            strcat(str->array[i], sep);
            new_str = str->array[i];
        }
        strcat(*str->array, new_str);
    }
    //printf("%s", *str->array);
    return *str->array;
}