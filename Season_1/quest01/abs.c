#include <stdio.h>

int my_abs(int num)
{
    if (num < 0) {
        num *= -1;
    }
    return num;
}