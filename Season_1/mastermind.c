#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4

int check_digit(char* s)
{
    unsigned int i = 0;
    while (i < strlen(s))
    {
        if (s[i] < '0' || s[i] > '9')
        {
            return 1;
        }
        i++;
    }
    return 0;
}

void convert_to_int(int* a, char* b)
{
    
    int i;
    char str_num[2] = {0};
    for (i = 0; b[i]; i++)
    {
        str_num[0] = b[i];
        a[i] = atoi(str_num);
    }
}

int* rand_number()
{
    int* temp = malloc(SIZE * sizeof(int));
    int new_num[9] = {0};

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        int num = rand() % 10;

        while(new_num[num] == 1)
        {
            num = rand() % 10;
        }
        temp[i] = num;
        new_num[num] = 1;
    }
    return temp;
}

int main(int argc, char** argv)
{
    int* hidden_code = malloc(SIZE * sizeof(char));
    int num_generated = 10;
    int round = 0;
    int* predit = malloc(SIZE * sizeof(int));

    if (argc > 2)
    {
        if ((check_digit(argv[2]) != 0) || (strlen(argv[2]) != 4))
        {
            printf("Wrong input %s passed\n", argv[2]);
            hidden_code = rand_number();
        }
        else
        {
            if (strcmp(argv[1], "-c") == 0)
            {
                convert_to_int(hidden_code, argv[2]);
            }
            else if (strcmp(argv[1], "-t") == 0)
            {
                num_generated = atoi(argv[2]);
                if (num_generated > 10)
                {
                    num_generated = 10;
                }
            }
        }
    }
    else
    {
        hidden_code = rand_number();
    }

    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");

    while (num_generated > 0)
    {
        printf("\nRound %d\n", round);
        round++;

        int well_placed = 0, miss_placed = 0;
        char* buffering = malloc(5 * sizeof(char));
        if (buffering == NULL)
        {
            printf("Memory Allocation failed!\n");
            return 1;
        }

        ssize_t a = read(0, buffering, 5);
        if (a <= 4)
        {
            num_generated--;
            break;
        }
        else
        {
            buffering[a] = '\0';
        }

        int num_int = atoi(buffering);
        if (num_int == 0)
        {
            printf("Wrong input passed.\n");
            num_generated--;
            continue;
        }
        else
        {
            convert_to_int(predit, buffering);
        }

        for (int i = 0; i < SIZE; i++)
        {
            if (hidden_code[i] == predit[i])
            {
                well_placed++;
            }
            else
            {
                for (int j = 0; j < SIZE; j++)
                {
                    if (hidden_code[i] == predit[j] && i != j)
                    {
                        miss_placed++;
                        break;
                    }
                }
            }
        }
        if (well_placed == 4)
        {
            printf("Congratz! You did it!\n");
            break;
        }
        else
        {
            printf("Well placed pieces: %d\nMisplaced pieces: %d\n", well_placed, miss_placed);
            num_generated--;
        }
        free(buffering);
    }
    free(hidden_code);
    free(predit);
    return 0;
}