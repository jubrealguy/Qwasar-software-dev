#include <stdbool.h>
#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif


bool my_is_sort(integer_array* arr)
{
    int i;
    if (arr->size == 0)
    {
        return true;
    }
    for (i = 0; i < arr->size; i++)
    {
        if (arr->array[i] >= arr->array[i + 1])
        {
            return true;
        }
        if (arr->array[i] >= arr->array[i + 1])
        {
            return true;
        }
        return false;
    }
}