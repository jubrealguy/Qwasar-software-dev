#include <stdio.h>
#include "main.h"

int main(void)
{
    char a[4] = "0123";
    char b[4];
    int i;

    int c = well_placed(a, b);
    int d = mis_placed(a, b);

    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");

    for (i = 0; i < 10; i++)
    {
        printf("---\nRound %d\n", i);
        scanf("%s", b);

       if (len(b) == 4)
       {
           if (c == 4)
           {
                printf("Congratz! You did it!\n");
                break;
            }
            else
            {
                printf("Well placed pieces: %d\n", c);
                printf("Misplaced pieces: %d\n", d);
            }
       }
       else {
            printf("Wrong\n");
       }
    }
    return 0;
}

int well_placed(char* nums, char* inp)
{
    int i, j;
    int well = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (nums[i] == inp[j] && i == j)
            {
                well++;
            }
        }
    }
    return well;
}

int mis_placed(char* nums, char* inp)
{
    int i, j;
    int mis = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (nums[i] == inp[j] && i != j)
            {
                mis++;
            }
        }
    }
    return mis;
}

int check_char(char* str)
{
    int i;
    int res;
    for (i = 0; i < len(str); i++)
    {
        if (str[i] < '0' || str[i] > '8')
            res = 0;
    }
    if (res == 0)
    {
        return 0;
    }
    return 1;
}

int len(char *str)
{
    int i;
    for (i = 0; str[i]; i++)
    {
        ;
    }
    return 0;
}