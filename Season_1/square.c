#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac != 3)
    {
        return 0;
    }
    else
    {
        int x = atoi(av[1]);
        int y = atoi(av[2]);
        int i, j;

        for (i = 0; i < y; i++)
        {
            for (j = 0; j < x; j++)
            {
                if ((j == 0 && i == 0) || (j == x-1 && i == 0) || (j == 0 && i == x-1) ||(j == x-1 && i == x-1))
                {
                    printf("o");
                }

                if ((j > 0 && j < x-1 && i == 0) || (j > 0 && j < x-1 && i == x-1))
                {
                    printf("-");
                }
                if ((j == 0 && i > 0 && i < x-1) || (j == x-1 && i > 0 && i < x-1))
                {
                    printf("|");
                }
                if ((j > 0 && j < x-1 && i > 0 && i < y-1))
                {
                    printf(" ");
                }
            }
            printf("\n");
            
        }
    }
    return 0;
}