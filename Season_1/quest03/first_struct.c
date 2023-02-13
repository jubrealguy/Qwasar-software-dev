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


void my_first_struct(integer_array* arr)
{
    int i;
    if (arr != NULL)
    {
        printf("%d\n", arr->size);
        for (i = 0; i < arr->size; i++)
        {
            printf("%d\n", arr->array[i]);
        }
    }
}