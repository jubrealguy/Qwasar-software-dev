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
#include <unistd.h>

void my_putchar(char c) {
  write(1, &c, 1);
}

void my_putstr(char* s)
{
    int i;
    for ( i = 0; s[i]; i++) {
        my_putchar(s[i]);
    }
}

void my_print_words_array(string_array* arr)
{
    int i, j;
    for (i = 0; i < arr->size; i++)
    {
       my_putstr(arr->array[i]);
       my_putstr("\n");
    }
}