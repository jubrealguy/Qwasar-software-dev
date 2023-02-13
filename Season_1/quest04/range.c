#include <stdlib.h>
int* my_range(int min, int max)
{
    int* nums = malloc(sizeof(int) * (max-min));
    int i;

    if (min >= max)
    {
        return NULL;
    }

    for (i = 0; i < max-min; i++)
    {
        nums[i] = min;
        min++;
    }
    nums[i] = min++;
    return nums;
}