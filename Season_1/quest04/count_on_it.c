#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
#include <stdlib.h>
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif
#include <string.h>
#include <stdio.h>

int my_strlen(char* arr)
{
    int i;
    for (i = 0; arr[i] != '\0'; i++) {
        ;
    }
    return i;
}


integer_array* my_count_on_it(string_array* arr)
{
    integer_array* num;
    int i, j;

    if (num == NULL)
    {
        printf("no");
    }

    num->size = arr->size;
    for (i = 0; i < arr->size; i++)
    {
        num->array[i] = my_strlen(arr->array[i]);
    }
    return num;
}