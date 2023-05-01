#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_ngram.h"


int main(int ac, char **av) {
    int arr[200] = {0};

    for (int index = 1; index < ac; index++) {
        getArray(&arr[0], av[index]);
    }
    displayArray(&arr[0], 128);

    return 0;
}

void getArray(int* arr, char* str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '"') {
            arr[(int)str[i]] += 1;
        }
    }
}

void displayArray(int* arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] > 0) {
            printf("%c:%i\n", i, arr[i]);
        }
    }
}
